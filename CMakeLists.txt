cmake_minimum_required(VERSION 3.13)
project(KoiUtility VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(${PROJECT_NAME} STATIC
    include/utility/enums.hpp
    include/utility/templates/observer.hpp
    include/utility/templates/observable.hpp
    include/utility/templates/publisher.hpp
    include/utility/templates/subscriber.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    LINKER_LANGUAGE CXX
)


add_subdirectory(example)
