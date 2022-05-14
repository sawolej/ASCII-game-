#ifndef HERO_H
#define HERO_H

#include "character.h"

//----------------------------------------------------------------------
class Hero : public Character
{
   public:
      Hero();
      virtual ~Hero() {};
      void AddExp(int ex);

   protected:
   private:



      Hero(const Hero& g);
      Hero& operator=(const Hero& g);

};
//----------------------------------------------------------------------

#endif



