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
  public:
  	BehaviourFactory() {}
    shared_ptr<Behaviour> getComportement(int indexCom){
  	if (!BehaviourPool.count(indexCom)){
		switch(indexCom){
			case 0:
				BehaviourPool[indexCom] = make_shared<FarsightedB>();
				break;
			case 1: 
				BehaviourPool[indexCom] = make_shared<GregariusB>();
				break;
			case 2: 
				BehaviourPool[indexCom] = make_shared<KamikazeB>();
				break;
			case 3: 
				BehaviourPool[indexCom] = make_shared<LazyB>();
				break;		
		}		
    } else {
		return BehaviourPool[indexCom];
	}}

};
#endif
