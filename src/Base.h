#pragma once
//Popcap library 2.00.  Made to complement Brian Fiete's SexyAppbase by combining some of his stuff
//with a more modern approach.  Uses C++17 and cmake to generate to a final executable.
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <cstdint>

#include "Graphics.h"

// https://en.sfml-dev.org/documentation/3.0.0/ // For ease of access. I will throw this comment latter.
#include <SFML/Graphics/RenderWindow.hpp>
namespace PopLib
{


	class sf::Image;
	class sf::Font; //No more image font.  It will be based here instead.  Will be wrapped with SFML later...
	class PopWidget;//widgets will now be used upon a standard 60fps scale but will probably not use legacy code..
	class PopGraphics;
	
	class AppBase
	{	
	public:
		sf::Event mThePollingEvent;
		sf::Window mTheWindow;
		int mWindowWidth;//800??
		int mWindowHeight;//600??
		std::string mTitle;
		std::string mRegKey;
		sf::VideoMode mVideoMode;


		AppBase();
		~AppBase();
		void Start();
		void Update();
		void GetVideoMode(sf::VideoMode TheMode);
		
		
		
	};

}
