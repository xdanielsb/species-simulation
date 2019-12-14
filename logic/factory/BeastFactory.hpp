#ifndef _CBeastFactory
#define _CBeastFactory
#include"../../model/beast/Animal.hpp"
#include"../../model/beast/Beast.hpp"
#include"../util/Random.hpp"
#include"./BehaviourFactory.hpp"

/**
 * Implementation of a BeastFactory to generate different beasts using 
 * factory design pattern
 *
 * Differents beasts are stored in the "list" and return by the methode
 * "newRandomPopulation", the input variable "n" decides the number of 
 * beasts in the "list", the methode "buildFactory" is used to initier 
 * the instance of BeastFactory and the methode "newRandomBeast" 
 * is used to return an instance of beast with certain "id" and 
 * different "types" of behaviour.     
 * 
 *
 */
class BeastFactory{
  private:
    static BeastFactory* instance;
    Random *rnd;
    const int NUM_BEHAVIOURS = 5;
    BehaviourFactory* behaviourFactory;

    BeastFactory(BehaviourFactory* b) {
      rnd =  Random::getInstance();
      this->behaviourFactory = b;
    }

  public:

    static BeastFactory *buildFactory(BehaviourFactory* behaviourFactory) {
      if (!instance) instance = new BeastFactory(behaviourFactory);
      return instance;
    }
    Beast* newRandomBeast(int id, int type){
      Beast *b = new Beast(id, {this->rnd->getInt(1, WIDTH_WINDOW),
                            this->rnd->getInt(1, HEIGHT_WINDOW)},
                            {this->rnd->getInt(-1, 1),
                            this->rnd->getInt(-1, 1)},
                            behaviourFactory->getComportement(type)
                      );
      b->setMaxAge( rnd->getInt(ONE_SECOND, ONE_MINUTE));
      b->sethasMultipleBehaviours( type == MULTIPLEBEHAVIOUR );
			return b;
    }
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
BeastFactory* BeastFactory::instance = 0;
#endif
