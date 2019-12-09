#include<iostream>
#include<vector>
#include<math.h>
#include<array>
#include<new>
#include"./view/Aquarium.hpp"
using namespace std;

int main(){
  Aquarium *q = new Aquarium(300, 300);
  try{
    q->run();
  }catch(const char* msg){
    printf("An error has occurred %s \n",msg);
  }
}
