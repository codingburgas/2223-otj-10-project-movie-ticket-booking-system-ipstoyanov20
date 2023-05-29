#pragma once
class SceneManager
{
	public:
	SceneManager();
	~SceneManager();

	enum Scenes : char {
		LOGIN,
		MENU,
	 } direction = MENU;

	
};

