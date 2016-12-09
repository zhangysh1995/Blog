#include "MemberCatalog.h"

MemberCatalog::MemberCatalog(){
	int myID = 0001;
	memberList_.push_back(new Member(myID));
}
bool MemberCatalog::isMember(int memberID){
	for (auto it: memberList_){
		if(it->getMemberID() == memberID) return true;
	}
	// if(it == *memberList.end()) 
	return false;
}