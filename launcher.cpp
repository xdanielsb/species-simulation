#include<iostream>
#include<vector>
#include<math.h>
#include<array>
#include<new>
#include"./logic/controller/Simulation.hpp"
using namespace std;
#include <thread>
int main(){
  int nBeast = 10;
  Simulation *stask = new Simulation(nBeast);
  try{
    thread th(&Simulation::start, stask);
    th.join();
  }catch(const char* msg){
    printf("An error has occurred %s \n",msg);
  }
  delete stask;
}
