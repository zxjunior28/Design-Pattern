// Copyright (c) 2023 Katelyn Bai
#ifndef SRC_PROTOTYPE_PROTOTYPE_HPP_
#define SRC_PROTOTYPE_PROTOTYPE_HPP_

#include <architecture/definitions.hpp>

namespace architecture::prototype {

// Interface
class CloneAble {
 public:
  virtual std::shared_ptr<CloneAble> clone() = 0;
  virtual ~CloneAble() = default;
  virtual void show() = 0;
};

// Concrete class
class Shape : public CloneAble {
 public:
  /// Constructor
  Shape(int id, std::string name) : CloneAble(), id_(id), name_(name) {
    std::cout << "Shape() address: " << this << std::endl;
    std::cout << "Shape() id address: " << &id_ << std::endl;
    std::cout << "Shape() name address: " << &name_ << std::endl;
  }

  /// Destructor
  ~Shape() {
    std::cout << this << " Distructor called!" << std::endl;
  }

  /// Copy Constructor
  Shape(const Shape& obj) {
    this->id_ = obj.id_;
    this->name_ = obj.name_;
    std::cout << "Shape(const Shape& obj) address: " << this << std::endl;
    std::cout << "Shape(const Shape& obj) id address: " << &id_ << std::endl;
    std::cout << "Shape(const Shape& obj) name address: " << &name_ << std::endl;
  }

  /// clone : Deep copy implementation
  std::shared_ptr<CloneAble> clone() override {
    return std::make_shared<Shape> (*this);
  }

  /// Show
  void show() override {
    std::cout << "id : " << id_ << std::endl;
    std::cout << "name: " << name_.data() << std::endl;
  }

 private:
  int id_;
  std::string name_;
};


}  /// namespace architecture::prototype
#endif  // SRC_PROTOTYPE_PROTOTYPE_HPP_
