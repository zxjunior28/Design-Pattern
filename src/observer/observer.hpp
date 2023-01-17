// Copyright (c) 2023 Katelyn Bai
#ifndef SRC_OBSERVER_OBSERVER_HPP_
#define SRC_OBSERVER_OBSERVER_HPP_

#include <architecture/definitions.hpp>

namespace architecture::observer {

/*Abstract Interface*/
class IObserver {
 public:
  virtual ~IObserver() {}
  virtual void update(const string_type& msg) = 0;
};

class ISubject {
 public:
  using observer_ptr = IObserver*;
  virtual ~ISubject() {}
  virtual void add(const observer_ptr& ob) = 0;
  virtual void remove(const observer_ptr& ob) = 0;
  virtual void notify() = 0;
};


/*Implementation*/

class Podcast : public ISubject {
 public:
  // add subscriber
  void add(const observer_ptr& ob) override {
    observer_list_.emplace(ob);
  }
  // remove subscriber
  void remove(const observer_ptr& ob) override {
    observer_list_.erase(ob);
  }
  // notify subscribers
  void notify() override {
    for (const auto& ob : observer_list_)
      ob->update(message_);
  }
  // create message
  void createMessage(string_type msg) {
    this->message_ = msg;
  }

 private:
  std::set<IObserver*> observer_list_;
  string_type message_;
};

class Student : public IObserver {
 public:
  explicit Student(string_type name, ISubject& subject) : name_(name), subject_(subject) {
    this->subject_.add(this);
  }
  void update(const string_type& msg) override {
    std::cout << "Observer \"" << this->name_ << "\": a new message is available --> " << msg << "\n";
  }
  void removeMeFromTheList() {
    subject_.remove(this);
    std::cout << "Observer \"" << this->name_ << "\" removed from the list.\n";
  }
 private:
  ISubject& subject_;
  string_type name_;
};

}  /// namespace architecture::observer
#endif  // SRC_OBSERVER_OBSERVER_HPP_
