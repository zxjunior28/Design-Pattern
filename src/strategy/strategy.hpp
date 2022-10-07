// Copyright (c) 2022 LucaWei
#ifndef SRC_STRATEGY_STRATEGY_HPP_
#define SRC_STRATEGY_STRATEGY_HPP_

#include <architecture/definitions.hpp>

namespace architecture::strategy {

class Hero;

class ISkill {
 public:
    ISkill();
    ~ISkill();
    virtual int attack(Hero attaking_hero, Hero attaked_hero);
};

class Hero {
 public:
    Hero(string_type name, ISkill skill) : name_(name), skill_(skill) {}
    ~Hero() = default;

    void attack(Hero target);
    string_type getName() {return name_;}
    int getHp() {return hp_ <= 0 ? 0 : hp_;}
 private:
    string_type name_;
    int hp_{500};
    int mp_{200};
    int strength_{150};
    int wisdom_{80};
    int defense_{50};
    ISkill skill_;

};

inline void Hero::attack(Hero target) {
    int injury = skill_.attack(*this, target);
    std::cout << getName() << "  used " << typeid(skill_).name() <<", the damage value is "<< injury << std::endl;
    std::cout << target.getName() << "has "<< target.getHp() <<" HP" << std::endl;
}


}
#endif  // SRC_STRATEGY_STRATEGY_HPP_
