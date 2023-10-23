cmake_minimum_required(VERSION 3.10)

project(hps_server)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -ggdb -std=c++11 -Wall -lpthread -lmysqlclient")

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(/usr/include)
link_directories(/usr/lib)

# set(LIB_SRC
#     ./CGImysql/sql_connection_pool.cpp
#     ./CGImysql/sql_connection_pool.h
#     ./http/http_conn.cpp
#     ./http/http_conn.h
#     ./lock/locker.h
#     ./log/log.h
#     ./log/block_queue.h
#     ./log/log.cpp
#     ./threadpool/threadpool.h
#     ./timer/lst_timer.cpp
#     ./timer/lst_timer.h
#     ./config.cpp
#     ./config.h
#     ./webserver.cpp
#     ./webserver.h
# )
#生成静态库
# add_library(hps_server STATIC ${LIB_SRC})

# 生成依赖
set(DEN
    ./CGImysql/sql_connection_pool.cpp
    ./http/http_conn.cpp
    ./log/log.cpp
    ./timer/lst_timer.cpp
    ./config.cpp
    ./webserver.cpp
)

add_executable(server main.cpp ${DEN})
target_link_libraries(server mysqlclient pthread)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
install(TARGETS server RUNTIME DESTINATION bin)



