#ifndef _CKamikaze
#define _CKamikaze
#include"./IBehaviour.hpp"
#define debug(x) cout << #x << " = " << x <<endl;
class KamikazeB:public Behaviour{
private:
  double getDistance(const ii &a1, const ii &a2){
      return hypot( a1.X - a2.X , a1.Y - a2.Y );
  }
  ii getNewDirection( Animal *src, Animal *aim){
    ii res;
    res.X = (aim->pos.X - src->pos.X);
    res.Y = (aim->pos.Y - src->pos.Y);
    if( fabs(res.X) > 1e-6 ) res.X /= getDistance( src->pos, aim->pos);
    if( fabs(res.Y) > 1e-6 ) res.Y /= getDistance( src->pos, aim->pos);
    return res;
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
    a->setDirX(getNewDirection( a, nearestAnimal).X);
    a->setDirY(getNewDirection( a, nearestAnimal).Y);
  if(isOutOfBoundariesX(a)){
		a->setDirX(a->getDirX()*-1);		
	}
  if(isOutOfBoundariesY(a)){
		a->setDirY(a->getDirY()*-1);		
	}
    a->setPosX(a->getPosX+a->getDirX());
    a->setPosY(a->getPosY+a->getDirY());
    printf("->K{%.2f, %.2f}\n", a->getPosX(), a->getPosY());
  }
};
#endif
