CC = g++
CFLAGS = -std=c++11
CSANIT = -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -O2 -g
TFLAGS = -pthread -pedantic -Dcimg_use_vt100 -Dcimg_display=1   -lm -lX11 -lpthread
NAMEFILE = launcher.cpp


all:
	$(CC) $(CSANIT) $(CFLAGS) $(NAMEFILE) $(TFLAGS) -o main.o && ./main.o

debug:
	$(CC) -DDEBUG  $(CFLAGS) $(NAMEFILE) $(TFLAGS) -o main.o && ./main.o
run:
	$(CC)  $(CFLAGS) $(NAMEFILE) $(TFLAGS) -o main.o && ./main.o
