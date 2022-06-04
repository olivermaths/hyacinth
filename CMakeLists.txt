project(HYACINTH)

# files setup
file(GLOB SANDBOX "sandbox/*.cpp")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_library(hyacinth SHARED 
            hyacinth/Application.cpp
            hyacinth/Log.cpp

)

add_subdirectory(hyacinth)

add_executable(${PROJECT_NAME} ${SANDBOX})

target_link_libraries(${PROJECT_NAME} PRIVATE hyacinth)

target_include_directories(${PROJECT_NAME} PRIVATE
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/hyacinth"
                          )



add_custom_command(OUTPUT run
                   COMMAND ./HYACINTH
)