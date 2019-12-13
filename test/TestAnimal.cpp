#include<bits/stdc++.h>
using namespace std;
#include"../logic/include.hpp"
#include"../model/beast/Animal.hpp"

void printBeast(){
  Animal *a = new Animal(1, {1,1}, {1,1});
  cout << a->getId() <<endl;
}

int main(){

  printBeast();
}
