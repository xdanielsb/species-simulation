#ifndef _CEnvironment
#define _CEnvironment
#include"../beast/Beast.hpp"
#include"../behaviour/IBehaviour.hpp"
class Environment{
private:
  vector< Beast* > lbeast;
public:
  void changeState(){

  }
  Environment( vector< Beast*> &lbeast){
    this->lbeast = lbeast;
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

  }
  void getCurrentState(){

  }
};
#endif
