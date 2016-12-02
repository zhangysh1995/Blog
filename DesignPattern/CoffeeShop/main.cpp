// Author: Yushan Zhang

#include <iostream>
#include <list>
using std::string;
using std::cout; using std::cin; using std::endl;
using std::list;
#include "coffee.cpp"
#include "barista.cpp"

int main(){
	Manager mBarista;
	SeniorBarista sBarista(&mBarista);
	JuniorBarista jBarista(&sBarista);

	Coffee* myCoffee;
	string name; 
	string ingredList;

	// ask customer to choose coffee size
	while(true){
		ingredList = "";
		char size;
		cout << "Welcome to Coffee Shack, "
			<< "can I get you [l]arge, [m]edium, [s]mall coffee, or [n]ot? ";
		cin >> size; if(size=='n') break;
		switch(size){
			case 's': myCoffee = new Coffee(DrinkType::small);break;
			case 'm': myCoffee = new Coffee(DrinkType::medim);break;
			case 'l': myCoffee = new Coffee(DrinkType::large);break;
			default: break;
		}

		// ask customer to add ingredients
		Coffee *addIngred;
		char ingred; 
		while(true){
			cout << "Would you like to add [s]prinkles, [c]aramel, "
				<< "milk [f]oam, [i]ce or [n]ot? " ;
			cin >> ingred;

			if(ingred=='n') break;
			// decorator design pattern
			switch(ingred){
				case 's': ingredList.append("s"); 
				addIngred = new Sprinkles(myCoffee);myCoffee = addIngred;break;
				case 'c': ingredList.append("c");
				addIngred = new Caramel(myCoffee);myCoffee = addIngred;break;
				case 'f': ingredList.append("f");
				addIngred = new MilkFoam(myCoffee);myCoffee = addIngred;break;
				case 'i': ingredList.append("i");
				addIngred = new Ice(myCoffee);myCoffee = addIngred;break;
				default: break;
			}
		}
		cout << "\nYour ingredients list: " << myCoffee->getName() << endl;
		cout << "Could I have your name? ";
		cin >> name; jBarista.attach(new Customer(name, myCoffee, ingredList));
		cout << "your total is: " << myCoffee->getPrice() <<endl;
		cout << "\n========== Next customer... ==========" <<endl;		
	}
	jBarista.make();
}
