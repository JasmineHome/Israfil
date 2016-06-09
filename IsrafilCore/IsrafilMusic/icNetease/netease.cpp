#include <netease.h>
#include <sstream>
#include <cstring>
#include <iostream>
#include <rapidjson/document.h>
using std::ostringstream;
namespace json = rapidjson;

#define ITS(x) Israfil::strfmt::Format("{0}", x) //Int To String using strfmt

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
    tmpSB.sAlbum.aID     = ITS(neAlbum["id"].GetInt());
    tmpSB.sAlbum.aName   = neAlbum["name"].GetString();
    tmpSB.sAlbum.aPicURL = ITS(neAlbum["picId"].GetUint64());
    tmpSB.sPicURLs.push_back(neAlbum["img1v1Url"].GetString());
    rVecSongBase.push_back(tmpSB);
    //dbg("finished");
  }

  return true;
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

bool Netease::FillMp3URL(Song &rSongBase){
    std::string rSongDetails = hc->HttpGet(Israfil::strfmt::Format(NESongInfo, rSongBase.sID));

}

}
}
