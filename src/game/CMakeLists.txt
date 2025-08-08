set(LIBRARY_NAME game)

add_library(${LIBRARY_NAME} STATIC)

target_link_libraries(${LIBRARY_NAME}
    PUBLIC
    INTERFACE
    PRIVATE
)

target_sources(${LIBRARY_NAME}
    PRIVATE
        game_state.cpp
    INTERFACE
    PUBLIC
        FILE_SET HEADERS
            FILES
                game_state.h
)

target_include_directories(${LIBRARY_NAME}
    PUBLIC
    INTERFACE
    PRIVATE
        .
)

