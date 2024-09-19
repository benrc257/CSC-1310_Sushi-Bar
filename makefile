# TO COMPILE WITH MAKEFILE ON WINDOWS, DO "mingw32-make"
# IF ON MAC OR LINUX, USE "make"

# file names
functions := Main/functions.cpp
driver:= Main/driver.cpp
sushibar := Storage Classes/sushibar.cpp
menu := Data Classes/menu.cpp
sushi := Data Classes/sushi.cpp

# compile SushiBar (All)
all: main.o classes.o
	g++ main.o classes.o -o SushiBar

# compile main.o
main.o: ${functions} ${driver}
	g++ ${functions} ${driver} -o main.o

# compile classes.o
classes.o: sushibar.o menu.o sushi.o
	g++ sushibar.o menu.o sushi.o -o classes.o

#compile classes
sushibar.o: ${sushibar}
	g++ ${sushibar} -o sushibar.o

menu.o: ${menu}
	g++ ${menu} -o menu.o

sushi.o: ${sushi}
	g++ ${sushi} -o sushi.o