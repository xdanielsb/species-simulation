#ifndef _CAccessoryFactory
#define _CAccessoryFactory
#include "../../model/accessory/Accessory.hpp"
#include "../../model/accessory/Camouflage.hpp"
#include "../../model/accessory/Fin.hpp"
#include "../../model/accessory/Shell.hpp"
#include <map>
#include<memory>

/**
 * Implementation of a AccessoryFactory to generate different accessories 
 * using pool object design pattern
 *
 * Differents accessories are stored in the hashmap "AccessoryPool", the 
 * methode "buildFactory" is used to initier the instance of 
 * AccessoryFactory and the methode "getAccessory" is used to return 
 * different accessories the input 'id' corresponds to different 
 * accessories, check Id of accessories in the file logic/include.hpp.  
 * 
 *
 */
class AccessoryFactory{
  private:
    map<int, shared_ptr<Accessory>> AccessoryPool;

	static AccessoryFactory *instance;

	AccessoryFactory() {}

  public:

	static AccessoryFactory *buildFactory() {
		if (!instance)
      	instance = new AccessoryFactory;
      	return instance;
	}

  shared_ptr<Accessory> getAccessory(int id){
  	if( !AccessoryPool.count(id)){
  	   switch(id){
  			case CAMOUFLAGE:
  				AccessoryPool[id] = make_shared<CamouflageS>();
  				break;
  			case FIN:
  				AccessoryPool[id] = make_shared<FinS>();
  				break;
        case SHELL:
  				AccessoryPool[id] = make_shared<ShellS>();
  				break;
  		}
    }
	  return AccessoryPool[id];
	}
};
AccessoryFactory* AccessoryFactory::instance = 0;
#endif
