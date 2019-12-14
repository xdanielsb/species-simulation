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
/**
 * Initier the aquarium 
 *
 * @param _width set the width of the aquarium
 * @param _height set the height of the aquarium
 * @param _env set the environment of the aquarium
 *
 *   
 */
  Aquarium( const unsigned int _width, const unsigned int _height, Environment *_env):  CImgDisplay(),  width(_width), height(_height){
    this->env = _env;
    //CImg<unsigned char> board(400,300,1,1,0);
    assign( *env, "Ecosystem" );
    this->move((CImgDisplay::screen_width() - _width)/2, (CImgDisplay::screen_height() - _height)/2).hide_mouse();
  }

/// Launch the simulation 
  void run( int argc,char **argv ){
    CImg<unsigned char> src(cimg_option("-i","assets/img/beast.ppm","Input image"));

    if (cimg::dialog(cimg::basename("Hi there, xD"),
                  "Authors : \n"
                  "----------------\n\n"
                  "(-) Daniel Santos.\n\n"
                  "(-) Zheng LI .\n\n"
                  "(-) Andy Méri.\n\n"
                  "(-) Gonza Quintana.\n\n"
		  "(-) Xue Wang.\n\n"
                  "(-) Lei Zan .\n\n"
                  "take a look to the code at https://github.com/xdanielsb/BeastCollider.\n"
                  "See also the available options (option '-h')\n","Start !","Quit",0,0,0,0,
                  src.get_resize(100,100,1,3),true)) std::exit(0);
    int step = 1;
    while(!this->is_closed() && step++){
      printf("Running step #%d\n", step);
      this->env->step();
      display( *this->env );
      this->wait(100);
    }
  }
/// Get the environment of the aquarium
  Environment &getEnvironment(){
    return *env;
  }
/// Get the width of the aquarium
  int getWidth( void ) const {
    return width;
  };
/// Get the height of the aquarium
  int getHeight( void ) const {
    return height;
  };
};
#endif
