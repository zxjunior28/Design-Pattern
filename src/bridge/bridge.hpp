// Copyright (c) 2022 Katelyn Bai
#ifndef SRC_BRIDGE_BRIDGE_HPP_
#define SRC_BRIDGE_BRIDGE_HPP_

#include <architecture/definitions.hpp>

namespace architecture::bridge {

/*Implementation Interface*/
class TvFunction {
 public:
    virtual ~TvFunction() {}
    virtual void turnOn() const = 0;
    virtual void turnOff() const = 0;
    virtual void setChannel(int channel) = 0;
};

/*Implementation*/
class SonyTV : public TvFunction{
 public:
    void turnOn() const override;
    void turnOff() const override;
    void setChannel(int channel) override;
 
 private:
    int channel_{10};
    void switchToHome() const {}
    void switchToChannel(int channel) {channel_ = channel;}
    void displayInfo() {std::cout << "the channel is " << channel_ << std::endl;}
};

void SonyTV::turnOn() const {
    std::cout << "SONY" << std::endl;
    switchToHome();
}

void SonyTV::turnOff() const {
    std::cout << "GoodBYE" << std::endl;
}

void SonyTV::setChannel(int channel) {
    switchToChannel(channel);
    displayInfo();
}



// ------------------------------------------------- //

/*Bridge Abstraction Interface*/

class RemoteControl {
 protected:
    TvFunction *tv_function_{NULL};
 public:
    explicit RemoteControl(TvFunction *tv_function) : tv_function_(tv_function) {}
    virtual ~RemoteControl() {}
    virtual void on() const = 0;
    virtual void off() const = 0;
    virtual void setChannel(int channel) const = 0;
};


class SonicRemoteControl : public RemoteControl {
 public:
    explicit SonicRemoteControl(TvFunction *tv_function) : RemoteControl(tv_function) {}
    void on() const override {
        tv_function_->turnOn();
    }

    void off() const override {
        tv_function_->turnOff();
    }
    void setChannel(int channel) const override {
        tv_function_->setChannel(channel);
    }
};

class SamgsungRemoteControl : public RemoteControl {
 public:
    explicit SamgsungRemoteControl(TvFunction *tv_function) : RemoteControl(tv_function) {}
    void on() const override {
        tv_function_->turnOn();
    }

    void off() const override {
        tv_function_->turnOff();
    }
    void setChannel(int channel) const override {
        tv_function_->setChannel(channel);
    }
};



}  // namespace architecture::bridge
#endif  // SRC_BRIDGE_BRIDGE_HPP_
