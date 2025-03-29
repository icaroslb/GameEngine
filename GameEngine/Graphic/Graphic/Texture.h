#ifndef GRAPHIC_TEXTURE_H
#define GRAPHIC_TEXTURE_H

#include <Math/Vector4.h>

namespace geb {
	enum TexId {
		TEXTURE0 = 0x84C0,
		TEXTURE1 = 0x84C1,
		TEXTURE2 = 0x84C2,
		TEXTURE3 = 0x84C3,
		TEXTURE4 = 0x84C4,
		TEXTURE5 = 0x84C5,
		TEXTURE6 = 0x84C6,
		TEXTURE7 = 0x84C7,
		TEXTURE8 = 0x84C8,
		TEXTURE9 = 0x84C9,
		TEXTURE10 = 0x84CA,
		TEXTURE11 = 0x84CB,
		TEXTURE12 = 0x84CC,
		TEXTURE13 = 0x84CD,
		TEXTURE14 = 0x84CE,
		TEXTURE15 = 0x84CF,
		TEXTURE16 = 0x84D0,
		TEXTURE17 = 0x84D1,
		TEXTURE18 = 0x84D2,
		TEXTURE19 = 0x84D3,
		TEXTURE20 = 0x84D4,
		TEXTURE21 = 0x84D5,
		TEXTURE22 = 0x84D6,
		TEXTURE23 = 0x84D7,
		TEXTURE24 = 0x84D8,
		TEXTURE25 = 0x84D9,
		TEXTURE26 = 0x84DA,
		TEXTURE27 = 0x84DB,
		TEXTURE28 = 0x84DC,
		TEXTURE29 = 0x84DD,
		TEXTURE30 = 0x84DE,
		TEXTURE31 = 0x84DF
	};
	
	enum TexType {
		TEXTURE_1D = 0x0DE0,
		TEXTURE_2D = 0x0DE1
	};

	enum TexRepeat {
		CLAMP_TO_EDGE        = 0x812F,
		CLAMP_TO_BORDER      = 0x812D,
		MIRRORED_REPEAT      = 0x8370,
		REPEAT               = 0x2901,
		MIRROR_CLAMP_TO_EDGE = 0x8743
	};

	enum Filter {
		NEAREST                = 0x2600,
		LINEAR                 = 0x2601,
		NEAREST_MIPMAP_NEAREST = 0x2700,
		LINEAR_MIPMAP_NEAREST  = 0x2701,
		NEAREST_MIPMAP_LINEAR  = 0x2702,
		LINEAR_MIPMAP_LINEAR   = 0x2703
	};

	class Texture {
	public:
		Texture();
		~Texture();

		Texture(const Texture&) = delete;
		Texture operator=(const Texture&) = delete;

		void GenerateTexture(
			const char* image_path, TexId tex_id,
			Filter min_filter, Filter mag_filter,
			TexRepeat s_repeat, TexRepeat t_repeat, Vector4 border_color = Vector4(0.0f, 0.0f, 0.0f, 1.0f));

		void bind();
		void unbind();
	private:
		unsigned int _texture_id;
	};
};

#endif // GRAPHIC_TEXTURE_H