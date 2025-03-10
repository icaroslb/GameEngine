# CMakeList.txt: projeto de CMake para GameEngine, incluir origem e definir
# lógica específica a um projeto aqui.
#

add_subdirectory(Math)

# Adicione a origem ao executável deste projeto.
add_executable (GameEngine "GameEngine.cpp" "GameEngine.h")

target_link_libraries(GameEngine Math)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GameEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.
