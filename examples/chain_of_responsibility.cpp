// Copyright (c) 2022 Katelyn Bai
#include <chain_of_responsibility/chain_of_responsibility.hpp>



int main(int argc, char **argv) {
    using architecture::chain_of_responsibility::LeaveRequest;
    using architecture::chain_of_responsibility::Handler;
    using architecture::chain_of_responsibility::Manager;
    using architecture::chain_of_responsibility::Director;
    using architecture::chain_of_responsibility::GeneralManager;


    std::shared_ptr<Handler> manager_ptr, director_ptr, generalmanager_ptr;
    manager_ptr = std::make_shared<Manager>("Wang");
    director_ptr = std::make_shared<Director>("Chang");
    generalmanager_ptr = std::make_shared<GeneralManager>("Lin");

    /*set successor*/
    manager_ptr->setSuccessor(director_ptr);
    director_ptr->setSuccessor(generalmanager_ptr);

    /*Request*/
    auto request1 = std::make_shared<LeaveRequest>("Katelyn", 2);
    manager_ptr->handleRequest(*request1);

    auto request2 = std::make_shared<LeaveRequest>("Katelyn", 5);
    manager_ptr->handleRequest(*request2);

    auto request3 = std::make_shared<LeaveRequest>("Katelyn", 10);
    manager_ptr->handleRequest(*request3);

    auto request4 = std::make_shared<LeaveRequest>("Katelyn", 15);
    manager_ptr->handleRequest(*request4);



    return 0;
}