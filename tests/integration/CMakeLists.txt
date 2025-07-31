find_package(Catch2 REQUIRED)

add_executable(4thand5.i.t)

target_link_libraries(4thand5.i.t
    PRIVATE
        Catch2::Catch2WithMain
        util
)

target_sources(4thand5.i.t
    PRIVATE
        util.t.cpp
)

