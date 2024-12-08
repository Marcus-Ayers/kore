# Create the Sandbox executable
add_executable(Sandbox src/application.cpp)

# Link the Engine library
target_link_libraries(Sandbox PRIVATE Engine)

add_custom_command(TARGET Sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Engine> $<TARGET_FILE_DIR:Sandbox>
)

# Include Engine's include directory
target_include_directories(Sandbox PRIVATE ${CMAKE_SOURCE_DIR}/Engine/include)

# Specify the output directory for the executable
set_target_properties(Sandbox PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

