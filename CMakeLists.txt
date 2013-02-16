cmake_minimum_required(VERSION 2.8)
project(librbt)



#Append path to the module path so we can find custom find macros
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake/Modules/")

#specifiy exteral packages
find_package(libusb-1.0 REQUIRED)

#specify include directories
include_directories(${LIBUSB_1_INCLUDE_DIR})

#add sources to exe
add_executable(librbt main.c armfunc.c armfunc.h data.h data.c motors.c motors.h)
#add_executable(librbt main.c ${HEADERS} ${SOURCE})
#link librabrues
target_link_libraries(librbt ${LIBUSB_1_LIBRARY})


#add_subdirectory(headers)
#add_subdirectory(src)