// Copyright (c) 2022 Katelyn Bai
#ifndef SRC_FACTORY_SIMPLE_FACTORY_HPP_
#define SRC_FACTORY_SIMPLE_FACTORY_HPP_

#include <architecture/definitions.hpp>

namespace architecture::simplefactory {

/*Simple Factory Pattern*/
/* Interface ( Abstract class  with pure virtual function)*/
// Product
class Character {
 public:
    virtual ~Character() {}
    virtual std::string getType() const = 0;
};

// Concrete Product
class Archer : public Character {
 public:
    std::string getType() const override {
        return type_;
    }
 private:
    std::string type_{"Archer"};
};

// Concrete Product
class Warrior : public Character {
 public:
    std::string getType() const override {
        return type_;
    }
 private:
    std::string type_{"Warrior"};
};


enum CharacterTYPE {
    ARCHER,
    WARRIOR
};

// Simple Factory
class CharacterFactory {
 public:
    using char_ptr_type = std::shared_ptr<Character>;
    char_ptr_type CreateCharacter(CharacterTYPE type) {
        switch (type) {
            case ARCHER:
                return std::make_shared<Archer>();
                break;
            case WARRIOR:
                return std::make_shared<Warrior>();
                break;
            default:
                return nullptr;
                break;
        }
    }
};
}  // namespace architecture::simplefactory
#endif  // SRC_FACTORY_SIMPLE_FACTORY_HPP_
