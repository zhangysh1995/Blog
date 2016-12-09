
#include "Car.h"

bool Car::getPosition(){
	return position_;
}

bool Car::getState(){
	return state_;
}

bool Car::isEmpty(){
	return empty_ == true;
}

void Car::setBayNumber(int bayNumber = -1){
	bayNumber_ = bayNumber;
}
int Car::getBayNumber(){
	return bayNumber_;
}

void Car::setSpotNumber(int spotNumber = -1){
	spotNumber_ = spotNumber;
}

int Car::getSpotNumber(){
	return spotNumber_;
}