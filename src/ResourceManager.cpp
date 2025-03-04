#include "ResourceManager.h"

#include <filesystem>
using namespace PopLib;

const std::vector<std::string> ResourceManager::TEXTURE_EXTENSIONS = { ".png", ".jpg", ".jpeg" };
const std::vector<std::string> ResourceManager::SOUND_EXTENSIONS = { ".wav", ".ogg"};
const std::vector<std::string> ResourceManager::FONT_EXTENSIONS = { ".ttf", ".otf"};

std::map<std::string, sf::Texture*> ResourceManager::mTextureMap;
std::map<std::string, sf::SoundBuffer*> ResourceManager::mSoundMap;
std::map<std::string, sf::Font*> ResourceManager::mFontMap;

const std::string ResourceManager::DEFAULT_INVALID_TEXTURE = "assets/missing.png";
const std::string ResourceManager::DEFAULT_INVALID_SOUND = "assets/missing.wav";
const std::string ResourceManager::DEFAULT_INVALID_FONT = "assets/missing.ttf";

std::string ResourceManager::mInvalidTexture = ResourceManager::DEFAULT_INVALID_TEXTURE;
std::string ResourceManager::mInvalidSound = ResourceManager::DEFAULT_INVALID_SOUND;
std::string ResourceManager::mInvalidFont = ResourceManager::DEFAULT_INVALID_FONT;

sf::Texture* ResourceManager::GetTexture(const std::string filePath)
{
    for (auto element : mTextureMap)
    {
        if (element.first == filePath && element.first != mInvalidTexture)
            return element.second;
    }

    sf::Texture* texture = new sf::Texture();

    if (!texture->loadFromFile(filePath))
    {
        texture->loadFromFile(mInvalidTexture);
    }

    mTextureMap[filePath] = texture;

    return mTextureMap[filePath];
}

int ResourceManager::GetNumberOfTextures()
{
    return mTextureMap.size();
}

void ResourceManager::PreLoadTextures(const std::string folderPath, bool recurse)
{
    if (recurse)
    {
        for (const auto& entry : std::filesystem::recursive_directory_iterator(folderPath))
        {
            std::filesystem::path fileName = entry.path();
            
            if (!Contains(TEXTURE_EXTENSIONS, fileName.extension().string()))
                continue;
            
            (void*)GetTexture(fileName.string());
        }

        return;
    }

    for (const auto& entry : std::filesystem::directory_iterator(folderPath))
    {
        std::filesystem::path fileName = entry.path();

        if (!Contains(TEXTURE_EXTENSIONS, fileName.extension().string()))
            continue;

        (void*)GetTexture(fileName.string());
    }
}

void ResourceManager::ClearTextures()
{
    for (auto element : mTextureMap)
    {
        delete element.second;
    }

    mTextureMap.clear();
}

std::string ResourceManager::GetInvalidTexturePath()
{
    return mInvalidTexture;
}

sf::SoundBuffer* ResourceManager::GetSoundBuffer(const std::string filePath)
{
    for (auto element : mSoundMap)
    {
        if (element.first == filePath && element.first != mInvalidSound)
            return element.second;
    }

    sf::SoundBuffer* sound = new sf::SoundBuffer();
    sound->loadFromFile(filePath);

    if (!sound->loadFromFile(filePath))
    {
        sound->loadFromFile(mInvalidSound);
    }

    mSoundMap[filePath] = sound;

    return mSoundMap[filePath];
}

int ResourceManager::GetNumberOfSoundBuffers()
{
    return mSoundMap.size();
}

void ResourceManager::PreLoadSoundBuffers(const std::string folderPath, bool recurse)
{
    if (recurse)
    {
        for (const auto& entry : std::filesystem::recursive_directory_iterator(folderPath))
        {
            std::filesystem::path fileName = entry.path();

            if (!Contains(SOUND_EXTENSIONS, fileName.extension().string()))
                continue;

            (void*)GetSoundBuffer(fileName.string());
        }

        return;
    }

    for (const auto& entry : std::filesystem::directory_iterator(folderPath))
    {
        std::filesystem::path fileName = entry.path();

        if (!Contains(SOUND_EXTENSIONS, fileName.extension().string()))
            continue;

        (void*)GetSoundBuffer(fileName.string());
    }
}

void ResourceManager::ClearSoundBuffers()
{
    for (auto element : mSoundMap)
    {
        delete element.second;
    }

    mSoundMap.clear();
}

std::string ResourceManager::GetInvalidSoundPath()
{
    return mInvalidSound;
}

sf::Font* ResourceManager::GetFont(const std::string filePath)
{
    for (auto element : mFontMap)
    {
        if (element.first == filePath && element.first != mInvalidFont)
            return element.second;
    }

    sf::Font* font = new sf::Font();
    font->loadFromFile(filePath);

    if (!font->loadFromFile(filePath))
    {
        font->loadFromFile(mInvalidFont);
    }

    mFontMap[filePath] = font;

    return mFontMap[filePath];
}

int ResourceManager::GetNumberOfFonts()
{
    return mFontMap.size();
}

void ResourceManager::PreLoadFonts(const std::string folderPath, bool recurse)
{
    if (recurse)
    {
        for (const auto& entry : std::filesystem::recursive_directory_iterator(folderPath))
        {
            std::filesystem::path fileName = entry.path();

            if (!Contains(FONT_EXTENSIONS, fileName.extension().string()))
                continue;

            (void*)GetFont(fileName.string());
        }

        return;
    }

    for (const auto& entry : std::filesystem::directory_iterator(folderPath))
    {
        std::filesystem::path fileName = entry.path();

        if (!Contains(FONT_EXTENSIONS, fileName.extension().string()))
            continue;

        (void*)GetFont(fileName.string());
    }
}

std::string ResourceManager::GetInvalidFontPath()
{
    return mInvalidFont;
}

void ResourceManager::ClearFonts()
{
    for (auto element : mFontMap)
    {
        delete element.second;
    }

    mFontMap.clear();
}

bool ResourceManager::Contains(std::vector<std::string> vec, std::string str)
{
    for (std::string s : vec)
    {
        if (s == str)
            return true;
    }
    return false;
}
