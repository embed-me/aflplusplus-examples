cmake_minimum_required(VERSION 3.20)
project(simple_crash)
add_executable(simple_crash simple_crash.cpp)

add_library(custom_mutator SHARED custom_mutator.c)
target_include_directories(custom_mutator PRIVATE "/opt/afl++/include/afl/")

add_custom_target(fuzz_run
  
  COMMAND AFL_CUSTOM_MUTATOR_LIBRARY=${CMAKE_BINARY_DIR}/libcustom_mutator.so
          AFL_CUSTOM_MUTATOR_ONLY=true
          ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR}
          /opt/afl++/bin/afl-fuzz
          -i ${CMAKE_SOURCE_DIR}/seeds
          -o /mnt/ramdisk/out
          -s 123
          -- $<TARGET_FILE:simple_crash>
  USES_TERMINAL
  COMMENT "Running AFL++ fuzzing (streams to terminal)..."
)

add_dependencies(fuzz_run simple_crash)
add_dependencies(fuzz_run custom_mutator)