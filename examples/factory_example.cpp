// Copyright (c) 2022 Katelyn Bai
#include <factory/factory.hpp>
#include <factory/simple_factory.hpp>
#include <factory/abstract_factory.hpp>



int main(int argc, char **argv) {

    /*Simple Factory Pattern*/
    using architecture::simplefactory::CharacterFactory;
    using architecture::simplefactory::CharacterTYPE;

    CharacterFactory characterFactory;
    const auto& Kavy = characterFactory.CreateCharacter(CharacterTYPE::ARCHER);
    if (Kavy) std::cout << "Kavy is the " << Kavy->getType() << std::endl;

    const auto& Jacky = characterFactory.CreateCharacter(CharacterTYPE::WARRIOR);
    if (Jacky) std::cout << "Jacky is the " << Jacky->getType() << std::endl;


    std::cout << "---------------------" << std::endl;

    /*Factory Pattern*/
    using architecture::factory::ArcherProducer;
    using architecture::factory::WarriorProducer;

    const auto& archerProducer = std::make_shared<ArcherProducer>();
    const auto& Kavy2 = archerProducer->CreateCharacter();
    if (Kavy2) std::cout << "Kavy is the " << Kavy2->getType() << std::endl;

    const auto& warriorProducer = std::make_shared<WarriorProducer>();
    const auto& Jacky2 = warriorProducer->CreateCharacter();
    if (Kavy2) std::cout << "Jacky is the " << Jacky2->getType() << std::endl;
    return 0;
}
