find_package(SDL2 REQUIRED)
#find_package(Vulkan REQUIRED)

add_library(Graphic
	"Graphic/SDL2App.h" "Graphic/SDL2App.cpp"
	  "Graphic/OpenGLApp.h" "Graphic/OpenGLApp.cpp"
	  "Graphic/ShaderProgram.h" "Graphic/ShaderProgram.cpp"
	  "Graphic/Buffer/VertexBuffer.h" "Graphic/Buffer/VertexBuffer.cpp"
	  "Graphic/Buffer/IndexBuffer.h" "Graphic/Buffer/IndexBuffer.cpp"
	  "Graphic/Buffer/Buffer.h" "Graphic/Buffer/Buffer.cpp")

target_include_directories(Graphic PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

# Linux and Window have diferent SDL2 names
if (LINUX)
	target_link_libraries(Graphic PUBLIC SDL2)
endif()
if (WIN32)
	target_link_libraries(Graphic PUBLIC SDL2::SDL2)
endif()

target_link_libraries(Graphic PUBLIC glad)