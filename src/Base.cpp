#include "Base.h"

namespace PopLib
{

	AppBase::AppBase()
	{
	//default to 0 before doing anything else.
	mTitle = nullptr;
	mRegKey = nullptr;
	mWindowWidth = 0;
	mWindowHeight = 0;
	

	}

	AppBase::~AppBase()
	{


	}
	int AppBase::MainWindow(int pWidth, int pHeight)
	{
		mWindowWidth = pWidth;
		mWindowHeight = pHeight;

		sf::Event aPollingEvent;
		sf::RenderWindow aWindowToSpawn;
	

		sf::Window aWindow;
		//get basic stuff for the windows properties.
		aWindow.getPosition(); aWindow.getSettings(); aWindow.getSize(); aWindow.setTitle(mTitle);
		aWindow.setFramerateLimit(60); aWindow.setVisible(1);

		aWindow.pollEvent(aPollingEvent);
		
	
		while (aWindow.isOpen())

			aPollingEvent.Closed;
		aWindow.close();

		return 0;


	}
	void AppBase::Update()
	{






	}

}