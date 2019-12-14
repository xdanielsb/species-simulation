#ifndef _CSimulation
#define _CSimulation
#include"../include.hpp"
#include"./Environment.hpp"
#include"../factory/BeastFactory.hpp"
#include"../factory/BehaviourFactory.hpp"
#include"../../view/Aquarium.hpp"
#include"../../model/beast/Animal.hpp"
#include"../../view/Dialog.hpp"
#include <thread>
#include <chrono>

/**
 * Implementation of a class Simulation to initier the simulation and to
 * launch and manage the simualtion.
 *
 * The constructeur is used to initialize the environment and generate a
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
  Dialog *diag;
public:
  Simulation( ){
      this->behaviourFactory = BehaviourFactory::buildFactory();
      this->beastFactory = BeastFactory::buildFactory(behaviourFactory);
      this->env = new Environment( WIDTH_WINDOW, HEIGHT_WINDOW );
  }
  ~Simulation() {
    delete behaviourFactory;
    delete beastFactory;
    delete env;
  }

  void startCLI( int nBeast ){
     vector< Animal*> list = this->beastFactory->newRandomPopulation( nBeast );
     this->env->setListBeast( list );
     for(int step = 1;; step++){
       #ifdef DEBUG
        printf("Running step #%d\n", step);
       #endif
       this_thread::sleep_for(chrono::seconds(1));
       this->env->step( step );
     }
  }
  void startGUI(int argc,char **argv, int nBeast){
    diag = new Dialog();
    diag->create(argc, argv);
    vector< Animal*> list = this->beastFactory->newRandomPopulation( nBeast );
    this->env->setListBeast( list );
    this->q = new Aquarium(WIDTH_WINDOW, HEIGHT_WINDOW, this->env);
    this->q->run();
  }
};
#endif
