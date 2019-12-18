// Auxiliar Struct to make test multiplatform
// just defines the signatures
template <typename T>
struct CImg {
  T aux;
  T x, y;
  CImg(...){}
  void draw_ellipse(...){}
  void draw_circle(...){}
  void draw_text(...){}
  void cimg_forXY(...){}
  void normalize(...){}
  void fillC(){};
};
#include<memory>
#include"../model/behaviour/IBehaviour.hpp"
#include"../model/behaviour/Lazy.hpp"
#include"../model/behaviour/Gregarius.hpp"
#include"../model/behaviour/Farsighted.hpp"

//why should class Lazy have a getter
TEST_CASE("Test getter for Lazy") {
   double mindis = 5;
   LazyB *lazy = new LazyB();
   CHECK(lazy->getMINDIS() == mindis);
   delete lazy;
}
