#ifndef UTIL_H
#define UTIL_H

#include<graphics.h>

inline void flip_image(IMAGE* src, IMAGE* dst)//翻转图像，src是要翻转的图像，dst是翻转后的图像
{
	int width = src->getwidth();
	int height = src->getheight();
	Resize(dst,width, height);
	DWORD* src_buffer = GetImageBuffer(src);
	DWORD* dst_buffer = GetImageBuffer(dst);

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int src_index = y * width + x;
			int dst_index = y * width + (width - 1 - x);
			dst_buffer[dst_index] = src_buffer[src_index];
		}
	}
}




#endif