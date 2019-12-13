#ifndef _CSimulation
#define _CSimulation
#include"../include.hpp"
#include"./Environment.hpp"
#include"../factory/BeastFactory.hpp"
#include"../factory/BehaviourFactory.hpp"
#include"../../view/Aquarium.hpp"
#include"../../model/beast/Animal.hpp"
#include <thread>
#include <chrono>

class Simulation{
private:
  Aquarium *q;
  BeastFactory *beastFactory;
  BehaviourFactory *behaviourFactory;
  Environment *env;

public:
  Simulation( int nBeast){
      this->behaviourFactory = BehaviourFactory::buildFactory();
      this->beastFactory = BeastFactory::buildFactory(behaviourFactory);
      vector< Animal*> list = this->beastFactory->newRandomPopulation( nBeast );
      this->env = new Environment( list );
  }
  ~Simulation() {
    delete behaviourFactory;
    delete beastFactory;
  }
  void startCLI( ){
   for(int step = 1;; step++){
     printf("Running step #%d\n", step);
     this_thread::sleep_for(chrono::seconds(1));
     this->env->step();
   }
  }
  void startGUI(){
      this->q = new Aquarium(300, 300, env);
      this->q->run();
  }
};
#endif
