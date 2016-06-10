#include <netease.h>
#include <sstream>
#include <cstring>
#include <iostream>
#include <rapidjson/document.h>
using std::ostringstream;
namespace json = rapidjson;

#define ITS(x) Israfil::strfmt::Format("{0}", x) // Int To String using strfmt

namespace Israfil {
namespace Netease {
Netease::Netease()
{
  hc = new Israfil::Network::HttpClient();
  hc->addHeader("User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.103 Safari/537.36");
  hc->addHeader("Accept: */*");

  // hc->addHeader("Accept-Encoding: gzip,deflate,sdch");
  hc->addHeader("Accept-Language: en-us");
  hc->addHeader("Connection: keep-alive");
  hc->addHeader("Content-Type: application/x-www-form-urlencoded");
  hc->addHeader("Host: music.163.com");
  hc->addHeader("Referer: http://music.163.com");
}

bool Netease::SearchSong(std::string name, std::vector<Song>& rVecSongBase)
{
  std::string rSongSearch = hc->HttpPost(NESearchURL, Israfil::strfmt::Format(NESearchApiParams, name));

  dbg(rSongSearch);

  json::Document doc;
  doc.Parse<0>(rSongSearch.c_str());

  if (doc.HasParseError()) {
    json::ParseErrorCode code = doc.GetParseError();
    dbgerr(code);
    return false;
  }
  json::Value& nCode = doc["code"];

  if ((nCode.IsInt() == false) || (nCode.GetInt() != 200)) { dbgerr(nCode.GetInt()); return false; }
      dbg(nCode.GetInt());
  json::Value& nResult = doc["result"];

  if (nResult.IsObject() == false) { dbgerr(nResult.GetType()); return false; }
  json::Value& nSongs = nResult["songs"];

  if (nSongs.IsArray() == false) { dbgerr(nSongs.GetType()); return false; }
      dbg(nSongs.Size());

  for (int i = 0; i < nSongs.Size(); i++) { // iteration for songs
      dbg(i);
    json::Value& neSong = nSongs[i];

    if (neSong.IsObject() == false) { dbgerr(neSong.GetType()); return false; }

    Song tmpSB;
      dbg(neSong["id"].GetInt());
    tmpSB.sID = ITS(neSong["id"].GetInt());
      dbg(tmpSB.sID);
    tmpSB.sName   = neSong["name"].GetString();
    tmpSB.sOnly   = neSong["copyrightId"].GetInt() == 0 ? false : true;
    tmpSB.sSource = srcNetease;
    tmpSB.uID     = Israfil::strfmt::Format("{0}{1}", srcNetease, tmpSB.sID);

    json::Value& neArtists = neSong["artists"];

    if (neArtists.IsArray() == false) { dbgerr(neArtists.GetType()); return false; }
      dbg(neArtists.Size());

    for (int j = 0; j < neArtists.Size(); j++) { // iteration for artists
      dbg(j);
      json::Value& neMusician = neArtists[j];
      Musician     tmpMC;

      tmpMC.mID   = ITS(neMusician["id"].GetInt());
      tmpMC.mName = neMusician["name"].GetString();
      tmpSB.sSingers.push_back(tmpMC);
    }

    json::Value& neAlbum = neSong["album"];
    Album tmpAB;
      dbg(neAlbum["id"].GetInt());
    tmpSB.sAlbum.aID   = ITS(neAlbum["id"].GetInt());
    tmpSB.sAlbum.aName = neAlbum["name"].GetString();

    /*For Netease, Slot1 stores PicID*/
      dbg(ITS(neAlbum["picId"].GetUint64()));
    tmpSB.sSlot1 = ITS(neAlbum["picId"].GetUint64());

    // dbg(neAlbum["img1v1Url"].GetString());
    // tmpSB.sPicURLs.push_back(neAlbum["img1v1Url"].GetString());
    rVecSongBase.push_back(tmpSB);

    // dbg("finished");
  }

  return true;
}

// Fill the Mp3 URL by HTTP get the song detail page
bool Netease::FillMp3URL(Song& rSongBase) {
  std::string rSongDetails = hc->HttpGet(Israfil::strfmt::Format(NESongInfo, rSongBase.sID));

      dbg(Israfil::strfmt::Format(NESongInfo, rSongBase.sID));
      dbg(rSongDetails);
  json::Document doc;
  doc.Parse<0>(rSongDetails.c_str());

  if (doc.HasParseError()) {
    json::ParseErrorCode code = doc.GetParseError();
    dbgerr(code);
    return false;
  }
  json::Value& nCode = doc["code"];

  if ((nCode.IsInt() == false) || (nCode.GetInt() != 200)) { dbgerr(nCode.GetInt()); return false; }
  dbg(nCode.GetInt());

  json::Value& nSongs = doc["songs"]; // TODO: add err handle;
  assert(nSongs.IsArray());
      dbg(nSongs.Size());
  json::Value& nSong = nSongs[0];
      dbg("nSong SUC");

  if (nSong.HasMember("hMusic")) {
      dbg("hMusic SUC");
    json::Value& hMusic = nSong["hMusic"];
      dbg("hMusic SUC2");

    if ((hMusic.IsNull() == false) && hMusic.HasMember("dfsId")) {
      dbg("IF dfsId SUC");
      json::Value& dfsId = hMusic["dfsId"];
      dbg("dfsId SUC");
      std::string did = ITS(dfsId.GetUint64());
      rSongBase.sMp3URLs.push_back(Israfil::strfmt::Format(NESongCDN, encryptID(did), did, hMusic["extension"].GetString()));
    }
  }

  if (nSong.HasMember("mMusic")) {
    json::Value& mMusic = nSong["mMusic"];

    if ((mMusic.IsNull() == false) && mMusic.HasMember("dfsId")) {
      json::Value& dfsId = mMusic["dfsId"];
      std::string  did   = ITS(dfsId.GetUint64());
      rSongBase.sMp3URLs.push_back(Israfil::strfmt::Format(NESongCDN, encryptID(did), did, mMusic["extension"].GetString()));
    }
  }

  if (nSong.HasMember("lMusic")) {
    json::Value& lMusic = nSong["lMusic"];

    if ((lMusic.IsNull() == false) && lMusic.HasMember("dfsId")) {
      json::Value& dfsId = lMusic["dfsId"];
      std::string  did   = ITS(dfsId.GetUint64());
      rSongBase.sMp3URLs.push_back(Israfil::strfmt::Format(NESongCDN, encryptID(did), did, lMusic["extension"].GetString()));
    }
  }

  if (nSong.HasMember("bMusic")) {
    json::Value& bMusic = nSong["bMusic"];

    if ((bMusic.IsNull() == false) && bMusic.HasMember("dfsId")) {
      json::Value& dfsId = bMusic["dfsId"];
      std::string  did   = ITS(dfsId.GetUint64());
      rSongBase.sMp3URLs.push_back(Israfil::strfmt::Format(NESongCDN, encryptID(did), did, bMusic["extension"].GetString()));
    }
  }

  rSongBase.isMp3Filled = true;
  return true;
}

bool Netease::FillPicURL(Song& rSongBase)
{
  if (rSongBase.isPicFilled) everWarn("Pic Already Filled");

  if (rSongBase.sSlot1.length() < 5) {
    everErr("sSlot1 is somewhat not set");
    return false;
  }

  rSongBase.sPicURLs.push_back(Israfil::strfmt::Format(NEPicURL, encryptID(rSongBase.sSlot1), rSongBase.sSlot1));
  rSongBase.isPicFilled = true;
  return true;
}

bool Netease::FillLyricsURL(Song& rSongBase)
{
  if (rSongBase.isLyricsFilled) everWarn("Lyrics Already Filled");
  rSongBase.sLyricsURLs.push_back(Israfil::strfmt::Format(NELyricsURL, rSongBase.sID));
  rSongBase.isLyricsFilled = true;
  everMsg("Lyrics Filled");
  return true;
}

std::string Netease::GetHMp3URL(Song& rSongBase) // get the highest bitrate mp3
{
  if (rSongBase.isMp3Filled == false) {
    everWarn("Mp3 URL not filled, filling it now.");

    if (FillMp3URL(rSongBase) == true) ;
    else { everErr("Fill Mp3 URL error"); return ""; }
  }

  if (rSongBase.sMp3URLs.size() > 0) return rSongBase.sMp3URLs[0];
  else { everErr("No Mp3 URL Available"); return ""; }
}

std::string Netease::GetLyricsURL(Song& rSongBase)
{
  if (rSongBase.isLyricsFilled == false) {
    everWarn("Lyrics not filled, filling it now");

    if (FillLyricsURL(rSongBase) == true) ;
    else { everErr("Fill Lyrics URL error"); return ""; }
  }

  if (rSongBase.sLyricsURLs.size() > 0) return rSongBase.sLyricsURLs[0];
  else { everErr("No Lyrics Available"); return ""; }
}

std::string Netease::GetPicURL(Song& rSongBase)
{
  if (rSongBase.isPicFilled == false) {
    everWarn("PicURL not filled, filling it now");

    if (FillPicURL(rSongBase) == false) {
      everErr("Fill PicURL error");
      return "";
    }
  }

  if (rSongBase.sPicURLs.size() > 0) return rSongBase.sLyricsURLs[0];
  else { everErr("No Pic Available"); return ""; }
}

std::string Netease::GetLyrics(Song& rSongBase)
{
  std::string rLyrics = hc->HttpGet(GetLyricsURL(rSongBase));

  return rLyrics;
}

std::string Netease::encryptID(std::string dfsID)
{
  Israfil::crypto::crypto *crt = new Israfil::crypto::crypto();

  int  magiclength = NEMagicKey.length();
  int  idlength    = dfsID.length();
  auto dfsArray    = crt->StrToByteArray(dfsID);

  vector<unsigned char> strans;

  for (int i = 0; i < idlength; i++) strans.push_back(dfsArray[i] ^ NEMagicKey[i % magiclength]);
  auto res = crt->b64enc(crt->md5enc(strans));

  ostringstream out_stream;

  for (vector<unsigned char>::iterator it = res.begin(); it !=
       res.end(); ++it) {
    if (*it == '/') out_stream.put('_');
    else if (*it == '+') out_stream.put('-');
    else out_stream.put(*it);
  }
  return out_stream.str();
}
}
}
