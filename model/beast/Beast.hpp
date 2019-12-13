#ifndef _CBeast
#define _CBeast
#include"../accesory/Accessory.hpp"
#include"../accesory/Camouflage.hpp"
#include"../accesory/Fin.hpp"
#include"../accesory/Shell.hpp"
#include"../sensor/Sensor.hpp"
#include"../sensor/Ear.hpp"
#include"../sensor/Eye.hpp"
#include"../behaviour/IBehaviour.hpp"
#include"../behaviour/Lazy.hpp"
#include"../behaviour/Kamikaze.hpp"
#include"../behaviour/Gregarius.hpp"
#include"../behaviour/Farsighted.hpp"
#include"../../logic/util/Random.hpp"

#include <iomanip>
#include <memory>

class Beast: public Animal{
private:
  
  double cam_limit_min = 1;
  double cam_limit_max = 4;
	double fin_limit = 3;
	double resistance_limit=5;
  double speed_limit=5;
  int maxNumAcce = 1;
	int maxNumSensor = 1; 
  
  double _dist_min_eye = 1;
	double _dist_max_eye = 10;
	double _deg_min_eye =  0;
	double _deg_max_eye = PI;
	double _det_min_eye = 1;
	double _det_max_eye = 5;

	double _dist_min_ear = 2;
	double _dist_max_ear = 15;
	double _deg_min_ear =2*PI; 
	double _deg_max_ear	=2*PI;
	double _det_min_ear = 1;
	double _det_max_ear = 10;
  Random* r = new Random();

  double camouflage;
  double perceptionEar;
  double perceptionEye;
  double speed;
  double resistance;
  vector<Sensor*> sensors;
  vector<Accessory*> accesories;
  shared_ptr<Behaviour> behaviour;
	//map<int, Accessory*> mapAccessory {{0, new Camouflage(cam_limit_min, )}, {1, new Fin()}, {2, new Shell()}};
	//map<int, Sensor*> mapSensor;

public:
  Beast(int _id, ii _pos, ii _dir, shared_ptr<Behaviour> b):Animal(_id, _pos, _dir) {
    b.swap(behaviour);
		this->addAccessory();
		this->addSensor();
		
  }
  ~Beast(){}
  //void addAccessory(share_ptr<Accessory>){
  //  this->accesories.push_back( a );
  //}


void addRandomlyAccessory(){
		int indexAccessory = this->r->getInt(1,4);
		switch(indexAccessory){
			case 1:
				this->accesories.push_back(new Camouflage(this->cam_limit_min,this->cam_limit_max));
				printf("Add a Camouflage/n");
			case 2:
				this->accesories.push_back(new Fin(this->fin_limit));
				printf("Add a Fin/n");
			case 3:
				this->accesories.push_back(new Shell(this->resistance_limit, this->speed_limit));
				printf("Add a Shell/n");
		}
	}
  void addAccessory(){
    int numberOfAccessory = this->r->getInt(0, maxNumAcce);
		for(int i=0; i<=numberOfAccessory; i++){
				this->addRandomlyAccessory();
		}
  }

  void randomGetSensor(){
		int indexSensor = this->r->getInt(1,3);
		switch(indexSensor){
			case 1:
				this->sensors.push_back(new Ear(this->_dist_min_eye, this->_dist_max_eye, this->_deg_min_eye, this->_deg_max_eye, this->_det_min_eye,  this->_det_max_eye));
				printf("Add a Ear/n");
			case 2:
				this->sensors.push_back(new Eye(this->_dist_min_ear, this->_dist_max_ear, this->_deg_min_ear, this->_deg_max_ear, this->_det_min_ear,  this->_det_max_ear));
				printf("Add a Eye/n");
		}	
	}
  void addSensor(){
		int numberOfSensor= this->r->getInt(0, maxNumSensor);
		for(int i=0; i<=numberOfSensor; i++){
			this->randomGetSensor();
		}
  }


  void move(vector<Animal*> &neighbors){
    cout << setprecision(2) << fixed << "\tMoving "<< this ;
    this->behaviour->move( this, neighbors );
  }
  Beast* clone(){
    return new Beast( *this);
  }
  void setBehavior( int type ){
  //  this->behaviour = b;
  }
  shared_ptr<Behaviour> getBehaviour(){
    return this->behaviour;
  }
  friend ostream& operator << (ostream &out, Beast *b) {
    out << "Animal #"<< b->getId() << " = {"<< b->getPosition().X <<", " << b->getPosition().Y << "}";
    return out;
  }

};
#endif
