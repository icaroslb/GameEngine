#ifndef OBJECTS_OBJECT_TEXTURE_H
#define OBJECTS_OBJECT_TEXTURE_H

#include <Math/Vector4.h>
#include <Math/Vector2.h>

namespace geb {
	class ObjectTexture {
	public:
		ObjectTexture(Vector4 position, Vector4 color, Vector2 tex);
		ObjectTexture(const ObjectTexture& ot);

		ObjectTexture& operator=(const ObjectTexture& ot);

		static size_t GetSize();
		static size_t GetdataSize(unsigned int offset_id);
		static void* GetOffsets(unsigned int offset_id);
	private:
		Vector4 _position;
		Vector4 _color;
		Vector2 _tex;
	};
};

#endif // OBJECTS_OBJECT_TEXTURE_H