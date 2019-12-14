#ifndef _CEye
#define _CEye
#include"./Sensor.hpp"
#include <random>
#include<iostream>
using namespace std;

/**
 * Implementation of Eye
 *
 *
 */
class EyeS: public Sensor{
public:
	EyeS(double dis, double det, double degr): Sensor(dis, det, degr){

	}
	~EyeS(){}
};
#endif
