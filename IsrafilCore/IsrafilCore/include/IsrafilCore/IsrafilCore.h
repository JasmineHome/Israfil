/*=============================================================================
#     FileName: IsrafilCore.h
#         Desc: IsrafilCore Main Header, should be included instead of sub headers
#       Author: LER0ever
#        Email: etasry@gmail.com
#     HomePage: http://yirong.ml
#      Version: 0.0.1
#   LastChange: 2016-08-13 12:17:12
#      History:
=============================================================================*/
#ifndef ISRAFILCORE_H
#define ISRAFILCORE_H


#pragma once


#include <IsrafilCore-api.h>
#include <IsrafilBase/IsrafilBase.h>
#include <IsrafilNetwork/IsrafilNetwork.h>
#include <qqmusic.h>
#include <netease.h>

namespace Israfil {
namespace Core {
class ISRAFILCORE_API IsrafilCore {
public:

  IsrafilCore();
  SongList SearchSong(std::string strName);
  SongListInfoList GetUserSongList(std::string strUserID);
  SongList GetSongsInSLD(std::string strSongListID);
  Song GetAltSong(Song Orig);

private:

  Israfil::QQMusic::QQMusic *pQM;
  Israfil::Netease::Netease *pNE;
};
} // namespace Core
} // namespace Israfil


#endif // ISRAFILCORE_H
