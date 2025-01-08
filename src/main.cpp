#include "Base.h"

using namespace PopLib;

//this should look extremely familar to the old one used.

//You will still need to use your own code to make your games, like the old one.
//However, you will not need to focus on the old drawing, pointing, etc.  this is direct-access. 
//If you do need to use something that points, please use std::shared_ptr.  
//The PopWidget class is just there for extra support for buttons and such...which will be filled out in the future..

int main(int Arg1, char* Arg2)
{
	AppBase AnApp;
	AnApp.mTitle = ""; //This can be changed to whatever you wish. 
	AnApp.mWindowWidth = 1024;//this can be changed later to fit the users preferences.
	AnApp.mWindowHeight = 768;
	
	AnApp.Start();

	//no Init because the start automatically calls sf::Window, automatically
	//registers, creates the process, and frees it automatically.
	
	AnApp.Update();//get the video mode so this way we can call graphics things...

	

}
