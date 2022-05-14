#include"level.h"
#include"replicant.h"
#include<fstream>
#include<iostream>
#include <cstdio>
#include<vector>


Level::Level(){

}

void Level::MakeLevel(string lvlFile,  Hero &hero){


    ifstream file;
    file.open(lvlFile);
    if(file.fail()){

        perror(lvlFile.c_str());
        system("PAUSE");
        exit(1);
    }

    string line;

    while (getline(file, line)){
        _lvlData.push_back(line);

    }

    file.close();
    //proccess the lve
    char tile;
    for(int i=0; i<_lvlData.size(); i++){
        for(int j=0; j<_lvlData[i].size(); j++){
            tile=_lvlData[i][j];

            switch (tile) {
            case '@':
                hero.SetPos(i, j);
                break;
            case 'X':
                _vReplicants.push_back(Replicant("rep x", tile, 1, 3, 1, 10, 5, 5));
                _vReplicants.back().SetPos(j,i);
                break;
            case 'F':
                _vReplicants.push_back(Replicant("rep f", tile, 2, 10, 5, 30, 50,6));
                _vReplicants.back().SetPos(j,i);
                break;
            case 'K':
                _vReplicants.push_back(Replicant("rep k", tile, 3, 20, 20, 100, 100,7));
                _vReplicants.back().SetPos(j,i);
                break;
            case 'O':
                _vReplicants.push_back(Replicant("rep o", tile, 100, 2000, 2000, 1000, 10000,4));
                _vReplicants.back().SetPos(j,i);
                break;

            }
        }


    }

}

void Level::print(){

    cout<< string(100, '\n');
    for(int i=0; i<_lvlData.size(); i++){
        printf("%s\n", _lvlData[i].c_str());
    }
    printf("\n");
}
void Level::PreMove(char input, Hero &hero){

    int heroX,heroY;
    hero.GetPos(heroX,heroY);
    char target;
     switch (input){
        //up
    case 'w':
    case 'W':
        processHeroMove(hero, heroX, heroY-1);
        break;
        //down
    case 's':
    case 'S':
        processHeroMove(hero, heroX, heroY+1);
        break;
        //left
    case 'a':
    case 'A':
        processHeroMove(hero, heroX-1, heroY);
        break;
        //right
    case 'd':
    case 'D':
        processHeroMove(hero, heroX+1, heroY);
        break;
    default:
        printf("INVALID INPUT \n");
        system("PAUSE");
        break;
}
}

char Level::getTarget(int x, int y){

    return _lvlData[y][x];

}

void Level::setTarget(int x, int y, char tile){
    _lvlData[y][x]=tile;

}

void Level::processHeroMove(Hero &hero, int targetX, int targetY){

        int heroX,heroY;
        hero.GetPos(heroX,heroY);

        char Mtarget = getTarget(targetX, targetY);

        switch(Mtarget) {

        case '.':
            hero.SetPos(targetX, targetY);
            setTarget(heroX, heroY, '.');
            setTarget(targetX, targetY, '@');
            break;
        default:
            BattleRep(hero, targetX,targetY);

        }
}

void Level::BattleRep(Hero &hero, int targetX, int targetY){

    int repX, repY, heroX, heroY;
    int attackRoll;
    int attackResult;
    string name;

    hero.GetPos(heroX, heroY);


    for (int i=0; i<_vReplicants.size(); i++){

            _vReplicants[i].GetPos(repX, repY);
            name = _vReplicants[i].GetName();

            if (targetX==repX && targetY ==repY){

                //battle
                attackRoll = hero.Attack();
                printf("you attack %s with a roll of %d \n", name.c_str(), attackRoll);
                attackResult= _vReplicants[i].TakeDamage(attackRoll);

                if(attackResult !=0){

                    setTarget(targetX, targetY, '.');
                    print();
                    printf("Monster dies! \n");
////!!!!!!!!!!!!!!
                   // _vReplicants[i] = _vReplicants.back();
                    //_vReplicants.pop_back();
                    //i--;

                    system("PAUSE");
                    hero.AddExp(attackResult);


                    return;
                }

                attackRoll=_vReplicants[i].Attack();
                printf("%s attack you with a roll of %d \n", name.c_str(), attackRoll);
                attackResult= hero.TakeDamage(attackRoll);

                if(attackResult !=0){

                    setTarget(heroX, heroY, 'X');
                    print();
                    printf("You died! \n");
                    system("PAUSE");

                    exit(0);
                 }
                system("PAUSE");
                return;
            }


    }
}

void Level::updateRep(Hero &hero){

    char AIMove;
    int heroX, heroY, repX, repY;
    hero.GetPos(heroX,heroY);


    for(int i =0; i<_vReplicants.size(); i++){
        AIMove=_vReplicants[i].GetMove(heroX,heroY);

        _vReplicants[i].GetPos(repX, repY);

        switch (AIMove){
        //up
    case 'w':
        processRepMove(hero, i,  repX, repY-1);
        break;
        //down
    case 's':
        processRepMove(hero,i,  repX, repY+1);
        break;
        //left
    case 'a':
        processRepMove(hero,i,  repX-1, repY);
        break;
        //right
    case 'd':
        processRepMove(hero,i,  repX+1, repY);
        break;

    }
}}
void Level::processRepMove(Hero &hero, int repIndex, int targetX, int targetY){

        int heroX,heroY, repX, repY;
        hero.GetPos(heroX,heroY);
        _vReplicants[repIndex].GetPos(repX, repY);
        char tile = _vReplicants[repIndex].GetTile();
        char Mtarget = getTarget(targetX, targetY);

        switch(Mtarget) {

        case '.':
            _vReplicants[repIndex].SetPos(targetX, targetY);
            setTarget(repX, repY, '.');
            setTarget(targetX, targetY, tile);
            break;
        default:
            break;
        }
}
