#include <Vectin.h>

class Sandbox : public Vectin::Application {

};

Vectin::Application* Vectin::createApplication() {
	return new Sandbox();
}