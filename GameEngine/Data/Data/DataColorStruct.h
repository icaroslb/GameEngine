#ifndef DATA_DATA_STRUCT_H
#define DATA_DATA_STRUCT_H

#include <Math/Vector4.h>

namespace sge {
	struct DataColorStruct {
		DataColorStruct(const Vector4& position, const Vector4& color)
			: _position(position)
			, _color(color)
		{}

		Vector4 _position;
		Vector4 _color;
	};
};

#endif // DATA_DATA_STRUCT_H