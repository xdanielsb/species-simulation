#ifndef _CSensor
#define _CSensor

#include<random>
#include<iostream>

using namespace std;

class Sensor{
private:

protected:
	double distance;
	double degree;
	double detection;
public:
	//Sensor();
	Sensor(double _dist_min, double _dist_max, double _deg_min, double _deg_max, double _det_min,  double _det_max){
		default_random_engine generator;		
		uniform_real_distribution<double> distribution_dist(_dist_min, _dist_max);
		uniform_real_distribution<double> distribution_deg(_deg_min, _deg_max);
		uniform_real_distribution<double> distribution_det(_det_min, _det_max);
		this->distance= distribution_dist(generator);
		this->detection= distribution_det(generator);
		this->degree= distribution_deg(generator);	
	}
	//Sensor(double _dist, double _deg, double _det){
	//	this->distance=_dist;
	//	this->degree=_deg;
	//	this->detection=_det;
	//}
};
#endif
