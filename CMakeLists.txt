# project
cmake_minimum_required (VERSION 2.6)
project (libicp)

# directories
set (LIBICP_SRC_DIR src)

# include directory
include_directories("${LIBICP_SRC_DIR}")

include_directories("C:/Program Files (x86)/boost/boost_1_47")

# make release version
set(CMAKE_BUILD_TYPE Release)

add_library(icp src/icp.cpp src/icpPointToPlane.cpp src/icpPointToPoint.cpp src/kdtree.cpp src/matrix.cpp)

# build demo program
add_executable(icp_demo src/demo.cpp)
target_link_libraries(icp_demo icp)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /clr")
# Give CLR-compatible errors
STRING(REPLACE "/EHs" "/EHa" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
add_library(icp_net SHARED src/icp_net.cpp)
target_link_libraries (icp_net icp)


