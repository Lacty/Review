
//MyLibrary
#pragma once

struct float2{
  float x;
  float y;
  float2(float fx, float fy) : x(fx), y(fy){}
  float2(Vec2f vf) : x(vf.x()), y(vf.y()){}
  static float2 Zero(){ return float2(0, 0); }
  float2 operator + (Vec2f vf){
    return  float2(vf.x() + this->x, vf.y() + this->y);
  }
};