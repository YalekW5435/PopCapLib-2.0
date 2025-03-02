 #pragma once

#include <map>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class ResourceManager
{
private:
	static std::map<std::string, sf::Texture*> mTextureMap;
	static std::map<std::string, sf::SoundBuffer*> mSoundMap;
	static std::map<std::string, sf::Font*> mFontMap;

	const static std::string DEFAULT_INVALID_TEXTURE;
	const static std::string DEFAULT_INVALID_SOUND;
	const static std::string DEFAULT_INVALID_FONT;

	static std::string mInvalidTexture;
	static std::string mInvalidSound;
	static std::string mInvalidFont;

	const static std::vector<std::string> TEXTURE_EXTENSIONS;
	const static std::vector<std::string> SOUND_EXTENSIONS;
	const static std::vector<std::string> FONT_EXTENSIONS;
	
public:
	static sf::Texture* GetTexture(const std::string filePath);
	static int GetNumberOfTextures();

	static void PreLoadTextures(const std::string folderPath, bool recurse = true);
	static std::string GetInvalidTexturePath();

	static void ClearTextures();

	static sf::SoundBuffer* GetSoundBuffer(const std::string filePath);
	static int GetNumberOfSoundBuffers();


	static void PreLoadSoundBuffers(const std::string folderPath, bool recurse = true);
	static std::string GetInvalidSoundPath();

	static void ClearSoundBuffers();

	static sf::Font* GetFont(const std::string filePath);
	static int GetNumberOfFonts();

	static void PreLoadFonts(const std::string folderPath, bool recurse = true);
	static std::string GetInvalidFontPath();

	static void ClearFonts();

	static bool Contains(std::vector<std::string> vec, std::string str);
