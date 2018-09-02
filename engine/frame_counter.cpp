#include "frame_counter.h"
#include <chrono>
#include <vector>
#include <numeric>

std::chrono::milliseconds lastTime;
float deltaTime;
std::vector<float> deltaList;
int currentFps;

void calcFPS()
{
	if (deltaList.size() == 60)
	{
		float avg = std::accumulate(deltaList.begin(), deltaList.end(), 0.0) / deltaList.size();
		int fps = 1 / (avg * 0.001);
		currentFps = fps;
		//std::cout << "Average FPS: " << fps << std::endl;
		deltaList.clear();
	}
}

void calcDelta()
{
	deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - lastTime.count();
	deltaList.push_back(deltaTime);
	lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	calcFPS();
}