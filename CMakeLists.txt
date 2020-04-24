cmake_minimum_required (VERSION 3.5)
project(protobuf_test)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3 -pthread")

#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -pthread -Wall")
#SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -g")
#SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -g")


find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

FILE(GLOB PROTO_FILES "${CMAKE_CURRENT_SOURCE_DIR}/proto/*.proto")
message(${PROTO_FILES})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})
message(${PROTO_SRCS})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src ALL_SOURCES)
add_executable(${PROJECT_NAME} ${ALL_SOURCES} ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES})

