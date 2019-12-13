#ifndef _CFarsighted
#define _CFarsighted
#include"./IBehaviour.hpp"

using namespace std;

class FarsightedB:public Behaviour{
private:
public:
  void move(Animal* a, vector<Animal*> list){
    double minDistance = 1e9;
    Animal *nearestAnimal;
    for(Animal* b:list){
      if( b->getId() == a->getId() )continue;
      double aux =  a->getDistance( b->getPosition());
      if( aux < minDistance){
        minDistance = aux;
        nearestAnimal = b;
      }
    }
    a->setDirX(nearestAnimal->getDirX());
    a->setDirY(nearestAnimal->getDirY());
    if(isOutOfBoundaries(a)){
  		a->setDirX(a->getDirX()*-1);
  		a->setDirY(a->getDirY()*-1);
	  }
    a->setPosX(a->getPosX()+a->getDirX());
    a->setPosY(a->getPosY()+a->getDirY());
    printf("->F{%.2f, %.2f}\n", a->getPosX(), a->getPosY());
  }
};
#endif
