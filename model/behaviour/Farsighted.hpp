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
    Animal *nearestAnimal;
    for(Animal* b:list){
      if( b->getId() == a->getId() )continue;
      double aux =  getDistance( a->getPosition(), b->getPosition());
      if( aux < minDistance){
        minDistance = aux;
        nearestAnimal = b;
      }
    }
    a->dir.X = nearestAnimal->dir.X;
    a->dir.X = nearestAnimal->dir.Y;
    a->pos.X += a->dir.X;
    a->pos.Y += a->dir.Y;
    printf( "F{%.2f, %.2f}\n", a->pos.X, a->pos.Y);
  }
};
#endif
