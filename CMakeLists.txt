#cmake的版本不能低于3.25
cmake_minimum_required(VERSION 3.25)
#项目名称
project(CPP_PrimerPlus)
#设置一个变量的值 C++17
set(CMAKE_CXX_STANDARD 17)

#add_executable(CPP_PrimerPlus main.cpp 9_memoryModelAndNameSpace/file2.cpp 9_memoryModelAndNameSpace/9_memoryModelAndNameSpace.cpp)
#添加一个库
#add_library()
#添加一个链接库
#target_link_libraries()
#指定如何安装项目的各个组件
#install()
#添加一个子目录到构建
add_subdirectory(project/StutentManagementSystem)
add_subdirectory(9_memoryModelAndNameSpace)
