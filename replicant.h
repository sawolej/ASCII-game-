#ifndef REPLICANT_H
#define REPLICANT_H

#include "character.h"


using namespace std;
//----------------------------------------------------------------------
class Replicant : public Character
{
   public:
      Replicant(string name, char tile,int level, int attack, int defense, int health, int xp, int attackRange);
     ~Replicant() {};
      //Replicant& operator=(const Replicant& g);
     //AI move
      char GetMove(int heroX, int heroY);
   protected:
   private:
       int _attackRange;
      // void Attack();
       //void TakeDamage();
      // void Move();
      //Replicant(const Replicant& g);

};
//----------------------------------------------------------------------

#endif




