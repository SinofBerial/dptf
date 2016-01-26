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

#include "DomainPriority.h"
#include "XmlNode.h"
#include "StatusFormat.h"

DomainPriority::DomainPriority() : m_currentPriority(0)
{
}

DomainPriority::DomainPriority(UIntN currentPriority) : m_currentPriority(currentPriority)
{
}

UIntN DomainPriority::getCurrentPriority(void) const
{
    return m_currentPriority;
}

Bool DomainPriority::operator==(const DomainPriority& rhs) const
{
    return (this->getCurrentPriority() == rhs.getCurrentPriority());
}

Bool DomainPriority::operator!=(const DomainPriority& rhs) const
{
    return !(*this == rhs);
}

Bool DomainPriority::operator>(const DomainPriority& rhs) const
{
    return (this->getCurrentPriority() > rhs.getCurrentPriority());
}

Bool DomainPriority::operator<(const DomainPriority& rhs) const
{
    return (this->getCurrentPriority() < rhs.getCurrentPriority());
}

XmlNode* DomainPriority::getXml(void)
{
    return XmlNode::createDataElement("domain_priority", StatusFormat::friendlyValue(m_currentPriority));
}