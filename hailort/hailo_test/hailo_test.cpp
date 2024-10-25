#include "hailo_test.hpp"
#include "hailo/device.hpp"

#include <iostream>

/**
 * @brief Main entry point 
 */
int main(int argc, char ** argv) {
    std::cout << "Hello Hailo!" << std::endl;

    auto device_ids = Device::scan();
    CHECK_EXPECTED_AS_STATUS(device_ids);

    if (device_ids->size() == 0) {
        std::cout << "Hailo devices not found" << std::endl;
    }
    else {
        std::cout << "Hailo Devices:" << std::endl;
        for (const auto& device_id : device_ids.value()) {
            std::cout << "[-] Device: " << device_id << std::endl;
        }
    }

    return HAILO_SUCCESS;

    return 0;
}