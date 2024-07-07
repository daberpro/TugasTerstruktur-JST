#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Matplot++::nodesoup" for configuration "Debug"
set_property(TARGET Matplot++::nodesoup APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Matplot++::nodesoup PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/Matplot++/libnodesoup.a"
  )

list(APPEND _cmake_import_check_targets Matplot++::nodesoup )
list(APPEND _cmake_import_check_files_for_Matplot++::nodesoup "${_IMPORT_PREFIX}/lib/Matplot++/libnodesoup.a" )

# Import target "Matplot++::matplot" for configuration "Debug"
set_property(TARGET Matplot++::matplot APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Matplot++::matplot PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libmatplot.a"
  )

list(APPEND _cmake_import_check_targets Matplot++::matplot )
list(APPEND _cmake_import_check_files_for_Matplot++::matplot "${_IMPORT_PREFIX}/lib/libmatplot.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
