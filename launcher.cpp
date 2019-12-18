#include<iostream>
#include<vector>
#include<math.h>
#include<array>
#include<new>
#include<unordered_set>
#include<vector>
#include<memory>
#include"./include/CImg.h"
using namespace cimg_library;
#include"./logic/include.hpp"
#include"./logic/controller/Simulation.hpp"
using namespace std;
#include <thread>

/**
 * Set the initial number of animal in the environment and launch
 * the simulation.
 *
 *
 */
int main(int argc,char **argv){
  int nBeast = 20;
  Simulation *stask = new Simulation();
  try{
    #ifndef CLI
        stask->startGUI(argc, argv, nBeast);
    #else
      thread th(&Simulation::startCLI, stask, nBeast);
      th.join();
    #endif
  }catch(const char* msg){
    printf("An error has occurred %s \n",msg);
  }
  delete stask;
}
