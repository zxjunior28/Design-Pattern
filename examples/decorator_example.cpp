// Copyright (c) 2022 LucaWei
#include <decorator/decorator.hpp>

int main(int argc, char **argv) {

    auto beef_spaghetti = new architecture::decorator::BeefSpaghetti;
    std::cout << "[Name] " << beef_spaghetti->GetName() << std::endl;
    std::cout << "  Price is  " << beef_spaghetti->GetPrice() << std::endl;


    auto cheese = new architecture::decorator::Cheese(beef_spaghetti);
    std::cout << "[Name] " <<  cheese->GetName() << std::endl;
    std::cout << "  Price is " << cheese->GetPrice() << std::endl;



    auto ham = new architecture::decorator::Ham(cheese);
    std::cout << "[Name] " <<  ham->GetName() << std::endl;
    std::cout << "  Price is " << ham->GetPrice() << std::endl;


    // only double cheese
    auto cheese2 = new architecture::decorator::Cheese(cheese);
    std::cout << "[Name] " <<  cheese2->GetName() << std::endl;
    std::cout << "  Price is " << cheese2->GetPrice() << std::endl;


    delete beef_spaghetti;
    delete cheese;
    delete ham;


    return 0;
}
