cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)

#---- \/ CHANGE THIS \/ ----

set(UK_DIR "/home/cub3d/Development/git/Unknown-1.0-CPP")

#---- \/ DONT CHANGE THIS \/ ----

project("Unknown Game")

set(UK_INCLUDE "${UK_DIR}/Output/lib/${CMAKE_HOST_SYSTEM_NAME}/include")
set(UK_LIB "${UK_DIR}/Output/lib/${CMAKE_HOST_SYSTEM_NAME}")
set(RJ_INCLUDE "${UK_DIR}/Libs/RapidJson/include/rapidjson")

message(${UK_INCLUDE})

set(DEBUG_DIR ${PROJECT_SOURCE_DIR}/run/Debug)
set(RELEASE_DIR ${PROJECT_SOURCE_DIR}/run/Release)

set(CMAKE_MODULE_PATH "${UK_DIR}/tools/build/cmake-scripts")

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
if(WIN32)
    set(Py3_FOUND TRUE)
    set(PYTHON_INCLUDE_DIRS B:\\Programs\\python3.6.6\\include)
    set(PYTHON_LIBRARIES B:\\Programs\\python3.6.6\\libs\\python36.lib)
endif()

#TODO: Make work on windows and add REQUIRED

#find_package(Python3 COMPONENTS Development)
#if(Python3_FOUND)
#    message("Python found: ${Python3_INCLUDE_DIRS}:${Python3_LIBRARIES}")
#endif()

#TODO: Add this back in when cmake 3.12 is available

if(UNIX)
find_package(Py3)
	if(Py3_FOUND)
		message("Python found: ${PYTHON_INCLUDE_DIRS}:${PYTHON_LIBRARIES}")
	endif(Py3_FOUND)
endif(UNIX)

# Find SDL2_mixer
find_package(SDL2_mixer REQUIRED)
if(SDL_MXIXER_FOUND)
    message("SDL2_mixer: ${SDL2_MIXER_INCLUDE_DIR}:${SDL2_MIXER_LIBRARY}")
endif()

if(UNIX)
    # Find box2d
    find_package(Box2D REQUIRED)
endif()
if(WIN32)
    find_package(Box2DWin REQUIRED)
endif()

if(BOX2D_FOUND)
    message("Found box2d: ${BOX2D_INCLUDE_DIR}:${BOX2D_LIBRARY}")
endif(BOX2D_FOUND)

# Find Reflex
set(Reflex_INCLUDE ${UK_DIR}/Libs/Reflex)


include_directories(${UK_INCLUDE} ${RJ_INCLUDE} ${PYTHON_INCLUDE_DIRS} ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} ${BOX2D_INCLUDE_DIR} ${Reflex_INCLUDE})
link_directories(${UK_LIB})

FILE(GLOB_RECURSE GAME_SRC "src/*.cpp")

message("UK: ${UK_LIB}")

add_executable(GameDebug ${GAME_SRC})
target_link_libraries(GameDebug UK ${SDL2_TTF_LIBRARY} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_MIXER_LIBRARY} ${PYTHON_LIBRARIES} ${BOX2D_LIBRARY} ${SDL2MAIN_LIBRARY})
set_target_properties(GameDebug PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DEBUG_DIR})
