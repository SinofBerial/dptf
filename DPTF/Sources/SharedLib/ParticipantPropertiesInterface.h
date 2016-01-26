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
#include "ParticipantProperties.h"
#include "DomainPropertiesSet.h"

class ParticipantPropertiesInterface
{
public:

    virtual ~ParticipantPropertiesInterface()
    {
    };

    virtual ParticipantProperties getParticipantProperties(UIntN participantIndex) = 0;
    virtual DomainPropertiesSet getDomainPropertiesSet(UIntN participantIndex) = 0;
};