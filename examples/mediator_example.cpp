// Copyright (c) 2022 Katelyn Bai
#include <mediator/mediator.hpp>


int main(int argc, char **argv) {
    using architecture::mediator::ChatRoomMediator;
    using architecture::mediator::User;

    ChatRoomMediator* Line = new ChatRoomMediator;
    User* Bob = new User("Bob");
    User* Tom = new User("Tom");
    User* Alice = new User("Alice");

    // Let Mediator associate with each ConcreteColleague
    Line->addUser(Bob);
    Line->addUser(Tom);
    Line->addUser(Alice);

    // Send Message to each User in the same group
    Bob->send("How are you?");
    Alice->send("I'm fine.");
    Tom->send("Bye!");


    // delete
    delete Line;
    delete Bob;
    delete Tom;
    delete Alice;

    return 0;
}