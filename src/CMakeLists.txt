set(EXECUTABLE_NAME 4thand5)

add_subdirectory(util)

add_executable(${EXECUTABLE_NAME})

target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
        util
)

target_sources(${EXECUTABLE_NAME}
    PRIVATE
        4thand5.m.cpp
)

target_include_directories(${EXECUTABLE_NAME}
    PRIVATE
        .
)

