#include "Transaction.h"
#include <vector>
class TransactionCatalog{
public:
	void newTransaction();
	double processTransaction(int transactionID);
private:
	std::vector<Transaction* >transactions_;
	static int transactionNo;
};