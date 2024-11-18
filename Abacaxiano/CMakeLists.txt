# Project name
project(Abacaxiano)

set(HEADER_FILES
    "include/Abacaxiano/Core/Config.h"
    "include/Abacaxiano/Core/Logger.h"
    "include/Abacaxiano/Core/Context.h"
    "include/Abacaxiano/Core/Application.h"
    "include/Abacaxiano/Core/EntryPoint.h"
    "include/Abacaxiano/Core/Randy.h"
    "include/Abacaxiano/Core/Window.h"
    "include/Abacaxiano/Abacaxiano.h"
)

set(CPP_FILES
    "src/Core/Logger.cpp"
    "src/Core/Application.cpp"
     "src/Core/Randy.cpp"
     "src/Core/Window.cpp"
)

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