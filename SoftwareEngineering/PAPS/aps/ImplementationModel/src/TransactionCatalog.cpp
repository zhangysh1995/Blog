#include "TransactionCatalog.h"

void TransactionCatalog::newTransaction(){
	transactions_.push_back(new Transaction());
}
double TransactionCatalog::processTransaction(int transactionID){
	return transactions_[--transactionID]->getTotal();
}