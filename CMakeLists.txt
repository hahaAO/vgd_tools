cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME vgd_tools)

if(NOT CMAKE_CXX_STANDARD)
    # This project requires C++14.
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif(NOT CMAKE_CXX_STANDARD)

set(PROJECT_PUBLIC_INCLUDE_DIR "include/vgd_tools")

project(vgd_tools VERSION 0.1.0)

aux_source_directory(${PROJECT_SOURCE_DIR}/src project_source_file)

add_library(${PROJECT_NAME} STATIC ${project_source_file})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_PUBLIC_INCLUDE_DIR})

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}_TARGETS

    LIBRARY DESTINATION lib/${PROJECT_NAME}
    ARCHIVE DESTINATION lib/${PROJECT_NAME}
    RUNTIME DESTINATION bin/${PROJECT_NAME}
)

# STUDY 如果有-config.cmake,find_package后不需要指定库目录和头文件
# 即无需使用 target_include_directories 和 target_link_directories
# 但在链接目标文件时仍需使用 target_link_libraries 指定该库
install(EXPORT ${PROJECT_NAME}_TARGETS
    FILE ${PROJECT_NAME}-config.cmake
    DESTINATION ${PROJECT_BINARY_DIR}
)

file(GLOB EXPORT_HEADER_LIST ${PROJECT_PUBLIC_INCLUDE_DIR}/*.hpp ${PROJECT_PUBLIC_INCLUDE_DIR}/*.h)
install(FILES
    ${EXPORT_HEADER_LIST}
    DESTINATION include/${PROJECT_NAME}
)

add_executable(log_test log_test.cpp)
target_link_libraries(log_test ${PROJECT_NAME})
target_include_directories(log_test PRIVATE "include/")
add_executable(timer_test timer_test.cpp)
target_link_libraries(timer_test ${PROJECT_NAME})
target_include_directories(timer_test PRIVATE "include/")
