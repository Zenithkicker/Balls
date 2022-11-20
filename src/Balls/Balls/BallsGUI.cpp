#include "pch.h"
#include "Balls.h"

void Balls::SetImGuiContext(uintptr_t ctx) {
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

std::string Balls::GetPluginName() {
	return "Balls";
}

void Balls::RenderSettings() 
{

	//Global Enable/Disable
	CVarWrapper cvarGlobalEnable = cvarManager->getCvar(Balls::Cvar_Plugin_Enabled);
	if (!cvarGlobalEnable) { return; }
	bool globalEnabled = cvarGlobalEnable.getBoolValue();
	if (ImGui::Checkbox("Enable plugin", &globalEnabled)) {
		cvarGlobalEnable.setValue(globalEnabled);
	}
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("Enable / Disable Plugin");
	}

	if (!globalEnabled)
		return;

	//Gate Distance From Car
	CVarWrapper cvarGateDist = cvarManager->getCvar(Balls::Cvar_Balls_Gate_Distance_From_Car);
	if (!cvarGateDist) { return; }
	float gateDist = cvarGateDist.getFloatValue();
	if (ImGui::SliderFloat("Gate Distance From Car", &gateDist, 270, 600)) {
		cvarGateDist.setValue(gateDist);
	}
	if (ImGui::IsItemHovered()) {
		std::string hoverText = "gate distance is " + std::to_string(gateDist);
		ImGui::SetTooltip(hoverText.c_str());
	}
}