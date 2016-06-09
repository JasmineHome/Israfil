#define CATCH_CONFIG_MAIN

#include "../test/catch.hpp"
#include <iostream>
#include <vector>
#include "netease.h"
#include "IsrafilBase/IsrafilBase.h"

using namespace Israfil::Netease;
using namespace Israfil::SongBase;
using std::vector;


TEST_CASE("Israfil::Netease Basic Tests - Search", "Netease") {
  // std::cout<<base64::encode("LOVE") <<std::endl;
  // std::cout<<MD5("LOVE").toStr() <<std::endl;
  Netease *ne = new Netease();

  std::cout << ne->encryptID("7947270045631279") << std::endl;
}
