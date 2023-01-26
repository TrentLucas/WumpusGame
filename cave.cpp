// cave.cpp
// constructors, destructors, methods, and functions for the Cave class
/////////////////////////////////////////////////////////////////

#include "cave.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;



//////////////////////////////////////////
// Constructor
//////////////////////////////////////////
Cave::Cave(int numB, int numP, int wumpusT) {

	srand(time(NULL));

	numBats = numB;
	if (numBats > 19) {
		numBats = 19;
	}

	numPits = numP;
	if (numPits > 19) {
		numPits = 19;
	}

	wumpusTiredness = wumpusT;

	setUpCave();
}

//////////////////////////////////////////
// Destructor
//////////////////////////////////////////
Cave::~Cave() {

	numBats = 0;
	numPits = 0;
	wumpusTiredness = 0;
	roomNumber = 0;
	playerHealth = 0;
	arrowCount = 0;
	

	delete [] cave;
}



///////////////////////////////////////////////////////
//  				          	     //
//                  Private Methods                  //
//                                                   //
///////////////////////////////////////////////////////



//////////////////////////////////////////
// setUpCave. Set variables, call setBats(),
// setPits(), and setWumpus()
//
// start the main game function
//////////////////////////////////////////
void Cave::setUpCave() {

	cave = new Room[20];

	roomNumber = 0;
	playerHealth = 1;
	arrowCount = 2;
	setBats();
	setPits();
	setWumpus();

	checkNearbyRooms();	
}

//////////////////////////////////////////
// setBats. place bats
//////////////////////////////////////////
void Cave::setBats() {

	for (int i = 0; i < numBats; i++) {
		int r1 = getRandom(19) + 1; // cannot be room 0

		if (cave[r1].getBats() == false) {   // if bat is already in room, place in another
			cave[r1].setBat();
		}

		else {
			i--;
		}
	}
}

//////////////////////////////////////////
// setPits. place Pits
//////////////////////////////////////////
void Cave::setPits() {

	for (int i = 0; i < numPits; i++) {
		int r1 = getRandom(19) + 1; // cannot be room 0

		if (cave[r1].getPit() == false) {   // if pit is already in room, place in another
			cave[r1].setPit();
		}

		else {
			i--;
		}
	}
}

//////////////////////////////////////////
// setWumpus. place Wumpus
//////////////////////////////////////////
void Cave::setWumpus() {
	int r1 = getRandom(19) + 1; // cannot be room 0
	wumpus.setWumpusTiredness(wumpusTiredness);
	wumpus.changeRoom(r1);
	cout << "  Wumpus in room " << r1 << endl;
}

//////////////////////////////////////////
// *arrowCount* getter
//////////////////////////////////////////
int Cave::getArrowCount() {
	return arrowCount;
}

//////////////////////////////////////////
// random number generator
//////////////////////////////////////////
int Cave::getRandom(int value) {
	int r1 = rand() % value;
	return r1;
}

//////////////////////////////////////////
// nextTurn. wumpusTiredness-- and batHealth++
//////////////////////////////////////////
void Cave::nextTurn() {

	wumpus.changeWumpusTiredness();

	for (int i = 0; i < 20; i++) {
		cave[i].nextTurn();
	}
}

//////////////////////////////////////////
// checkNearbyRooms. check connected rooms
// if they contain bats, pits, or the Wumpus
//////////////////////////////////////////
void Cave::checkNearbyRooms() {
	cout << "You are in room " << roomNumber << endl;

	if (cave[mapping[roomNumber][0]].getBats() == true || cave[mapping[roomNumber][1]].getBats() == true || 
			cave[mapping[roomNumber][2]].getBats() == true) {
		cout << "     You hear the wings of a bat fluttering" << endl;
	}

	if (cave[mapping[roomNumber][0]].getPit() == true || cave[mapping[roomNumber][1]].getPit() == true || 
			cave[mapping[roomNumber][2]].getPit() == true) {
		cout << "     You feel a cold draft" << endl;
	}

	if (mapping[roomNumber][0] == wumpus.getRoom() || mapping[roomNumber][1] == wumpus.getRoom() || mapping[roomNumber][2] == wumpus.getRoom()) {
		cout << "     You smell a Wumpus nearby" << endl;
	}
}

//////////////////////////////////////////
// flyPlayer. calculate travel distance
// for (distance), choose a random connect room to move
// the player 
//
// return new room
//////////////////////////////////////////
int Cave::flyPlayer(int batHealth, int temp) {

	int distance = (batHealth % 3) + 1;

	for (int i = 0; i < distance; i++) {
		int r1 = getRandom(3);
		temp = mapping[temp][r1];
	}
	nextTurn();

	return temp;
}

//////////////////////////////////////////
// wumpusEat. checks if Wumpus is in room
// if so, the wumpus may eat the player
// or run away based on wumpusTiredness
//////////////////////////////////////////
void Cave::wumpusEat() {

	// if current room contains the Wumpus
	if (roomNumber == wumpus.getRoom()) {

		// if wumpusTiredness = 0
		if (wumpus.getWumpusTiredness() == 0) {
			playerHealth = 0;
			cout << "     The Wumpus ate you!" << endl;

			return;
		}

		// if WumpusTiredness != 0
		if (getRandom(wumpus.getWumpusTiredness()) == 0) { 
			playerHealth = 0;
			cout << "     The Wumpus unluckily ate you!" << endl;
		}

		// Wumpus runs away
		else {
			int r1 = getRandom(20);

			while (r1 == roomNumber) {
				r1 = getRandom(20);
			}

			wumpus.changeRoom(r1);
			cout << "     The Wumpus ran away" << endl << endl;
			cout << "  Wumpus in room " << r1 << endl << endl;
		}
	}
}



///////////////////////////////////////////////////////
//  				          	     //
//                  Public Methods                   //
//                                                   //
///////////////////////////////////////////////////////



//////////////////////////////////////////
// *playerHealth* setter
//////////////////////////////////////////
void Cave::setPlayerHealth(int value) {
	playerHealth = value;
}

//////////////////////////////////////////
// *playerHealth* getter
//////////////////////////////////////////
int Cave::getPlayerHealth() {
	return playerHealth;
}

//////////////////////////////////////////
// *wumpusHealth* getter
//////////////////////////////////////////
int Cave::getWumpusHealth() {
	return wumpus.getWumpusHealth();
}

//////////////////////////////////////////
// *roomNumber* getter
//////////////////////////////////////////
int Cave::getRoom() {
	return roomNumber;
}

//////////////////////////////////////////
// *roomNumber* getter
//////////////////////////////////////////
void Cave::getConnectedRooms() {
	cout << "You may go to room " << mapping[roomNumber][0] << ", room " << mapping[roomNumber][1] << 
			", room " << mapping[roomNumber][2] << endl;
}

//////////////////////////////////////////
// movePlayer. takes in the desired room to move to
//
// if the desired room is connected to the current room, 
// move the player
// if the desired room is not connected to the current room,
// return "Invalid Room Number"
//
//////////////////////////////////////////
void Cave::movePlayer( int nextRoom) {

	// if nextRoom is connected to currentRoom
	if (nextRoom == mapping[roomNumber][0] || nextRoom == mapping[roomNumber][1] || nextRoom == mapping[roomNumber][2]) {

		roomNumber = nextRoom;
		nextTurn();   // identify the turn has been completed
		
		// if currentRoom has bats
		while (cave[roomNumber].getBats() == true) {

			// bat flys player
			int temp = roomNumber;
			roomNumber = flyPlayer(cave[roomNumber].bat.getBatHealth(), roomNumber);
			cave[temp].bat.setBatHealthDefault(); 

			// if the new room contains a Wumpus, it runs away
			if (temp == wumpus.getRoom()) {
				int r1 = getRandom(20);
				while (r1 == roomNumber) {
					r1 = getRandom(20);
				}
				wumpus.changeRoom(r1);
				cout << "     The noise of the bat woke the Wumpus. The Wumpus ran away" << endl;
				cout << "  Wumpus in room " << r1 << endl << endl;
			}

			cout << "     A giant Bat picks you up and drops you in room " << roomNumber << endl << endl;
		}


		// if currentRoom is a pit
		if (cave[roomNumber].getPit() == true) {
			playerHealth = 0;
			cout << "     You have fallen into a pit. You are dead" << endl;
			return;
		}


		// if currentRoom has the Wumpus
		if (roomNumber == wumpus.getRoom() && playerHealth != 0) {
			wumpusEat();
		}

		if (playerHealth != 0) {
			checkNearbyRooms();
		}
	}

	else { 
		std::cout << "  Invalid Room Number" << std::endl;
	}
}

//////////////////////////////////////////
// shootArrow. check to see if the desired
// room to shoot is a connected room 
// and has the Wumpus inside
//
// if not, arrowCount--
//
// if arrowCount = 0, playerHealth = 0
//////////////////////////////////////////
void Cave::shootArrow(int roomToShoot) {

	// roomToShoot is a connected room && Wumpus is in roomToShoot
	if ((roomToShoot == mapping[roomNumber][0] || roomToShoot == mapping[roomNumber][1] || roomToShoot == mapping[roomNumber][2])
		       	&& roomToShoot == wumpus.getRoom()) {
	
		wumpus.wumpusDead();
		cout << "     You killed the Wumpus! You win" << endl;
		return;
	}

	else {
	
		cout << "     Your arrow broke against the wall" << endl;
	}

	arrowCount--;

	if (arrowCount == 0) {
		playerHealth = 0; 
		cout << endl << "     You have no arrows! You lose" << endl;
	}
}
