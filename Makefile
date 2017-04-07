
# CONSTANT MACROS
CC = "C:\Compiler\MinGW-w64\mingw32\bin\g++.exe"
DEBUG = -g
SDLLIBC = -IC:\Compiler\SDL\include\SDL2 -w -Wl,-subsystem,windows
SDLLIBL = -LC:\Compiler\SDL\lib -lmingw32 -lSDL2main -lSDL2


CFLAGS = $(DEBUG) -Wall -std=c++17 -c
LFLAGS = $(DEBUG) -Wall

FINALBUILD = -std=c++17 -static $(CFLAGS) $(LFLAGS)

main:
	$(CC) $(CFLAGS) ".\main.cpp" -o ".\obj\main.o"
	
board:
	$(CC) $(CFLAGS) ".\board.cpp" -o ".\obj\board.o" 
	
computerAI:
	$(CC) $(CFLAGS) ".\computerAI.cpp" -o ".\obj\computerAI.o"
	
gameFunc:
	$(CC) $(CFLAGS) ".\gameFunc.cpp" -o ".\obj\gameFunc.o"
	
prgm:
	$(CC) ".\obj\*.o" $(LFLAGS) -o ".\bin\main.exe"
	
final:
	$(CC) ".\*.cpp" $(FINALBUILD) -o ".\bin\final.exe"
	
clean:
	del ".\obj\*.o"