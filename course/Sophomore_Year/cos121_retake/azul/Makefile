CXXFLAGS = -g -std=c++17 -fPIC -O3

OBJS = Board.o \
       Player.o \
       Table.o \
       Tile.o \
       Turn.o \
       conio.o

PLAYERS = Myplayer.so \
          MyBetterPlayer.so \
          Human.so
#Greedy.so \
	  Human.so \
	  Minimax.so \
	  Random.so \ 
#Dummy.so

all: azul ${PLAYERS}

azul: ${OBJS} main.o
	g++ -o azul ${OBJS} main.o -ldl -lpthread -lstdc++fs

#main.o: main.cpp Board.h Player.h Table.h Turn.h
#conio.o: conio.cpp conio.h
#Board.o: Board.cpp Board.h Tile.h Turn.h
#Player.o: Player.cpp Player.h Board.h Table.h Turn.h
#Table.o: Table.cpp Table.h Board.h Tile.h Turn.h
#Tile.o: Tile.cpp Tile.h
#Turn.o: Turn.cpp Turn.h Tile.h

${PLAYERS}: %.so: %.cpp ${OBJS}
	${CXX} ${CXXFLAGS} -shared -rdynamic -fPIC ${OBJS} $< -o $*.so

Dummy.so: Dummy.cpp Dummy.h Player.h
Greedy.so: Greedy.cpp Greedy.h Player.h
Human.so: Human.cpp Human.h Player.h
Minimax.so: Minimax.cpp Minimax.h Player.h
Random.so: Random.cpp Random.h Player.h
Myplayer.so: Myplayer.cpp Myplayer.h Player.h
MyBetterPlayer.so: MyBetterPlayer.cpp MyBetterPlayer.h Player.h
