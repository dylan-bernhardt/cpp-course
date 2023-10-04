G++ = g++

vpath %.h include
vpath %.cpp src
vpath %.o obj

all : 
	mkdir obj
	make exe

%.o : %.cpp
	$(G++) -c $< -Iinclude

exe : point.o segment.o main.o forme.o
	$(G++) point.o segment.o main.o forme.o -o exe
	mv $^ ./obj

clean :
	rm -rf ./obj
	rm exe
	