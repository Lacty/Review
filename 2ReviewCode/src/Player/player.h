
#pragma once
#include "../common.h"


class cPlayer {
public:

  cPlayer();

  void update();
  void draw();

private:

  void runGravity();
  void runJump();
  void chengeDirection();
  void setPosOnGround();

  enum class JumpStatus {
    Landing,
    Jumping
  } jump_status;

  enum class Direction {
    Right =  1,
    Left  = -1
  } direction_status;

  Texture m_image;

  float2 m_pos;
  float  m_vy;
  float2 m_size;
};