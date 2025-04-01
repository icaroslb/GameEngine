#include "Texture.h"

#include <glad/glad.h>
#include <stb/stb_image.h>

namespace sge {
	Texture::Texture() {
		// Generate the texture
		glGenTextures(1, &_texture_id);
	}

	Texture::~Texture() {
		// Delete the texture
		glDeleteTextures(1, &_texture_id);
	}

	void Texture::GenerateTexture(const char* image_path, TexId tex_id, Filter min_filter, Filter mag_filter, TexRepeat s_repeat, TexRepeat t_repeat, Vector4 border_color) {
		// Fli the image
		stbi_set_flip_vertically_on_load(true);
		int img_width;
		int img_height;
		int channels;
		// Load it
		unsigned char* texture_data = stbi_load(image_path, &img_width, &img_height, &channels, STBI_rgb_alpha);

		// Activate the texture
		glActiveTexture(tex_id);
		glBindTexture(GL_TEXTURE_2D, _texture_id);

		// Add the filter used
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);

		// And how to wrap it
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, s_repeat);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, t_repeat);

		// If is clamp to border, add the color
		if (s_repeat == GL_CLAMP_TO_BORDER || t_repeat == GL_CLAMP_TO_BORDER) {
			glTextureParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color.data());
		}

		// Pass the texture data and generate the mipmap
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img_width, img_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture_data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(texture_data);

		glBindTexture(GL_TEXTURE_2D, 0);

		_resolution.X() = img_width;
		_resolution.Y() = img_height;
	}

	void Texture::bind() {
		glBindTexture(GL_TEXTURE_2D, _texture_id);
	}

	void Texture::unbind() {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Vector2 Texture::GetResolution() {
		return _resolution;
	}
};