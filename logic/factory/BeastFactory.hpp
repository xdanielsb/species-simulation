#ifndef _CBeastFactory
#define _CBeastFactory
#include"../../model/beast/Animal.hpp"
#include"../../model/beast/Beast.hpp"
#include"../util/Random.hpp"
#include"./BehaviourFactory.hpp"
#include"./SensorFactory.hpp"
#include"./AccessoryFactory.hpp"

/**
 * Implementation of a BeastFactory to generate different beasts using
 * singleton design pattern
 *
 * Differents beasts are stored in the "list" and return by the methode
 * "newRandomPopulation", the input variable "n" decides the number of
 * beasts in the "list", the methode "getInstance" is used to initier
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

    BeastFactory() {
      rnd =  Random::getInstance();
    }

  public:

    static BeastFactory *getInstance() {
      if (!instance) instance = new BeastFactory();
      return instance;
    }
    Beast* newRandomBeast(int id, int type){
      Beast *b = new Beast(id, {this->rnd->getInt(1, WIDTH_WINDOW),
                            this->rnd->getInt(1, HEIGHT_WINDOW)},
                            {this->rnd->getInt(-2, 2),
                            this->rnd->getInt(-2, 2)},
                            BehaviourFactory::getInstance()->getComportement(type)
                      );
      b->setMaxAge( rnd->getInt(ONE_SECOND, ONE_MINUTE));
      b->setSpeed(  rnd->getInt(1, 3));
      b->setBehavior( type  );
      bool addAccesory = this->rnd->getBool();
      bool addSensor = this->rnd->getBool();
      if( addAccesory )
      b->addAccessory(
        AccessoryFactory::getInstance()->getAccessory(this->rnd->getInt(0, NUMACCESORIES))
      );
      if( addSensor )
      b->addSensor(
        SensorFactory::getInstance()->getSensor(this->rnd->getInt(0, NUMSENSORS))
      );
			return b;
    }
    vector<Animal*> newRandomPopulation( int n ){
      vector<Animal*> list;
      vector< float > pseudoRandomDistribution = rnd->getVector(  NUMBEHAVIOURS );
      for( int i = 0, id = 1; i < NUMBEHAVIOURS; i++){
        int totali = round(pseudoRandomDistribution[ i ] * n);
        for( int j = 0; j < totali; j++, id++){
            list.push_back( this->newRandomBeast( id, i ) );
        }
      }
      return list;
    }
};
BeastFactory* BeastFactory::instance = 0;
#endif
