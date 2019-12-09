#ifndef _CEnvironment
#define _CEnvironment
#include"../beast/Beast.hpp"
#include"../behaviour/IBehaviour.hpp"
class Environment{ // facade 
private:
  vector< Beast* > lbeast;
public:
  void changeState(){

  }
  Environment( vector< Beast*> &lbeast){
    this.lbeast = lbeast;

    //Initialize pointer to zero so that it can be initialized in first call to buildFactory
    FactoryBeast *FactoryBeast::factory = 0;
    Factory *f = f->buildFactory();
  }

  bool step(){

  }
  void removeCollidedBeast(){


  }
  void removeDiedBeast(){

  }
  void giveBirthToNewBeast(){

  }
  void cloneBeast(){

  }
  void changeBehaviour( Beast* beast, Behaviour *behaviour){
    beast->setBehavior( behaviour);
  }
  void getCurrentState(){

  }
};
#endif
