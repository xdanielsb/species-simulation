#ifndef _CAquarium
#define _CAquarium

/*
 * Depenedencies
 */
#include"./include.hpp"
#include"../model/environment/Environment.hpp"
#include"../model/beast//Beast.hpp"


#include"./factory/BeastFactory.hpp"
class Aquarium{
private:
  BeastFactory *fac;
  Environment *env;
public:
  Aquarium(){
    this->fac = new BeastFactory();
    //Animal *a = new Animal(1, {1,1}, {1,1});

    //vector< Beast*> list_beast = this->fac->newPopulation();
    //env = new Environment( list_beast );
  }
  void* run(){
    //bool ok = true;
    //while( ok ){
      //ok &= env->step();
    //}
  }
};
#endif
