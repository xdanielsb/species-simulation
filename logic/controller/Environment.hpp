#ifndef _CEnvironment
#define _CEnvironment
#include"../factory/BeastFactory.hpp"
#include"../../model/beast/Beast.hpp"
#include"../../model/behaviour/IBehaviour.hpp"
#include<unordered_set>
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
      this->removeCollidedBeast();
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
    unordered_set< int > died;
    int i = 0, n = lbeast.size();
    for( int i= 0; i < n; i++){
      if( died.count(i) ) continue;
      for( int j = i+1; j < n; j++){
        if( died.count( j )) continue;
        double dis = lbeast[i]->getDistance( lbeast[j]->getPosition());
        if( dis <= SIZEBEAST ){
          double pdiedFirst = rnd->getDouble();
          double pdiedSecon = rnd->getDouble();
          if(pdiedFirst >= PROBABILITY_OF_DIED_IN_COLLISION)died.insert( i );
          else lbeast[i]->invertDirection();
          if(pdiedSecon >= PROBABILITY_OF_DIED_IN_COLLISION)died.insert( j );
          else lbeast[j]->invertDirection();
        }
      }
    }
    vector< Animal* > lbeastn;
    for( int i = 0; i < n ; ++i){
      if( !died.count(i) ) lbeastn.push_back( lbeast[i]);
      else{
        #ifdef DEBUG
          printf("The Beast %d died by collision\n", lbeast[i]->getId());
        #endif
      }
    }
    this->lbeast  = lbeastn;
  }
  void removeOlderBeast(){
    vector< Animal* > lbeastn;
    for( auto beast= lbeast.begin(); beast != lbeast.end(); beast++){
      if( (*beast)->getAge() <= (*beast)->getMaxAge() ){
        lbeastn.push_back( *beast );
      }
      else{
        #ifdef DEBUG
          printf("The Beast %d died by age\n", (*beast)->getId());
        #endif
      }

    }
    this->lbeast = lbeastn;
  }
  void giveBirthToNewBeast(){

  }
  void cloneBeast(){

  }
};
#endif
