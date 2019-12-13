#ifndef _CAccessoryFactory
#define _CAccessoryFactory
#include "../../model/accessory/Accessory.hpp"
#include "../../model/accessory/Camouflage.hpp"
#include "../../model/accessory/Fin.hpp"
#include "../../model/accessory/Shell.hpp"
#include <map>
#include<memory>

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
