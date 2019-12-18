#ifndef _CFarsighted
#define _CFarsighted
#include"./IBehaviour.hpp"

using namespace std;

/**
 * Implementation of behaviour Farsignted
 *
 * A Farsighted animal estimates the trajectories of critters
 * around it and adjusts its trajectory to avoid possible collisions.
 *
 *
 */
class FarsightedB:public Behaviour{

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
    if(isOutOfBoundaryX(a))
		   a->setDirX(-a->getDirX());
    if(isOutOfBoundaryY(a))
       a->setDirY(-a->getDirY());
    a->setPosX(a->getPosX()+a->getDirX() * a->getSpeed());
    a->setPosY(a->getPosY()+a->getDirY() * a->getSpeed());
    #ifdef DEBUG
      printf("->F{%.2f, %.2f}\n", a->getPosX(), a->getPosY());
    #endif
  }
};
#endif
