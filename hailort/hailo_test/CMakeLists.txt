cmake_minimum_required(VERSION 3.5.0)

# Set firmware version
add_definitions( -DFIRMWARE_VERSION_MAJOR=0 )
add_definitions( -DFIRMWARE_VERSION_MINOR=1 )
add_definitions( -DFIRMWARE_VERSION_REVISION=0 )

if(HAILO_BUILD_SERVICE)
    add_definitions( -DHAILO_SUPPORT_MULTI_PROCESS )
endif()

set(HAILO_TEST_CPP_FILES
    hailo_test.cpp
)

set_property(TARGET hailo_test PROPERTY CXX_STANDARD 14)

target_link_libraries(hailo_test
    libhailort
)

target_include_directories(hailo_test
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

install(TARGETS hailo_test
   RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
   CONFIGURATIONS Release
)
