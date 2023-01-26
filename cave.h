// homework05
// cave.h
//
// In this file are constructors, destructors, methods, functions, and variables
// for the Cave class
//
// This Game is a explore game that has the player search through a 
// cave looking to kill a Wumpus. The player travels throughout the rooms
// of the cave looking for the Wumpus. These rooms can also contain
// a bat or pit which will act on the player. If the player dies the game ends.
////////////////////////////////////////////////////////////////////

#ifndef CAVE_H
#define CAVE_H

#include "room.h"
#include "wumpus.h"


class Cave {
	public:
		// constructor
		Cave(int numB, int numP, int wumpusT);

		// destructor
		~Cave();

		// functions
		void setPlayerHealth(int value);
		int getPlayerHealth();
		int getWumpusHealth(); 
		int getRoom(); 
		void getConnectedRooms(); 
		void movePlayer(int nextRoom); 
		void shootArrow(int roomToShoot);

	private:

		// methods		
		void setUpCave();
		void setBats();
		void setPits();
		void setWumpus();

		int getArrowCount();
		int getRandom(int value);
		void nextTurn();
		void checkNearbyRooms();
		int flyPlayer(int batHealth, int temp);
		void wumpusEat();


		// variables
		const int mapping [20][3] = {
			{13, 16, 19}, // 0
			{2, 5, 8},    // 1
			{1, 3, 10},   // 2
			{2, 4, 12},   // 3
			{3, 5, 14},   // 4
			{1, 4, 6},    // 5
			{5, 7, 15},   // 6
			{6, 8, 17},   // 7
			{1, 7, 9},    // 8
			{8, 10, 18},  // 9
			{2, 9, 11},   // 10
			{10, 12, 19}, // 11
			{3, 11, 13},  // 12
			{12, 14, 0},  // 13
			{4, 13, 15},  // 14
			{6, 14, 16},  // 15
			{15, 17, 0},  // 16
			{7, 16, 18},  // 17
			{9, 17, 19},  // 18
			{11, 18, 0},  // 19
		};

		Room * cave;
		Wumpus wumpus;

		int numBats;
		int numPits;
		int wumpusTiredness;
	
		int roomNumber;
		int arrowCount;
		int playerHealth;


	friend class Room;
};

#endif
