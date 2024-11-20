# Project name
project(Client)

# Add a varaible that includes all header files
set(HEADER_FILES
)

set(CPP_FILES
    "src/main.cpp"
)

#Add the executable
add_executable(${PROJECT_NAME} 
    ${CPP_FILES}
    ${HEADER_FILES}
)

#Linking libraries
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    Abacaxiano
    sfml-graphics
    ${OPENGL_LIBRARIES}
    spdlog::spdlog_header_only
)

# Include header files
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/../Abacaxiano/include
)

# If on Windows, set the executable to be a WIN32 executable
if(WIN32)
	set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif() 

# Add compile definitions 
target_compile_definitions(${PROJECT_NAME} 
	PRIVATE
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<CONFIG:Release>:NDEBUG>
    $<$<CONFIG:Dist>:DIST>
)

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