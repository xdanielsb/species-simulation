#ifndef _CFarsighted
#define _CFarsighted
#include"./IBehaviour.hpp"

using namespace std;

class FarsightedB:public Behaviour{
private:
  double getDistance(const ii &a1, const ii &a2){
      return hypot( a1.X - a2.X , a1.Y - a2.Y );
  }
public:
  void move(Animal* a, vector<Animal*> list){
    double minDistance = 1e9;
    Animal *nearestAnimal=nullptr;
    for(Animal* b:list){
      if( b->getId() == a->getId() )continue;
      double aux =  a->getDistance( b->getPosition());
      if( aux < minDistance){
        minDistance = aux;
        nearestAnimal = b;
      }
    }
		if(nearestAnimal){
    	a->setDirX(nearestAnimal->getDirX());
    	a->setDirY(nearestAnimal->getDirY());
		}
    if(isOutOfBoundaryX(a)){
		    a->setDirX(a->getDirX()*-1);
	  }
    if(isOutOfBoundaryY(a)){
		    a->setDirY(a->getDirY()*-1);
	  }
    a->setPosX(a->getPosX()+a->getDirX());
    a->setPosY(a->getPosY()+a->getDirY());
    printf("->F{%.2f, %.2f}\n", a->getPosX(), a->getPosY());
  }
};
#endif
