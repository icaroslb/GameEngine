add_library(Math
	"Math/Vector4.h" "Math/Vector4.cpp"
	"Math/Matrix4x4.h" "Math/Matrix4x4.cpp"
	"Math/TransformationMatrix4x4.h" "Math/TransformationMatrix4x4.cpp"
	"SIMD_Math/simd.h"
	"Math/Transformation.h" "Math/Transformation.cpp"
	"Math/Vector2.h" "Math/Vector2.cpp")

target_include_directories(Math PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")