#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "version.h"
#include "CourseManager.h"
constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);

struct FNameStruct {
	int Index;
	int Number;
};

struct KeyPressParams {
	int ControllerID;
	FNameStruct Key;
	unsigned char EventType;
	float AmountDepressed;
	unsigned int bGamepad;
	unsigned int ReturnValue;
};

enum EInputEvent
{
	Pressed = 0,
	Released = 1,
	Repeat = 2,
	DoubleClick = 3,
	Axis = 4
};

class Balls: public BakkesMod::Plugin::BakkesModPlugin, public BakkesMod::Plugin::PluginSettingsWindow
{
	virtual void onLoad();
	virtual void onUnload();
	virtual void RegisterCvars();
	virtual void RegisterNotifiers();
	virtual void RegisterHookEvents();
	void RenderSettings() override;
	std::string GetPluginName() override;
	void SetImGuiContext(uintptr_t ctx) override;
	void Render(CanvasWrapper canvas);
	void OnFreeplayLoad(std::string eventName);
	void OnFreeplayDestroy(std::string eventName);
	void OnKeyPressed(ActorWrapper aw, void* params, std::string eventName);
	const std::string Cvar_Plugin_Enabled = "plugin_enabled";
	const std::string Cvar_Balls_Gate_Distance_From_Car = "balls_gate_distance_from_car";
	CourseManager _courseManager = CourseManager();
};

