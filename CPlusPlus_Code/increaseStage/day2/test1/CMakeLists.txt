# 版本要求
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# 工程
project(test LANGUAGES CXX)

# 依赖头文件
include_directories(./circle/include)
include_directories(./point/include)
include_directories(./func/include)
include_directories(./circle/include)
# 依赖文件
aux_source_directory(. SRCS_FILES)

# 增加子库
add_subdirectory(./circle circle)
add_subdirectory(./point point)

# 寻找静态库
link_directories(
    ./func/lib
)

# 寻找静态库
# link_libraries(
 #   libfunc.a
#)
# 生成可执行文件
add_executable(main ${SRCS_FILES})

# 链接库
target_link_libraries(main func circle point)
# target_link_libraries(main  circle point)