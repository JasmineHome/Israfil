#ifndef TTPOD_H
#define TTPOD_H
#include "base.h"
#include "IsrafilNetwork/IsrafilNetwork.h"
#include "IsrafilBase/IsrafilBase.h"

using namespace Israfil::SongBase;
using namespace Israfil::Base;

namespace Israfil {
namespace TTPod {
class ISRAFILCORE_API TTPod {
public:

  TTPod();
  bool        SearchSong(std::string        name,
                         std::vector<Song>& rVecSongBase);
  bool        FillMp3URL(Song& rSongBase);
  std::string GetHMp3URL(Song& rSongBase);
  bool        FillPicURL(Song& rSongBase);
  std::string GetPicURL(Song& rSongBase);
  bool        FillLyricsURL(Song& rSongBase);
  std::string GetLyricsURL(Song& rSongBase);
  std::string GetLyrics(Song& rSongBase);

private:

  Israfil::Network::HttpClient *hc;
};
}
}
#endif // TTPOD_H
