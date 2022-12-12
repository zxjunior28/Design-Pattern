// Copyright (c) 2022 Katelyn Bai
#ifndef SRC_BUILDER_BUILDER_HPP_
#define SRC_BUILDER_BUILDER_HPP_

#include <architecture/definitions.hpp>

namespace architecture::builder {


/// @brief  Product
class Computer{
 public:
    // Final Constructor
    Computer(string_type cpu, string_type mb, string_type hdd,
    string_type vga, string_type key_board, string_type mouse)
    : cpu_(cpu), mb_(mb), hdd_(hdd), vga_(vga), key_board_(key_board), mouse_(mouse) {}

    Computer() = delete;
    ~Computer() = default;
    void showInfomation() {
        std::cout << " CPU : " << cpu_ << std::endl
                  << " Mother Board: " << mb_ << std::endl
                  << " HDD: " << hdd_ << std::endl
                  << " VGA: " << vga_ << std::endl
                  << " Key Board: " << key_board_ << std::endl
                  << " Mouse: " << mouse_ << std::endl;
    }
 private:
    string_type cpu_{"NULL"};  // key
    string_type mb_{"NULL"};  // key
    string_type hdd_{"NULL"};  // key
    string_type vga_{"NULL"};  // optional
    string_type key_board_{"NULL"};  // optional
    string_type mouse_{"NULL"};  // optional
};


/// @brief  The Builder interface specifies methods for creating
/// @brief   the different parts of the Product objects.
class IComputerBuilder {
 public:
    virtual ~IComputerBuilder() {}
    virtual IComputerBuilder& setCPU(string_type cpu) = 0;
    virtual IComputerBuilder& setMB(string_type mb) = 0;
    virtual IComputerBuilder& setHDD(string_type hdd) = 0;
    virtual IComputerBuilder& setVGA(string_type vga) = 0;
    virtual IComputerBuilder& setKeyBoard(string_type key_board) = 0;
    virtual IComputerBuilder& setMouse(string_type mouse) = 0;
    virtual void build() = 0;
};


/// @brief  The Concrete Builder classes follow the Builder interface
/// @brief  and provide specific implementations of the building steps.
class ComputerBuilder : public IComputerBuilder {
 private:
    std::unique_ptr<Computer> computer_;
    string_type cpu_{"NULL"};  // key
    string_type mb_{"NULL"};  // key
    string_type hdd_{"NULL"};  // key
    string_type vga_{"NULL"};  // optional
    string_type key_board_{"NULL"};  // optional
    string_type mouse_{"NULL"};  // optional

 public:
    using computer_ptr = std::unique_ptr<Computer>;

    ComputerBuilder() = default;

    ~ComputerBuilder() = default;

    void build() {
        computer_ = std::make_unique<Computer>(cpu_, mb_, hdd_,
                                        vga_, key_board_, mouse_);
    }
    /**
     * All production steps work with the same product instance.
     */
    ComputerBuilder& setCPU(string_type cpu) override {
        this->cpu_ = cpu;
        return (*this);
    }

    ComputerBuilder& setMB(string_type mb) override {
        this->mb_ = mb;
        return (*this);
    }

    ComputerBuilder& setHDD(string_type hdd) override {
        this->hdd_ = hdd;
        return (*this);
    }

    ComputerBuilder& setVGA(string_type vga) override {
        this->vga_ = vga;
        return (*this);
    }

    ComputerBuilder& setKeyBoard(string_type key_board) override {
        this->key_board_ = key_board;
        return (*this);
    }

    ComputerBuilder& setMouse(string_type mouse) override {
        this->mouse_ = mouse;
        return (*this);
    }

    computer_ptr GetComputer() {
        return std::move(computer_);
    }
};



/**
 * The Director is only responsible for executing the building steps in a
 * particular sequence. It is helpful when producing products according to a
 * specific order or configuration. Strictly speaking, the Director class is
 * optional, since the client can control builders directly.
 */

class Director {
    /**
     * @var Builder
     */
 private:
    // aggregation
    ComputerBuilder& builder_;

 public:

    // set builder
    explicit Director(ComputerBuilder* builder) : builder_(*builder) {}

    /**
     * The Director can construct several product variations using the same
     * building steps.
     */

    void appleSpec() {
        builder_
        .setCPU("Apple")
        .setHDD("Apple")
        .setMB("Apple")
        .setVGA("Apple")
        .build();
    }

    void mixSpec() {
        builder_
        .setCPU("intel")
        .setHDD("Apple")
        .setMB("acer")
        .setVGA("msi")
        .setMouse("logi")
        .build();
    }
};


/// Construcotr Overloading
// class Computer {
//  public:
//     using string_type = std::string;

//     Computer() = delete;

//     // Overload
//     Computer(string_type cpu, string_type mb, string_type hdd)
//     : cpu_(cpu), mb_(mb), hdd_(hdd) {}

//     Computer(string_type cpu, string_type mb, string_type hdd,
//     string_type vga, string_type key_board, string_type mouse)
//     : cpu_(cpu), mb_(mb), hdd_(hdd), vga_(vga), key_board_(key_board), mouse_(mouse) {}

//     void showInfomation() {
//         std::cout << " CPU : " << cpu_ << std::endl
//                   << " Mother Board: " << mb_ << std::endl
//                   << " HDD: " << hdd_ << std::endl
//                   << " VGA: " << vga_ << std::endl
//                   << " Key Board: " << key_board_ << std::endl
//                   << " Mouse: " << mouse_ << std::endl;
//     }

//     ~Computer() = default;

//  private:
//     string_type cpu_{"Null"};  // key
//     string_type mb_{"Null"};  // key
//     string_type hdd_{"Null"};  // key
//     string_type vga_{"Null"};  // optional
//     string_type key_board_{"Null"};  // optional
//     string_type mouse_{"Null"};  // optional

// };

}  // namespace architecture::builder
#endif  // SRC_BUILDER_BUILDER_HPP_
