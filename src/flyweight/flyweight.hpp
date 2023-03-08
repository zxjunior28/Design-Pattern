// Copyright (c) 2023 Katelyn Bai
#ifndef SRC_FLYWEIGHT_FLYWEIGHT_HPP_
#define SRC_FLYWEIGHT_FLYWEIGHT_HPP_

#include <architecture/definitions.hpp>

namespace architecture::flyweight {
/**
 * Flyweight Design Pattern
 *
 * Intent: Lets you fit more objects into the available amount of RAM by sharing
 * common parts of state between multiple objects, instead of keeping all of the
 * data in each object.
 */

/// The pattern extracts the repeating intrinsic state from a main Car class and moves it into the flyweight class CarType.

// shared state (instrinsic Data)
struct CarType {
  std::string brand_;
  std::string model_;
  std::string color_;

  CarType(const std::string &brand, const std::string &model, const std::string &color)
  : brand_(brand), model_(model), color_(color) {
  }

  friend std::ostream &operator<<(std::ostream &os, const CarType &ss) {
      return os << "[ " << ss.brand_ << " , " << ss.model_ << " , " << ss.color_ << " ]";
  }
};

// unique state (extrinsic Data)
struct Car {
  std::string owner_;
  std::string plates_;
  Car(const std::string &owner, const std::string &plates)
    : owner_(owner), plates_(plates) {
  }

  friend std::ostream &operator<<(std::ostream &os, const Car &car) {
    return os << "[ " << car.owner_ << " , " << car.plates_ << " ]";
  }
};


/**
 * The Flyweight stores a common portion of the state (also called intrinsic
 * state) that belongs to multiple real business entities. The Flyweight accepts
 * the rest of the state (extrinsic state, unique for each entity) via its
 * method parameters.
 */

class Flyweight {
 private:
  CarType *car_type_;
 public:
  explicit Flyweight(const CarType *car_type) : car_type_(new CarType(*car_type)) {}
  /// Copy constructors
  Flyweight(const Flyweight &other) : car_type_(new CarType(*other.car_type_)) {}
  ~Flyweight() {
    delete car_type_;
  }
  CarType* getCarType() const {
        return car_type_;
  }
  void Operation(const Car &car) const {
    std::cout << "Flyweight: Displaying car shared infomation(" << *car_type_ << ") and car unique information(" << car << ") state.\n";
  }
};


/**
 * The Flyweight Factory creates and manages the Flyweight objects. It ensures
 * that flyweights are shared correctly. When the client requests a flyweight,
 * the factory either returns an existing instance or creates a new one, if it
 * doesn't exist yet.
 */
class FlyweightFactory {
 private:
  std::unordered_map<std::string, Flyweight> flyweights_;
  std::string generate_key(const CarType &ct) const {
    return ct.brand_+"_"+ct.model_+"_"+ct.color_;
  }

 public:
  FlyweightFactory(std::initializer_list<CarType> car_type) {
    for (const CarType &ct : car_type) {
      this->flyweights_.insert(std::make_pair(this->generate_key(ct), Flyweight(&ct)));
    }
  }

  /**
    * Returns an existing Flyweight with a given state or creates a new one.
  */
  Flyweight GetFlyweight(const CarType &car_type) {
    std::string key = this->generate_key(car_type);
    if (this->flyweights_.find(key) == this->flyweights_.end()) {
      std::cout << "FlyweightFactory: Can't find a flyweight, creating new one.\n";
      this->flyweights_.insert(std::make_pair(key, Flyweight(&car_type)));
    } else {
      std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
    }
    return this->flyweights_.at(key);
  }

  void ListFlyweights() const {
    size_t count = this->flyweights_.size();
    std::cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";
    for (std::pair<std::string, Flyweight> pair : this->flyweights_) {
      std::cout << pair.first << "\n";
    }
  }
};

// Client code
void AddCarToDatabase(
    FlyweightFactory& ff, const std::string& plates, const std::string& owner,
    const std::string& brand, const std::string& model, const std::string& color) {
    std::cout << "\nClient: Adding a car to database.\n";
    const Flyweight &flyweight = ff.GetFlyweight({brand, model, color});
    // The client code either stores or calculates extrinsic state and passes it
    // to the flyweight's methods.
    flyweight.Operation({owner, plates});
}



}  /// namespace architecture::flyweight
#endif  // SRC_FLYWEIGHT_FLYWEIGHT_HPP_
