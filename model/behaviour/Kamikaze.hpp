#ifndef _CKamikaze
#define _CKamikaze
#include"./Behaviour.hpp"
class Kamikaze:public Behaviour{
public:
  auto move(int index, ii posActual, ii dirActual, vector< Beast*> listBeast){

    int count =0;
    pair<int, int> nearestPos;
    bool flag = true;
    double nearestDistance;

    for(auto ptr=listBeast.begin(); ptr!=listBeast.end(); ptr++){
      // If it's himself, than turn to the next bestle
      if(index== ptr->getIndex()){
        break;
      }
      pair<int, int> posA = ptr->getPosition();   // not defind in the class beast, return type pair<int, int>
      if(flag==true){
        nearestDistance = sqrt((posA.first- posActual.first)*(posA.first- posActual.first)+(posA.second- posActual.second)*(posA.second- posActual.second));
        nearestPos = ptr->getPosition();          // not define in the class beast, return type pair<int, int>
        flag = false;
        break;
      }
      // if we find another beast, whose distance is smaller than nearestdDistance, we will update this variable
      if(sqrt((posA.first- posActual.first)*(posA.first- posActual.first)+(posA.second- posActual.second)*(posA.second- posActual.second))< nearestDistance){
        nearestPos = ptr->getPosition();          // not define in the class beast, return type pair<int, int>
        nearestDistance = sqrt((posA.first- posActual.first)*(posA.first- posActual.first)+(posA.second- posActual.second)*(posA.second- posActual.second));
      }
    }
    //change the direction and normalisation
    dirActual.first = (nearestPos.first-posActual.first)/sqrt((nearestPos.first-posActual.first)*(nearestPos.first-posActual.first)+(nearestPos.second-posActual.second)*(nearestPos.second-posActual.second));
    dirActual.second = (nearestPos.second-posActual.second)/sqrt((nearestPos.first-posActual.first)*(nearestPos.first-posActual.first)+(nearestPos.second-posActual.second)*(nearestPos.second-posActual.second));
    // change the position
    posActual.first+=dirActual.first;
    posActual.second+=dirActual.second;
    return make_pair(posActual, dirActual);

  }
};
#endif
