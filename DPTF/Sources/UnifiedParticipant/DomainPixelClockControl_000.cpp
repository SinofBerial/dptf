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

#include "DomainPixelClockControl_000.h"

DomainPixelClockControl_000::DomainPixelClockControl_000(UIntN participantIndex, UIntN domainIndex, 
    ParticipantServicesInterface* participantServicesInterface)
    : DomainPixelClockControlBase(participantIndex, domainIndex, participantServicesInterface)
{
    // Do nothing.  Not an error.
}

void DomainPixelClockControl_000::setPixelClockControl(UIntN participantIndex, UIntN domainIndex,
    const PixelClockDataSet& pixelClockDataSet)
{
    throw not_implemented();
}

void DomainPixelClockControl_000::clearCachedData(void)
{
    // Do nothing.  Not an error.
}

XmlNode* DomainPixelClockControl_000::getXml(UIntN domainIndex)
{
    throw not_implemented();
}

std::string DomainPixelClockControl_000::getName(void)
{
    return "Pixel Clock Control (Version 0)";
}