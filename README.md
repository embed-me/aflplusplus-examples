# AFL++ Examples
Ref.: https://aflplus.plus/

## Setup
### Install AFLplusplus 
Follow: https://aflplus.plus/building/.
The examples assume that the PREFIX `/opt/afl++` was used.
`sudo make install PREFIX=/opt/afl++`

### Fuzzing Directory
Mount /mnt/ramdisk before, this protects SSDs/Disks due to high IO operations
eg.: `sudo mount -t tmpfs -o size=2G tmpfs /mnt/ramdisk`

### Running an example
1. `cmake --preset afl`
2. `cmake --build preset afl`
3. `cmake --build --preset afl --target fuzz_run`

## Examples
### Example 1
Using auto instrumentation with AFL.
This is easy, but slow as the APP has to be loaded for each run!

### Example 2
Using persistent mode in AFL.
The app does not need to be loaded every time. If there is no persistency in code it is much faster!
Ref: https://github.com/AFLplusplus/AFLplusplus/blob/stable/instrumentation/README.persistent_mode.md

### Example 3
Similar to example 1/2, however, uses a single strcmp.
Demonstrates that Coverage-guided Fuzzing (example 1/2) is much more successful because
the mutator detects the extended coverage of each level, while here you would need
a full match of "dead" in order to move one level/increase coverage - hence much slower!

### Example 4
The used dictionary shows how a good starting point for the fuzzer. This is called
strcture-aware-fuzzing and can make the process much more successful and faster.
Ref: https://github.com/AFLplusplus/AFLplusplus/blob/stable/dictionaries/README.md

### Example 5
Using a custom mutator allows for efficient structure-aware-fuzzing if certain criteria 
have to be met on the input which are hard to get right with the standard mutator.
This example uses a c mutator.
Ref: https://github.com/AFLplusplus/AFLplusplus/blob/stable/docs/custom_mutators.md

### Example 6
Using a custom mutator allows for efficient structure-aware-fuzzing if certain criteria 
have to be met on the input which are hard to get right with the standard mutator.
This example uses a python mutator.
Ref: https://github.com/AFLplusplus/AFLplusplus/blob/stable/docs/custom_mutators.md

### Example 7
Fuzz an application that reads a file. The `@@` is used to tell afl-fuzz where the
path to the file is expected. In our case it is the first argument of the application.
