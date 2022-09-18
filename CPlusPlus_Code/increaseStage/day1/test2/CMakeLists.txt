# 最低版本
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# 工程名
project(cube LANGUAGES CXX)

# 包含所有源文件
aux_source_directory(. SRCS_FILES)

# 生成可执行文件
add_executable(main ${SRCS_FILES})
# add_executable(main main.cpp cube.cpp)