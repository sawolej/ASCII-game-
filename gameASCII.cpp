
#include "gameASCII.h"


GameASCII::GameASCII(string lvl) :Game(){

    _hero.Init(1, 10, 10, 0, 100);
    _lvl.MakeLevel(lvl, _hero);
    _lvl.print();

    system("PAUSE");
}
