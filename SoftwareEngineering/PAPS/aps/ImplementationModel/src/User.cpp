#include "User.h"

std::string User::getFirstName(){
	return firstName_;
}
std::string User::getLastName(){
	return lastName_;
}
std::string User::getLisenceNo(){
	return lisenceNo_;
}
void User::setFirstName(std::string firstName){
	firstName_ = firstName;
}
void User::setLastName(std::string lastName){
	lastName_ = lastName;
}
void User::setLisenceNo(std::string lisenceNo){
	lisenceNo_ = lisenceNo;
}