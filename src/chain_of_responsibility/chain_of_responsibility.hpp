// Copyright (c) 2022 Katelyn Bai
#ifndef SRC_CHAIN_OF_RESPONSIBILITY_CHAIN_OF_RESPONSIBILITY_HPP_
#define SRC_CHAIN_OF_RESPONSIBILITY_CHAIN_OF_RESPONSIBILITY_HPP_

#include <architecture/definitions.hpp>

namespace architecture::chain_of_responsibility {

/* Leave application system */

/*Leave Request*/
class LeaveRequest {
 public:
    LeaveRequest(std::string name, int days) : name_(name), leave_days_(days) {}
    int getLeaveDays() const { return this->leave_days_;}
    std::string getName() const { return this->name_;}
 private:
    std::string name_;
    int leave_days_;
};


/*Abstract Handler Interface*/
class Handler {
 public:
    explicit Handler(std::string name, int days) : name_(name), days_(days) {}
    void setSuccessor(std::weak_ptr<Handler> successor) {this->successor = successor;}
    virtual void handleRequest(const LeaveRequest& request) = 0;
 protected:
    std::string name_;
    int days_;
    std::weak_ptr<Handler> successor;
};


/*Concrete Handler*/
class Manager : public Handler {
 public:
    explicit Manager(std::string name, int days) : Handler(name, days) {}
    void handleRequest(const LeaveRequest& request) override;
};

/*Concrete Handler*/
class Director : public Handler {
 public:
    explicit Director(std::string name, int days) : Handler(name, days) {}
    void handleRequest(const LeaveRequest& request) override;
};

/*Concrete Handler*/
class GeneralManager : public Handler {
 public:
    explicit GeneralManager(std::string name, int days) : Handler(name, days) {}
    void handleRequest(const LeaveRequest& request) override;
};


void Manager::handleRequest(const LeaveRequest& request) {
    if (request.getLeaveDays() < days_) {
        std::cout <<request.getName() << "'s " << request.getLeaveDays() << "-day leave is approved by "
        <<"manager "<< name_ << std::endl;
    } else {
        if (this->successor.lock() != nullptr) {
            this->successor.lock()->handleRequest(request);
        }
    }
}

void Director::handleRequest(const LeaveRequest& request) {
    if (request.getLeaveDays() < days_) {
        std::cout <<request.getName() << "'s " << request.getLeaveDays() << "-day leave is approved by "
        <<"director "<< name_ << std::endl;
    } else {
        if (this->successor.lock() != nullptr) {
            this->successor.lock()->handleRequest(request);
        }
    }
}

void GeneralManager::handleRequest(const LeaveRequest& request) {
    if (request.getLeaveDays() < days_) {
        std::cout <<request.getName() << "'s " << request.getLeaveDays() << "-day leave is approved by "
        <<"general manager "<< name_ << std::endl;
    } else {
        if (this->successor.lock() != nullptr) {
            this->successor.lock()->handleRequest(request);
        } else {
            std::cout <<request.getName() << "'s " << request.getLeaveDays() << "-day leave is not approved. ";
            std::cout << "(exceeded the "<< days_ <<" leave days per year given to an employee)" << std::endl;
        }
    }
}



}  // namespace architecture::chain_of_responsibility
#endif  // SRC_CHAIN_OF_RESPONSIBILITY_CHAIN_OF_RESPONSIBILITY_HPP_
