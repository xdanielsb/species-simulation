#include"./Behaviour.hpp"

using namespace std;
#ifndef _CFarsigthed
#define _CFarsigthed
class Farsigthed:public Behaviour{
  pair<pair<int, int >, pair< int, int >> move(int index, pair< int, int > posActual, pair< int, int > dirActual, vector< Beast*> listBeast){

    vector<Beast*>::iterator ptr;

    for(ptr=listBeast.begin(); ptr!=listBeast.end(); ptr++){
      if(index == ptr->getIndex()){
        break;
      }
      pair<int, int> posA = ptr->getPosition();   // not defind in the class beast, return type pair<int, int>

      //To verify the beast is next to this beast or not and the range of forseeing is 4
      if(sqrt((posA.first- posActual.first)*(posA.first- posActual.first)+(posA.second- posActual.second)*(posA.second- posActual.second))< 4) {
          dirActual = ptr->getDirection();  // not defind in the class beast, return type pair<int, int>
      }
    }
    // change the position
    posActual.first+=dirActual.first;
    posActual.second+=dirActual.second;
    return pair<pair< int, int >, pair< int, int >>(posActual, dirActual);
  }
};
#endif
