# CMakeList.txt: projeto de CMake para GameEngine, incluir origem e definir
# lógica específica a um projeto aqui.
#

add_subdirectory(Libraries)
add_subdirectory(Math)
add_subdirectory(Graphic)

# Adicione a origem ao executável deste projeto.
if (LINUX)
	add_executable (GameEngine "GameEngine.cpp" "GameEngine.h")
endif()

if (WIN32)
	add_executable (GameEngine "GameEngine.cpp" "GameEngine.h")
endif()


target_link_libraries(GameEngine Math Graphic)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GameEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Shader/simple_shader.vert" DESTINATION "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/Shader")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Shader/simple_shader.frag" DESTINATION "${CMAKE_BINARY_DIR}/${PROJECT_NAME}/Shader")
