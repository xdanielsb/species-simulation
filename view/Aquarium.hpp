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
#include"../include/CImg.h"
#include"../model/beast/Animal.hpp"
using namespace cimg_library;
class Aquarium : public CImgDisplay{
private:

  const unsigned int width;
  const unsigned int height;
  Environment *env;
public:
  Aquarium( const unsigned int _width, const unsigned int _height, Environment *_env):  CImgDisplay(),  width(_width), height(_height){
    this->env = _env;
    //CImg<unsigned char> board(400,300,1,1,0);
    assign( *env, "Ecosystem" );
  //  this->move((CImgDisplay::screen_width() - _width)/2, (CImgDisplay::screen_height() - _height)/2).hide_mouse();
  }
  void run( ){
    int step = 1;
    while(!this->is_closed() && step++){
      printf("Running step #%d\n", step);
      this->env->step();
      display( *this->env );
      this->wait(100);
    }
  }
  Environment &getEnvironment(){
    return *env;
  }
  int getWidth( void ) const {
    return width;
  };
  int getHeight( void ) const {
    return height;
  };
};
#endif
