#pragma once

#include <SFML/Graphics.hpp>

namespace PopLib
{

/**
 * @class Graphics
 * @brief A class responsible for rendering shapes using SFML.
 *
 * The Graphic class provides methods to draw to an SFML RenderWindow.
 */
class Graphics
{

public:
    sf::RenderWindow *mRenderer; ///< Pointer to the SFML RenderWindow used for rendering.

public:
    /**
     * @brief Constructor for the Graphic class.
     * @param renderer A pointer to an SFML RenderWindow used for rendering shapes.
     */
    Graphics(sf::RenderWindow *renderer);

    /**
     * @brief Destructor for the Graphic class.
     */
    ~Graphics();

    /**
     * @brief Draws a shape at a specified position with a given color.
     *
     * This method can draw various types of shapes (e.g., circles, rectangles)
     * based on the provided shape type.
     *
     * @tparam T The type of the shape to be drawn.
     * @param position The position where the shape will be drawn.
     * @param shape The shape object to be drawn.
     * @param color The color of the shape.
     * @param fill A boolean indicating whether the shape should be filled (default is false).
     */
    template <typename T> void DrawShape(sf::Vector2f &position, T &shape, sf::Color color, bool fill = false);

    /**
     * @brief Draws a shape with specified outline and fill properties.
     *
     * This method allows for more customization of the shape's appearance,
     * including outline thickness and colors for both outline and fill.
     *
     * @tparam T The type of the shape to be drawn.
     * @param position The position where the shape will be drawn.
     * @param shape The shape object to be drawn.
     * @param outlineThickness The thickness of the shape's outline.
     * @param outlineColor The color of the shape's outline.
     * @param fillColor The color used to fill the shape.
     * @param fill A boolean indicating whether the shape should be filled (default is false).
     */
    template <typename T>
    void DrawShapeEX(
        sf::Vector2f &position, T &shape, float outlineThickness, sf::Color outlineColor, sf::Color fillColor,
        bool fill = false
    );
};

} // namespace Engine