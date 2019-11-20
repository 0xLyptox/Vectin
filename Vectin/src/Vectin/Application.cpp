#include <vnpch.h>
#include "Application.h"

namespace Vectin {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::run() {
		WindowResizeEvent ev(10, 10	);
		VN_CORE_TRACE(ev.toString());

		while (true);
	}

}