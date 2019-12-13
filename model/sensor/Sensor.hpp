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
  ~Sensor();
	Sensor(double dis, double det, double degr){
		this->distance= dis;
		this->detection= det;
		this->degree= degr;
	}
};
#endif
