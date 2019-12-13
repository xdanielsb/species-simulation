#ifndef _CSensorFactory
#define _CSensorFactory
#include "../../model/sensor/Sensor.hpp"
#include "../../model/sensor/Ear.hpp"
#include "../../model/sensor/Eye.hpp"

#include <map>
#include<memory>
class SensorFactory{
  private:
    map<int, shared_ptr<Sensor>> SensorPool;

	static SensorFactory *instance;
	SensorFactory() {}

  public:
	static SensorFactory *buildFactory() {
		if (!instance)
      	instance = new SensorFactory;
      	return instance;
	}
  shared_ptr<Sensor> getSensor(int id){
  	if( !SensorPool.count(id)){
  	   switch(id){
  			case EAR:
  				SensorPool[id] = make_shared<EarS>();
  				break;
  			case EYE:
  				SensorPool[id] = make_shared<EarS>();
  				break;
  		}
    }
	  return SensorPool[id];
	}
};
#endif
