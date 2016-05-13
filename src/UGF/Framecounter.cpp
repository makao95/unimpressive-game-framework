#include "UGF/Framecounter.h"
#include <iostream>
using namespace ugf;

FrameCounter::FrameCounter():fps(0), frames(0), timeMs(0) {
}

int FrameCounter::getFPS() {
    if (timeMs >= 1000) {
        fps = frames*1000/timeMs;
        timeMs -= 1000;
		frames = 0;
	}
	return fps;
}

sf::Time FrameCounter::getFrameTime(){
    return frameTime;
}

void FrameCounter::countFrame() {
    frameTime = clock.getElapsedTime();
    timeMs += frameTime.asMilliseconds();
	clock.restart();
    frames++;
}
