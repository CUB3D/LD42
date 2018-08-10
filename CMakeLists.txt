cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)

#---- \/ CHANGE THIS \/ ----

set(UK_DIR /home/cub3d/Development/git/Unknown-1.0-CPP)

#---- \/ DONT CHANGE THIS \/ ----

project("Unknown Game")

set(UK_INCLUDE ${UK_DIR}/Output/lib/${CMAKE_HOST_SYSTEM_NAME}/include)
set(UK_LIB ${UK_DIR}/Output/lib/${CMAKE_HOST_SYSTEM_NAME})
set(RJ_INCLUDE ${UK_DIR}/Libs/RapidJson/include/rapidjson)

set(DEBUG_DIR ${PROJECT_SOURCE_DIR}/run/Debug)
set(RELEASE_DIR ${PROJECT_SOURCE_DIR}/run/Release)

set(CMAKE_MODULE_PATH ${UK_DIR}/tools/build/cmake-scripts)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb")

# Find SDL2
find_package(SDL2 REQUIRED)
if(SDL2_FOUND)
	message("SDL2 Found: ${SDL2_INCLUDE_DIR}:${SDL2_LIBRARY}")
endif()

# Find SDL2_image
find_package(SDL2_image REQUIRED)
if(SDL2_IMAGE_FOUND)
	message("SDL2_image Found: ${SDL2_IMAGE_INCLUDE_DIR}:${SDL2_IMAGE_LIBRARY}")
endif()

# Find SDL2_ttf
find_package(SDL2_ttf REQUIRED)
if(SDL2_TTF_FOUND)
	message("SDL2_ttf Found: ${SDL2_TTF_INCLUDE_DIR}:${SDL2_TTF_LIBRARY}")
endif()

# Find python
find_package(Py3)
if(PYTHONLIBS_FOUND)
	message("Python found: ${PYTHON_INCLUDE_DIRS}:${PYTHON_LIBRARIES}")
endif()

include_directories(${UK_INCLUDE} ${RJ_INCLUDE} ${PYTHON_INCLUDE_DIRS} ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})
link_directories(${UK_LIB})

FILE(GLOB_RECURSE GAME_SRC "src/*.cpp")

message("UK: ${UK_LIB}")

add_executable(GameDebug ${GAME_SRC})
target_link_libraries(GameDebug UK ${SDL2_TTF_LIBRARY} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${PYTHON_LIBRARIES} pthread dl util m)
set_target_properties(GameDebug PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DEBUG_DIR})
