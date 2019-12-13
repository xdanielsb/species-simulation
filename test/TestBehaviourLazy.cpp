#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include<bits/stdc++.h>
using namespace std;
#include"../logic/include.hpp"
#include"../model/beast/Beast.hpp"
#include "../logic/controller/Simulation.hpp"
#include <assert.h>
#include "../include/doctest.h"
#include "../logic/factory/BeastFactory.hpp"

/*
void printBeast(Beast *a){
  cout << a << endl;
}

int main(){
  int lazy_behaviour = 3;
  Beast *me = new Beast(1, {1,1}, {1,1}, lazy_behaviour);
  Beast *neighbour1 = new Beast(1, {1,1}, {1,1}, lazy_behaviour);
  Beast *neighbour2 = new Beast(1, {1,1}, {1,1}, lazy_behaviour);
  Beast *neighbour3 = new Beast(1, {1,1}, {1,1},lazy_behaviour);
  Beast *neighbour4 = new Beast(1, {1,1}, {1,1},lazy_behaviour);

  printBeast(me);
}
*/

TEST_CASE("testing the beast's position and moves") {
	
	int n_neighs = 4;
	shared_ptr<LazyB> lazy_behaviour = shared_ptr<LazyB>();
	

	Beast *me = new Beast(1, {1,1}, {1,1}, lazy_behaviour);

/*
	vector <Animal*> lbeast;

	lbeast.push_back(me);

	int j;
	for(j=0;j<n_neighs;j++){

		Animal *b = new Beast(1, {-10,-10}, {0,0}, lazy_behaviour);
		lbeast.push_back(b);
	}*/
	
	BeastFactory fac = new BeastFactory();
	
	//vector<Animal*> lbeast = fac.newRandomPopulation(4);
		
	CHECK(get<0>(me->getPosition()) == 1);
	CHECK(get<1>(me->getPosition()) == 1);
	
	//shared_ptr<behaviour>  l = me->getBehaviour();
	
	//cout<<l.getMINDIS()<<endl;
	
	//me->move(lbeast);

	CHECK(get<0>(me->getPosition()) == 1);
	CHECK(get<1>(me->getPosition()) == 1);
	
}

