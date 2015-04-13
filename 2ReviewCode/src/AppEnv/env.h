
#pragma once
#include "../common.h"


class cEnv {
public:

  static AppEnv& get();


private:

  cEnv() = default;
};