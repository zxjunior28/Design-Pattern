// Copyright (c) 2022 Katelyn Bai
#include <bridge/bridge.hpp>

int main(int argc, char **argv) {
    using architecture::bridge::SonyTV;
    using architecture::bridge::SamgsungRemoteControl;

    SonyTV* tv = new SonyTV;
    SamgsungRemoteControl* remote_controller = new SamgsungRemoteControl(tv);

    remote_controller->on();
    remote_controller->setChannel(50);
    remote_controller->off();

    delete tv;
    delete remote_controller;
    return 0;
}
