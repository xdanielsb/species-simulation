#ifndef _CDialog
#define _CDialog
class Dialog{
private:
  const int WIDTH = 100;
  const int HEIGHT = 100;
public:
  Dialog(){}
  ~Dialog(){}
  void create(int argc,char **argv ){
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
                  "Look the readme.md for more details","Start !","Quit",0,0,0,0,
                  src.get_resize(this->WIDTH,this->HEIGHT,1,3),true)) std::exit(0);
  }
};
#endif
