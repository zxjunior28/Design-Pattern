// Copyright (c) 2022 Katelyn Bai
#ifndef SRC_FACTORY_FACTORY_HPP_
#define SRC_FACTORY_FACTORY_HPP_

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


// Factory
class CharacterFactory {
 public:
    using char_ptr_type = std::shared_ptr<Character>;
    virtual ~CharacterFactory() {}
    virtual char_ptr_type CreateCharacter() = 0;
};

class ArcherProducer : public CharacterFactory {
 public:
    char_ptr_type CreateCharacter() override {
        return std::make_shared<Archer>();
    }
};

class WarriorProducer : public CharacterFactory {
 public:
    char_ptr_type CreateCharacter() override {
        return std::make_shared<Warrior>();
    }
};


}  // namespace architecture::factory
#endif  // SRC_FACTORY_FACTORY_HPP_
