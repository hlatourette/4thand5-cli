set(LIBRARY_NAME templateapplib)

add_library(${LIBRARY_NAME} STATIC)

target_link_libraries(${LIBRARY_NAME}
    PUBLIC
    INTERFACE
    PRIVATE
)

target_sources(${LIBRARY_NAME}
    PRIVATE
        templateapp_util.cpp
    INTERFACE
    PUBLIC
        FILE_SET HEADERS
            FILES
                templateapp_util.h
)

target_include_directories(${LIBRARY_NAME}
    PUBLIC
    INTERFACE
    PRIVATE
        .
)
