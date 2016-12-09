class Car{
public:
	bool getPosition();
	bool getState();
	bool isEmpty();
	void setBayNumber(int bayNumber);
	int getBayNumber();
	void setSpotNumber(int spotNumber);
	int getSpotNumber();
private:
	bool position_;
	bool state_;
	bool empty_;
	int bayNumber_;
	int spotNumber_;
};