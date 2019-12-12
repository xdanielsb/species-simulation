#ifndef _CBeastFactory
#define _CBeastFactory
#include"../../model/beast/Animal.hpp"
#include"../../model/beast/Beast.hpp"
#include"../util/Random.hpp"
class BeastFactory{
  private:
    Random *rnd;
    const int NUM_BEHAVIOURS = 5;
  public:
    BeastFactory() {
      rnd = new Random();
    }
    Beast* newRandomBeast(int id, int type){
      return new Beast(id, {1,1}, {1,1}, type);
    }
    // TODO: put a limit of the maximun number of elements in the population
    vector<Animal*> newRandomPopulation( int n ){
      vector<Animal*> list;
      vector< float > pseudoRandomDistribution = rnd->getVector(  NUM_BEHAVIOURS );
      for( int i = 0, id = 1; i < NUM_BEHAVIOURS; i++){
        int totali = round(pseudoRandomDistribution[ i ] * n);
        printf("\tNumber of beast with behaviour %d = %d \n", i,  totali);
        for( int j = 0; j < totali; j++, id++){
            list.push_back( this->newRandomBeast( id, i ) );
        }
      }
      return list;
    }
};
#endif
