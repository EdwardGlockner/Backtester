# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BackTester_autogen"
  "CMakeFiles/BackTester_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/BackTester_autogen.dir/ParseCache.txt"
  )
endif()
