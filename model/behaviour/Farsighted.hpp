#ifndef _CFarsighted
#define _CFarsighted
#include"./Behaviour.hpp"

using namespace std;

class Farsighted:public Behaviour{
public:
  auto move(int index,pair<float, float> posActual, pair<float, float> dirActual, vector< Beast*> listBeast){

    for(auto ptr=listBeast.begin(); ptr!=listBeast.end(); ptr++){
      if(index == ptr->getIndex()){
        break;
      }
      pair<float, float> posA = ptr->getPosition();   // not defind in the class beast, return type pair<int, int>

      //To verify the beast is next to this beast or not and the range of forseeing is 4
      if(sqrt((posA.first- posActual.first)*(posA.first- posActual.first)+(posA.second- posActual.second)*(posA.second- posActual.second))< 4) {
          dirActual = ptr->getDirection();  // not defind in the class beast, return type pair<int, int>
      }
    }
    // change the position
    posActual.first+=dirActual.first;
    posActual.second+=dirActual.second;
    return make_pair(posActual, dirActual);
  }
};
#endif
