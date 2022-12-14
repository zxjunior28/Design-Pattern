// Copyright (c) 2022 Katelyn Bai
#ifndef SRC_MEDIATOR_MEDIATOR_HPP_
#define SRC_MEDIATOR_MEDIATOR_HPP_

#include <architecture/definitions.hpp>

namespace architecture::mediator {

class IUser;

/**
 * IChatRoomMediator is the Mediator interface, declares a method used by components to notify the
 * mediator about various events. The Mediator may react to these events and
 * pass the execution to other components.
 */
class IChatRoomMediator {
 public:
  virtual void addUser(IUser *sender) = 0;
  virtual void notify(IUser *sender, std::string msg) = 0;
};


/**
 * IUser is the Colleague provides the basic functionality of storing a mediator's
 * instance inside component objects.
 */
class IUser {
 protected:
  IChatRoomMediator *mediator_;
  string_type name_;

 public:
  explicit IUser(string_type name) : name_(name) {}
  void setMediator(IChatRoomMediator *mediator) { this->mediator_ = mediator;}
  string_type getUserName() {return name_;}
  virtual void send(string_type msg) = 0;
  virtual void receive(string_type msg) = 0;
};

/**
 * Concrete Components implement various functionality. They don't depend on
 * other components. They also don't depend on any concrete mediator classes.
 */
class User : public IUser {
 public:
  explicit User(string_type name) : IUser(name) {}
  void send(string_type msg) override {
    // Call Mediator to help it send messages to others
    mediator_->notify(this, msg);
  }
  void receive(string_type msg) override {
    std::cout << name_ << " received: " << msg << std::endl;
  }
};


/**
 * ChatRoom Mediator implement cooperative behavior by coordinating several
 * components.
 */
class ChatRoomMediator : public IChatRoomMediator {
 private:
  std::set<IUser*> user_list_;
 public:

  void addUser(IUser *sender) override {
    user_list_.insert(sender);
    sender->setMediator(this);
  }

  // Send the message sent by the user to other people in the chat room
  void notify(IUser *sender, std::string msg) override {
    for (const auto& user : user_list_) {
      if (user->getUserName() != sender->getUserName())
        user->receive(msg);
    }
  }

};


}  /// namespace architecture::mediator
#endif  // SRC_MEDIATOR_MEDIATOR_HPP_
