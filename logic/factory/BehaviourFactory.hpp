#ifndef _CBehaviourFactory
#define _CBehaviourFactory
#include "../../model/behaviour/IBehaviour.hpp"
#include "../../model/behaviour/Farsighted.hpp"
#include "../../model/behaviour/Gregarius.hpp"
#include "../../model/behaviour/Kamikaze.hpp"
#include "../../model/behaviour/Lazy.hpp"
#include <map>
#include<memory>

/**
 * Implementation of a BehaviourFactory to generate different behaviours using
 * pool object design pattern
 *
 * Differents behaviours are stored in the hashmap "BehaviourPool", the
 * methode "getInstance" is used to initier the instance of BehaviourFactory
 * and the methode "getComportement" is used to return different behaviours
 * the input 'id' corresponds to different behaviours, for exemples,
 * {{0, FarsightedB}, {1, GregariusB}, {2, KamikazeB}, {3, LazyB},
 * {4, MULTIPLEBEHAVIOUR}}.
 *
 *
 */
class BehaviourFactory{
  private:
    map<int, shared_ptr<Behaviour>> BehaviourPool;
	  static BehaviourFactory *instance;
    BehaviourFactory() {}
  public:
	static BehaviourFactory *getInstance() {
		if (!instance)
      	instance = new BehaviourFactory;
      	return instance;
	}

  shared_ptr<Behaviour> getComportement(int id){
    if( id == MULTIPLEBEHAVIOUR ) id = 0;
  	if( !BehaviourPool.count(id)){
  		switch(id){
  			case FARSIGTHED:
  				BehaviourPool[id] = make_shared<FarsightedB>();
  				break;
  			case GREGARIU:
  				BehaviourPool[id] = make_shared<GregariusB>();
  				break;
  			case KAMIKAZE:
  				BehaviourPool[id] = make_shared<KamikazeB>();
  				break;
  			case LAZY:
  				BehaviourPool[id] = make_shared<LazyB>();
  				break;
  		}
    }
	  return BehaviourPool[id];
	}
};
BehaviourFactory* BehaviourFactory::instance = 0;
#endif
