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
  int simulateWithGUI = true;
  Simulation *stask = new Simulation(nBeast);
  try{
    if(simulateWithGUI ){
        stask->startGUI();
    }else{
      thread th(&Simulation::startCLI, stask);
      th.join();
    }
  }catch(const char* msg){
    printf("An error has occurred %s \n",msg);
  }
  //delete stask;
}
