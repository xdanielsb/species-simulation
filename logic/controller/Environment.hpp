#ifndef _CEnvironment
#define _CEnvironment
#include"../factory/BeastFactory.hpp"
#include"../../model/beast/Animal.hpp"
#include"../../model/behaviour/IBehaviour.hpp"


/**
 * Implementation of a class Environment to initier the Environment and to
 * launch, manage the Environment.
 *
 * The constructeur is used to generate the ground with certain "width",
 * certain "height" and a list of beasts "l". The methode "step" is used
 * to represent one iteration of simulation and during each iteration some
 * fonctions have to be realized, "changeStateMultipleBehaviourBeast"
 * changes the behaviour of the beast after each iteration,
 * "removeCollidedBeast" removes or changes the moving direction with certain
 * probability of beasts who are in collision, "removeOlderBeast" removes the
 * beast whose age is beyound his max_age, "autoClonage" clones some beasts
 * randomly after each iteration.
 *
 *
 */
class Environment: public CImg<unsigned char>
{
private:

  std::vector< Animal* > lbeast;
  Random *rnd;
  const double PROBABILITY_OF_DIED_IN_COLLISION  = 0.5;
  const double PROBABILITY_OF_AUTO_CLONAGE  = 0.05;
  const double SIZEBEAST = 10;
  const unsigned int width;
  const unsigned int height;
  const unsigned int wWave = 2000;
  const unsigned int hWave = 2000;
public:
  Environment( std::vector< Animal*> &l, const unsigned int _w, const unsigned int _h):
  CImg( _w, _h, 1, 3 ),  width(_w), height(_h){
    this->lbeast = l;
    rnd = Random::getInstance();
  }
  bool step(){
      const unsigned char black[] = { 0,0,0 };
      this->removeOlderBeast();
      this->removeCollidedBeast();
      this->autoClonage();
      int n = lbeast.size();
      cimg_forXY( *this, x, y )
//      fillC( x, y, 0, black[0], black[1],black[2] );


                    this->fillC(x,y,0,
                      x*std::cos(6.0*y/this->height) +
                      y*std::sin(9.0*x/this->width),
                      x*std::sin(8.0*y/this->height) -
                      y*std::cos(11.0*x/this->width),
                      x*std::cos(13.0*y/this->height) -
                      y*std::sin(8.0*x/this->width));
                      normalize(240,255);

      for( int i = 0; i < n ; i++){
          this->lbeast[i]->move( this->lbeast );
          this->lbeast[i]->draw(*this);
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
