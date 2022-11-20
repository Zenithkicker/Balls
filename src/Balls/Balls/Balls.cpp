#include "pch.h"
#include "Balls.h"
using namespace std;

BAKKESMOD_PLUGIN(Balls, "Balls", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void Balls::onLoad()
{
	_globalCvarManager = cvarManager;
	RegisterCvars();
	RegisterNotifiers();
	RegisterHookEvents();
}

void Balls::OnFreeplayLoad(std::string eventName)
{
	gameWrapper->RegisterDrawable(std::bind(&Balls::Render, this, std::placeholders::_1));
}

void Balls::OnFreeplayDestroy(std::string eventName)
{
	gameWrapper->UnregisterDrawables();
}

void Balls::onUnload()
{
	LOG("Hello World onUnLoad!");
}

void Balls::RegisterCvars()
{
	_globalCvarManager->registerCvar(Balls::Cvar_Plugin_Enabled, "0");
}

void Balls::RegisterNotifiers()
{
	
}

void Balls::RegisterHookEvents()
{
	

	gameWrapper->HookEvent("Function TAGame.Mutator_Freeplay_TA.Init", bind(&Balls::OnFreeplayLoad, this, std::placeholders::_1));
	gameWrapper->HookEvent("Function TAGame.GameEvent_Soccar_TA.Destroyed", bind(&Balls::OnFreeplayDestroy, this, std::placeholders::_1));
	gameWrapper->HookEventWithCaller<ActorWrapper>("Function TAGame.GameViewportClient_TA.HandleKeyPress", std::bind(&Balls::OnKeyPressed, this, placeholders::_1, placeholders::_2, placeholders::_3));
}

void Balls::Render(CanvasWrapper canvas)
{
	CVarWrapper cvarGlobalIsEnabled = _globalCvarManager->getCvar(Balls::Cvar_Plugin_Enabled);
	if (cvarGlobalIsEnabled.IsNull() || !cvarGlobalIsEnabled.getBoolValue())
		return;

	
}

void Balls::OnKeyPressed(ActorWrapper aw, void* params, std::string eventName)
{
	CVarWrapper cvarGlobalIsEnabled = _globalCvarManager->getCvar(Balls::Cvar_Plugin_Enabled);
	if (cvarGlobalIsEnabled.IsNull() || !cvarGlobalIsEnabled.getBoolValue())
		return;

	KeyPressParams* keyPressData = (KeyPressParams*)params;
	if (keyPressData->EventType != EInputEvent::Released)
		return;

	ServerWrapper sw = gameWrapper->GetGameEventAsServer();
	if (sw.IsNull())
		return;

	

	if (keyPressData->Key.Index == gameWrapper->GetFNameIndexByString("LeftAlt"))
	{
		
	}
	else if (keyPressData->Key.Index == gameWrapper->GetFNameIndexByString("RightAlt"))
	{
		
	}
	else if (keyPressData->Key.Index == gameWrapper->GetFNameIndexByString("G"))
	{
		
	}
}

std::string Balls::GetPluginName() 
{
	return "Balls";
}

void Balls::SetImGuiContext(uintptr_t ctx) {
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

void Balls::RenderSettings() {

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

}