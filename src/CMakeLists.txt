# define library
add_library(${PROJECT_NAME} INTERFACE)

# add architecture
add_subdirectory(${PROJECT_NAME})

# add Decorator Pattern
set(pattern_name decorator)
add_subdirectory(${pattern_name})

# add Strategy Pattern
set(pattern_name strategy)
add_subdirectory(${pattern_name})

# add Factory Pattern
set(pattern_name factory)
add_subdirectory(${pattern_name})

# add Composite Pattern
set(pattern_name composite)
add_subdirectory(${pattern_name})

# add Bridge Pattern
set(pattern_name bridge)
add_subdirectory(${pattern_name})

# add Chain Pattern
set(pattern_name chain_of_responsibility)
add_subdirectory(${pattern_name})

# add Builder Pattern
set(pattern_name builder)
add_subdirectory(${pattern_name})

# add Mediator Pattern
set(pattern_name mediator)
add_subdirectory(${pattern_name})


# add Observer Pattern
set(pattern_name observer)
add_subdirectory(${pattern_name})

# add Template Method Pattern
set(pattern_name template_method)
add_subdirectory(${pattern_name})

# add Prototype Pattern
set(pattern_name prototype)
add_subdirectory(${pattern_name})

# add Flyweight Pattern
set(pattern_name flyweight)
add_subdirectory(${pattern_name})
