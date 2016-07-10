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
  std::string rSongSearch = hc->HttpGet(Israfil::strfmt::Format(TTSearchURL, name, 0, 20));

  dbg(rSongSearch);

  json::Document doc;
  doc.Parse<0>(rSongSearch.c_str());

  if (doc.HasParseError()) {
    json::ParseErrorCode code = doc.GetParseError();
    dbgerr(code);
    return false;
  }

  json::Value& tData = doc["data"];

  if (tData.IsArray() == false) { dbgerr(tData.GetType()); return false; }
    dbg(tData.Size());

  for (int i = 0; i < tData.Size(); i++) {
    dbg(i);

    // iteration for songs in search result
    json::Value& tSong = tData[i];

    if (tSong.IsObject() == false) { dbgerr(tSong.GetType()); return false; }

    Song tmpSB;
    tmpSB.sName      = tSong["name"].GetString();
    tmpSB.sID        = ITS(tSong["songId"].GetInt64());
    tmpSB.sDevString = tSong["alias"].GetString();

    for (int j = tSong["urlList"].Size() - 1; j = 0; j--) {
      tmpSB.sMp3URLs.push_back(tSong["urlList"][j]["url"].GetString());
    }

    tmpSB.sSource = srcTTPod;
    tmpSB.uID     = Israfil::strfmt::Format("{0}{1}", tmpSB.sSource, tmpSB.sID);
    tmpSB.sOnly   = false;

    tmpSB.sAlbum.aID       = ITS(tSong["albumId"].GetInt64());
    tmpSB.sAlbum.aName     = tSong["albumName"].GetString();
    tmpSB.sAlbum.aPicURL   = "";
    tmpSB.isAlbumPicFilled = false; // TODO

    Musician tmpMSC;
    tmpMSC.mID   = ITS(tSong["singerId"].GetInt64());
    tmpMSC.mName = tSong["singerName"].GetString();
    tmpSB.sSingers.push_back(tmpMSC); // TODO: fix multi singer.

    tmpSB.sLyricsURLs.push_back(Israfil::strfmt::Format(TTLyricsURL, tSong["singerName"].GetString(), tmpSB.sName));
    tmpSB.isLyricsFilled = true;
    tmpSB.sPicURLs.push_back(Israfil::strfmt::Format(TTSongPicURL, tSong["singerName"].GetString()));
    tmpSB.isPicFilled = true;

    rVecSongBase.push_back(tmpSB);
  }
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

//TODO: deal with mp3url session timeout.
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
