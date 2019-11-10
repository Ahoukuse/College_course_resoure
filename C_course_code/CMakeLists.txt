cmake_minimum_required(VERSION 3.10)

project(C_course)

add_definitions("-DLocalhost")
option(Debug 
       "是否开启Debug编译,其实就是启用一个宏'Debug'"
       ON)

if(Debug)

add_definitions("-DDebug")
add_definitions("-Wall -g")

endif(Debug)

define_property(
                TARGET
                PROPERTY f
                BRIEF_DOCS "指定一个默认启动文件呗"
                FULL_DOCS "要啥FULL_DOCS"
)

add_executable(C_course TestModule/AhoTestModule.c ${f})

target_link_libraries(C_course m)