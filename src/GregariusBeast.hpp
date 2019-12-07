#include"./Behaviour.hpp"

using namespace std;

class GregariusBeast:public Behaviour{
  pair<pair< int, int >, pair< int, int >> move(int index, pair< int, int > posActual, pair< int, int > dirActual, vector< Beast*> listBeast){
    int moyenDirX = 0;
    int moyenDirY = 0;
    vector<Beast*>::iterator ptr;
    int count =0;
    
    for(ptr=listBeast.begin(); ptr!=listBeast.end(); ptr++){
      
      pair<int, int> posA = ptr->getPosition();   // not defind in the class beast, return type pair<int, int>
      pair<int, int> dirA = ptr->getDirection();  // not defind in the class beast, return type pair<int, int>
      
      //To verify the beast is next to this beast or not and the range of detection is 30, variable count will count the number of beast in the range of detection
      if(sqrt((posA.first- posActual.first)*(posA.first- posActual.first)+(posA.second- posActual.second)*(posA.second- posActual.second))< 30) {
        count +=1;
        moyenDirX+=dirA.first;
        moyenDirY+=dirA.second;
		}
    }
    moyenDirX/=count;
    moyenDirY/=count;
    //change the direction 
    dirActual.first = moyenDirX;
    dirActual.second = moyenDirY;
    // change the position
    posActual.first+=dirActual.first;
    posActual.second+=dirActual.second;
    return pair<pair< int, int >, pair< int, int >>(posActual, dirActual);
    }
};
