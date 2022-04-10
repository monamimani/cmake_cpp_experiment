cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

get_filename_component(WorkspaceName ${CMAKE_SOURCE_DIR} NAME)
string(REPLACE " " "_" WorkspaceName ${WorkspaceName})

project(${WorkspaceName})

find_package(GTest CONFIG REQUIRED)
find_package(benchmark CONFIG REQUIRED)

# macro(get_dir_list result curdir)
#     file(GLOB children ${curdir}/*)
#     set(dirlist "")
#     foreach(child ${children})
#         if(IS_DIRECTORY ${child})
#             list(APPEND dirlist ${child})
#         endif()
#     endforeach()
#     set(${result} ${dirlist})
# ENDMACRO()

# get_dir_list(ProjectDirList Projects)

# foreach(subdir ${ProjectDirList})
#   add_subdirectory(${ProjectDirList})
# endforeach()

include(GoogleTest)

if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
enable_testing()

add_subdirectory(Projects/ALib)
add_subdirectory(Projects/App)

