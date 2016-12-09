#include "Member.h"
#include <vector>

class MemberCatalog{
public:
	MemberCatalog();
	bool isMember(int memberID);
private:
	std::vector<Member* >memberList_;
};