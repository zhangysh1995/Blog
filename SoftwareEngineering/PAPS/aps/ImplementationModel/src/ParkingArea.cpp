#include "ParkingArea.h"
#include "PAPS.cpp"
#include "Bay.h"
#include <algorithm>
#include <iostream>
ParkingArea::ParkingArea(): numberOfBay_(10), numberOfSpot_(1000),
	location_("Default Location"){
		paps_ = new PAPS();
		for(int i = 0; i <= numberOfBay_; ){
			Bay newBay(++i);			
			bays_.push_back(newBay);
		}
		for(int i=0; i<10;i++){
			for(int j=0; j<10; j++){
				for(int k=0; k<10; k++){
					if(i==0&&j==0) spots_[i][j][k] = nullptr;
					else spots_[i][j][k] = new Spot();
				}
			}
		}
	}
bool ParkingArea::isBayFull(){
	int bayIsEmpty = count_if(bays_.cbegin(),bays_.cend(),
							[=](Bay bay){return bay.isOccupied();});
	return bayIsEmpty > 0;
}

void ParkingArea::assignBay(Car* car){
	if(isBayFull()){
		Bay *bay;
		for(auto& it: bays_){
			if(it.isOccupied()){
				it.changeState(car);
				bay = &it;
				break;
			}
		}
	}else std::cout << "Bays are full! Wait" << std::endl;		
}

void ParkingArea::assignSpot(Car* car){
	paps_->assignSpot(car, spots_);
}