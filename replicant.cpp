#include <ctime>
#include <random>
#include "replicant.h"

using namespace std;

Replicant::Replicant(string name, char tile,int level, int attack, int defense, int health, int xp, int attackRange){
    _name= name;
    _ascii=tile;
    _level = level;
    _attack=attack;
    _defence=defense;
    _experience=xp;
    _health=health;
    _attackRange = attackRange;

}

char Replicant::GetMove(int heroX, int heroY){

    static default_random_engine randEngine(time(NULL));
    uniform_int_distribution<int>moveRoll(0,6);
    int distance;
    int dx = _x - heroX;
    int dy = _y-heroY;
    int adx = abs(dx);
    int ady = abs(dy);

    distance =adx + ady;

    if(distance <= _attackRange){
        if(adx<ady){
                //move along x
            if(dx>0) return 'a';
            else return 'd';
        }else{
            //move along y
            if(dy>0) return 'w';
            else return 's';
        }
    }

    int randomMove = moveRoll(randEngine);
    switch(randomMove){
    case 0:
        return 'a';
    case 1:
        return 'w';
    case 2:
        return 's';
    case 3:
        return 'd';
    default:
        return '.';
    }

}
