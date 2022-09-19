# 设置变量
set (Target point)
# 包含头文件
include_directories(./include)
# 包含源文件
aux_source_directory(./source SRC_FILES)
# 生成静态库
add_library(${Target} STATIC ${SRC_FILES})