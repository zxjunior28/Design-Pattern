// Copyright (c) 2022 LucaWei
#include <strategy/strategy.hpp>

int main(int argc, char **argv) {
    architecture::strategy::Waterball waterball;
    architecture::strategy::Colliding colliding;
    // architecture::strategy::
    architecture::strategy::Hero hero1("Kavy");
    architecture::strategy::Hero hero2("Jacky");


    // while ()
    std::cout << "[Start]" << std::endl;
    hero1.attack(hero2, waterball);
    hero2.attack(hero1, colliding);
    std::cout << "[End]" << std::endl;


    return 0;
}
