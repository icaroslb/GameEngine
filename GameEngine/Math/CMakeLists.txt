add_library(Math
	"Math/Vector.h" "Math/Vector.cpp"
	"Math/Matrix.h" "Math/Matrix.cpp"
	"Math/TransformationMatrix.h"
	"SIMD_Math/simd.h")

target_include_directories(Math PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")