# gtest
Build and Test C++ libraries with Google Test Framework 
 
> This repo should provide a basic understanding of how to use Google Test Framework, and Linking libraries using CMake Build tool
 
> Build Status 
 

> Basics 

- CMakeList 

<details>
<summary>  
CMake Configuration 
</summary> 

 
 ```text 

# CMake Version
cmake_minimum_required(VERSION 2.8)

# Project Name
project(MathFunc CXX)

# Build for Release
set(CMAKE_BUILD_TYPE Release)
message(WARNING "A ${CMAKE_BUILD_TYPE} build configuration is detected")

# Where to throw Binaries
set(CMAKE_LIBRARY_DIR ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/out)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_LIBRARY_DIR})

# Add directories
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib)
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

# Optional args for running Google Test
option (DO_TEST "Run Google Test" OFF) 

# Add Source Files
set(PROJECT_SRCS  ${PROJECT_SOURCE_DIR}/src/main.cc )

# Add Library Source Files
set(LIB_SRC  ${PROJECT_SOURCE_DIR}/lib/mymathfunc.cc )

# Build shared Libs
add_library(${PROJECT_NAME}_shared SHARED ${LIB_SRC})
set(SHARED_LIB ${PROJECT_NAME}_shared)

# Build static Libs
add_library(${PROJECT_NAME}_static STATIC ${LIB_SRC})
set(STATIC_LIB ${PROJECT_NAME}_static)

# Fix symbol visibility
include(GenerateExportHeader)
GENERATE_EXPORT_HEADER(${SHARED_LIB}
    BASE_NAME ${SHARED_LIB}
    EXPORT_MACRO_NAME ${SHARED_LIB}_EXPORTS
    EXPORT_FILE_NAME ${SHARED_LIB}_EXPORTS.h
    STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC)

    
if(DO_TEST)
    include_directories("${PROJECT_SOURCE_DIR}/include/googletest/googletest/include")
    add_subdirectory(include/googletest)
    set(TEST_LIBS_FLAGS ${CMAKE_LIBRARY_DIR}/libgtest_main.a m gtest pthread ${SHARED_LIB})
    add_executable(test_mathfunc 
        ${PROJECT_SOURCE_DIR}/test/test_mymathfunc.cc) 
    add_dependencies(test_mathfunc gtest_main)
    target_link_libraries(test_mathfunc ${TEST_LIBS_FLAGS})
endif (DO_TEST)

# Build Exec
add_executable(${PROJECT_NAME}_st ${PROJECT_SRCS})
target_link_libraries(${PROJECT_NAME}_st ${STATIC_LIB})

add_executable(${PROJECT_NAME}_sh ${PROJECT_SRCS})
target_link_libraries(${PROJECT_NAME}_sh ${SHARED_LIB}) 

```       


</details> 
 
-  Library 

<details> 
<summary> 
Sample Library File 
</summary> 

```c++ 
#include "mymathfunc.hpp"

    double MyMathFunc::add(double a, double b)
    {
        return a + b;
    }

    double MyMathFunc::multiply(double a, double b)
    {
        return a * b;
    }

    double MyMathFunc::divide(double a, double b)
    {
        return a / b;
    }

    double MyMathFunc::subtract(double a, double b)
    {
        return a - b;
    }

    double MyMathFunc::square(double a)
    {
        return a * a;
    }
```   
 
```c++ 
#ifndef MYMATHFUNC_H
#define MYMATHFUNC_H

    class MyMathFunc
    {
    public:
        MyMathFunc(){}
        static double add(double a, double b);
        static double subtract(double a, double b);
        static double multiply(double a, double b);
        static double divide(double a, double b);
        static double square(double a);
        
    };

#endif // !MYMATHFUNC_H
```   

</details>   
 
-  Test 

<details>
<summary>
Test Cases 
</summary> 

```c++ 
 #include "../lib/mymathfunc.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <cstdlib>

using namespace std;
MyMathFunc func_test;

class MyMathFuncTest : public ::testing::Test {
protected:
	virtual void SetUp() { }
	virtual void TearDown() {}
public:
    static const double a = 47.98;
    static const double b = 18.25;
};

TEST_F(MyMathFuncTest, test_addition)
{
    EXPECT_DOUBLE_EQ(66.23,func_test.add(a, b));
}

TEST_F(MyMathFuncTest, test_subtraction)
{
    EXPECT_DOUBLE_EQ(29.73,func_test.subtract(a, b));
}
TEST_F(MyMathFuncTest, test_division)
{
    EXPECT_NEAR(2.62904, func_test.divide(a, b), 0.0000011);
}
TEST_F(MyMathFuncTest, test_multiply)
{
    EXPECT_DOUBLE_EQ(875.635,func_test.multiply(a, b));
}
TEST_F(MyMathFuncTest, test_square)
{
    EXPECT_DOUBLE_EQ(2302.0804,func_test.square(a));
    EXPECT_DOUBLE_EQ(333.0625,func_test.square(b));
}
int main(int argc, char * argv[])
{
	/*The method is initializes the Google framework and must be called before RUN_ALL_TESTS */
	::testing::InitGoogleTest(&argc, argv);

	/*RUN_ALL_TESTS automatically detects and runs all the tests defined using the TEST macro.
	It's must be called only once in the code because multiple calls lead to conflicts and,
	therefore, are not supported.
	*/
	return RUN_ALL_TESTS();
}
``` 
   
</details>   
 
- App file 

<details> 
<summary> 
Application File 
</summary>  

```c++ 
 #include <iostream>
#include <cstdlib>
#include "../lib/mymathfunc.hpp"

using namespace std;
MyMathFunc func;
int main()
{
    
    double a = 19.85;
    double b = 8.91;
    
    cout << "a + b = " <<
        func.add(a, b) << endl;
    cout << "a - b = " <<
        func.subtract(a, b) << endl;
    cout << "a * b = " <<
        func.multiply(a, b) << endl;
    cout << "a / b = " <<
        func.divide(a, b) << endl;
    cout << "a * a = " <<
        func.square(a) << endl;
    return 0;
}
``` 

</details>  
