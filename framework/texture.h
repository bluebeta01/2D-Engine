#pragma once
#pragma warning (disable : 4996)
#include <png.h>


namespace framework
{
	namespace render
	{
		struct Texture
		{
			int x, y;

			int width, height;
			png_byte color_type;
			png_byte bit_depth;

			png_structp png_ptr;
			png_infop info_ptr;
			int number_of_passes;
			png_bytep * row_pointers;

			static Texture read_png_file(const char* file_name)
			{
				char header[8];    // 8 is the maximum size that can be checked

				Texture tex;

								   /* open file and test for it being a png */
				FILE *fp = fopen(file_name, "rb");

				fread(header, 1, 8, fp);



				/* initialize stuff */
				tex.png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);



				tex.info_ptr = png_create_info_struct(tex.png_ptr);


				png_init_io(tex.png_ptr, fp);
				png_set_sig_bytes(tex.png_ptr, 8);

				png_read_info(tex.png_ptr, tex.info_ptr);

				tex.width = png_get_image_width(tex.png_ptr, tex.info_ptr);
				tex.height = png_get_image_height(tex.png_ptr, tex.info_ptr);
				tex.color_type = png_get_color_type(tex.png_ptr, tex.info_ptr);
				tex.bit_depth = png_get_bit_depth(tex.png_ptr, tex.info_ptr);

				tex.number_of_passes = png_set_interlace_handling(tex.png_ptr);
				png_read_update_info(tex.png_ptr, tex.info_ptr);




				tex.row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * tex.height);
				for (tex.y = 0; tex.y<tex.height; tex.y++)
					tex.row_pointers[tex.y] = (png_byte*)malloc(png_get_rowbytes(tex.png_ptr, tex.info_ptr));

				png_read_image(tex.png_ptr, tex.row_pointers);

				fclose(fp);

				return tex;
			}
		};
	}
}