#include "Graphics.h"


using namespace sf;

namespace PopLib
{

Graphics::Graphics(RenderWindow *renderer)
{
    mRenderer = renderer;
}

Graphics::~Graphics()
{
}

template <typename T> void Graphics::DrawShape(Vector2f &position, T &shape, Color color, bool fill)
{
    shape.setPosition(position);
    shape.setOutlineColor(color);

    if (fill) shape.setFillColor(color);

    mRenderer->draw(shape);
}

template <typename T>
void Graphics::DrawShapeEX(
    Vector2f &position, T &shape, float outlineThickness, Color outlineColor, Color fillColor, bool fill
)
{
    shape.setPosition(position);
    shape.setOutlineColor(outlineColor);
    shape.setOutlineThickness(outlineThickness);

    if (fill) shape.setFillColor(fillColor);

    mRenderer->draw(shape);
}

} // namespace Engine