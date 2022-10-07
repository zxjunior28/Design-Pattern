// Copyright (c) 2022 LucaWei
#include <strategy/strategy.hpp>

int main(int argc, char **argv) {
    architecture::strategy::Waterball waterball;
    architecture::strategy::Colliding colliding;
    // architecture::strategy::
    architecture::strategy::Hero hero1("Kavy", waterball);
    architecture::strategy::Hero hero2("Jacky", colliding);


    hero1.attack(hero2);

    return 0;
}
