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
	
    shared_ptr<Behaviour> getComportement(int indexCom){
    if( indexCom == MultipleBehaviour ) indexCom = 0;
  	if( !BehaviourPool.count(indexCom)){
  		switch(indexCom){
  			case FarSighted:
  				BehaviourPool[indexCom] = make_shared<FarsightedB>();
  				break;
  			case Gregariu:
  				BehaviourPool[indexCom] = make_shared<GregariusB>();
  				break;
  			case Kamikaze:
  				BehaviourPool[indexCom] = make_shared<KamikazeB>();
  				break;
  			case Lazy:
  				BehaviourPool[indexCom] = make_shared<LazyB>();
  				break;
  		}
  }
	return BehaviourPool[indexCom];
	}
};
#endif
