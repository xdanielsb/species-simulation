/***
 * This class defines a window that
 * contains the Beasts
**/
#ifndef _CAquarium
#define _CAquarium

/*
 * Depenedencies
 */
#include"../logic/include.hpp"
#include"../model/beast//Animal.hpp"
#include "../include/CImg.h"
using namespace cimg_library;

class Aquarium {
private:
  int width;
  int height;
  Environment *env;
public:
  Aquarium( int _width, int _height, Environment *_env): width(_width), height(_height){
    this->env = _env;
  }
  void run(){
    CImg<unsigned char> board(400,300,1,1,0);
    CImgDisplay disp(board,"Beast House",0,false,true);
    disp.move((CImgDisplay::screen_width() - disp.width())/2,
            (CImgDisplay::screen_height() - disp.height())/2).hide_mouse();
    int step = 1;
    while(!disp.is_closed() && step++){
      printf("Running step #%d\n", step);
      this->env->step();
      disp.wait( 1000 );
    }
  }
};
#endif
