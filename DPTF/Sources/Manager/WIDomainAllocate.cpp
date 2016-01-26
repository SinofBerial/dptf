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

#include "WIDomainAllocate.h"
#include "ParticipantManager.h"
#include "EsifServices.h"

WIDomainAllocate::WIDomainAllocate(DptfManagerInterface* dptfManager, UIntN participantIndex, UIntN* newDomainIndex) :
    ParticipantWorkItem(dptfManager, FrameworkEvent::Type::DomainAllocate, participantIndex),
    m_newDomainIndex(newDomainIndex)
{
}

WIDomainAllocate::~WIDomainAllocate(void)
{
}

void WIDomainAllocate::execute(void)
{
    WriteParticipantWorkItemStartingInfoMessage();

    try
    {
        getParticipantPtr()->allocateDomain(m_newDomainIndex);
    }
    catch (std::exception ex)
    {
        *m_newDomainIndex = Constants::Esif::NoDomain;
        WriteParticipantWorkItemErrorMessage_Function("Participant::allocateDomain");
    }
}