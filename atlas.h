#ifndef ATLAS_H
#define ATLAS_H

#include<vector>
#include<graphics.h>

class Atlas
	/*图集类，负责加载和管理游戏中的图像资源*/
{
public:
	Atlas() = default;
	~Atlas() = default;

	void load_from_file(LPCTSTR path_template, int num)//从文件加载图像资源，path_template是一个包含占位符的字符串，用于指定图像文件的路径和命名规则，num是要加载的图像数量
	{
		img_list.clear();
		img_list.resize(num);
		TCHAR path_file[256];
		for (int i = 0; i < num; ++i)
		{
			_stprintf_s(path_file, path_template, i+1);
			loadimage(&img_list[i], path_file);
		}
	}

	void clear()//清除图集中的图像资源
	{
		img_list.clear();
	}

	int get_size()//获取图集中的图像数量
	{
		return (int)img_list.size();
	}

	IMAGE* get_image(int index)//根据索引获取图集中的图像资源，返回指向图像的指针，如果索引无效则返回nullptr
	{
		if(index < 0 || index >= img_list.size())
		{
			return nullptr;
		}
		return &img_list[index];
	}

	void add_image(const IMAGE& img)//向图集中添加新的图像资源
	{
		img_list.push_back(img);
	}

private:
	std::vector<IMAGE> img_list;//存储图集中的图像资源的容器
};

#endif