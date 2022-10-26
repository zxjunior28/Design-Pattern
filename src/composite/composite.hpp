// Copyright (c) 2022 Katelyn Bai
#ifndef SRC_COMPOSITE_COMPOSITE_HPP_
#define SRC_COMPOSITE_COMPOSITE_HPP_

#include <architecture/definitions.hpp>

namespace architecture::composite {

/*Component*/
class Article {
 public:
    virtual double calculation() = 0;
    virtual void show() = 0;
};

/*Leaf*/
class Commodity : public Article {
 public:
    Commodity(std::string name, double unit_price, int quantity)
    : name_(name), unit_price_(unit_price), quantity_(quantity) {}
    double calculation() override {
        return quantity_*unit_price_;
    }
    void show() override {
        std::cout << name_ <<" (quantity: " << quantity_
        << ",  unit price: " << unit_price_ << ")"<< std::endl;
    }
 private:
    std::string name_;
    int quantity_;
    double unit_price_;
};

/*Composite*/
class Bags : public Article {
 public:
    explicit Bags(std::string name) : name_(name) {}
    /*Manage*/
    void add(Article* atricle) {
        this->article_list_.push_back(atricle);
    }

    void remove(Article* atricle) {
        std::vector<Article*>::iterator it;
        it = article_list_.begin();
        while (it != article_list_.end()) {
            if (*it == atricle) {
                article_list_.erase(it);
                break;
            }
        }
    }


    double calculation() override {
        if (article_list_.empty())
            return 0;
        double total_price = 0;
        for (const auto& article : article_list_) {
            total_price += article->calculation();
        }
        return total_price;
    }
    void show() override {
        if (article_list_.empty()) {
            std::cout << name_ << " is empty" << std::endl;
        } else {
            for (const auto& article : article_list_)
                article->show();
        }
    }

 protected:
    std::string name_;
    std::vector<Article*> article_list_;
};

}  // namespace architecture::composite
#endif  // SRC_COMPOSITE_COMPOSITE_HPP_
