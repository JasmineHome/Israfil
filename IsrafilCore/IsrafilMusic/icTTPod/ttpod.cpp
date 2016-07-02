#include "stdio.h"
#include "ttpod.h"
#include "rapidjson/document.h"

namespace Israfil {
namespace TTPod {
namespace json = rapidjson;

TTPod::TTPod()
{
  hc = new Israfil::Network::HttpClient();
  hc->addHeader("User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.103 Safari/537.36");
  hc->addHeader("Accept: */*");

  //    hc->addHeader("Accept-Encoding: gzip,deflate,sdch");
  hc->addHeader("Accept-Language: en-us");
  hc->addHeader("Connection: keep-alive");
  hc->addHeader("Content-Type: application/x-www-form-urlencoded");
  hc->addHeader("Host: www.ttpod.com");
  hc->addHeader("Referer: www.ttpod.com");
}

bool TTPod::SearchSong(std::string name, std::vector<Song>& rVecSongBase)
{
  // vector<SongBase> rVecSongBase;
  // TODO: add search function
  return true;
}

bool TTPod::FillMp3URL(Song& rSongBase) {
  if (rSongBase.isMp3Filled == true) return true;
  else return false;  // by default its filled, so if not, throw a false;
}

bool TTPod::FillLyricsURL(Song& rSongBase) {
  if (rSongBase.isLyricsFilled == true) return true;
  else return false;
}

bool TTPod::FillPicURL(Song& rSongBase) {
  if ((rSongBase.isPicFilled == true) && (rSongBase.isAlbumPicFilled == true)) return true;
  else return false;
}

std::string TTPod::GetHMp3URL(Song& rSongBase) {
  if ((rSongBase.isMp3Filled == false) && (FillMp3URL(rSongBase) == true)) return rSongBase.sMp3URLs[0];
  return rSongBase.sMp3URLs[0]; // TODO: fix potential indexoutofbound err;
}

std::string TTPod::GetPicURL(Song& rSongBase) {
  if ((rSongBase.isPicFilled == false) && (FillPicURL(rSongBase) == true)) return rSongBase.sPicURLs[0];
  return rSongBase.sPicURLs[0]; // TODO: fix potential indexoutofbound err;
  // TODO: add AlbumPic support;
}

std::string TTPod::GetLyricsURL(Song& rSongBase) {
  if ((rSongBase.isLyricsFilled == false) && (FillLyricsURL(rSongBase) == true)) return rSongBase.sLyricsURLs[0];
  return rSongBase.sLyricsURLs[0];
}
}
}
