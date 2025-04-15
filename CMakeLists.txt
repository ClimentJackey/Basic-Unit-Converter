cmake_minimum_required(VERSION 3.10)
project(UnitConverter)

if(NOT CMAKE_INSTALL_PREFIX_INITIALIZED_IN_SETUP)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}" CACHE PATH "Install prefix path" FORCE)
endif()

#Libraries
add_library(unitconverter-lib STATIC
    lib/src/temperature_converter.cpp
)
target_include_directories(unitconverter-lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib/include>
        $<INSTALL_INTERFACE:include>
)

install(TARGETS unitconverter-lib DESTINATION bin)

# Application
add_executable(unitconverter-app app/src/main.cpp)
target_link_libraries(unitconverter-app PRIVATE unitconverter-lib) # Link against the library

target_include_directories(unitconverter-app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/include
)
install(TARGETS unitconverter-app
    RUNTIME DESTINATION bin
)

# Example "Hello, World!" program that uses the library
add_executable(helloworld examples/helloworld.cpp)
target_link_libraries(helloworld PRIVATE unitconverter-lib)
target_include_directories(helloworld PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/include
)
install(TARGETS helloworld DESTINATION bin/examples)