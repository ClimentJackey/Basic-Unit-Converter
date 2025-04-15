cmake_minimum_required(VERSION 3.10)
project(UnitConverter)

#Libraries
add_library(unitconverter-lib STATIC
    lib/src/temperature_converter.cpp
)
target_include_directories(unitconverter-lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib/include>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS unitconverter-lib
    EXPORT unitconverter-config
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include/unitconverter
)
install(EXPORT unitconverter-config DESTINATION lib/cmake/UnitConverter)

# Application
add_executable(unitconverter-app app/src/main.cpp)
target_link_libraries(unitconverter-app PRIVATE unitconverter-lib) # Link against the library

target_include_directories(unitconverter-app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/include
)
install(TARGETS unitconverter-app
    RUNTIME DESTINATION bin
)