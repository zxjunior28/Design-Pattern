# Design Pattern Implementation
Gangs of Four (GoF) Design Patterns

# Design Pattern
## Creational
>* Factory
    - Simple Factory
    - Factory
    - Abstract Factory
>* Builder

## Structural
>* Decorator
>* Composite
>* Bridge  
    - Decouple an abstraction from its implementation so that the two can vary independently. 
## Behavioral
>* Strategy  
    - Program to an interface, not an implementation  
    - Favor object aggregation over class inheritance  
    - Seperation of Concerns(SOC)
>* Chain of responsibility
>* Mediator

## Build
###  Build using scripts
```console
$ source scripts/boost.sh
```
### Build using CMake directly
```console
$ cmake -S . -B build/ -DBUILD_EXAMPLES=ON
$ cmake --build build/ -j4
$ ./build/bin/bridge_example
```
# Reference
>* Strategy Pattern
    - https://github.com/Johnny850807/Waterball-Youtube-Demo  
