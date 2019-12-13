#ifndef _CEar
#define _CEar
#include"./Sensor.hpp"
#include <random>
#include<iostream>
using namespace std;
class Ear: public Sensor{
public:
	Ear();
	Ear(double _dist_min, double _dist_max, double _deg_min, double _deg_max, double _det_min,  double _det_max): Sensor(_dist_min, _dist_max, PI*2, PI*2, _det_min, _det_max){}
	double getDistanceEar(){
		return this->distance;
	}
	double getDetectionEar(){
		return this->detection;
	}
	double getDegreeEar(){
		return this->degree;
	}
};
#endif
