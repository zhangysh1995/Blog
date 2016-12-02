// drink class to be used in Coffee Shack lab
// Mikhail Nesterenko
// 11/15/2016

#include <string>

enum class DrinkType {small, medim, large};

class Drink{
public:
   Drink(DrinkType type=DrinkType::small, int price=0):type_(type), price_(price){}
   virtual double getPrice() const=0;
   virtual string getName() const=0;
protected:
   double price_;
   DrinkType type_;
};
