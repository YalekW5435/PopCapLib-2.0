################################################################################
# Sources
################################################################################
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

# you can add more sub Directories by just adding the add_subdirectory and a new CMake
# list file into that directory
# everything related to code should be under the /src/ folder

target_sources(${PROJECT_NAME} PRIVATE
    "Base.h" "Base.cpp"
    "ResourceManager.h" "ResourceManager.cpp"
    "main.cpp"
)
