add_subdirectory(integration)
add_subdirectory(unit)

add_test(NAME unittest COMMAND templateapp.u.t)
