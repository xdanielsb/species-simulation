#ifndef _CBehaviourFactory
#define _CBehaviourFactory
#include "../../model/behaviour/IBehaviour.hpp"
#include "../../model/behaviour/Farsighted.hpp"
#include "../../model/behaviour/Gregarius.hpp"
#include "../../model/behaviour/Kamikaze.hpp"
#include "../../model/behaviour/Lazy.hpp"
#include <map>

class BehaviourFactory{
  private:
    map<int, Behaviour*> BehaviourPool;	
    BehaviourFactory() {}
  public:
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
	}
		{
			flyweightPool[info] = new ElectricCar(info);
			cout << "create a new object." << endl;
		}
    }
};
#endif
