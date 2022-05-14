#include "hero.h"


Hero::Hero() : Character(){


}


void Hero::AddExp(int ex){

    _experience+=ex;

    while(_experience > 50 ){
        printf("LEVELED UP! \N");
        _experience-=50;
        _attack+=10;
        _defence+=5;
        _health+=10;
        _level++;
        system("PAUSE");
    }
}
