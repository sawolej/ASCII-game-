#ifndef CHARACTER_H
#define CHARACTER_H

#include "actor.h"
#include "item.h"
#include <vector>
using namespace std;
//----------------------------------------------------------------------
class Character : public Actor
{
   public:
      Character();
      virtual ~Character() {};
      void Init(int level, int attack, int defence, int experience, int health);
      void SetPos(int x, int y);
      void GetPos(int &x, int &y);
      int Attack();
      int TakeDamage( int attack);


   protected:

       //properties
       int _level, _attack, _defence, _experience, _health;
       //position
       int _x, _y;
       //func

       string makeName();


       virtual void Move(){};

      private:
        //  Character(const Character& g);
      Character& operator=(const Character& g);
};
//----------------------------------------------------------------------

#endif


