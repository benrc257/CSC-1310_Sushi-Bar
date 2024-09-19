# TO COMPILE WITH MAKEFILE ON WINDOWS, DO "mingw32-make"
# IF ON MAC OR LINUX, USE "make"

# settings
CXX = g++
CXXFLAGS = -c

# file names
functions := Main/functions.cpp
driver:= Main/driver.cpp
sushibar := Storage/sushibar.cpp
menu := Data/menu.cpp
sushi := Data/sushi.cpp

# compile SushiBar (All)
all: main.o functions.o sushibar.o sushi.o menu.o
	g++ main.o functions.o sushibar.o sushi.o menu.o -o SushiBar

# compile main.o
main.o: ${driver}
	${CXX} ${CXXFLAGS} ${driver} -o main.o

functions.o: ${functions}
	${CXX} ${CXXFLAGS} ${functions} -o functions.o

#compile classes
sushibar.o: ${sushibar}
	${CXX} ${CXXFLAGS} ${sushibar} -o sushibar.o

menu.o: ${menu}
	${CXX} ${CXXFLAGS} ${menu} -o menu.o

sushi.o: ${sushi}
	${CXX} ${CXXFLAGS} ${sushi} -o sushi.o