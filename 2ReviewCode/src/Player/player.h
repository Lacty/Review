
#pragma once
#include "../common.h"


class cPlayer {
public:

  cPlayer();

  void update();
  void draw();

private:

  void drawPlayer();
  void runGravity();
  void runJump();
  void chengeDirection();
  void setPosOnGround();

  void drawShot();
  void runShot();
  void createShots();
  void moveShots();
  void killShots();

  WindowEdge edge;

  enum class JumpStatus {
    Landing,
    Jumping
  } jump_status;

  enum class Direction {
    Right =  1,
    Left  = -1
  } direction_status;

  enum ShotNum {
    Shot_Max = 4
  };

  enum class ShotStatus {
    Inactive,
    Active
  };

  Texture m_image;

  // playerèÓïÒ
  float2 m_pos;
  float  m_vy;
  float2 m_size;

  // íeèÓïÒ
  struct ShotData {
    ShotStatus status;
    Direction  direction;
    float2     pos;
    float      speed;
  } m_shots[Shot_Max];
};