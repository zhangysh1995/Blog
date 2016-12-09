#include "Bay.h"
#include "Car.h"

Bay::Bay(int bayNumber){
	bayNumber_ = bayNumber;
	car_ = nullptr;
}
bool Bay::isOccupied(){
	return car_ == nullptr;
}

void Bay::changeState(Car* car){
	car_ = car;
	car_->setBayNumber(bayNumber_);
	if(occupied_==true)	occupied_ = false;
	else occupied_ = true;
}

int Bay::getBayNumber(){
	return bayNumber_;
}