#include "first_app.hpp"

#include <stdexcept>

namespace vs {

	FirstApp::FirstApp() {
		createPipelineLayout();
		createPipeline();
		createCommandBuffers();
	}

	FirstApp::~FirstApp() {
		vkDestroyPipelineLayout(vsDevice.device(), pipelineLayout, nullptr);
	}

	void FirstApp::run() {
		while (!vsWindow.shouldClose()) {
			glfwPollEvents();
		}
	}

	void FirstApp::createPipelineLayout() {
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0;
		pipelineLayoutInfo.pSetLayouts = nullptr;
		pipelineLayoutInfo.pushConstantRangeCount = 0;
		pipelineLayoutInfo.pPushConstantRanges = nullptr;

		if (vkCreatePipelineLayout(vsDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
			throw std::runtime_error("failed to create pipeline layout!");
		}
	}

	void FirstApp::createPipeline() {
		auto pipelineConfig = VsPipeline::defaultPipelineConfigInfo(vsSwapChain.width(), vsSwapChain.height());
		pipelineConfig.renderPass = vsSwapChain.getRenderPass();
		pipelineConfig.pipelineLayout = pipelineLayout;
		vsPipeline = std::make_unique<VsPipeline>(vsDevice, "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv", pipelineConfig);
	}

	void FirstApp::createCommandBuffers() {

	}
	
	void FirstApp::drawFrame() {

	}
}