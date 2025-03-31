find_package(SDL3 REQUIRED)
#find_package(Vulkan REQUIRED)

add_library(Graphic
	"Graphic/SDL3App.h" "Graphic/SDL3App.cpp"
	  "Graphic/OpenGLApp.h" "Graphic/OpenGLApp.cpp"
	  "Graphic/ShaderProgram.h" "Graphic/ShaderProgram.cpp"
	   
	  "Graphic/Buffer/VAO.h" "Graphic/Buffer/VAO.cpp"
	    "Graphic/Buffer/EBO.h" "Graphic/Buffer/VBO.h" "Graphic/Buffer/VBO.cpp" "Graphic/Buffer/EBO.cpp" "Graphic/Uniform.h" "Graphic/Uniform.cpp" "Graphic/Texture.h" "Graphic/Texture.cpp" "Graphic/Camera.h" "Graphic/Camera.cpp")

target_include_directories(Graphic PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

# Linux and Window have diferent SDL2 names
if (LINUX)
	target_link_libraries(Graphic PUBLIC SDL3)
endif()
if (WIN32)
	target_link_libraries(Graphic PUBLIC SDL3::SDL3)
endif()

target_link_libraries(Graphic PUBLIC glad stb Math)