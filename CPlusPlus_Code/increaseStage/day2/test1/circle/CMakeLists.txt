# 包含头文件
include_directories(./include)
include_directories(../point/include)
# 包含源文件
aux_source_directory(./source SRC_FILES)
# 生成静态库
add_library(circle STATIC ${SRC_FILES})