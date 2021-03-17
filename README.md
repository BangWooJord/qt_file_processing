# Qt app that works with files in different threads.
Uses:
  - https://github.com/ToruNiina/toml11 library to work with *.toml. 
  - https://github.com/catchorg/Catch2 library for unit-tests.
Files that it's reading are just random binary files, that i filled with random numbers. 
The whole point is for those files to be big, so that threads will actually have to do some work, while processing them. 
