#include "game.h"
#include <iostream>




void Game::StartGame(){
    bool isDone = false;
    while(!isDone){
        _lvl.print();
        HeroMove();
        _lvl.updateRep(_hero);
    }

}
