add_library(Cubes
	 "Cubes/Cube.h" "Cubes/Cube.cpp"
	 "Cubes/CubeTexture.h" "Cubes/CubeTexture.cpp"
	 "Cubes/CubeCreator.h" "Cubes/CubeCreator.cpp"
	 "Cubes/CubeColor.h" "Cubes/CubeColor.cpp"
	 "Cubes/CubeTextureModel.h" "Cubes/CubeTextureModel.cpp"
	 "Cubes/CubeTextureCreator.h" "Cubes/CubeTextureCreator.cpp")

target_include_directories(Cubes PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(Cubes PUBLIC Data Graphic)