#include<bits/stdc++.h>
#include"./logic/Aquarium.hpp"
using namespace std;

int main(){
  Aquarium *q = new Aquarium();
  try{
    q->run();
  }catch(const char* msg){
    printf("An error has occurred %s \n",msg);
  }
}
