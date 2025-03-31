#include "ObjectTexture.h"

namespace geb {
	ObjectTexture::ObjectTexture(const Vector4& position, const Vector4& color, const Vector2& tex)
		: _position(position)
		, _color(color)
		, _tex(tex)
	{}

	ObjectTexture::ObjectTexture(const ObjectTexture& ot) {
		_position = ot._position;
		_color = ot._color;
		_tex = ot._tex;
	}

	ObjectTexture& ObjectTexture::operator=(const ObjectTexture& ot) {
		if (this != &ot) {
			_position = ot._position;
			_color = ot._color;
			_tex = ot._tex;
		}

		return *this;
	}

	size_t ObjectTexture::GetSize() {
		return sizeof(ObjectTexture);
	}

	size_t ObjectTexture::GetdataSize(unsigned int data_id) {
		size_t data_size;

		switch (data_id) {
		case 0:
			data_size = 4;
			break;
		case 1:
			data_size = 4;
			break;
		case 2:
			data_size = 2;
			break;
		default:
			data_size = 0;
		}

		return data_size;
	}

	void* ObjectTexture::GetOffsets(unsigned int offset_id) {
		void* offset;
		
		switch (offset_id) {
		case 0:
			offset = (void*)0;
			break;
		case 1:
			offset = (void*)sizeof(Vector4);
			break;
		case 2:
			offset = (void*)(2 * sizeof(Vector4));
			break;
		default:
			offset = (void*)0;
		}

		return offset;
	}
};