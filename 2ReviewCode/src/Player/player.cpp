
#include "player.h"
#include "../AppEnv/env.h"


enum Ground {
  Ground_Pos = -200
};

enum TextureSize {
  Size_W = 256,
  Size_H = 128
};

enum InitPos {
  Pos_X = 0,
  Pos_Y = Ground_Pos
};

enum ShotSpeed {
  Shot_Speed = 20
};

cPlayer::cPlayer() :
m_image("res/player_img.png"),
direction_status(Direction::Right),
jump_status(JumpStatus::Landing),
m_pos(Pos_X, Pos_Y),
m_vy(0.0f),
m_size(Size_W, Size_H)
{
  for (int i = 0; i < Shot_Max; ++i) {
    m_shots[i].status = ShotStatus::Inactive;
    m_shots[i].speed  = Shot_Speed;
  }
}


void cPlayer::update() {
  chengeDirection();
  runJump();
  runGravity();
  setPosOnGround();
  runShot();
}

void cPlayer::draw() {
  drawTextureBox(m_pos.x, m_pos.y, m_size.x, m_size.y,
                 0, 0, m_size.x, m_size.y,
                 m_image,
                 Color::white,
                 0.0f,
                 Vec2f(static_cast<float>(direction_status), 1),
                 Vec2f(m_size.x * 0.5f, m_size.y * 0.5f));
}


void cPlayer::chengeDirection() {
  if (cEnv::get().isPressKey('D')) direction_status = Direction::Right;
  if (cEnv::get().isPressKey('A')) direction_status = Direction::Left;
}

void cPlayer::setPosOnGround() {
  if (m_pos.y >= Ground_Pos) return;
  m_pos.y = Ground_Pos;
  m_vy    = 0.0f;
  jump_status = JumpStatus::Landing;
}

void cPlayer::runGravity() {
  // == Landing Ç…Ç∑ÇÈÇ©ñ¿Ç¡ÇΩ
  // ç°!=Ç™Ç©Ç¡Ç±ÇÊÇ≠Ç›Ç¶ÇΩÇÃÇ≈Ç±Ç§ÇµÇƒÇ®Ç≠
  if (jump_status != JumpStatus::Jumping) return;

  const float g = -0.2f;
  m_vy += g;
  m_pos.y += m_vy;
}

void cPlayer::runJump() {
  if (jump_status != JumpStatus::Landing) return;
  if (!cEnv::get().isPushKey(GLFW_KEY_SPACE)) return;

  const float JumpPower = 10.0f;
  m_vy += JumpPower;
  m_pos.y += m_vy;

  jump_status = JumpStatus::Jumping;
}

void cPlayer::runShot() {

}

void cPlayer::createShots() {
  if (cEnv::get().isPushButton(Mouse::LEFT)) return;
  for (int i = 0; i < Shot_Max; ++i) {
    if (m_shots[i].status != ShotStatus::Inactive) return;
    // status == ShotStatus::Inactive Ç»ÇÁèàóùÇí ÇÈ

    // PlayerÇÃèÓïÒÇì«Ç›çûÇﬁ
    m_shots[i].direction = direction_status;
    m_shots[i].pos       = m_pos;
    m_shots[i].speed    *= static_cast(m_shots[i].direction); //err
    m_shots[i].status    = ShotStatus::Active;
  }
}

void cPlayer::moveShots() {

}