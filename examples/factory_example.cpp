// Copyright (c) 2022 Katelyn Bai
#include <factory/factory.hpp>
#include <factory/simple_factory.hpp>
#include <factory/abstract_factory.hpp>



int main(int argc, char **argv) {
    using architecture::factory::CharacterFactory;
    using architecture::factory::CharacterTYPE;

    /*Simple Factory*/
    CharacterFactory characterFactory;
    auto Kavy = characterFactory.CreateCharacter(CharacterTYPE::ARCHER);
    std::cout << "Kavy is the " << Kavy->getType() << std::endl;

    auto Jacky = characterFactory.CreateCharacter(CharacterTYPE::WARRIOR);
    std::cout << "Jacky is the " << Jacky->getType() << std::endl;

    return 0;
}
