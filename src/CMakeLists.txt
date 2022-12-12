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
