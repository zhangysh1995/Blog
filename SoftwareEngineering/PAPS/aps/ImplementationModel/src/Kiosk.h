#include "MemberCatalog.h"
#include "TransactionCatalog.h"

class Kiosk{
public:
	Kiosk();
	bool verifyCard(std::string carNumber="");
	bool verifyMember(int MemberID);
	void processTransaction(int transactionID);
private:
	void newTransaction();
	MemberCatalog *memberCatalog_;
	TransactionCatalog *transactionCatalog_;
};