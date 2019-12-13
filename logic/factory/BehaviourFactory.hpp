#ifndef _CBehaviourFactory
#define _CBehaviourFactory
#include "../../model/behaviour/IBehaviour.hpp"
#include "../../model/behaviour/Farsighted.hpp"
#include "../../model/behaviour/Gregarius.hpp"
#include "../../model/behaviour/Kamikaze.hpp"
#include "../../model/behaviour/Lazy.hpp"
#include <map>
#include<memory>

class BehaviourFactory{
  private:
    map<int, shared_ptr<Behaviour>> BehaviourPool;

	static BehaviourFactory *instance;

	BehaviourFactory() {}

  public:

	static BehaviourFactory *buildFactory() {
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
#endif
