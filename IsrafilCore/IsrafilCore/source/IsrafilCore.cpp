#include <IsrafilCore/IsrafilCore.h>

namespace Israfil {
namespace Core {
IsrafilCore::IsrafilCore()
{
  pQM = new Israfil::QQMusic::QQMusic();
  pNE = new Israfil::Netease::Netease();
}

SongList IsrafilCore::SearchSong(std::string strName)
{
  // currently just return the qm search result
  SongList retSL;
  bool     bSS = pQM->SearchSong(strName, retSL);

  if (bSS == true) bSS = pNE->SearchSong(strName, retSL);
  dbg(bSS);
  return retSL;
}

SongListInfoList IsrafilCore::GetUserSongList(std::string strUserID) {
  SongListInfoList retSLIL;
  bool bSuc = pNE->GetUserSongList(strUserID, retSLIL);

  if (bSuc == false) dbgerr(strUserID);
  return retSLIL;
}
}
}
