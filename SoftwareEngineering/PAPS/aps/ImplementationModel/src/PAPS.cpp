#include "PAPS.h"
#include "Spot.cpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
void PAPS::assignSpot(Car* car, Spot* spots[10][10][10]){ 
	std::srand(std::time(nullptr));
	int floorNo = 0, row = 0, column = 0;
	Spot * spot = nullptr;
	while(true){
		floorNo = rand()%10;
		row = rand()%10;
		column = rand()%10;
		if(floorNo==0 && row==0) continue;

		spot = spots[floorNo][row][column];
		if(spot == nullptr) continue;

		if(spot->isOccupied()) {
			spot->assignCar(car);
			break;
		}
		else continue;
	}
}