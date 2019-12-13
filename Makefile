run:
	g++ -std=c++11 -pthread launcher.cpp -pedantic -Dcimg_use_vt100 -Dcimg_display=1   -lm -lX11 -lpthread && ./a.out
