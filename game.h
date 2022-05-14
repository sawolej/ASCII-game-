#ifndef GAME_H
#define GAME_H

#include "engine.h"

//----------------------------------------------------------------------
class Game : public Engine
{
   public:
      Game(){};
      virtual ~Game() {};
      void StartGame();
      virtual void View(){};
   protected:
   private:
      Game(const Game& g);
      Game& operator=(const Game& g);
};
//----------------------------------------------------------------------

#endif

