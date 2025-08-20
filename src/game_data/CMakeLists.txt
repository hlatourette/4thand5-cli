set(LIBRARY_NAME game_data)

add_library(${LIBRARY_NAME} STATIC)

target_link_libraries(${LIBRARY_NAME}
    PUBLIC
    INTERFACE
    PRIVATE
)

target_sources(${LIBRARY_NAME}
    PRIVATE
        game_data.cpp
    INTERFACE
    PUBLIC
        FILE_SET HEADERS
            FILES
                game_data.h
)

target_include_directories(${LIBRARY_NAME}
    PUBLIC
    INTERFACE
    PRIVATE
        .
)

