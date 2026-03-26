#ifndef ANIMATION_H
#define ANIMATION_H

#include"atlas.h"
#include<graphics.h>
#include"util.h"
#include<functional>

class Animation
	/*动画类，负责管理游戏中的动画效果*/
{
public:
	Animation() = default;
	~Animation() = default;

	void reset()//重置动画状态，将计时器和帧索引重置为初始值
	{
		timer = 0;
		idx_frame = 0;
	}

	void set_atlas(Atlas* atlas)//设置动画使用的图集，参数atlas是一个指向Atlas对象的指针，表示动画将使用该图集中的图像资源
	{
		reset();
		this->atlas = atlas;
	}

	void set_loop(bool loop)//设置动画是否循环播放，参数loop是一个布尔值，如果为true则动画播放完后会重新开始，否则动画播放完后会停止在最后一帧
	{
		is_loop = loop;
	}

	void set_interval(int interval)//设置动画帧间隔，参数interval是一个整数，单位为毫秒，表示每帧动画之间的时间间隔
	{
		this->interval = interval;
	}

	int get_idx_frame() //获取当前动画帧的索引，返回一个整数，表示正在播放的动画帧在图集中的位置
	{
		return idx_frame;
	}

	IMAGE* get_frame()
	{
		return atlas->get_image(idx_frame);
	}

	bool check_finished()//检查动画是否播放完毕，返回一个布尔值，如果动画已经播放完毕则返回true，否则返回false
	{
		if(is_loop)
		{
			return false;
		}
		return idx_frame==atlas->get_size()-1;
	}

	void on_updata(int delta)
	{
		timer += delta;
		if(timer >= interval)
		{
			timer = 0;
			idx_frame++;
			if(idx_frame >= atlas->get_size())
			{
				if(is_loop)
				{
					idx_frame = 0;
				}
				else
				{
					idx_frame = atlas->get_size() - 1;
				}
				if(!is_loop&&callback)
				{
					callback();
				}
			}
		}
	}

	void on_draw(int x, int y) const
	{
		putimage_alpha(x, y,atlas->get_image(idx_frame));
	}

	void set_callback(std::function<void()> callback)
	{
		this->callback = callback;
	}

private:
	int timer = 0;		//动画计时器，用于控制动画的播放速度
	int interval = 0;	//动画帧间隔，单位为毫秒，表示每帧动画之间的时间间隔
	int idx_frame = 0;	//当前动画帧的索引，表示正在播放的动画帧在图集中的位置
	bool is_loop = true;	//是否循环播放动画，如果为true则动画播放完后会重新开始，否则动画播放完后会停止在最后一帧
	Atlas* atlas = nullptr;	//动画使用的图集，指向一个Atlas对象
	std::function<void()> callback;//动画播放完毕后的回调函数，可以在动画播放完毕时执行一些特定的操作，例如触发事件或切换场景
};


#endif // ANIMATION_H
