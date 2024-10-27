cmake_minimum_required(VERSION 3.5.0)

include(${HAILO_EXTERNALS_CMAKE_SCRIPTS}/spdlog.cmake)

set(HAILO_TEST_CPP_FILES
    hailo_test.cpp
)

add_executable(hailo_test
    ${HAILO_TEST_CPP_FILES}
)

set_property(TARGET hailo_test PROPERTY CXX_STANDARD 14)

target_link_libraries(hailo_test
    libhailort
    spdlog::spdlog
)

target_include_directories(hailo_test
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

install(TARGETS hailo_test
   RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
   CONFIGURATIONS Release
)
