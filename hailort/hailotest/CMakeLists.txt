cmake_minimum_required(VERSION 3.5.0)

set(APPNAME hailotest)

set(HAILOTEST_CPP_FILES
    ${APPNAME}.cpp
)

add_executable(${APPNAME}
    ${HAILOTEST_CPP_FILES}
)

set_property(TARGET ${APPNAME} PROPERTY CXX_STANDARD 14)

target_link_libraries(${APPNAME}
    libhailort
    spdlog::spdlog
)

target_include_directories(${APPNAME}
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

install(TARGETS ${APPNAME}
   RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
   CONFIGURATIONS Release
)
