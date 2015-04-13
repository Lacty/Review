
#include "common.h"
#include "AppEnv/env.h"
#include "Player/player.h"


int main() {
  cEnv::get();
  cEnv::get().bgColor(Color::white);
  cPlayer player;

  while (cEnv::get().isOpen()) {
    player.update();

    cEnv::get().begin();
    player.draw();

    cEnv::get().end();
  }
}
