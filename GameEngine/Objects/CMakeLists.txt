add_library(Objects
	 "Objects/ObjectTexture.h" "Objects/ObjectTexture.cpp")

target_include_directories(Objects PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(Objects PRIVATE Math)