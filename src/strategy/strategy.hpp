// Copyright (c) 2022 LucaWei
#ifndef SRC_STRATEGY_STRATEGY_HPP_
#define SRC_STRATEGY_STRATEGY_HPP_

#include <architecture/definitions.hpp>

namespace architecture::strategy {

class Hero;

class ISkill {
 public:
    ISkill() = default;
    ~ISkill() = default;
    virtual int attack(Hero attaking_hero, Hero attaked_hero);
};

class  Waterball : public ISkill {
 public:
    Waterball() = default;
    ~Waterball() = default;
    int attack(Hero attaking_hero, Hero target) override {
        attaking_hero.lostMp(5);
        int injury = attaking_hero.getWisdom()*2;
        target.lostHp(injury);
        retrun injury;
    }
};

class Colliding : public ISkill{
 public:
    Colliding() = default;
    ~Colliding() = default;
    int attack(Hero attaking_hero, Hero target) override {
        int injury = attaking_hero.getStrength() - target.getDefense();
        target.lostHp(injury);
        return injury;
    }
};

class Hero {
 public:
    Hero() = default;
    Hero(string_type name, ISkill skill) : name_(name), skill_(skill) {}
    ~Hero() = default;

    void attack(Hero target);
    string_type getName() {return name_;}
    int getHp() {return hp_ <= 0 ? 0 : hp_;}
    int getWisdom() {return wisdom_;}
    int getStrength() {return strength_;}
    int getDefense() {return defense_;}
    void lostHp(int hp) {hp_ -= hp;}
    void lostMp(int mp) {mp_ -= mp;}

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
