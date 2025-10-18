#pragma once

#include "vs_device.hpp"
#include "vs_pipeline.hpp"
#include "vs_swap_chain.hpp"
#include "vs_window.hpp"

#include <memory>
#include <vector>

namespace vs {

	class FirstApp {

		public:
			static constexpr int WIDTH = 800;
			static constexpr int HEIGHT = 600;

			FirstApp();
			~FirstApp();

			FirstApp(const FirstApp&) = delete;
			FirstApp& operator=(const FirstApp&) = delete;

			void run();

		private:
			void createPipelineLayout();
			void createPipeline();
			void createCommandBuffers();
			void drawFrame();

			VsWindow vsWindow{ WIDTH, HEIGHT, "Hello, Vulkan!" };
			VsDevice vsDevice{ vsWindow };
			VsSwapChain vsSwapChain{ vsDevice, vsWindow.getExtent() };
			std::unique_ptr<VsPipeline> vsPipeline;
			VkPipelineLayout pipelineLayout;
			std::vector<VkCommandBuffer> commandBuffers;
	};
}