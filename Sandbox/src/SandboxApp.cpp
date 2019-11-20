#include <vnpch.h>
#include <Vectin.h>
#include <iostream>

namespace Vectin {
	class Sandbox : public Application {

	};



	Application* createApplication() {
		return new Sandbox();
	}
}