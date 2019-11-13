#pragma once

#include "Core.h"

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
