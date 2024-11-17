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