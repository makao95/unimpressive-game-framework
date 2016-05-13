#pragma once
#include <SFML/System.hpp>

namespace ugf{

class FrameCounter {
public:
	FrameCounter();
	int getFPS();
    void countFrame();
    sf::Time getFrameTime();
private:
	sf::Clock clock;
	int fps;
    double timeMs;
    sf::Time frameTime;
	int frames;
};

}
