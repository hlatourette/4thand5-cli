set(LIBRARY_NAME util)

add_library(${LIBRARY_NAME} STATIC)

target_link_libraries(${LIBRARY_NAME}
    PUBLIC
    INTERFACE
    PRIVATE
)

target_sources(${LIBRARY_NAME}
    PRIVATE
        util.cpp
    INTERFACE
    PUBLIC
        FILE_SET HEADERS
            FILES
                util.h
)

target_include_directories(${LIBRARY_NAME}
    PUBLIC
    INTERFACE
    PRIVATE
        .
)

