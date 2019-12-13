#ifndef _CEnvironment
#define _CEnvironment
#include"../factory/BeastFactory.hpp"
#include"../../model/beast/Animal.hpp"
#include"../../model/behaviour/IBehaviour.hpp"
#include"../../include/CImg.h"
#include<unordered_set>
#include<vector>
using namespace std;
using namespace cimg_library;
typedef unsigned char        T;
typedef CImg<T>            UImg;

class Environment: public UImg
{
private:

  std::vector< Animal* > lbeast;
  Random *rnd;
  inline static const T     black[] =  { (T)0, (T)0, (T)0 };
  const double PROBABILITY_OF_DIED_IN_COLLISION  = 0.5;
  const double PROBABILITY_OF_AUTO_CLONAGE  = 0.05;
  const double SIZEBEAST = 10;
public:
  Environment( std::vector< Animal*> &l, const unsigned int _width, const unsigned int _height):
  UImg( _width, _height, 1, 3 ){
    this->lbeast = l;
    rnd = Random::getInstance();
  }
  bool step(){
      this->removeOlderBeast();
      this->removeCollidedBeast();
      this->autoClonage();
      int n = lbeast.size();
      cimg_forXY( *this, x, y )
      fillC( x, y, 0, black[0], black[1],black[2] );
      for( int i = 0; i < n ; i++){
          this->lbeast[i]->move( this->lbeast );
          this->lbeast[i]->draw(*this);
          const unsigned char yellow[] = { 255,255,0 };
          this->lbeast[i]->getOlder();
      }
      return n;
  }
  void changeStateMultipleBehaviourBeast(){
    int n = lbeast.size();
    for( int i= 0; i < n; i++){
      if( lbeast[i]->gethasMultipleBehaviours()){

      }
    }
  }
  void removeCollidedBeast(){
    unordered_set< int > died;
    //int i = 0, n = lbeast.size();
		int n = lbeast.size();
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
    std::vector< Animal* > lbeastn;
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
    std::vector< Animal* > lbeastn;
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
  void autoClonage(){
    int n = this->lbeast.size();
    for( int i = 0; i < n; i++ ){
      int probAutoClonage  = this->rnd->getDouble();
      if( probAutoClonage <= PROBABILITY_OF_AUTO_CLONAGE){
        this->lbeast.push_back( this->lbeast[i]->clone() );
        #ifdef DEBUG
          printf("The Beast %d was cloned\n", this->lbeast[i]->getId());
        #endif
      }
    }
  }
};
#endif
