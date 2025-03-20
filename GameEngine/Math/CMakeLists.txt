add_library(Math
	"Math/Vector.h" "Math/Vector.cpp"
	"Math/Matrix.h" "Math/Matrix.cpp"
	"Math/TransformationMatrix.h" "Math/TransformationMatrix.cpp"
	"SIMD_Math/simd.h"
	"Math/Transformation.h" "Math/Transformation.cpp"
	"Math/Vector2.h" "Math/Vector2.cpp")

target_include_directories(Math PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")