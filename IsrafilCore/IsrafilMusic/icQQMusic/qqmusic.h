#ifndef QQMUSIC_H
#define QQMUSIC_H
#include "base.h"
#include "IsrafilNetwork/IsrafilNetwork.h"
#include "IsrafilBase/IsrafilBase.h"

using namespace Israfil::SongBase;
using namespace Israfil::Base;

namespace Israfil {
namespace QQMusic {
class ISRAFILCORE_API QQMusic {
public:

  QQMusic();
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

  void SplitF(std::string               FString,
              std::vector<std::string>& FArray);
  bool isAtString(std::string FAtString); // isAtString
  Israfil::Network::HttpClient *hc;
};
}
}
#endif // QQMUSIC_H
