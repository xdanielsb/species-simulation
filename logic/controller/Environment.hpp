#ifndef _CEnvironment
#define _CEnvironment
#include"../factory/BeastFactory.hpp"
#include"../../model/beast/Beast.hpp"
#include"../../model/behaviour/IBehaviour.hpp"
class Environment{ // facade
private:
  vector< Animal* > lbeast;
public:
  void changeState(){

  }
  Environment( vector< Animal*> &lbeast){
    this->lbeast = lbeast;

    //Initialize pointer to zero so that it can be initialized in first call to buildFactory
    //BeastFactory *BeastFactory::factory = 0;
    //Factory *f = f->buildFactory();
  }
  bool step(){
      this->removeDiedBeast();
      this->removeCollidedBeast();
      for( Animal* b: this->lbeast){
        b->move( this->lbeast );
      }
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
