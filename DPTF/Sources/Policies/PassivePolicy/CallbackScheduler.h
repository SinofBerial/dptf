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
#include "ThermalRelationshipTable.h"
#include "TimeInterface.h"
#include "PolicyServicesInterfaceContainer.h"
#include "SourceAvailability.h"
#include "PolicyCallbackScheduler.h"
#include "TargetMonitor.h"
#include "TargetSourceRelationship.h"

// responsible for determining when to schedule callbacks for targets based on sampling intervals in the TRT
class dptf_export CallbackScheduler
{
public:

    CallbackScheduler(
        const PolicyServicesInterfaceContainer& policyServices,
        const ThermalRelationshipTable& trt,
        TargetMonitor* targetMonitor,
        std::shared_ptr<TimeInterface> time);
    ~CallbackScheduler();

    Bool isFreeForRequests(UIntN target, UIntN source, UInt64 time) const;
    void markBusyForRequests(UIntN target, UIntN source, UInt64 time);
    void ensureCallbackByNextSamplePeriod(UIntN target, UIntN source, UInt64 time);
    Bool isFreeForCommits(UIntN source, UInt64 time) const;
    void ensureCallbackByShortestSamplePeriod(UIntN target, UInt64 time);
    void acknowledgeCallback(UIntN target);

    // participant availability
    void removeParticipantFromSchedule(UIntN participant);
    void markSourceAsBusy(UIntN source, const TargetMonitor& targetMonitor, UInt64 time);

    // updates service objects
    void setTrt(const ThermalRelationshipTable& trt);
    void setTimeObject(std::shared_ptr<TimeInterface> time);

    // status
    XmlNode* getXml() const;
    
private:

    SourceAvailability m_sourceAvailability;
    ThermalRelationshipTable m_trt;
    TargetMonitor* m_targetMonitor;
    std::shared_ptr<PolicyCallbackSchedulerInterface> m_targetScheduler;
    std::map<TargetSourceRelationship, UInt64> m_requestSchedule;
};