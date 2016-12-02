// Author: Yushan Zhang

#include "drink.h"

class Coffee: public Drink{
public:
	Coffee(DrinkType type=DrinkType::small, Drink* ingred=nullptr);
	virtual double getPrice() const;
	virtual string getName() const;
protected:
	Drink* ingred_;
	string name_;
};

Coffee::Coffee(DrinkType type, Drink* ingred){
	ingred_ = ingred;
	type_ = type;
	if(type_ == DrinkType::small){ price_ = 1; name_ = "small coffee "; }
	else if(type_ == DrinkType::medim){ price_ = 2; name_ = "medium coffee"; }
	else{ price_ =3; name_ = "large coffee"; }
}

double Coffee::getPrice() const { 
	if(ingred_!=nullptr) return price_+ ingred_->getPrice();
	else return price_;
}

string Coffee::getName() const {
	string name = name_;
	if(ingred_ != nullptr) return name+=(ingred_ -> getName());
	else return name;
}

class Sprinkles: public Coffee{
public:
	Sprinkles(Drink* ingred){price_ = 0.5; ingred_ = ingred; name_ = "sprinkles, ";}
};

class Caramel: public Coffee{
public:
	Caramel(Drink* ingred){price_ = 0.2; ingred_ = ingred; name_ = "caramel, ";}
};

class MilkFoam: public Coffee{
public:
	MilkFoam(Drink* ingred){price_ = 0.4;ingred_ = ingred; name_ = "milk foam, ";}
};

class Ice: public Coffee{
public:
	Ice(Drink* ingred){price_ = 0.1; ingred_ = ingred; name_ = "ice, ";}
};
