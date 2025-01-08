#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include <map>
#include <memory>
#include <string>

namespace PopLib
{

/**
 * @class AppBase
 * @brief Main AppBase class.
 *
 * The AppBase class serves as the core of the Cherinux game AppBase,
 * managing the main game loop, resource management, and event polling.
 */
class AppBase
{

public:
    sf::Clock mDTClock; ///< Clock used to track delta time.
    sf::View mMainView;

    std::unique_ptr<sf::RenderWindow> mWindow;

public:
    AppBase(const AppBase &e) = delete; ///< Deleted copy constructor to prevent copying.

    /**
     * @brief Constructor for the AppBase class.
     *
     * Initializes the AppBase and its components.
     */
    AppBase();

    /**
     * @brief Destructor for the AppBase class.
     *
     * Cleans up resources used by the AppBase.
     */
    ~AppBase() = default;

    /**
     * @brief Starts the AppBase and begins the main game loop.
     *
     * This method initializes the AppBase and enters the main loop,
     * where it continuously updates and renders the game.
     */
    void Start();

    /**
     * @brief Stops the AppBase and exits the main game loop.
     *
     * This method gracefully shuts down the AppBase and releases resources.
     */
    void Stop();

    /**
     * @brief Updates the AppBase state.
     *
     * This method is called every frame to update game logic,
     * handle input, and manage resources.
     */
    void Update();

    /**
     * @brief Polls for events from the window.
     *
     * This method retrieves and processes events such as keyboard
     * and mouse input, ensuring the game responds to user actions.
     */
    void PollEvent();

    /**
     * @brief Checks if the window should close.
     *
     * @return True if the window should close, false otherwise.
     */
    bool IsWindowOpen();
};

extern std::shared_ptr<AppBase> gAppBase;

} // namespace PopLib