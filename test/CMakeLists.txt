cmake_minimum_required(VERSION 3.10)

project(codingPractice)

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g")
set(CMAKE_C_FLAGS_DEBUG "-Og -g")


set(INCLUDE_DIRS
	../src
  ../catch2
  /mnt/c/Program\ Files/OpenSSL-Win64/include
    # ../trompeloeil/include
	# ../mingw-std-threads
)

set(CPP_SRCS

)

set(C_SRCS
	../src/bubbleSort/bubble_sort.c
	../src/memoryAllocator/memalloc.c
	../src/matrixMultiply/matrix_multiply.c
	../src/fastModularExponent/fast_modular_exponent.c
)

set(CPP_TEST_SRCS
	main.cpp
	# bubble_sort_test.cpp
	# memory_allocator_tests.cpp
	# matrix_multiply_test.cpp
	fast_modular_exponent_tests.cpp
)

set(C_TEST_SRCS

)

set(GLOBAL_DEFINES

)

find_package (Threads REQUIRED)

set(LINKED_LIBS
	${CMAKE_THREAD_LIBS_INIT}
find_package(OpenSSL REQUIRED)

set(LINKED_LIBS
	OpenSSL::SSL
	OpenSSL::Crypto
)

link_directories(
		/mnt/c/Program Files/OpenSSL-Win64/lib
)

include_directories(${INCLUDE_DIRS})
add_definitions(${GLOBAL_DEFINES})

#include(cppcheck.cmake)

# generate unit tests executable
add_executable(${CMAKE_PROJECT_NAME} ${CPP_SRCS} ${C_SRCS} ${CPP_TEST_SRCS} ${C_TEST_SRCS})

# target_link_libraries(untitled )
target_link_libraries(${CMAKE_PROJECT_NAME} ${LINKED_LIBS})
