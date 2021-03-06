#pragma once

#include "../Vulkan/device.h"
#include "../Descriptor/descriptorpoolbuilder.h"
#include "../Descriptor/descriptorsetlayoutbuilder.h"
#include "../Pass/pipelinelayoutbuilder.h"
#include "../Transfer/imagefactory.h"

#include "imgui.h"

struct ImGUIInstance {
	ImGUIInstance(Device &device, Window &window, ImageFactory &imageFactory);

	vk::Device device;
	GLFWwindow *window;
	std::unique_ptr<CombinedImage> fontImage;
	DescriptorPoolWrapper descriptorPool{ DescriptorPoolBuilder::monoCombinedSampler(device, 1) };
	DescriptorSetLayout descriptorSetLayout{ DescriptorSetLayoutBuilder::monoCombinedImage(device, vk::ShaderStageFlagBits::eFragment) };
	vk::DescriptorSet descriptorSet{ descriptorPool.allocate(descriptorSetLayout) };
	PipelineLayout pipelineLayout{ PipelineLayoutBuilder::build(device, {descriptorSetLayout}, {vk::PushConstantRange(vk::ShaderStageFlagBits::eVertex, 0, 4 * sizeof(float))}) };

	~ImGUIInstance();
};
