#include "Base.h"

using namespace sf;

namespace PopLib
{

std::shared_ptr<AppBase> gAppBase;

AppBase::AppBase()
{
    mWindow = std::make_unique<RenderWindow>(VideoMode(800, 600), "PopLib");
    gAppBase = std::shared_ptr<AppBase>(this);
}

void AppBase::Start()
{
    mMainView.reset(FloatRect(0.0f, 0.0f, 800.0f, 600.0f));
    mWindow->setView(mMainView);

    while (IsWindowOpen())
        Update();
}

void AppBase::Stop()
{
}

void AppBase::Update()
{
    PollEvent();

    mWindow->clear();
    //TODO: Draw shit here.
    mWindow->display();
}

void AppBase::PollEvent()
{
    Event event;

    while (mWindow->pollEvent(event))
    {
        switch (event.type)
        {
        case Event::EventType::Closed: mWindow->close(); break;

        default: break;
        }
    }
}

bool AppBase::IsWindowOpen()
{
    return mWindow->isOpen();
}

} // namespace PopLib