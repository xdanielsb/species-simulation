#ifndef _CSensorFactory
#define _CSensorFactory
#include "../../model/sensor/Sensor.hpp"
#include "../../model/sensor/Ear.hpp"
#include "../../model/sensor/Eye.hpp"
#include"../util/Random.hpp"
#include <map>
#include<memory>

/**
 * Implementation of a SensorFactory to generate different sensors using pool
 * object design pattern
 *
 * Differents sensors are stored in the hashmap "SensorPool", the methode
 * "getInstance" is used to initier the instance of SensorFactory and
 * the methode "getSensor" is used to return different sensors the
 * input 'id' corresponds to different sensors, for exemples,
 * {{0, EAR}, {1, EYE}}.
 *
 *
 */
class SensorFactory{
  private:
    map<int, shared_ptr<Sensor>> SensorPool;
	  static SensorFactory *instance;
    Random *rnd;
	  SensorFactory() {
        rnd =  Random::getInstance();
    }
  public:
	static SensorFactory *getInstance() {
		if (!instance)
      	instance = new SensorFactory;
      	return instance;
	}
  shared_ptr<Sensor> getSensor(int id){
  	if( !SensorPool.count(id)){
  	   switch(id){
  			case EAR:
  				SensorPool[id] = make_shared<EarS>(
            this->rnd->getDouble(),
            this->rnd->getDouble());
  				break;
  			case EYE:
  				SensorPool[id] = make_shared<EyeS>(
            this->rnd->getDouble(),
            this->rnd->getDouble(),
            this->rnd->getDouble()*PI*2
          );
  				break;
  		}
    }
	  return SensorPool[id];
	}
};
SensorFactory* SensorFactory::instance = 0;
#endif
