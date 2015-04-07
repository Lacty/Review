
#pragma once
#include "common.h"


// 画面端情報
struct WindowEdge {
  const float top   =  HEIGHT * 0.5f;
  const float down  = -HEIGHT * 0.5f;
  const float right =  WIDTH  * 0.5f;
  const float left  = -WIDTH  * 0.5f;
};