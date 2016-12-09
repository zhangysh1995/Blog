#include <string>
class User{
public:
	User(std::string firstName="", std::string lastName="", std::string lisenceNo="default"):
		firstName_(firstName), lastName_(lastName), lisenceNo_(lisenceNo){}
	std::string getFirstName();
	std::string getLastName();
	std::string getLisenceNo();
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setLisenceNo(std::string lisenceNo);
private:
	std::string firstName_;
	std::string lastName_;
	std::string lisenceNo_;
};