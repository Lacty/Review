
#include "env.h"


AppEnv& cEnv::get() {
  static AppEnv env(WIDTH, HEIGHT);
  return env;
}