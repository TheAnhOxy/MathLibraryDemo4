# --- Phần 1: Thông tin cơ bản của dự án ---
cmake_minimum_required(VERSION 3.14)
project(GTestDemo)

# Ép tất cả các target trong dự án dùng chung một Runtime Library
# để sửa lỗi liên kết (linker errors) trên Visual Studio.
if(MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

# --- Phần 2A: Tạo thư viện MathLibrary (file .dll) ---
add_library(MathLibrary SHARED
    src/MathLibrary.cpp
)
target_include_directories(MathLibrary PUBLIC include)
target_compile_definitions(MathLibrary PUBLIC MATHLIBRARY_EXPORTS)

# --- Phần 2B: Tạo thư viện Calculator (file .lib tĩnh) ---
# STATIC nghĩa là code của Calculator sẽ được gộp thẳng vào file .exe.
# Cách này đơn giản và phù hợp cho các lớp nhỏ.
add_library(CalculatorLib STATIC
    src/Calculator.cpp
)
target_include_directories(CalculatorLib PUBLIC include)

# --- Phần 3: Cấu hình Google Test ---
set(gtest_force_shared_crt ON CACHE BOOL "Force shared CRT for gtest")
add_subdirectory(libs/googletest-1.17.0)

# --- Phần 4: Tạo chương trình Test (file .exe) ---
enable_testing()

# Chương trình test sẽ biên dịch CẢ HAI file test.
add_executable(
    RunAllTests
    tests/MathFunctionsTests.cpp
    tests/CalculatorTests.cpp
)

# Chỉ cho trình biên dịch biết nơi tìm các file header của GTest.
target_include_directories(RunAllTests PRIVATE
    ${gtest_SOURCE_DIR}/googletest/include
    ${gtest_SOURCE_DIR}/googlemock/include
)

# Liên kết chương trình test với TẤT CẢ các thư viện cần thiết:
# 1. Thư viện DLL MathLibrary.
# 2. Thư viện tĩnh CalculatorLib.
# 3. Thư viện GTest và GMock.
target_link_libraries(
    RunAllTests
    PRIVATE
    MathLibrary
    CalculatorLib
    gtest_main
    gmock_main
)

# --- Phần 5: Giúp CMake tự động phát hiện các bài test ---
include(GoogleTest)
gtest_discover_tests(RunAllTests)