class Car;

class Bay{
public:
	Bay(int bayNumber);
	bool isOccupied();
	int getBayNumber();
	void changeState(Car* car);
private:
	int bayNumber_;
	bool occupied_;
	Car* car_;
};