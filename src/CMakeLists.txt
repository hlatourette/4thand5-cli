set(EXECUTABLE_NAME 4thand5)

add_subdirectory(feed)
add_subdirectory(game_data)

add_executable(${EXECUTABLE_NAME})

target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
        ncurses
        feed # local
        game_data  # local
)

target_sources(${EXECUTABLE_NAME}
    PRIVATE
        4thand5.m.cpp
)

target_include_directories(${EXECUTABLE_NAME}
    PRIVATE
        .
)

