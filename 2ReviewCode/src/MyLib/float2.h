
//MyLibrary
#pragma once

struct float2{
  float x;
  float y;
  float2(float x0 = 0, float y0 = 0) : x(x0), y(y0){}
  float2(Vec2f vf) : x(vf.x()), y(vf.y()){}
  static float2 Zero(){ return float2(0, 0); }
  float2 operator + (Vec2f vf){
    return  float2(vf.x() + this->x, vf.y() + this->y);
  }
};