/******************************************************************************
** Copyright (c) 2013-2015 Intel Corporation All Rights Reserved
**
** Licensed under the Apache License, Version 2.0 (the "License"); you may not
** use this file except in compliance with the License.
**
** You may obtain a copy of the License at
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
** WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**
** See the License for the specific language governing permissions and
** limitations under the License.
**
******************************************************************************/

#pragma once

#include "Dptf.h"
#include "PolicyServicesInterfaceContainer.h"
#include "DomainSetCachedProperty.h"
#include "ParticipantPropertiesCachedProperty.h"
#include "CriticalTripPointsCachedProperty.h"
#include "ActiveTripPointsCachedProperty.h"
#include "PassiveTripPointsCachedProperty.h"
#include "DomainProxy.h"
#include "TimeInterface.h"
#include "ParticipantProxyInterface.h"

// represents a participant.  contains cached records of participant properties and a list of domains contained within
// the participant.
class dptf_export ParticipantProxy : public ParticipantProxyInterface
{
public:

    ParticipantProxy();
    ParticipantProxy(
        UIntN participantIndex,
        const PolicyServicesInterfaceContainer& policyServices,
        std::shared_ptr<TimeInterface> time);
    ~ParticipantProxy();

    // domain access
    virtual DomainProxyInterface* bindDomain(UIntN domainIndex) override;
    virtual void unbindDomain(UIntN domainIndex) override;
    virtual DomainProxyInterface* getDomain(UIntN domainIndex) override;
    virtual std::vector<UIntN> getDomainIndexes() override;

    // properties
    virtual UIntN getIndex() const override;
    virtual const DomainPropertiesSet& getDomainPropertiesSet() override;
    virtual const ParticipantProperties& getParticipantProperties() override;

    // trip point sets
    virtual CriticalTripPointsCachedProperty& getCriticalTripPointProperty() override;
    virtual ActiveTripPointsCachedProperty& getActiveTripPointProperty() override;
    virtual PassiveTripPointsCachedProperty& getPassiveTripPointProperty() override;
    virtual XmlNode* getXmlForCriticalTripPoints() override;
    virtual XmlNode* getXmlForActiveTripPoints() override;
    virtual XmlNode* getXmlForPassiveTripPoints() override;

    // temperatures
    virtual Bool supportsTemperatureInterface()  override;
    virtual Temperature getFirstDomainTemperature() override;
    virtual void setTemperatureThresholds(const Temperature& lowerBound, const Temperature& upperBound) override;
    virtual TemperatureThresholds getTemperatureThresholds() override;
    virtual void notifyPlatformOfDeviceTemperature(const Temperature& currentTemperature) override;
    XmlNode* getXmlForTripPointStatistics();
    virtual void refreshHysteresis() override;
    virtual void refreshVirtualSensorTables() override;

    // thresholds
    virtual void setThresholdCrossed(const Temperature& temperature, UInt64 timestampInMs) override;
    virtual UInt64 getTimeOfLastThresholdCrossed() const override;
    virtual Temperature getTemperatureOfLastThresholdCrossed() const override;

    // capabilities
    virtual Bool hasSetDscpSupported() override;
    virtual Bool hasSetScpSupported() override;
    virtual Bool supportsDscp() override;
    virtual Bool supportsScp() override;
    virtual void setDscpSupport(Bool dscpSupported) override;
    virtual void setScpSupport(Bool scpSupported) override;
    virtual void setCoolingPolicy(const DptfBuffer& coolingPreference, CoolingPreferenceType::Type type) override;
    virtual XmlNode* getXmlForScpDscpSupport() override;
    virtual XmlNode* getXmlForPassiveControlKnobs() override;
    virtual XmlNode* getXmlForConfigTdpLevel() override;

private:

    // participant properties
    UIntN m_index;
    ParticipantPropertiesCachedProperty m_participantProperties;
    CriticalTripPointsCachedProperty m_criticalTripPointProperty;
    ActiveTripPointsCachedProperty m_activeTripPointProperty;
    PassiveTripPointsCachedProperty m_passiveTripPointProperty;

    // domain properties
    DomainSetCachedProperty m_domainSetProperty;
    std::map<UIntN, DomainProxy> m_domains;
    void refreshDomainSetIfUninitialized();
    void refreshDomains();

    // Temperatures
    Temperature getTemperatureForStatus(DomainProxyInterface* domainProxy);
    TemperatureThresholds getTemperatureThresholdsForStatus();

    Temperature m_previousLowerBound;
    Temperature m_previousUpperBound;
    Temperature m_lastIndicationTemperatureLowerBound;
    Temperature m_lastThresholdCrossedTemperature;
    UInt64 m_timeOfLastThresholdCrossed;

    // capabilities
    Bool m_supportsDscp;
    Bool m_supportsDscpValid;
    Bool m_supportsScp;
    Bool m_supportsScpValid;

    // services
    PolicyServicesInterfaceContainer m_policyServices;
    std::shared_ptr<TimeInterface> m_time;
};