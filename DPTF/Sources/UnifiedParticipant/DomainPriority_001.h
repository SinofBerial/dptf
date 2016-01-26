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
#include "DomainPriorityBase.h"

class DomainPriority_001 : public DomainPriorityBase
{
public:

    DomainPriority_001(UIntN participantIndex, UIntN domainIndex, 
        ParticipantServicesInterface* participantServicesInterface);

    // DomainPriorityInterface
    virtual DomainPriority getDomainPriority(UIntN participantIndex, UIntN domainIndex) override;

    // ComponentExtendedInterface
    virtual void clearCachedData(void) override;
    virtual std::string getName(void) override;
    virtual XmlNode* getXml(UIntN domainIndex) override;

private:

    // hide the copy constructor and = operator
    DomainPriority_001(const DomainPriority_001& rhs);
    DomainPriority_001& operator=(const DomainPriority_001& rhs);

    Bool m_cacheDataCleared;
    DomainPriority m_currentPriority;

    void updateCacheIfCleared(UIntN domainIndex);
    void updateCache(UIntN domainIndex);
};