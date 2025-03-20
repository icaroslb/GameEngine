#ifndef OBJECTS_OBJECT_TEXTURE_H
#define OBJECTS_OBJECT_TEXTURE_H

#include <Math/Vector.h>
#include <Math/Vector2.h>

namespace geb {
	class ObjectTexture {
	public:
		ObjectTexture(Vector position, Vector color, Vector2 tex);
		ObjectTexture(const ObjectTexture& ot);

		ObjectTexture& operator=(const ObjectTexture& ot);

		static size_t GetSize();
		static size_t GetdataSize(unsigned int offset_id);
		static void* GetOffsets(unsigned int offset_id);
	private:
		Vector _position;
		Vector _color;
		Vector2 _tex;
	};
};

#endif // OBJECTS_OBJECT_TEXTURE_H