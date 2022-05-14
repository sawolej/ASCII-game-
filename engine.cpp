#include "engine.h"
#include "conio.h"



Engine::Engine(){

}

void Engine::HeroMove(){
    char input;
    printf("enter a move command (w/s/a/d): ");
    input = _getch();
    _lvl.PreMove(input, _hero);
}
