#ifndef UNIVERSAL_H
#define UNIVERSAL_H

#include <IsrafilBase/IsrafilBase.h>

class Universal
{
public:
  Universal();
  Israfil::SongBase::SongList search(string name);
};

#endif // UNIVERSAL_H
