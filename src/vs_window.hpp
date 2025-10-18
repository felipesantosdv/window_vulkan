#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace vs {

	class VsWindow {

		public:
			VsWindow(int w, int h, std::string name);
			~VsWindow();
			VsWindow(const VsWindow&) = delete;
			VsWindow& operator = (const VsWindow&) = delete;

			bool shouldClose();
			VkExtent2D getExtent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }
			void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

		private:
			GLFWwindow* window;
			const int width;
			const int height;
			std::string windowName;

			void initWindow();

	};
}