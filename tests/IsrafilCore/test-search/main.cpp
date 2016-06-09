#define CATCH_CONFIG_MAIN

#include "../test/catch.hpp"
#include <iostream>
#include <vector>
#include "qqmusic.h"
#include "netease.h"
#include "IsrafilBase/IsrafilBase.h"

using namespace Israfil::QQMusic;
using namespace Israfil::Netease;
using namespace Israfil::SongBase;
using std::vector;


TEST_CASE("Israfil::Core Basic Tests - Search", "QQMusic and Netease") {
  vector<Song> ret;
  QQMusic     *qm = new QQMusic();
  Netease     *ne = new Netease();
  std::string  SearchNameInput;
  std::cout << "Don\'t run inside Qt Creator!" << std::endl   \
            << "Input the name you wonna search" << std::endl \
            << "It will return the result from QQMusic and Netease" << std::endl;
  std::cin >> SearchNameInput;
  qm->SearchSong(SearchNameInput, ret);
  ne->SearchSong(SearchNameInput, ret);
  dbg("search complete");
  for (int i=0; i<ret.size(); i++){
      if (ret[i].sSource == srcNetease){
          ne->FillMp3URL(ret[i]);
      }
  }
  dbg(ret.size());

  /*
  for (int i = 0; i < ret.size(); i++) {
    std::cout << ret[i].sName << " :: " << ret[i].sSingers[0].mName << " :: " << ret[i].sMp3URLs[0] \
              << " :: " << ret[i].sLyricsURLs[0] << " : "                                           \
              << ret[i].sPicURLs[0] << " vs " << ret[i].sAlbum.aPicURL << std::endl;
  }*/

  std::cout << SongListToJson(ret) << std::endl;
}
