
if (TARGET tinyusb_device)
    add_executable(hello_usb
            hello_usb.c
            buttons.c
            usb_descriptors.c
            )

    # Make sure TinyUSB can find tusb_config.h
    target_include_directories(hello_usb PUBLIC
    ${CMAKE_CURRENT_LIST_DIR})

    # pull in common dependencies
    target_link_libraries(hello_usb PUBLIC pico_stdlib hardware_adc pico_stdlib pico_unique_id tinyusb_device tinyusb_board)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(hello_usb 0)
    pico_enable_stdio_uart(hello_usb 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(hello_usb)

    # add url via pico_set_program_url
    example_auto_set_url(hello_usb)


elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()
