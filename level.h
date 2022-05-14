#include <vector>
#include <string>
#include "hero.h"
#include "replicant.h"

using namespace std;

class Level
{
public:
    Level();
    void MakeLevel(string lvlFile, Hero &hero);
    void print();
    void PreMove(char input, Hero &hero);
    char getTarget(int x, int y);
    void setTarget(int x, int y, char tile);
    void updateRep(Hero &hero);
    vector <Replicant> _vReplicants;
private:

    vector <string> _lvlData;
    void BattleRep(Hero &hero, int targetX, int targetY);
    void processHeroMove(Hero &hero, int targetX, int targetY);
    void processRepMove(Hero &hero, int repIndex, int targetX, int targetY);
};
