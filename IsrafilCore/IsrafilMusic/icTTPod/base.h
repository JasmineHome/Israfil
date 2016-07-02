#ifndef BASE_H
#define BASE_H
#include <string>

namespace Israfil {
namespace TTPod {
using std::string;

const string TTBase          = "www.ttpod.com";
const string TTSearchBase    = "http://search.dongting.com";
const string TTSearchURL     = TTSearchBase + "/song/search/?q={0}&page={1}&size={2}";
const string TTSongPicURL    = "http://lp.music.ttpod.com/pic/down?artist={0}"; //Artist
const string TTLyricsURL     = "http://lp.music.ttpod.com/lrc/down?artist={0}&title={1}"; //Artist and title

#define DEBUG 1
}
}
#endif // ifndef BASE_H
