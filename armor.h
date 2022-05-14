#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"
#include "hero.h"

//----------------------------------------------------------------------
class Armor : public Item
{
   public:
      Armor();
      virtual ~Armor() {};
   protected:
   private:
      void ChangeStat(Hero &_hero);
      Armor(const Armor& g);
      Armor& operator=(const Armor& g);
      friend class Hero;
};
//----------------------------------------------------------------------

#endif



