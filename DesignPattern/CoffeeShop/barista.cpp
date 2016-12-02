// Author: Yushan Zhang

#include "customer.cpp"

class Barista{
public:
	Barista(Barista* successor):successor_(successor){}
	// register orders/customers; get new order
	virtual void attach(Customer* order){
		if(successor_ != nullptr) successor_->attach(order);
		else cout << "======No one could make this coffee======";
	}
	// if order is done, deregister it
	virtual void detach(Customer* order){orders_.pop_front();}
	// notify customer's coffee is done
	virtual void notify(Customer* order){
		order->notify();
		detach(order);
	}
	// make coffee
	virtual void make(){
		for (auto &it: orders_){
			cout << it->getName() << "'s Coffee is done...... ";
			notify(it);
		}
		if(successor_ != nullptr) successor_ -> make();
	}
protected:
	list<Customer* > orders_;
	Barista* successor_;
};

class Manager: public Barista{
public:
	Manager(Barista* successor=nullptr):Barista(successor){}
	// manager prepares all coffee
	void attach(Customer* order){
		orders_.push_back(order);
		cout << "\nManager gets this order, ";
	}
};

class  SeniorBarista: public Barista{
public:
	SeniorBarista(Barista* successor=nullptr):Barista(successor){}
	void attach(Customer* order){
		string ingred = order->getIngred();
		// senior prepares coffee without milk foam
		if(ingred.find('f')!= string::npos) Barista::attach(order);
		else{
			orders_.push_back(order);
			cout << "\nSenior barista gets this order, ";
		}
	}
};

class JuniorBarista: public Barista{
public:
	JuniorBarista(Barista* successor=nullptr):Barista(successor){}
	void attach(Customer* order){
		string ingred = order->getIngred();
		// junior only prepares coffee without ingredients
		if(ingred != "") Barista::attach(order);
		else{
			orders_.push_back(order);
			cout << "\nJunior barista gets this order, ";
		}
	}
};