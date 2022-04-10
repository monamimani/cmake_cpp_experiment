
# file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp" "*.cxx" "*.ixx")
# file(GLOB_RECURSE headers CONFIGURE_DEPENDS "*.h" "*.hpp")

add_library(ALib
    ALib/ALib.cpp)

target_include_directories(ALib
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
)

# enable_testing()
# find_package(GTest REQUIRED)