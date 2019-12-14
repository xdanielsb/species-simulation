#ifndef _CEar
#define _CEar
#include"./Sensor.hpp"
#include <random>
#include<iostream>
using namespace std;

/**
 * Implementation of Ear
 *
 *
 */
class EarS: public Sensor{
public:
	EarS(double dis, double det): Sensor(dis, det, 2*PI){
	}
	~EarS(){}
};
#endif
