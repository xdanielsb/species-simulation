
#ifndef _CContexBehaviour
#define _CContexBehaviour

#include "./Behaviour.hpp"
#include "./Beast.hpp"
class ContextBehavior{
private:
	Behavior* behavior;
public:
	explicit Contextbehavior(Behavior* behavior):behavior(behavior){}
	void setBehavior(Behavior* behavior){
		this->behavior= behavior;
	}
	pair<ii, ii> executeBehavior(int index, ii posActual, ii dirActual, vector< Beast*> listBeast){
		retrun this->behavior->move(int index, ii posActual, ii dirActual, vector< Beast*> listBeast);
	}
};
#endif
