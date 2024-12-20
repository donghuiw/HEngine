
-- HEngine Dependencies

--VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/HEngine/vendor/stb_image"
IncludeDir["yaml_cpp"] = "%{wks.location}/HEngine/vendor/yaml-cpp/include"
IncludeDir["GLFW"] = "%{wks.location}/HEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/HEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/HEngine/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/HEngine/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/HEngine/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/HEngine/vendor/entt/include"
IncludeDir["shaderc"] = "%{wks.location}/HEngine/vendor/VulkanSDK/Include/shaderc"
IncludeDir["SPIRV_Cross"] = "%{wks.location}/HEngine/vendor/VulkanSDK/Include/spirv_cross"
IncludeDir["VulkanSDK"] = "%{wks.location}/HEngine/vendor/VulkanSDK/Include"

LibraryDir = {}

LibraryDir["VulkanSDK"] = "%{wks.location}/HEngine/vendor/VulkanSDK/Lib"
LibraryDir["VulkanSDK_Debug"] = "%{wks.location}/HEngine/vendor/VulkanSDK/Lib"
LibraryDir["VulkanSDK_DebugDLL"] = "%{wks.location}/HEngine/vendor/VulkanSDK/Bin"

Library = {}
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"
