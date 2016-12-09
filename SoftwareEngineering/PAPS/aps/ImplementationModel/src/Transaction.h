#include <ctime>
class Transaction{
public:
	Transaction(int memberID=-1);
	double getTotal();
	int getID();
private:
	std::time_t startTime_;
	std::time_t endTime_;
	double total_;
	int memberID_;
	int transactionID_;
	static int transactionCount_;
};