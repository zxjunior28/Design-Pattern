// Copyright (c) 2022 Katelyn Bai
#include <composite/composite.hpp>

int main(int argc, char **argv) {

    using architecture::composite::Commodity;
    using architecture::composite::Bags;

    Bags bag("my bag");
    Commodity* Milk = new Commodity("milk", 90, 5);
    Commodity* Meet = new Commodity("chicken", 100, 1);
    Commodity* drink = new Commodity("soda", 50, 2);
    
    /*add*/
    bag.add(Milk);
    bag.add(Meet);
    bag.add(drink);
    std::cout << "the total price is " << bag.calculation() << std::endl;
    bag.show();

    /*remove*/
    bag.remove(Milk);
    std::cout << "\nthe total price is " << bag.calculation() << std::endl;
    bag.show();

    delete Milk;
    delete Meet;
    delete drink;
    return 0;
}
