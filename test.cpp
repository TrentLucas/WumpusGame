// test.cpp
// test file for homework05
////////////////////////////////

#include "cave.h"

#include <iostream>
#include <limits>

using namespace std;



int main (int argc, char ** argv) {

	// parameters
	if (argc != 4) {
		cout << "Incorrect number of parameters. " << "Provide: <numPits> <numBats> <wumpusTiredness> " << endl;
		return (-1);
	}
	cout << "#1 param = " << stoi(argv[1]) << endl; // numBats
	cout << "#2 param = " << stoi(argv[2]) << endl; // numPits
	cout << "#3 param = " << stoi(argv[3]) << endl; // wumpusTiredness

	cout << endl;

	Cave a1(stoi(argv[1]), stoi(argv[2]), stoi(argv[3]));
	int choice;



	// main game function
	while (a1.getPlayerHealth() != 0 && a1.getWumpusHealth() != 0) {
		cout << endl;
		a1.getConnectedRooms();
		cout << "Enter Choice: ";
		cin >> choice;
		cout << endl;

		// invalid input
		while (cin.fail()) {
			
   			cin.clear();
    			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  			cout << "Invalid Input. Enter an integer" << endl << endl;
			cout << "Enter Choice: ";
  			cin >> choice;
			cout << endl;
		}

		// exit game
		if (choice == -1) {
			cout << "Game Exited." << endl;
			a1.setPlayerHealth(0);
		}

		// move to a room
		else if (choice >=0 && choice <=19) {
			a1.movePlayer(choice);
		}

		// shootArrow
		else if (choice == 20) {
			int room;
			cout << "What direction do you want to shoot your arrow?" << endl;
			cout << "Enter Room Number: ";
			cin >> room;
			cout << endl;
			a1.shootArrow(room);
		}

		else {
			cout << "Invalid Choice" << endl;
		}
	}
}
