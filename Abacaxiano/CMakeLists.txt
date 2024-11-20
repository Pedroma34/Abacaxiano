# Project name
project(Abacaxiano)

#Get all the cpp files inside src folder
file(GLOB_RECURSE CPP_FILES "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "include/*.h")

#Add the executable
add_library(${PROJECT_NAME}
    STATIC # this means that the library is static
    ${CPP_FILES} 
    ${HEADER_FILES}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    sfml-graphics
    ${OPENGL_LIBRARIES}
    spdlog::spdlog_header_only
)

# Include header files
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include/Abacaxiano
)

# Add compile definitions 
target_compile_definitions(${PROJECT_NAME} 
	PRIVATE
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<CONFIG:Release>:NDEBUG>
    $<$<CONFIG:Dist>:DIST>
)

# Static sfml
add_definitions(-DSFML_STATIC)

#Setting the Project as the startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

# Function to group files by their directory structure
function(group_sources_by_folder)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    foreach(file IN LISTS ARGN)
        # Get the directory of the file
        get_filename_component(dir ${file} DIRECTORY)

        # Make the path relative to the project directory
        string(REPLACE "${PROJECT_SOURCE_DIR}/" "" dir ${dir})
        
        # Replace forward slashes with backslashes for Visual Studio compatibility
        string(REPLACE "/" "\\" dir ${dir})

        # Group files by this relative directory
        source_group(${dir} FILES ${file})
    endforeach()
endfunction()

# Group the source files
group_sources_by_folder(${CPP_FILES} ${HEADER_FILES})