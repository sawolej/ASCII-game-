#ifndef HUMAN_H
#define HUMAN_H

#include "character.h"

//----------------------------------------------------------------------
class Human : public Character
{
   public:
      Human();
      virtual ~Human() {};
   protected:
   private:
       void Dialog();
       void Move();
      Human(const Human& g);
      Human& operator=(const Human& g);

};
//----------------------------------------------------------------------

#endif




