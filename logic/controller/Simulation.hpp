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

/**
 * Implementation of a class Simulation to initier the simulation and to
 * launch and manage the simualtion. 
 *
 * The constructeur is used to initier the environment and generate a 
 * list of beasts "list" with number"nBeast". The methode "startCLI" is used 
 * to count the number of iteration and print the log, the methode "startGUI"
 * is used to create the graphique interface.
 * 
 *  
 */

using namespace std;
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
      this->env = new Environment( list, WIDTH_WINDOW, HEIGHT_WINDOW );
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
  void startGUI(int argc,char **argv){
      this->q = new Aquarium(WIDTH_WINDOW, HEIGHT_WINDOW, env);
      this->q->run(argc, argv);
  }
};
#endif
