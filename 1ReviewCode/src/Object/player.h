
#include "../common.h"
#include "../MyLib/float2.h"
#include "../window_edge.h"


class cPlayer {
public:

  cPlayer(AppEnv&);

  void update();
  void draw();


private:

  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
  void moveBound();

  AppEnv&    m_env;
  WindowEdge m_edge;

  short m_directionStatus;
  enum DirectionStatus {
    Left,
    Right
  };

  float2  m_pos;
  float2  m_size;
  Texture m_image;
};