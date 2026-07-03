#pragma once

#include "Application.h"

extern Sakura::Application* Sakura::CreateApplication();

int main(int argc, char** argv) {
	auto app = Sakura::CreateApplication();
	
	int res = app->Run();
	
	delete app;

	return res;
}