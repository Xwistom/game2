#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_


#include"scene.h"
#include"scene_manager.h"
#include<iostream>

extern SceneManager scene_manager;

class GameScene :public Scene
	/*游戏局内界面*/ 
{
public:
	GameScene() {}
	~GameScene() {}

	void on_enter()
	{
		std::cout << "进入游戏局内界面" << std::endl;
	}

	void on_update()
	{
		std::cout << "游戏正在运行..." << std::endl;
	}

	void on_draw()
	{
		outtextxy(10, 10, _T("游戏局内绘图内容"));
	}

	void on_input(const ExMessage& msg)
	{
		if(msg.message == WM_KEYDOWN)
		{
			scene_manager.switch_to(SceneManager::SceneType::Menu);
		}	
	}

	void on_exit()
	{
		std::cout << "游戏局内退出" << std::endl;
	}
private:


};




#endif