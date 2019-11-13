#pragma once

#ifdef VN_PLATFORM_WINDOWS

extern Vectin::Application* Vectin::createApplication();

int main(int argc, char** argv) {
	auto application = Vectin::createApplication();
	application->run();
	delete application;
}

#endif