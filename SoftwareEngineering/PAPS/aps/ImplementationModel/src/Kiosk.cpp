#include "Kiosk.h"
#include <iostream>
Kiosk::Kiosk(){
	memberCatalog_ = new MemberCatalog();
	transactionCatalog_ = new TransactionCatalog();
}
bool Kiosk::verifyCard(std::string carNumber){
	//call external system, default is confirmed
	newTransaction();
	return true;
}

bool Kiosk::verifyMember(int memberID){
	if(memberCatalog_->isMember(memberID)){
		newTransaction();
		return true;
	}else return false;
}

void Kiosk::processTransaction(int transactionID){
	// need transaction catalog
	std::cout << transactionCatalog_->processTransaction(transactionID);
}

void Kiosk::newTransaction(){
	transactionCatalog_->newTransaction();
}