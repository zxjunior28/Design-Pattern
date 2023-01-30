// Copyright (c) 2023 Katelyn Bai
#include <prototype/prototype.hpp>

int main(int argc, char **argv) {
    using architecture::prototype::Shape;
    auto figure = std::make_shared<Shape> (1, "schematic diagram");
    figure->show();

    /// protype
    auto figure_copy = figure->clone();
    figure_copy->show();

    return 0;
}
