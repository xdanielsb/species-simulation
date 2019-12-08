#include "./Behaviour.hpp"
#include "./Beast.hpp"
#include<vector>

using namespace std;

#ifndef _CContexBehaviour
#define _CContexBehaviour
class ContextBehavior{
private:
	Behavior* behavior;
public:
	explicit Contextbehavior(Behavior* behavior):behavior(behavior){}
	void setBehavior(Behavior* behavior){
		this->behavior= behavior;
	}
	pair<pair<int, int >, pair< int, int >> executeBehavior(int index, pair< int, int > posActual, pair< int, int > dirActual, vector< Beast*> listBeast){
		retrun this->behavior->move(int index, pair< int, int > posActual, pair< int, int > dirActual, vector< Beast*> listBeast);
	}
};
#endif
