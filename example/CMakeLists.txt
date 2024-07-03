cmake_minimum_required(VERSION 3.13)
project(KoiUtilityExample)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(OBSERVABLE_EXAMPLE ObservableExample)

add_executable(${OBSERVABLE_EXAMPLE}
    observable_example.cpp
)

target_link_libraries(${OBSERVABLE_EXAMPLE} PRIVATE
    KoiUtility
)
