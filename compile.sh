#!/bin/bash

binary="Hangman"

source="main.cpp Game.cpp State.cpp GameContext.cpp StateStart.cpp StateSettings.cpp StateLoop.cpp StateEnd.cpp"
object="main.o Game.o State.o GameContext.o StateStart.o StateSettings.o StateLoop.o StateEnd.o"

g++ $source -c
g++ $object -o $binary
