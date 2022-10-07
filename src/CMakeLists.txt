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
