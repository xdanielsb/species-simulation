#include<iostream>
#include<vector>
#include<math.h>
#include<array>
#include<new>
#include<unordered_set>
#include<vector>
#include"./include/CImg.h"
using namespace cimg_library;
#include"./logic/include.hpp"
#include"./logic/controller/Simulation.hpp"
using namespace std;
#include <thread>
int main(int argc,char **argv){
  int nBeast = 20;
  int simulateWithGUI = true;
  Simulation *stask = new Simulation(nBeast);
  try{
    if(simulateWithGUI ){
        stask->startGUI(argc, argv);
    }else{
      thread th(&Simulation::startCLI, stask);
      th.join();
    }
  }catch(const char* msg){
    printf("An error has occurred %s \n",msg);
  }
  //delete stask;
}
