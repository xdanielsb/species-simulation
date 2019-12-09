#ifndef _CFarsighted
#define _CFarsighted
#include"./Behaviour.hpp"

using namespace std;

class Farsighted:public Behaviour{
public:
  void move(Animal* animal, vector<Animal*> listAnimals){
    ii posSelf = animal->getPosition();
    for(auto ptr:listAnimals){
      if(index == ptr->getIndex()){
        continue;
      }
      ii posA = ptr->getPosition();   // not defind in the class beast, return type pair<int, int>

      //To verify the beast is next to this beast or not and the range of forseeing is 4
      if(sqrt((posA.X- posSelf.X)*(posA.X- posSelf.X)+(posA.Y- posSelf.Y)*(posA.Y- posSelf.Y))< 4) {
          animal->dir = ptr->getDirection();  // not defind in the class beast, return type pair<int, int>
      }
    }
    // change the position
    animal->pos.X+= animal->dir.X;
    animal->pos.Y+= animal->dir.Y;
  }
};
#endif
