// Copyright (c) 2023 Katelyn Bai
#ifndef SRC_TEMPLATE_METHOD_TEMPLATE_METHOD_HPP_
#define SRC_TEMPLATE_METHOD_TEMPLATE_METHOD_HPP_

#include <architecture/definitions.hpp>

namespace architecture::template_method {

/*Abstract Class*/
class DataMiner {
  /**
   * The template method defines the skeleton of an algorithm.
   */
 public:
  void TemplateMethod(char *path) const {
    std::ifstream in = this->openFile(path);
    auto data =  extractData(in);
    auto result = analyzeData(data);
    sendReport(result);
  }
  /**
   * These operations already have (default) implementations.
   */
 protected:
  bool analyzeData(const std::vector<int>& data) const {
    int sum{0};
    for (int i : data)
      sum += i;
    std::cout << "Sum = " << sum << std::endl;
    return sum > 0;
  }
  void sendReport(bool result) const {
    if (result)
      std::cout << "Data sum is greater than zero\n";
    else
      std::cout << "Data sum is less than or equal to zero\n";
  }
  /**
   * These operations have to be implemented in subclasses.
   */
  virtual std::ifstream openFile(char *path) const = 0;
  virtual std::vector<int> extractData(std::ifstream& in) const = 0;

};

/*Concrete Class*/
class CsvDataMiner : public DataMiner {
 protected:
  std::ifstream openFile(char *path) const override {
    std::ifstream in(path, std::ifstream::in);
    if (in.fail()) {
      std::cerr << "no such file!! " <<  std::endl;
      throw;
    } else {
      return in;
    }
  }
  std::vector<int> extractData(std::ifstream& in) const override {
    std::string s;
    std::getline(in, s);
    std::stringstream ss(s);
    std::vector<int> data_list;
    int data;
    while (ss >> data) {
      data_list.push_back(data);
      std::cout << data << " ";
    }

    std::cout << std::endl;
    return data_list;
  }
};

}  /// namespace architecture::template_method
#endif  // SRC_TEMPLATE_METHOD_TEMPLATE_METHOD_HPP_
