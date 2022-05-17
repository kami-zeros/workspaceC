cmake_minimum_required(VERSION 3.17)
project(workspaceC)

set(CMAKE_CXX_STANDARD 14)

# 在刷算法的过程中在Clion中是Cmake在管理项目，不能像Dev-c++中那样在一个文件夹下运行多个带main函数的文件。
# 方法一：多写几个以下文件
add_executable(workspaceC
#        C_01/main.cpp
#        C_02/Day02.cpp
#        C_03/main_struct.cpp
#        C_03/main_fun.cpp
#        C_04/DataStore.cpp
#        C_04/DataStore.h
#        C_04/main_object.cpp
        C_04/af_console.cpp
        C_04/af_console.h
#        C_04/student.h
        C_05/student.h
        C_05/main_database.cpp
        C_06/main_class.cpp
        C_06/CmdHandler.h
        C_06/CmdInput.cpp
        C_06/CmdInput.h
        C_06/CmdParser.cpp
        C_06/CmdParser.h
        )

# 方法二：对main进行重定义
# #define main04 main   (你的main函数改为main04)
# #define main04 main04   (运行完后把此重定义的main改为main04，防止其他重名)
