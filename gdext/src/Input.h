#pragma once

#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/sub_viewport.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <memory>

using namespace godot;

namespace ImGui::Godot {
class Input
{
public:
    Input(Window* mainWindow);
    ~Input();

    void Update();
    bool ProcessInput(const Ref<InputEvent>& evt, Window* window);
    void ProcessNotification(int what);
    void SetActiveSubViewport(godot::SubViewport* svp, Vector2 pos);

    void SetJoyAxisDeadZone(float val);
    float GetJoyAxisDeadZone();

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
} // namespace ImGui::Godot
