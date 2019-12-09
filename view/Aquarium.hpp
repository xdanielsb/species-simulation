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
#include"../model/beast//Beast.hpp"
#include"../model/environment/Environment.hpp"
#include"../logic/factory/BeastFactory.hpp"

class Aquarium{
private:
  BeastFactory *fac;
  Environment *env;
  int width;
  int height;
public:
  Aquarium( int _width, int _height ): width(_width), height(_height){
    this->fac = new BeastFactory();
    vector< Animal*> list = this->fac->newPopulation();
    env = new Environment( list );
  }
  void run(){
    env->step();
  }
};
#endif
