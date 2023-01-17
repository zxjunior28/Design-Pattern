// Copyright (c) 2023 Katelyn Bai
#include <observer/observer.hpp>

int main(int argc , char **argv) {
    using architecture::observer::Podcast;
    using architecture::observer::Student;

    Podcast* podcast = new Podcast;
    Student* studentA = new Student("studentA", *podcast);
    Student* studentB = new Student("studentB", *podcast);
    Student* studentC = new Student("studentC", *podcast);


    podcast->createMessage("Hello podcast! :D");
    podcast->notify();

    studentB->removeMeFromTheList();
    podcast->notify();


    delete podcast;
    delete studentA;
    delete studentB;
    delete studentC;

    return 0;
}