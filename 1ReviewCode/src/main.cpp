
#include "common.h"
#include "Object/player.h"


int main() {
  AppEnv env(WIDTH, HEIGHT);
  env.bgColor(Color::white);

  cPlayer player(env);

  while (env.isOpen()) {
    player.update();

    env.begin();
    player.draw();

    env.end();
  }
}
