# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/CppCalculator_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CppCalculator_autogen.dir/ParseCache.txt"
  "CppCalculator_autogen"
  )
endif()
