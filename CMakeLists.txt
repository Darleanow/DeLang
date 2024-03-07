# CMakeList.txt : CMake project for AST_Interpretor, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("AST_Interpretor")

# Add source to this project's executable.
add_executable (AST_Interpretor "main.cpp" "utils/tokens_types.h" "Lexer/Lexer.h" "utils/Token.h" "utils/Token.cpp" "Lexer/Lexer.cpp")

set_property(TARGET AST_Interpretor PROPERTY CXX_STANDARD 20)


# TODO: Add tests and install targets if needed.
