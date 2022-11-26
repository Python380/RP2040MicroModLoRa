cmake_minimum_required(VERSION 3.20)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
pico_sdk_init()

project(RotschyRover_Main)

# add_subdirectory(./src)

include_directories(RotschyRover_Main
#     ${PICO_SDK_PATH}/src/rp2_common/hardware_i2c/include/
#     ${PICO_SDK_PATH}/src/rp2_common/pico_multicore/include/
    # ${PICO_SDK_PATH}/src/common/pico_util/include/
)

add_executable(RotschyRover_Main
    # main
    ./src/main.cpp

    # local libs
    # ./src/motor/Motor.cpp
    # ./src/I2C/I2C.cpp
    # ./src/accelerometer/mpu9250.cpp
    # ./src/motor/MotorDriver.cpp
    # ./src/queue/wrapper.cpp
    # ./src/math/math.cpp

    # HACKY FIX FOR SOMETHING?
    # # include directories need executable paths as well
    # ${PICO_SDK_PATH}/src/rp2_common/hardware_i2c/i2c.c
    # ${PICO_SDK_PATH}/src/rp2_common/pico_multicore/multicore.c
    # ${PICO_SDK_PATH}/src/common/pico_util/queue.c
    )

# pull in common dependencies
target_link_libraries(RotschyRover_Main
    pico_stdlib
    # hardware_i2c
    # pico_multicore
)

pico_enable_stdio_usb(RotschyRover_Main 1)
pico_enable_stdio_uart(RotschyRover_Main 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(RotschyRover_Main)
