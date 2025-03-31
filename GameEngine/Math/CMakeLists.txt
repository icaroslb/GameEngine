add_library(Math
	"Math/Vector4.h" "Math/Vector4.cpp"
	"Math/Matrix4.h" "Math/Matrix4.cpp"
	"Math/TransformationMatrix4.h" "Math/TransformationMatrix4.cpp"
	"SIMD_Math/simd.h"
	"Math/Transformation.h" "Math/Transformation.cpp"
	"Math/Vector2.h" "Math/Vector2.cpp")

target_include_directories(Math PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")