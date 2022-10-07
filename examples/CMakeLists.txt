set(project_name ${PROJECT_NAME})
project(${PROJECT_NAME})

set(example_name decorator_example)
set(executable_name ${example_name})
# add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
add_executable(${executable_name} ${example_name}.cpp)
target_link_libraries(${executable_name} PUBLIC ${PROJECT_NAME})
# target_link_libraries(${PROJECT_NAME}_${example_name} PUBLIC Eigen3::Eigen)

set(example_name strategy_example)
set(executable_name ${example_name})
# add_gtest_with_libraries(${PROJECT_NAME}_${example_name} ${example_name}.cpp ${PROJECT_NAME})
add_executable(${executable_name} ${example_name}.cpp)
target_link_libraries(${executable_name} PUBLIC ${PROJECT_NAME})

unset(project_name)
unset(example_name)