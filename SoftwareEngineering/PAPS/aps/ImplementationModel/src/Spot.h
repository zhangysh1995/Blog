#include "Car.h"

class Spot{
public:
	Spot(): spotNumber_(++spotCount_){}
	void assignCar(Car* car);
	bool isOccupied();
	void moveCar();
private:
	int spotNumber_;
	static int spotCount_;
	Car* car_;
};

int Spot::spotCount_ = 0;
