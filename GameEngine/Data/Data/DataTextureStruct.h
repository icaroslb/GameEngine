#ifndef DATA_DATA_TEXTURE_STRUCT_H
#define DATA_DATA_TEXTURE_STRUCT_H

#include <Math/Vector4.h>
#include <Math/Vector2.h>

namespace sge {
	struct DataTextureStruct {
		DataTextureStruct(const Vector4& position, const Vector4& color, const Vector2& tex)
			: _position(position)
			, _color(color)
			, _tex(tex)
		{}

		Vector4 _position;
		Vector4 _color;
		Vector2 _tex;
	};
};

#endif // DATA_DATA_TEXTURE_STRUCT_H