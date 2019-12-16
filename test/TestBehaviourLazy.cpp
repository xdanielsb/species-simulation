#include <memory>
#include <iomanip>
#include "CImg.h"
#include"../logic/include.hpp"
#include"../model/accessory/Accessory.hpp"
#include"../model/sensor/Sensor.hpp"
#include"../model/beast/Animal.hpp"
#include"../model/beast/Beast.hpp"
#include"../model/behaviour/IBehaviour.hpp"
#include"../model/behaviour/Lazy.hpp"
#include"../include/doctest.h"

#include"../logic/util/Random.hpp"

TEST_CASE("Beasts without speed don't move") {
	
	
	int n_neighs = 4;
	int xinit = 4;
	int yinit = 5;
	
	shared_ptr<LazyB> lazy_behaviour = make_shared<LazyB>();
	
	vector <Animal*> list;

	for(int j=0;j<n_neighs;j++){

		Beast *b = new Beast(j, {xinit,yinit}, {0,0}, lazy_behaviour);
		
		list.push_back(b);
	}	
	
	for(int i=0;i<2;i++){

		for(Animal*  b:list){
				b->move(list);
			
				CHECK(get<0>(b->getPosition()) == xinit);
				CHECK(get<1>(b->getPosition()) == yinit);
		}
	}
	
	
	for(Animal*  b:list){
			delete(b);
	}
	

	
}




TEST_CASE("Lazy beast returnig in it's way when there are too many quiet beasts - 1D") {
	
	shared_ptr<LazyB> lazy_behaviour = make_shared<LazyB>();
	int n_neighs = lazy_behaviour->getMINDIS();


	Beast *me = new Beast(1, {0,1}, {0,1}, lazy_behaviour);
	
	vector <Animal*> list;

	for(int j=0;j<n_neighs;j++){

		Beast *b = new Beast(j, {0,10}, {0,0}, lazy_behaviour);
		list.push_back(b);
	}
	
	list.push_back(me);
	
	CHECK(get<0>(me->getPosition()) == 0);
	CHECK(get<1>(me->getPosition()) == 1);
	
	for(int j=0;j<5;j++){
	
		me->move(list);
	}
	
	CHECK(get<0>(me->getPosition()) == 0);
	CHECK(get<1>(me->getPosition()) == 6);
	
	me->move(list);
	
	// The beast goes back in it's direction!
	
	CHECK(get<0>(me->getPosition()) == 0);
	CHECK(get<1>(me->getPosition()) == 5);
	
	for(Animal*  b:list){
			delete(b);
	}

}

TEST_CASE("Lazy beast doesn't return. There are not too many beasts - 1D") {
	
	shared_ptr<LazyB> lazy_behaviour = make_shared<LazyB>();
	int n_neighs = lazy_behaviour->getMINDIS()-1;
	
	ii my_pos = {0,1};
	ii my_speed = {0,1};
	ii others_pos = {0,1};
	ii others_speed = {0,1};

	Beast *me = new Beast(1, my_pos, my_speed, lazy_behaviour);
	
	vector <Animal*> list;

	for(int j=0;j<n_neighs;j++){

		Beast *b = new Beast(j, others_pos, others_speed, lazy_behaviour);
		list.push_back(b);
	}
	
	list.push_back(me);
	
	CHECK(get<0>(me->getPosition()) == get<0>(my_pos));
	CHECK(get<1>(me->getPosition()) == get<1>(my_pos));
	
	int nmoves = 5;
	for(int j=0;j<nmoves;j++){
	
		me->move(list);
	}
	
	CHECK(get<0>(me->getPosition()) == get<0>(my_pos));
	CHECK(get<1>(me->getPosition()) == get<1>(my_pos)+nmoves);
	
	me->move(list);
	
	// The beast should't go back!
	
	CHECK(get<0>(me->getPosition()) == 0);
	CHECK(get<1>(me->getPosition()) == 7);
	
	for(Animal*  b:list){
			delete(b);
	}

}

TEST_CASE("Lazy beast bouncing when reaching the aquarium bounds") {
	
	shared_ptr<LazyB> lazy_behaviour = make_shared<LazyB>();
	
	ii pos1 = {WIDTH_WINDOW,0};
	ii speed1 = {1,0};
	ii pos2 = {0,HEIGHT_WINDOW};
	ii speed2 = {0,1};
	ii pos3 = {0,0};
	ii speed3 = {-1,-1};
	
	vector <Animal*> list;


	Beast *b1 = new Beast(0, pos1, speed1, lazy_behaviour);
	Beast *b2 = new Beast(1, pos2, speed2, lazy_behaviour);
	Beast *b3 = new Beast(2, pos3, speed3, lazy_behaviour);
	
	list.push_back(b1);
	list.push_back(b2);
	list.push_back(b3);
	
	b1->move(list);
	b2->move(list);
	b3->move(list);
	
	// The beasts should bounce

	
	CHECK(get<0>(b1->getPosition()) == WIDTH_WINDOW-1);
	CHECK(get<1>(b1->getPosition()) == 0);
	
	CHECK(get<0>(b2->getPosition()) == 0);
	CHECK(get<1>(b2->getPosition()) == HEIGHT_WINDOW-1);
	
	CHECK(get<0>(b3->getPosition()) == 1);
	CHECK(get<1>(b3->getPosition()) == 1);
	
	delete(b1);
	delete(b2);
	delete(b3);
	
}


