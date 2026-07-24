# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CRUD-GYM_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CRUD-GYM_autogen.dir\\ParseCache.txt"
  "CRUD-GYM_autogen"
  )
endif()
