# Qt app that works with files in different threads.

Files that it's reading are just random binary files, that i filled with random numbers. 
The whole point is for those files to be big, so that threads will actually have to do some work, while processing them. 

Technologies:
  - C++(17)
  - Qt(5.14.2)
  - Toml11(2.13.4) - https://github.com/ToruNiina/toml11 library to work with *.toml. 
  - Catch2(3.6.0) - https://github.com/catchorg/Catch2 library for unit-tests.
