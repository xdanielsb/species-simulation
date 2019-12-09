#ifndef _CEye
#define _CEye
#include"./Sensor.hpp"
#include <random>
#include<iostream>
using namespace std;
class Eye: public: Sensor{
public:
	Eye();
	Eye( double _dist_min, double _dist_max, double _deg_min, double _deg_max, double _det_min,  double _det_max): Sensor(_dist_min, _dist_max, _deg_min, _deg_max, _det_min, _det_max){
	}
	double getDistanceEye(){
		return this->distance;
	}

	double getDetectionEye(){
		return this->detection;
	}
	double getSDegreeEye(){
		return this->degree;
	}
};
#endif
