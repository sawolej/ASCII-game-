#include "character.h"
#include "actor.h"
#include <random>
#include <ctime>




//constructor, init pos to 0
Character::Character() : Actor(){
_x=0;
_y=0;
}
 //gets the pos of character using references
void Character::GetPos(int &x, int &y){
    x=_x;
    y=_y;
}
//sets the pos of the character
void Character::SetPos(int x, int y){
    _x=x;
    _y=y;
}
void Character::Init(int level, int attack, int defence, int experience, int health){
    _level=level;
    _attack=attack;
    _defence=defence;
    _experience=experience;
    _health=health;

}

int Character::Attack(){

    static default_random_engine randomEngine(time(NULL));
    uniform_int_distribution<int> attackRoll(0,_attack);

    return attackRoll(randomEngine);
}

int Character::TakeDamage( int attack){

    attack-=_defence;
    if(attack>0){
        _health-= attack;
        if(_health<=0){
            return _experience;
        }
    }else{
        return 0;
    }
}
