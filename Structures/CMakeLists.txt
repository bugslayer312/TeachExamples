message(${PROJECT_SOURCE_DIR})

include_directories (${PROJECT_SOURCE_DIR}/DynStructures)

add_executable (Structures
  ${PROJECT_SOURCE_DIR}/DynStructures/Data.cpp
  ${PROJECT_SOURCE_DIR}/DynStructures/Data.h
  main.cpp
)
