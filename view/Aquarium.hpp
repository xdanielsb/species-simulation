/***
 * This class defines a window that
 * contains the Beasts
**/
#ifndef _CAquarium
#define _CAquarium

/*
 * Dependencies
 */
#include"../model/beast/Animal.hpp"
#include"../logic/factory/BeastFactory.hpp"
#include"../logic/factory/BehaviourFactory.hpp"
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
    this->move((CImgDisplay::screen_width() - _width)/2, (CImgDisplay::screen_height() - _height)/2);
    //.hide_mouse();
  }


  /// Launch the simulation
  void run( ){
    int step = 1;
    double clicX = -1, clicY = -1;
    while(!this->is_closed() && step++){
      const unsigned int but = button();
      #ifdef  DEBUG
        printf("Running step #%d\n", step);
      #endif
      clicX = mouse_x(); clicY= mouse_y();
      if( clicX > 1 && clicY > 1 && but){
        this->createNewBeast( {clicX, clicY} );
      }
      this->env->step( step );
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
  /// Create new beast
  void createNewBeast( ii pos ){
     this->env->createNewBeast( pos );
  }

};
#endif
