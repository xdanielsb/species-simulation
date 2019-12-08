#include "FactoryBeast.hpp"

class Environment{
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
  void changeBehaviour( Beast* b, Behaviour *b){

  }

  void getCurrentState(){
    
  }

};
