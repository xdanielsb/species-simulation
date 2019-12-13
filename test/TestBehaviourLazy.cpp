#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include<bits/stdc++.h>
using namespace std;
#include"../logic/include.hpp"
#include"../model/beast/Beast.hpp"
#include <assert.h>
#include "../include/doctest.h"

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
	
	int lazy_behaviour = 3;
	int n_neighs = 4;

	Beast *me = new Beast(1, {1,1}, {1,1}, lazy_behaviour);

	vector <Animal*> lbeast;

	lbeast.push_back(me);

	int j;
	for(j=0;j<n_neighs;j++){

		Beast *b = new Beast(1, {1,1}, {1,1}, lazy_behaviour);
		lbeast.push_back(b);
	}
	
	CHECK(get<0>(me->getPosition()) == 1);
	CHECK(get<1>(me->getPosition()) == 1);
	
	me->move(lbeast);

	CHECK(get<0>(me->getPosition()) != 1);
	CHECK(get<1>(me->getPosition()) != 1);
	
}

