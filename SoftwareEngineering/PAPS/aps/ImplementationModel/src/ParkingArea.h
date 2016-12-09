class Bay;
class Spot;
class Car;
class PAPS;
#include <vector>
#include <string>
class ParkingArea{
public:
	ParkingArea();
	void assignBay(Car* car);
	void assignSpot(Car* car);
private:
	// bay
	bool isBayFull();
	std::string location_;
	int numberOfBay_;
	std::vector<Bay>bays_;
	// spot
	int numberOfSpot_;
	Spot* spots_[10][10][10];
	PAPS* paps_;
};
