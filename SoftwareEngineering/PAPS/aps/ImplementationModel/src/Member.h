#include "User.h"

class Member: public User{
public:
	Member(int memberID): memberID_(memberID){}
	int getMemberID();
	void setMemberID(int memberID);
private:
	int memberID_;
};
