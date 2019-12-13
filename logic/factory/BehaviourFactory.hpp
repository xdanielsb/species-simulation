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
<<<<<<< HEAD
    Behaviour* getComportement(int indexCom){
			if (!BehaviourPool.count(indexCom)){
				switch(indexCom){
					case 0:
						BehaviourPool[indexCom] = new FarsightedB;
						break;
					case 1: 
						BehaviourPool[indexCom] = new GregariusB;
						break;
					case 2: 
						BehaviourPool[indexCom] = new KamikazeB;
						break;
					case 3: 
						BehaviourPool[indexCom] = new LazyB;
						break;		
				}
			return 	
			
	}
	 
=======
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

>>>>>>> 47f3c90c922d3e7e19b2ae43a2ee01cedad5ad94
};
#endif
