#pragma once

#ifndef BEYOND_GRAPHICS_VULKAN_FWD_HPP
#define BEYOND_GRAPHICS_VULKAN_FWD_HPP

#include <beyond/graphics/backend.hpp>
#include <memory>

namespace beyond::graphics::vulkan {

/// @brief Create a VulkanGraphicsContext
[[nodiscard]] auto create_vulkan_gpu_device(Window& window) noexcept
    -> std::unique_ptr<GPUDevice>;

} // namespace beyond::graphics::vulkan

#endif // BEYOND_GRAPHICS_VULKAN_FWD_HPP
