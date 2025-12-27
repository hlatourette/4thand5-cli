set(LIBRARY_NAME feed)

add_library(${LIBRARY_NAME} STATIC)

target_link_libraries(${LIBRARY_NAME}
    PUBLIC
        game_data # local
    INTERFACE
    PRIVATE
)

target_sources(${LIBRARY_NAME}
    PRIVATE
        feed.cpp
    INTERFACE
    PUBLIC
        FILE_SET HEADERS
            FILES
                feed.h
)

target_include_directories(${LIBRARY_NAME}
    PUBLIC
    INTERFACE
    PRIVATE
        .
)

