// Copyright (c) 2022 Katelyn Bai
#ifndef SRC_DECORATOR_DECORATOR_HPP_
#define SRC_DECORATOR_DECORATOR_HPP_

#include <architecture/definitions.hpp>

namespace architecture::decorator {

/* Interface ( Abstract class  with pure virtual function)*/
class Spaghetti {
 public:
    virtual ~Spaghetti() = default;
    virtual std::string GetName() const = 0;
    virtual int  GetPrice() const = 0;
};

class BeefSpaghetti : public Spaghetti {
 public:
  std::string GetName() const override {
    return std::string("Beef Spaghetti");
  }

  int GetPrice() const override {
    return 120;
  }
};


/*Condiment Docorator */
class Condiment : public Spaghetti {
 public:
  explicit Condiment(Spaghetti* spaghetti) : spaghetti_(spaghetti) {}
  std::string GetName() const override {
    return spaghetti_->GetName();
  }

  int GetPrice() const override {
    return spaghetti_->GetPrice();
  }
 protected:
    Spaghetti* spaghetti_;
};

class Cheese : public Condiment {
 public:
  explicit Cheese(Spaghetti* spaghetti) : Condiment(spaghetti) {}  // Initialize at the same time
  std::string GetName() const override {
    return (spaghetti_->GetName() + " + Cheese");
  }

  int GetPrice() const override {
    return (spaghetti_->GetPrice() + 25);
  }
};

class Ham : public Condiment {
 public:
  explicit Ham(Spaghetti* spaghetti) : Condiment(spaghetti) {}  // Initialize at the same time
  std::string GetName() const override {
    return (spaghetti_->GetName() + " + Ham");
  }

  int GetPrice() const override {
    return (spaghetti_->GetPrice() + 50);
  }
};

}  // namespace architecture::decorator
#endif  // SRC_DECORATOR_DECORATOR_HPP_
