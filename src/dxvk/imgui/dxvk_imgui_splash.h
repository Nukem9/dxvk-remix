/*
* Copyright (c) 2022, NVIDIA CORPORATION. All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include "../../util/rc/util_rc.h"
#include "../../util/rc/util_rc_ptr.h"
#include "imgui.h"

#include <chrono>

namespace dxvk {
  class DxvkContext;

  class ImGuiSplash : public RcObject {
  public:
    ImGuiSplash() { }

    ImGuiSplash(const ImGuiSplash& other) = delete;
    ImGuiSplash(const ImGuiSplash&& other) = delete;

    void update(ImFont* largeFont);

  private:
    const int m_timeToLiveSeconds = 10;

    bool m_hasStarted = false;
    std::chrono::system_clock::time_point  m_startTime;
  };
}