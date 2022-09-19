# 包含业务头文件
include_directories(./include)
include_directories(../point/include)
include_directories(../circle/include)

# 增加源文件
aux_source_directory(./source SRC_FILES)

# 生成静态库
add_library(func STATIC ${SRC_FILES})