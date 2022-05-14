#ifndef GAMEASCII_H
#define GAMEASCII_H

#include "game.h"

//----------------------------------------------------------------------
class GameASCII : public Game
{
   public:
      GameASCII(string lvl);
      virtual ~GameASCII() {};
      void View(){};
   protected:
   private:
      GameASCII(const GameASCII& g);
      GameASCII& operator=(const GameASCII& g);
};
//----------------------------------------------------------------------

#endif


