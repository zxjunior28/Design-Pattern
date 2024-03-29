# Design Pattern Implementation
Gangs of Four (GoF) Design Patterns

## Creational
>* Builder
>* Factory  
    - Simple Factory  
    - Factory  
    - Abstract Factory  
>* Prototype

## Structural
>* Decorator
>* Composite
>* Bridge  
    - Decouple an abstraction from its implementation so that the two can vary independently. 
>* Flyweight

## Behavioral
>* Strategy  
    - Program to an interface, not an implementation  
    - Favor object aggregation over class inheritance  
    - Seperation of Concerns(SOC)
>* Chain of responsibility
>* Mediator
>* Observer
>* Template Method

# Build
##  Build using scripts
```console
$ source scripts/boost.sh
```
## Build using CMake directly
```console
$ cmake -S . -B build/ -DBUILD_EXAMPLES=ON
$ cmake --build build/ -j4
$ ./build/bin/bridge_example
```
# Reference
>* https://refactoring.guru/ 
>* https://github.com/Johnny850807/Waterball-Youtube-Demo  
