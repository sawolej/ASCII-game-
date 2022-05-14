#ifndef ACTOR_H
#define ACTOR_H
#include<string>
using namespace std;
//======================================================================
class Actor
{
   public:
     Actor(){};
     string GetName() {return _name;}
     char GetTile(){return _ascii;}
   protected:

      virtual ~Actor() {};


       string _name;
       char _ascii;
        virtual string MakeName(){};
        void Delete();
        private:
      //Actor(const Actor& e);
      Actor& operator=(const Actor& e);
};
//----------------------------------------------------------------------

#endif

