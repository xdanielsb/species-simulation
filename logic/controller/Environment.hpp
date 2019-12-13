#ifndef _CEnvironment
#define _CEnvironment
#include"../factory/BeastFactory.hpp"
#include"../../model/beast/Beast.hpp"
#include"../../model/behaviour/IBehaviour.hpp"
class Environment{ // facade
private:
  vector< Animal* > lbeast;
  Random *rnd;
  const double PROBABILITY_OF_DIED_IN_COLLISION  = 0.5;
  const double SIZEBEAST = 1;
public:
  void changeState(){

  }
  Environment( vector< Animal*> &lbeast){
    this->lbeast = lbeast;
    rnd = new Random();
  }
  bool step(){
      this->removeOlderBeast();
//      this->removeCollidedBeast();
      int n = lbeast.size();
      debug( n );
      for( int i = 0; i < n ; i++){
        if( this->lbeast[i]){
          this->lbeast[i]->move( this->lbeast );
          this->lbeast[i]->getOlder();
        }
      }
  }
  void removeCollidedBeast(){
    int i = 0, n = lbeast.size();
    for( int i= 0; i < n; i++){
      for( int j = i+1; j < n; j++){
        double dis = lbeast[i]->getDistance( lbeast[j]->getPosition());
        if( dis <= SIZEBEAST ){
          double pdied = rnd->getDouble();
          if(pdied >= PROBABILITY_OF_DIED_IN_COLLISION){

          }
        }
      }
    }
  }
  void removeOlderBeast(){
    vector< Animal* > lbeastn;
    for( auto beast= lbeast.begin(); beast != lbeast.end(); beast++)
        if( (*beast)->getAge() <= (*beast)->getMaxAge() )lbeastn.push_back( *beast );
    this->lbeast = lbeastn;
  }
  void giveBirthToNewBeast(){

  }
  void cloneBeast(){

  }
};
#endif
