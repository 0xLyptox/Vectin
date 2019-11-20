#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Vectin {
	class VECTIN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* createApplication();

}
