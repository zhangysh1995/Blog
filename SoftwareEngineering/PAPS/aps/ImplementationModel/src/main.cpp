#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "ParkingArea.cpp"
#include "GuideSystem.h"
#include "Kiosk.h"
#include "Logger.h"

using std::cout; using std::endl; using std::cin;
using std::string;

int main() {

	ParkingArea lot;
	GuideSystem guide;
	Car *car;

	Logger& logger = Logger::instance();
	logger.report("Begain\n");

	cout << "\nWelcome to parking system! " << endl;
	cout << "======================================\n";

	lot.assignBay(car);
	cout << "\nYou are assigned bay number: " << car->getBayNumber();
	logger.report("Assigned bay\n");

	cout << "\nCar is moving into the bay...\n";

	cout << "\nDemo of guidance system: \n";
	cout << "If vehicle is not in correct area: " 
		<< guide.showGuidance(1);
	cout << "If vehivle is not empty: "
		<< guide.showGuidance(2);
	cout << "\nSystem guides user to move the vehicle and get off.\n\n";

	cout << "==========Guide system is UI layer now==========" << endl;
	logger.report("Start collect info... \n");


	cout << "Reading user information from file......wait......" <<endl;
	std::ifstream info("./input/input.txt");
	string first; info >> first;
	string last; info >> last;
	string lisence; info >> lisence;
	int memberID; info >> memberID;

	User *me = new User(first, last, lisence);
	logger.report("Info collected...\n");
	Kiosk *kiosk = new Kiosk();
	cout << "Verify membership: " << 
		(kiosk->verifyMember(memberID) ? "Yes" : "No ") <<endl;
	cout << "Verify card: " << (kiosk->verifyCard()? "Yes" : "No")<<endl;
	logger.report("Payment method verified...\n");

	cout << "\n==========Start parking car==========" <<endl;
	lot.assignSpot(car);
	cout << "You are assigned spot number: " << car->getSpotNumber() <<endl;
	logger.report("Assigned spot\n");
	
	// detail implementation not done yet
	cout << "\n========Start retrieving car========" <<endl;
	// transaction class is constructed but no details on pyment process
	cout << "Car is retrived to bay, payment is processed " <<endl;

	cout << "\nSee output/log.txt for history\n\n";
	return 0;
}
