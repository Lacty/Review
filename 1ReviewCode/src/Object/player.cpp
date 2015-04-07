
#include "player.h"


enum ImageStatus {
  Img_Size_Width  = 256,
  Img_Size_Height = 128
};

enum MoveSpeed {
  Speed_X = 10,
  Speed_Y = 10
};

cPlayer::cPlayer(AppEnv& env) :
m_env(env),
m_directionStatus(Right),
m_pos(float2::Zero()),
m_size(Img_Size_Width, Img_Size_Height),
m_image("res/player_img.png") {}


void cPlayer::update() {
  moveUp();
  moveDown();
  moveLeft();
  moveRight();
  moveBound();
}

void cPlayer::draw() {
  drawTextureBox(m_pos.x, m_pos.y, m_size.x, m_size.y,
                 0,
                 (m_directionStatus * m_size.y),
                 m_size.x,
                 m_size.y,
                 m_image,
                 Color::white);
}


void cPlayer::moveUp() {
  if (!m_env.isPressKey('W')) return;
  m_pos.y += Speed_Y;
}

void cPlayer::moveDown() {
  if (!m_env.isPressKey('S')) return;
  m_pos.y -= Speed_Y;
}

void cPlayer::moveLeft() {
  if (!m_env.isPressKey('A')) return;
  m_pos.x -= Speed_X;
  m_directionStatus = Right;
}

void cPlayer::moveRight() {
  if (!m_env.isPressKey('D')) return;
  m_pos.x += Speed_X;
  m_directionStatus = Left;
}


void cPlayer::moveBound() {
  if ((m_pos.x < edge.left) ||
      (m_pos.x + m_size.x > edge.right))
  {
    m_pos.x = std::max(m_pos.x, edge.left);
    m_pos.x = std::min(m_pos.x, edge.right - m_size.x);
  }

  if ((m_pos.y < edge.down) ||
      (m_pos.y + m_size.y > edge.top))
  {
    m_pos.y = std::max(m_pos.y, edge.down);
    m_pos.y = std::min(m_pos.y, edge.top - m_size.y);
  }
}