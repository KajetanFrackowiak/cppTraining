// Cherno.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <chrono>

struct Timer {
	std::chrono::time_point<std::chrono::steady_clock> start, endl;
	std::chrono::duration<float> duration;

	Timer();
	~Timer();
};

void Function();

// TODO: Reference additional headers your program requires here.
