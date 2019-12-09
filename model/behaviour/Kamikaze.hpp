#ifndef _CKamikaze
#define _CKamikaze
#include"./Behaviour.hpp"
class Kamikaze:public Behaviour{
public:
  void move(Animal* animal, vector<Animal*> listAnimals){

    int countAnimal =0;
    ii nearestPos;
    ii posSelf = animal->getPosition();
    bool flag = true;
    double nearestDistance;
    
    for(auto ptr:listAnimals){
      // If it's himself, than turn to the next bestle
      if(index== ptr->getIndex()){
        continue;
      }
      ii posA = ptr->getPosition();   // not defind in the class beast, return type pair<int, int>
      if(flag==true){
        nearestDistance = sqrt((posA.X- posSelf.X)*(posA.X- posSelf.X)+(posA.Y- posSelf.Y)*(posA.Y- posSelf.Y));
        nearestPos = ptr->getPosition();          // not define in the class beast, return type pair<int, int>
        flag = false;
        continue;
      }
      // if we find another beast, whose distance is smaller than nearestdDistance, we will update this variable
      if(sqrt((posA.X- posSelf.X)*(posA.X- posSelf.X)+(posA.Y- posSelf.Y)*(posA.Y- posSelf.Y))< nearestDistance){
        nearestPos = ptr->getPosition();          // not define in the class beast, return type pair<int, int>
        nearestDistance = sqrt((posA.X- posSelf.X)*(posA.X- posSelf.X)+(posA.Y- posSelf.Y)*(posA.Y- posSelf.Y));
      }
    }
    //change the direction and normalisation
    animal->dir.X = (nearestPos.X - animal->pos.X)/sqrt((nearestPos.X - animal->pos.X)*(nearestPos.X - animal->pos.X)+(nearestPos.Y - animal->pos.Y)*(nearestPos.Y - animal->pos.Y));
    animal->dir.Y = (nearestPos.Y - animal->pos.Y)/sqrt((nearestPos.X - animal->pos.X)*(nearestPos.X - animal->pos.X)+(nearestPos.Y - animal->pos.Y)*(nearestPos.Y - animal->pos.Y));
    // change the position
    animal->pos.X+= animal->dir.X;
    animal->pos.Y+= animal->dir.Y;
  }
};
#endif
