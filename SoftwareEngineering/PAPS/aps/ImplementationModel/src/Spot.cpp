#include "Spot.h"
#include <cstddef>

void Spot::assignCar(Car* car){
	car_ = car;
	car_->setSpotNumber(spotNumber_);
}
void Spot::moveCar(){
	if(isOccupied()) car_ = nullptr;
}

bool Spot::isOccupied(){
	return car_ == nullptr;
}