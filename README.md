
## Runtime median getter project

#### build on unix system:
* git clone repo
* please clone github.com/google/googletest.git into test folder (and fix the CMAKE_VERSION VERSION_GREATER_EQUAL to CMAKE_VERSION VERSION_GREATER if you CMake requires it)
* mkdir build && cd build && cmake .. && make all

###### run program:
./src/median_project_run
###### run tests:
./test/median_project_tst

median getter time measurment can be turned on by setting flag SHALL_PRINT_MEASURMENT_RES to true (test.cpp)


#### running on windows Visual Studio:
* git clone
* setup remote configuration to linux-server
* generate cmake
* run


#### TODO list:
* move SHALL_PRINT_MEASURMENT_RES to program arg
* expand template for more specific types like string (I see template specializations here) or custom objects (maybe static requirment for + and / operator overload)
* add auto googletest git downloader in cmake
* median.cpp -> consider if addition on equal can be always added only to one heap