// Copyright (c) 2022 Katelyn Bai
#include <builder/builder.hpp>


int main(int argc, char **argv) {

    /// Construcotr Overloading
    // using architecture::builder::Computer;
    // Computer* myComputer = new Computer("Apple", "Apple", "Apple");
    // myComputer->showInfomation();

    /// Builder Pattern
    using architecture::builder::ComputerBuilder;
    using architecture::builder::Director;

    ComputerBuilder* builder = new ComputerBuilder();
    Director* director = new Director(builder);

    director->mixSpec();
    auto computer = builder->GetComputer();
    computer->showInfomation();


    delete builder;
    delete director;

    return 0;
}