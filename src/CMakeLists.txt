set(EXECUTABLE_NAME templateapp)

add_subdirectory(templateapp_util)

add_executable(${EXECUTABLE_NAME})

target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
        templateapplib
)

target_sources(${EXECUTABLE_NAME}
    PRIVATE
        templateapp.m.cpp
)

target_include_directories(${EXECUTABLE_NAME}
    PRIVATE
        .
)
