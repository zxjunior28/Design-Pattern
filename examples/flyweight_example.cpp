// Copyright (c) 2023 Katelyn Bai
#include <flyweight/flyweight.hpp>

int main(int argc, char **argv) {
    using architecture::flyweight::FlyweightFactory;
    using architecture::flyweight::CarType;
    

    // std::cout << "hi! flyweight~" << std::endl;

    FlyweightFactory *factory = new FlyweightFactory({{"AUDI", "Q5", "white"},
    {"Mercedes Benz", "C300", "black"}, {"BMW", "M5", "red"}});

    factory->ListFlyweights();

    AddCarToDatabase(*factory,
                    "CL234IR",
                    "James Doe",
                    "BMW",
                    "M5",
                    "red");

    AddCarToDatabase(*factory,
                    "CL888IR",
                    "James Doe",
                    "BMW",
                    "X1",
                    "white");
    factory->ListFlyweights();
    delete factory;

    return 0;

    return 0;
}
