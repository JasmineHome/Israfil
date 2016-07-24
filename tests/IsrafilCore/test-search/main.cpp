#define CATCH_CONFIG_MAIN

#include "../test/catch.hpp"
#include <iostream>
#include <vector>
#include <IsrafilCore/IsrafilCore.h>

using namespace Israfil::SongBase;
using std::vector;


TEST_CASE("Israfil::Core Basic Tests - Search", "QQMusic and Netease") {
  vector<Song> ret;
  Israfil::QQMusic::QQMusic     *qm = new Israfil::QQMusic::QQMusic();
  Israfil::Netease::Netease     *ne = new Israfil::Netease::Netease();
  std::string  SearchNameInput;
  std::cout << "Don\'t run inside Qt Creator!" << std::endl   \
            << "Input the name you wonna search" << std::endl \
            << "It will return the result from QQMusic and Netease" << std::endl;
  std::cin >> SearchNameInput;
  Israfil::Core::IsrafilCore *ic = new Israfil::Core::IsrafilCore();
  ret = ic->SearchSong(SearchNameInput);
  dbg(ret.size());

  /*
     for (int i = 0; i < ret.size(); i++) {
     std::cout << ret[i].sName << " :: " << ret[i].sSingers[0].mName << " :: "
        << ret[i].sMp3URLs[0] \
              << " :: " << ret[i].sLyricsURLs[0] << " : "
                                                           \
              << ret[i].sPicURLs[0] << " vs " << ret[i].sAlbum.aPicURL <<
                 std::endl;
     }*/

  std::cout << SongListToJson(ret) << std::endl;
}
