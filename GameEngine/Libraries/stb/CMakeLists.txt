add_library(stb
	"Include/stb/stb_image.h" "src/stb.cpp")

target_include_directories(stb PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")