cmake_minimum_required(VERSION 3.10)
project(2DCollisionEngine LANGUAGES CXX VERSION 1.0)

#设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#收集所有源文件
set(SOURCE_FILES
    # main_test/function_in_main
    main_test/function_in_main/add_a_circle.cpp
    main_test/function_in_main/add_a_polygon.cpp
    main_test/function_in_main/graphic_create.cpp
    main_test/main.cpp

    # src/collision_visitor
    src/collision_visitor/get_normals.cpp
    src/collision_visitor/is_circle_circle_collision.cpp
    src/collision_visitor/is_polygon_circle_collision.cpp
    src/collision_visitor/is_polygon_polygon_collision.cpp
    src/collision_visitor/projection.cpp

    # src/collision_response
    src/collision_response/circle_circle_collision.cpp
    src/collision_response/circle_polygon_collision.cpp
    src/collision_response/polygon_polygon_collision.cpp

    # src/collision_world
    src/collision_world/collision_edge_detect.cpp

    # src/polygon_object
    src/polygon_object/cal_axis_type.cpp
    src/polygon_object/cal_centroid.cpp
    src/polygon_object/cal_moment_of_inertia.cpp
    src/polygon_object/update.cpp
)

#生成可执行文件
add_executable(CollisionEngineTest
    ${SOURCE_FILES}
)

#构建目录
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})