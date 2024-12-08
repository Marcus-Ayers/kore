# Create a shared library for the engine
add_library(Engine SHARED)
find_package(SDL2 REQUIRED)

# Add source files
target_sources(Engine
        PRIVATE
        src/Rendering/Renderer.cpp
        PUBLIC
        include/Rendering/Renderer.h
)

# Add include directories
target_include_directories(Engine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${SDL2_INCLUDE_DIRS}
)

# Specify the output directory for the shared library
set_target_properties(Engine PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Link SDL2 libraries
target_link_libraries(Engine
        PUBLIC
        ${SDL2_LIBRARIES}
)
# Find SDL2 (replace this if find_package is not working)
set(SDL2_INCLUDE_DIRS /opt/homebrew/include/SDL2)
set(SDL2_LIBRARIES /opt/homebrew/lib/libSDL2.dylib)