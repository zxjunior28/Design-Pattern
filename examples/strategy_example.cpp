// Copyright (c) 2022 LucaWei
#include <strategy/strategy.hpp>

int main(int argc, char **argv) {

    auto waterball = std::make_shared<architecture::strategy::Waterball>();
    auto colliding = std::make_shared<architecture::strategy::Colliding>();

    architecture::strategy::Hero hero1("Kavy", waterball);
    architecture::strategy::Hero hero2("Jacky", colliding);

    std::cout << "[Start 2]" << std::endl;
    hero1.attack(hero2);
    hero2.attack(hero1);
    std::cout << "[End 2]" << std::endl;


    return 0;
}
