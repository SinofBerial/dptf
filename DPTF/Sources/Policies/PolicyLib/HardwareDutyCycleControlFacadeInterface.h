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
#include "DomainProperties.h"

class dptf_export HardwareDutyCycleControlFacadeInterface
{
public:

    virtual ~HardwareDutyCycleControlFacadeInterface(void) {};

    virtual DptfBuffer getHardwareDutyCycleUtilizationSet() const = 0;
    virtual Bool isEnabledByPlatform() const = 0;
    virtual Bool isSupportedByPlatform() const = 0;
    virtual Bool isEnabledByOperatingSystem() const = 0;
    virtual Bool isSupportedByOperatingSystem() const = 0;
    virtual Bool isHdcOobEnabled() const = 0;
    virtual void setHdcOobEnable(const UInt8& hdcOobEnable) = 0;
    virtual void setHardwareDutyCycle(const Percentage& dutyCycle) = 0;
    virtual Percentage getHardwareDutyCycle() const = 0;
    virtual Bool supportsHdcControls() const = 0;
};