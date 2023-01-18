// Copyright (c) 2023 Katelyn Bai
#include <template_method/template_method.hpp>

int main(int argc , char **argv) {
    if (argc < 2) {
        std::cout << "Usage: ./template_method_example <Input_flie>" << std::endl;
    }
    using architecture::template_method::CsvDataMiner;
    CsvDataMiner *csvDataMiner = new CsvDataMiner;

    csvDataMiner->TemplateMethod(argv[1]);


    delete csvDataMiner;

    return 0;
}