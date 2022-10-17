// Copyright (c) 2022 Katelyn Bai
#ifndef SRC_FACTORY_ABSTRACT_FACTORY_HPP_
#define SRC_FACTORY_ABSTRACT_FACTORY_HPP_

#include <architecture/definitions.hpp>

namespace architecture::abstractfactory {

/* Interface ( Abstract class  with pure virtual function)*/
// product 1
class Archer {
 public:
    virtual ~Archer() {}
    virtual std::string getType() const = 0;
    // virtual std::string getType() const = 0;
};

// Concrete Product
class IceArcher : public Archer {
 public:
    std::string getType() const override {
        return type_;
    }
 private:
    std::string type_{"IceArcher"};
};

// Concrete Product
class FireArcher : public Archer {
 public:
    std::string getType() const override {
        return type_;
    }
 private:
    std::string type_{"FireArcher"};
};

/* Interface ( Abstract class  with pure virtual function)*/
// product 2
class Warrior {
 public:
    virtual ~Warrior() {}
    virtual std::string getType() const = 0;
};

// Concrete Product
class IceWarrior : public Warrior {
 public:
    std::string getType() const override {
        return type_;
    }
 private:
    std::string type_{"IceWarrior"};
};

// Concrete Product
class FireWarrior : public Warrior {
 public:
    std::string getType() const override {
        return type_;
    }
 private:
    std::string type_{"FireWarrior"};
};

// Factory by character attribute
class CharacterFactory {
 public:
    using archer_ptr_type = std::shared_ptr<Archer>;
    using warrior_ptr_type = std::shared_ptr<Warrior>;
    virtual ~CharacterFactory() {}
    virtual archer_ptr_type CreateArcher() = 0;
    virtual warrior_ptr_type CreateWarrior() = 0;
};

class IceCharacterFactory : public CharacterFactory {
 public:
    archer_ptr_type CreateArcher() override {
        return std::make_shared<IceArcher>();
    }

    warrior_ptr_type CreateWarrior() override {
        return std::make_shared<IceWarrior>();
    }
};

class FireCharacterFactory : public CharacterFactory {
 public:
    archer_ptr_type CreateArcher() override {
        return std::make_shared<FireArcher>();
    }

    warrior_ptr_type CreateWarrior() override {
        return std::make_shared<FireWarrior>();
    }
};


}  // namespace architecture::factory
#endif  // SRC_FACTORY_ABSTRACT_FACTORY_HPP_
