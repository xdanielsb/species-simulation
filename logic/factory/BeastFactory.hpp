#ifndef _CBeastFactory
#define _CBeastFactory
#include"../../model/beast/Animal.hpp"
#include"../../model/beast/Beast.hpp"
#include"../util/Random.hpp"
#include"./BehaviourFactory.hpp"

class BeastFactory{
  private:
    Random *rnd;
    const int NUM_BEHAVIOURS = 5;
    BehaviourFactory* behaviourFactory;

    static BeastFactory* instance;

    BeastFactory(BehaviourFactory* b) {
      rnd = new Random();
      this->behaviourFactory = b;
    }

  public:

    static BeastFactory *buildFactory(BehaviourFactory* behaviourFactory) {
      if (!instance)
      instance = new BeastFactory(behaviourFactory);
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
