#include "Base.h"

namespace PopLib
{

	AppBase::AppBase()
	{
	//default to 0 before doing anything else.
	mTitle = "";
	mRegKey = "";
	mWindowWidth = 0;
	mWindowHeight = 0;

	}

	AppBase::~AppBase()
	{
	


	}
	void AppBase::GetVideoMode(sf::VideoMode TheMode)
	{
		mWindowWidth = TheMode.width;
		mWindowHeight = TheMode.height;
		mVideoMode = TheMode;

	}
	void AppBase::Start()
	{
		GetVideoMode(mVideoMode);
	}
	void AppBase::Update()
	{
		if (mVideoMode.isValid() == true)
			
			
		mTheWindow.pollEvent(mThePollingEvent);


		while (mTheWindow.isOpen())

		mThePollingEvent.Closed;
		mTheWindow.close();

	}
}
