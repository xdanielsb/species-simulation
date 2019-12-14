#ifndef CRandom
#define CRandom
#include<stdlib.h>
#include<time.h>
#include <assert.h>

/**
 * Implementation of a class Random to generate random int, double, pair 
 * or vector
 *
 * The methode "getInstance" is used to initier the instance of 
 * class Random, the methode "getDouble" is used to generate a double 
 * randomly,the methode "getInt" is used to generate an int between 
 * ]"a", "b"[randomly, "getPair" is used to generate a pair of type
 * pair<pair<int, int>, pair<int, int>> randomly, "getVector" is used 
 * to generate a normalised vector with length "n". 
 *
 * 
 */
class Random{
  private:
    static Random* instance;
    Random(){
      srand (time(NULL));
    }
  public:

  static Random *getInstance() {
    if (!instance) instance = new Random();
    return instance;
  }

  double getDouble(){
    return rand();
  }
  int getInt(int a , int b){
     assert( a < b );
     int val = rand() % b + a;
     assert( val >= a && val <= b );
     return val;
  }
  ii getPair( int a, int b){
    return make_pair( getInt(a, b), getInt(a,b ));
  }
  vector< float > getVector( int n ){
    long double sum = 0;
    vector< float > res;
    for( int i = 0; i < n ; i++){
      res.push_back( this->getInt(1, 101));
      sum += res.back();
    }
    assert( sum >= 1.);
    for( int i =0; i < n; i++) res[i] /= sum;
    return res;
  }
};
Random* Random::instance = 0;
#endif
