#include<bits/stdc++.h>
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
