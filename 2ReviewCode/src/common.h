
#pragma once
#include "lib/framework.hpp"
#include "MyLib/float2.h"

enum WindowSize {
  WIDTH = 512,
  HEIGHT = 512,
};

struct WindowEdge {
  const float top    =  HEIGHT * 0.5f;
  const float bottom = -HEIGHT * 0.5f;
  const float left   = -WIDTH  * 0.5f;
  const float right  =  WIDTH  * 0.5f;
};