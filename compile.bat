:
:	g++ (GCC) 3.4.5 (mingw-vista special r3)
:	Win32 xp
:
@echo off

set binary="Hangman.exe"

set source=main.cpp Game.cpp State.cpp GameContext.cpp StateStart.cpp StateSettings.cpp StateLoop.cpp StateEnd.cpp 
set object=main.o Game.o State.o GameContext.o StateStart.o StateSettings.o StateLoop.o StateEnd.o 


g++ %source% -c
g++ %object% -o %binary%

@echo on