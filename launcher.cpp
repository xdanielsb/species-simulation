#include<iostream>
#include<vector>
#include<math.h>
#include<array>
#include<new>
#include"./logic/controller/Simulation.hpp"
#include"./model/behaviour/Lazy.hpp"
using namespace std;


int main(){
  Simulation *s = new Simulation();

  try{
    s->start();
  }catch(const char* msg){
    printf("An error has occurred %s \n",msg);
  }
}
