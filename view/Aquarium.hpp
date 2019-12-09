/***
 * This class defines a window that
 * contains the Beasts
**/
#ifndef _CAquarium
#define _CAquarium

/*
 * Depenedencies
 */
#include"../logic/include.hpp"
#include"../model/beast//Animal.hpp"


class Aquarium{
private:
  int width;
  int height;
public:
  Aquarium( int _width, int _height ): width(_width), height(_height){

  }

  void drawAnimal( Animal *a){

  }
  void run(){
    
  }
};
#endif
