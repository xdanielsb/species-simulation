#include<bits/stdc++.h>
using namespace std;
#include"../logic/include.hpp"
#include"../model/beast/Beast.hpp"

void printBeast(){
  Beast *a = new Beast(1, {1,1}, {1,1});
  cout << a << endl;
}

int main(){
  printBeast();
}
