add_library(Data
	 "Data/VBOTextureData.h" "Data/VBOTextureData.cpp"
	 "Data/VBOColorData.h" "Data/VBOData.cpp"
	 "Data/DataColorStruct.h"
	 "Data/VAOData.h" "Data/VAOData.cpp"
	 "Data/VAODataCreator.h"
	 "Data/VBOData.h"
	 "Data/DataColorStruct.h"
	 "Data/DataTextureStruct.h"
)

target_include_directories(Data PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(Data PRIVATE Math Graphic)