cmake_minimum_required(VERSION 3.20)
project(simple_crash)
add_executable(simple_crash simple_crash.cpp)

add_custom_target(fuzz_run
  
  COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR}
          /opt/afl++/bin/afl-fuzz
          -i ${CMAKE_SOURCE_DIR}/seeds/
          -o /mnt/ramdisk/out
          -s 123
          -- $<TARGET_FILE:simple_crash> @@
  USES_TERMINAL
  COMMENT "Running AFL++ fuzzing (streams to terminal)..."
)

add_dependencies(fuzz_run simple_crash)