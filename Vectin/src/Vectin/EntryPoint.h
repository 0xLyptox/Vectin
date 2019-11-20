#pragma once

#ifdef VN_PLATFORM_WINDOWS

extern Vectin::Application* Vectin::createApplication();

int main(int argc, char** argv) {
	Vectin::Log::init();
	VN_CORE_CRITICAL("charon is gay");

	auto application = Vectin::createApplication();

	application->run();
	delete application;
}

#endif