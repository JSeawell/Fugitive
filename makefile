# Makefile for FinalGame

# Name: Jake Seawell
# Date: 11/25/18
# Description: This Makefile shows all the files
# necessary to compile and run the executable
# file "FinalGame", for CS162 Final Project.

CXX = g++
CXXFLAGS = -std=c++0x
//CXXFLAGS += -g

OBJS = Space.o EmptySpace.o Player.o FinalGame.o Handcuffs.o Flashlight.o Trap.o Armor.o intVal.o choiceFunction.o
SRCS = Space.cpp EmptySpace.cpp Player.cpp FinalGame.cpp Handcuffs.cpp Flashlight.cpp Trap.cpp Armor.cpp intVal.cpp choiceFunction.cpp Final_main.cpp
HDRS = Space.hpp EmptySpace.hpp Player.hpp FinalGme.hpp Handcuffs.hpp Flashlight.hpp Trap.hpp Armor.hpp intVal.hpp choiceFunction.hpp


FinalGame: Space.o EmptySpace.o Player.o FinalGame.o Handcuffs.o Flashlight.o Trap.o Armor.o intVal.o choiceFunction.o Final_main.cpp
	${CXX} ${CXXFLAGS} ${OBJS} Final_main.cpp -o FinalGame

Space.o: Space.cpp Space.hpp
	${CXX} ${CXXFLAGS} -c Space.cpp

EmptySpace.o: EmptySpace.cpp EmptySpace.hpp
	${CXX} ${CXXFLAGS} -c EmptySpace.cpp

Player.o: Player.cpp Player.hpp
	${CXX} ${CXXFLAGS} -c Player.cpp

FinalGame.o: FinalGame.cpp FinalGame.hpp
	${CXX} ${CXXFLAGS} -c FinalGame.cpp

Handcuffs.o: Handcuffs.cpp Handcuffs.hpp
	${CXX} ${CXXFLAGS} -c Handcuffs.cpp

Flashlight.o: Flashlight.cpp Flashlight.hpp
	${CXX} ${CXXFLAGS} -c Flashlight.cpp

Trap.o: Trap.cpp Trap.hpp
	${CXX} ${CXXFLAGS} -c Trap.cpp

Armor.o: Armor.cpp Armor.hpp
	${CXX} ${CXXFLAGS} -c Armor.cpp 

intVal.o: intVal.cpp intVal.hpp
	${CXX} ${CXXFLAGS} -c intVal.cpp

choiceFunction.o: choiceFunction.cpp choiceFunction.hpp
	${CXX} ${CXXFLAGS} -c choiceFunction.cpp

clean:
	rm *.o FinalGame

#target(what to create): dependencies(what is used to make)
#(tab)action(rule to build)
