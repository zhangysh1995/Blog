// Author: Yushan Zhang
class Coffee;

class Customer{
public:
	Customer(string name, Coffee* order, string ingredList):
		name_(name), order_(order), ingredList_(ingredList){}
	string getName(){return name_;}
	Coffee* getCoffee(){return order_;}
	string getIngred(){return ingredList_;}
	void notify(){cout << "This is my coffee. " << getName() <<endl;}
private: 
	string name_;
	Coffee *order_;
	string ingredList_;
};