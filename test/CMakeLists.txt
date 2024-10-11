add_executable(mytest test_signal.c unity_config.c ../src/signaling.c)

target_link_libraries(mytest PRIVATE
  pico_stdlib
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
  pico_cyw43_arch_none
  unity
)
pico_enable_stdio_uart(mytest 0)
pico_enable_stdio_usb(mytest 1)

add_custom_target(flash_test picotool load -f $<TARGET_FILE:mytest> DEPENDS mytest)


add_executable(lab4_test_fifo test_fifo.c unity_config.c ../src/fifo.c )
target_link_libraries(lab4_test_fifo PRIVATE
  pico_stdlib
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
  pico_cyw43_arch_none
  unity
)
pico_enable_stdio_uart(lab4_test_fifo 0)
pico_enable_stdio_usb(lab4_test_fifo 1)

add_custom_target(flash_lab4_test_fifo picotool load -f $<TARGET_FILE:lab4_test_fifo> DEPENDS lab4_test_fifo)
