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
  Aquarium( const unsigned int _width,
            const unsigned int _height,
            Environment *_env):
            CImgDisplay(),  width(_width), height(_height){
    this->env = _env;
    assign( *env, "Ecosystem of Beast" );
    this->move((CImgDisplay::screen_width() - _width)/2 + 200,
               (CImgDisplay::screen_height() - _height)/2);
    //.hide_mouse();
  }

  /// Launch the simulation
  void run( ){
    int step = 1;
    double clicX = -1, clicY = -1;
    CImg<unsigned char> backDetailleView(400, 300);
    CImgDisplay detailleView(400,300,"Detailled View of Ecosystem ",0);
    detailleView.move((CImgDisplay::screen_width() - _width)/2 - 200,
                      (CImgDisplay::screen_height() - _height)/2 + 150);
    int iterationsToDieSelectedBeast = -1;
    Animal *choosed;
    while(!this->is_closed() && step++){
      const unsigned int but = button();
      // Draw detailled view
      cimg_forXY( backDetailleView, x,y)
      backDetailleView.fillC(x,y,0,255,255,235);
      int numAliveBeast = this->env->getListBeast().size();
      if( numAliveBeast == 0){
        backDetailleView.draw_text(110, 150,
                 "Click on the environment to create a new Beast.",
                 WHITE,BLACK,
                 1,13);
      }else{
        if( iterationsToDieSelectedBeast == -1){
          backDetailleView.draw_text(110, 150,
                   "Click on any beast to show its information.",
                   WHITE,BLACK,
                   1,13);
        }
      }
      #ifdef  DEBUG
        printf("Running step #%d\n", step);
      #endif

      // Actions
      clicX = mouse_x(); clicY= mouse_y();
      if( clicX > 1 && clicY > 1 && but){
        double minDist = 1e9;
        bool isThereBeastNearClick = false;
        for( Animal *c: this->env->getListBeast()){
           double dist = c->getDistance( {clicX, clicY} );
           if( dist  < 10 && dist < minDist){
             minDist = dist;
             choosed = c;
             isThereBeastNearClick = true;
             iterationsToDieSelectedBeast = c->getMaxAge() - c->getAge();
           }
        }
        if(!isThereBeastNearClick )
          this->createNewBeast( {clicX, clicY} );
      }
      if( iterationsToDieSelectedBeast >= 0){
        backDetailleView.draw_text(110, 110,
                 "Detail Beast\n \
                  Age =   %d         \n\
                  Max Age = %d       \n\
                  Behaviour = %c     \n\
                  Has Accessory = %c \n\
                  Has Sensors = %c \n\
                 ",
                 WHITE,BLACK,
                 1,13, choosed->getAge(),
                 choosed->getMaxAge(),
                 INITALS_BEHAVIOURS[choosed->getBehaviour()][0],
                 choosed->hasAccessories()?'Y':'N',
                 choosed->hasSensors()?'Y':'N'
             );
        iterationsToDieSelectedBeast--;
      }
      this->env->step( step );
      display( *this->env );
      detailleView.display( backDetailleView );
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
