#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <string>
#include "hero.h"
#include "level.h"
#include "human.h"
//======================================================================
class Engine
{
   protected:
      Engine();
      void HeroMove();
      //void DisplayTXT (string _txt);
      vector <string> lvl;
      virtual ~Engine() {};
      virtual void view(int, int){};
      Hero _hero;
      vector <Human> _vHumans;
      Level _lvl;


      Engine(const Engine& e);
      Engine& operator=(const Engine& e);
};
//----------------------------------------------------------------------

#endif

