CXX=g++
CFLAGS=--std=c++0x 
INCLUDE=-Isrc/res -Isrc/utils -Isrc/ -Ilib/ -Ilib/utils/ -Ilib/TmxParser/ -Ilib/TmxParser/base64/ 
LDFLAGS= -Wextra -Wall -std=gnu++11 -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system -lGLU -lglut -lpthread -lGL
EXEC=.build/graph/code
DEBUG=.build/graph/code
SRC=../code_source/src/graphique/code.cpp $(wildcard ../code_source/src/cube/*.cpp) $(wildcard ../code_source/src/cube/type_cube/*.cpp)  $(wildcard ../code_source/src/plateau/*.cpp) $(wildcard ../code_source/src/Joueur/*.cpp)  
OBJ= $(SRC:.cpp=.o)

build: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $^ $(LDFLAGS)

main.o: *.hpp

%.o: %.cpp
	# Compiling $<
	$(CXX) -o $@ -c $< $(CFLAGS) $(INCLUDE)

.PHONY: clean mrproper

clean:
	rm $(OBJ)

mrproper: clean
	rm $(EXEC)

run:
	$(EXEC)

build-run: build run

debug: build
	gdb $(EXEC)
