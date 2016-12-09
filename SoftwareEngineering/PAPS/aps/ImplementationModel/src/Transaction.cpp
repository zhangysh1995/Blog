#include "Transaction.h"

int Transaction::transactionCount_ = 0;
Transaction::Transaction(int memberID){
	memberID_ = memberID; 
	total_ = 0;
	transactionID_ = ++transactionCount_;
	endTime_ = startTime_ = std::time(nullptr);
}
double Transaction::getTotal(){
	endTime_ = std::time(nullptr);
	//calculate total and return
	return total_;
}
int Transaction::getID(){
	return transactionID_;
}