#ifndef _CBehaviour
#define _CBehaviour
#include"../beast/Animal.hpp"
#include<vector>

using namespace std;

class Behaviour{
public:
 virtual void move(Animal* animal, vector<Animal*> listAnimals) = 0;
 virtual ~Behaviour() {};
 bool isOutOfBoundaryX(const Animal* a){
   float futurePositionX = (a->getPosX() + a->getDirX());
   return ( futurePositionX < 0 || futurePositionX > WIDTH_WINDOW );
 }
 bool isOutOfBoundaryY(const Animal* a){
   float futurePositionY = (a->getPosY() + a->getDirY());
   return ( futurePositionY < 0 || futurePositionY > HEIGHT_WINDOW );
 }
};
#endif
