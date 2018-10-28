cmake_minimum_required(VERSION 3.0)
project(test_protobuf)
set(CMAKE_CXX_STANDARD 14)
find_package(Protobuf REQUIRED)

set(PROTO_HEADER_FILES ${PROJECT_SOURCE_DIR}/proto/build/addressbook.pb.h)
set(PROTO_SRC_FILES ${PROJECT_SOURCE_DIR}/proto/build/addressbook.pb.cc)

## v1
#include_directories(
#        ${PROJECT_SOURCE_DIR}
#        ${PROJECT_SOURCE_DIR}/proto/build
#)
#add_executable(write_protobuf writer.cpp ${PROTO_HEADER_FILES} ${PROTO_SRC_FILES})
#target_link_libraries(write_protobuf ${PROTOBUF_LIBRARY})
#add_executable(read_protobuf reader.cpp ${PROTO_HEADER_FILES} ${PROTO_SRC_FILES})
#target_link_libraries(read_protobuf ${PROTOBUF_LIBRARY})

### v2
#add_executable(write_protobuf writer.cpp ${PROTO_HEADER_FILES} ${PROTO_SRC_FILES})
#target_link_libraries(write_protobuf ${PROTOBUF_LIBRARY})
#target_include_directories(write_protobuf PRIVATE proto/build)
#add_executable(read_protobuf reader.cpp ${PROTO_HEADER_FILES} ${PROTO_SRC_FILES})
#target_link_libraries(read_protobuf ${PROTOBUF_LIBRARY})
#target_include_directories(read_protobuf PRIVATE proto/build)


## v3
include_directories(
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/proto/build
)
add_library(proto ${PROTO_HEADER_FILES} ${PROTO_SRC_FILES})
add_executable(write_protobuf writer.cpp ${PROTO_HEADER_FILES} ${PROTO_SRC_FILES})
target_link_libraries(write_protobuf proto ${PROTOBUF_LIBRARY})
add_executable(read_protobuf reader.cpp ${PROTO_HEADER_FILES} ${PROTO_SRC_FILES})
target_link_libraries(read_protobuf proto ${PROTOBUF_LIBRARY})