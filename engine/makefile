OBJS= Img_Func.obj Soldier.obj Main.obj
CC= gcc
CPP= g++
DEBUG= -g
LFLAGS= -Wall -lSDL -lSDL_image -lSDL_ttf $(DEBUG)
CFLAGS= -Wall -c $(DEBUG)

Test_rtf : $(OBJS)
	echo "==== Linking ... ===="
	$(CPP) $(LFLAGS) -o Test_rtf $(OBJS)

Img_Func.obj : img_functions.cpp
	echo "==== Building main.cpp ===="
	$(CPP) $(CFLAGS) img_functions.cpp -o Img_Func.obj

Soldier.obj : soldier.cpp
	echo "==== Building main.cpp ===="
	$(CPP) $(CFLAGS) soldier.cpp -o Soldier.obj

Main.obj : main.cpp
	echo "==== Building main.cpp ===="
	$(CPP) $(CFLAGS) main.cpp -o Main.obj


clean:
	echo "==== Cleaning ... ===="
	rm *.obj *~ Test_rtf