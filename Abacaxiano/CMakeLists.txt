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