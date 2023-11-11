# CMakeList.txt : CMake project for HW2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("HW2")

# Find SDL2
find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} ...)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE
    SDL2::SDL2
    SDL2::SDL2main)

# Link SDL2 libraries
target_link_libraries(YourExecutable PRIVATE ${SDL2_LIBRARIES})

# Add source to this project's executable.
add_executable (HW2 "HW2.cpp" "HW2.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HW2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
