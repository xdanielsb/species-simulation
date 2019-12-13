#ifndef _CBehaviour
#define _CBehaviour
#include"../beast/Animal.hpp"
#include<vector>

using namespace std;

class Behaviour{
public:
 virtual void move(Animal* animal, vector<Animal*> listAnimals) = 0;
 virtual ~Behaviour() {};
 bool isOutOfBoundaries(const Animal* a){
   float futurePositionX = (a->getPosX() + a->getDirX());
   float futurePositionY = (a->getPosY() + a->getDirY());
   return ( futurePositionX < 0 || futurePositionY < 0 ||
      futurePositionX > WIDTH_WINDOW || futurePositionY > HEIGHT_WINDOW );
 }
};
#endif
