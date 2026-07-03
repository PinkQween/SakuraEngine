#include <Sakura/Sakura.h>

namespace Sakura {
	class Sandbox : public Application {
	public:
		Sandbox()
		{

		}

		~Sandbox()
		{

		}
	};

	Application* CreateApplication() {
		return new Sandbox();
	}
}