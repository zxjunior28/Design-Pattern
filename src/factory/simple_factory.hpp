// Copyright (c) 2022 Katelyn Bai
#ifndef SRC_FACTORY_SIMPLE_FACTORY_HPP_
#define SRC_FACTORY_SIMPLE_FACTORY_HPP_

#include <architecture/definitions.hpp>

namespace architecture::factory {


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
    Character *CreateCharacter(CharacterTYPE type) {
        switch (type) {
            case ARCHER:
                return new Archer();
                break;
            case WARRIOR:
                return new Warrior();
                break;
            default:
                return NULL;
                break;
        }
    }
};
}  // namespace architecture::factory
#endif  // SRC_FACTORY_SIMPLE_FACTORY_HPP_
