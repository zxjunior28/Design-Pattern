// Copyright (c) 2022 LucaWei
#ifndef SRC_STRATEGY_STRATEGY_HPP_
#define SRC_STRATEGY_STRATEGY_HPP_

#include <architecture/definitions.hpp>

namespace architecture::strategy {

class Hero;

class ISkill {
 public:
    ISkill() {}
    ~ISkill() = default;
    virtual int attack(Hero& attaking_hero, Hero& attaked_hero);
};

class  Waterball : public ISkill {
 public:
    Waterball() {}
    ~Waterball() = default;
    int attack(Hero& attaking_hero, Hero& target) override;
};

class Colliding : public ISkill{
 public:
    Colliding() {}
    ~Colliding() = default;
    int attack(Hero& attaking_hero, Hero& target) override;
};


class Hero {
 public:
    // Hero() {} {;
    explicit Hero(string_type name): name_(name) {}
    ~Hero() = default;

    void attack(Hero& target, ISkill skill);
    string_type getName() {return name_;}
    int getHp() {return hp_ <= 0 ? 0 : hp_;}
    int getWisdom() {return wisdom_;}
    int getStrength() {return strength_;}
    int getDefense() {return defense_;}
    void lostHp(int hp) {hp_ -= hp;}
    void lostMp(int mp) {mp_ -= mp;}
    bool status();

 private:
    string_type name_;
    int hp_{500};
    int mp_{200};
    int strength_{150};
    int wisdom_{80};
    int defense_{50};
};



inline void Hero::attack(Hero& target, ISkill skill) {
    int injury = skill.attack(*this, target);
    std::cout << getName() << "  used " << typeid(skill).name() <<", the damage value is "<< injury << std::endl;
    std::cout << target.getName() << " has "<< target.getHp() <<" HP" << std::endl;
}


inline int ISkill::attack(Hero& attaking_hero, Hero& target) {
    return 0;
}

inline int Waterball::attack(Hero& attaking_hero, Hero& target) {
    attaking_hero.lostMp(5);
    int injury = attaking_hero.getWisdom()*2;
    target.lostHp(injury);
    return injury;
}

inline int Colliding::attack(Hero& attaking_hero, Hero& target) {
    int injury = attaking_hero.getStrength() - target.getDefense();
    target.lostHp(injury);
    return injury;
}


}
#endif  // SRC_STRATEGY_STRATEGY_HPP_
