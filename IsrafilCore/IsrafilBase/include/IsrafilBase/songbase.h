#ifndef SONGBASE_H
#define SONGBASE_H

#include <string>
#include <vector>

using std::string;
using std::vector;


namespace Israfil {
namespace SongBase {
#define srcNetease 1
#define srcQQMusic 2
#define srcXiami 3
#define srcKugou 4

struct Musician { // Artists
  string mName;
  string mID;
  string mNumOfAlbums;
  string mNumOfSongs;
};

struct Album {
  string aName;
  string aID;
  string aPicURL;

  // Musician aSinger;
};

struct Song {
  string          sName;
  string          sID;
  string          uID; // Israfil Universal Song ID;
  vector<Musician>sSingers;
  Album           sAlbum;
  int             sSource;
  bool            sOnly;
  vector<string>  sMp3URLs; // Mp3URL[0] is the highest bitrate
  vector<string>  sLLURL;   // Lossless Audio URL.
  vector<string>  sPicURLs;
  vector<string>  sLyricsURLs;
  string          sDevString;
  string          sSlot1;
  string          sSlot2;
  bool            isMp3Filled      = false;
  bool            isPicFilled      = false;
  bool            isLyricsFilled   = false;
  bool            isAlbumPicFilled = false;
};

typedef std::vector<Israfil::SongBase::Song>SongList;

string SongListToJson(SongList inSL);
}
}

#endif // SONGBASE_H
