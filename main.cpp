#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>


using namespace std;
#include "gameASCII.h"
int main()
{
    GameASCII game("lvl1.txt");

    game.StartGame();


    /*
    char input;

    while (true) {
        input = _getch();
        cout<<string(100, '\n');
        cout<<"you'r entered: "<< input<<"\n";
    }
*/
    return 0;
}
