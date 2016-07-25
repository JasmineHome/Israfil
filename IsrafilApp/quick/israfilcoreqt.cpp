#include "israfilcoreqt.h"
#include <string>

IsrafilCoreQt::IsrafilCoreQt(QObject *parent) : QObject(parent)
{
  pIC = new Israfil::Core::IsrafilCore();
}

QString IsrafilCoreQt::searchSong(QString Name)
{
  std::string strRet = Israfil::SongBase::SongListToJson(pIC->SearchSong(Name.toStdString()));
  QString     qRet   = QString(QString::fromStdString(strRet));
  return qRet;
}

QString IsrafilCoreQt::getUserSongList(QString UserID)
{
  std::string strRet = Israfil::SongBase::SongListInfoListToJson(pIC->GetUserSongList(UserID.toStdString()));
  QString     qRet   = QString(QString::fromStdString(strRet));
  return qRet;
}

QString IsrafilCoreQt::getSongsInSLD(QString SongListID)
{
  std::string strRet = Israfil::SongBase::SongListToJson(pIC->GetSongsInSLD(SongListID.toStdString()));
  QString     qRet   = QString(QString::fromStdString(strRet));
  return qRet;
}
