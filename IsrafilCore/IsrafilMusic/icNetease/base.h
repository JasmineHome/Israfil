#ifndef BASE_H
#define BASE_H
#include <string>
using std::string;
namespace Israfil {
namespace Netease {
const string NEBase            = "http://music.163.com";
const string NEApiBase         = NEBase + "/api";
const string NEWeApiBase       = NEBase + "/weapi";
const string NESearchURL       = NEApiBase + "/search/get";
const string NESongInfo        = NEApiBase + "/song/detail?ids=[{0}]";
const string NEGetArtistAlbums = NEApiBase + "/artist/albums/{0}?offset={1}&limit={2}";
const string NEGetAlbumSongs   = NEApiBase + "/album/{0}";
const string NESongCDN         = "http://m1.music.126.net/{0}/{1}.{2}";
const string NELyricsURL       = NEApiBase + "/song/lyric?os=osx&id={0}&lv=-1&kv=-1&tv=-1";
const string NEPicURL          = "http://p4.music.126.net/{0}/{1}.jpg";
const string NEMagicKey        = "3go8&$8*3*3h0k(2)2";
const string NESearchApiParams = "s={0}&limit=20&type=1&offset=0";

#define USE_NETEASE_NEW_API false
} // namespace Netease
} // namespace Israfil
#endif // ifndef BASE_H
