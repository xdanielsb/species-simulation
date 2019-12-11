#ifndef _CSimulation
#define _CSimulation
#include"../include.hpp"
#include"./Environment.hpp"
#include"../factory/BeastFactory.hpp"
#include"../../view/Aquarium.hpp"
#include"../../model/beast/Animal.hpp"
class Simulation{
private:
  Aquarium *q;
  BeastFactory *fac;
  Environment *env;
public:
  Simulation(){
      // create window
      // this->q = new Aquarium(300, 300);
      this->fac = new BeastFactory();
      vector< Animal*> list = this->fac->newPopulation();
      this->env = new Environment( list );
  }
  void start (){
      this->env->step();
  }
  void stop(){

  }
};
#endif
