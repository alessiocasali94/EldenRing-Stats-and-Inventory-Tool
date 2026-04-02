#include "UIRenderer.h"
#include "imgui/imgui.h"
#include <windows.h>

void SetupImGuiStyle()
{
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.07f, 0.07f, 0.07f, 0.0f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border] = ImVec4(0.2f, 0.2f, 0.2f, 0.5f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.16f, 0.17f, 0.54f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.29f, 0.36f, 0.53f, 0.4f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.29f, 0.36f, 0.53f, 0.67f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.0f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.29f, 0.36f, 0.53f, 1.0f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.0f, 0.0f, 0.0f, 0.51f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.0f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.0f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.0f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.0f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.29f, 0.56f, 0.89f, 1.0f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.35f, 0.35f, 0.67f, 1.0f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.29f, 0.56f, 0.89f, 1.0f);
    colors[ImGuiCol_Button] = ImVec4(0.29f, 0.36f, 0.53f, 0.4f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.29f, 0.36f, 0.53f, 1.0f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.39f, 0.46f, 0.73f, 1.0f);
    colors[ImGuiCol_Header] = ImVec4(0.29f, 0.36f, 0.53f, 0.31f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.29f, 0.36f, 0.53f, 0.8f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.29f, 0.36f, 0.53f, 1.0f);
    colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.5f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.29f, 0.36f, 0.53f, 0.78f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.29f, 0.36f, 0.53f, 1.0f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.29f, 0.36f, 0.53f, 0.25f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.29f, 0.36f, 0.53f, 0.67f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.29f, 0.36f, 0.53f, 0.95f);
    colors[ImGuiCol_Tab] = ImVec4(0.18f, 0.18f, 0.18f, 0.86f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.29f, 0.36f, 0.53f, 0.8f);
    colors[ImGuiCol_TabActive] = ImVec4(0.29f, 0.36f, 0.53f, 1.0f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.1f, 0.15f, 0.97f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.18f, 0.26f, 1.0f);
    colors[ImGuiCol_Text] = ImVec4(0.88f, 0.88f, 0.88f, 1.0f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.29f, 0.36f, 0.53f, 0.35f);

    style.WindowRounding = 4.0f;
    style.ChildRounding = 4.0f;
    style.FrameRounding = 3.0f;
    style.GrabRounding = 3.0f;
    style.PopupRounding = 4.0f;
    style.ScrollbarRounding = 9.0f;
    style.WindowBorderSize = 1.0f;
    style.FrameBorderSize = 0.0f;
    style.WindowPadding = ImVec2(8, 8);
    style.FramePadding = ImVec2(5, 3);
    style.ItemSpacing = ImVec2(8, 6);
    style.ItemInnerSpacing = ImVec2(6, 4);
}

bool RenderUI(AppState& state)
{
    ImGuiIO& io = ImGui::GetIO();

    static bool initialized = false;
    if (!initialized)
    {
        ImGui::SetNextWindowPos(ImVec2((io.DisplaySize.x - 440) / 2, (io.DisplaySize.y - 700) / 2), ImGuiCond_Once);
        initialized = true;
    }
    ImGui::SetNextWindowSize(ImVec2(440, 700), ImGuiCond_FirstUseEver);

    bool windowOpen = true;
    ImGui::Begin("Elden Ring Trainer", &windowOpen, ImGuiWindowFlags_NoCollapse);
    
    if (ImGui::CollapsingHeader("Character Stats", ImGuiTreeNodeFlags_DefaultOpen))
    {
        ImGui::Text("Num 1 - God Mode / Ignore Hits");
        ImGui::SameLine(320);
        ImGui::Checkbox("##opt1", &state.Option_Num1);
        
        ImGui::Text("Num 2 - Infinite HP");
        ImGui::SameLine(320);
        ImGui::Checkbox("##opt2", &state.Option_Num2);
        
        ImGui::Text("Num 3 - Infinite FP / Mana");
        ImGui::SameLine(320);
        ImGui::Checkbox("##opt3", &state.Option_Num3);
        
        ImGui::Text("Num 4 - Infinite Stamina");
        ImGui::SameLine(320);
        ImGui::Checkbox("##opt4", &state.Option_Num4);
        
        ImGui::Text("Num 5 - No Stamina Cost");
        ImGui::SameLine(320);
        ImGui::Checkbox("##opt5", &state.Option_Num5);
        
        ImGui::Spacing();
        ImGui::Text("Num 6 - Super Run Speed");
        ImGui::SameLine(320);
        ImGui::Checkbox("##opt6", &state.Option_Num6);
        ImGui::SetNextItemWidth(200);
        ImGui::SliderFloat("##speed", &state.Option_Num6_Value, 1.0f, 12.0f, "%.1fx");
        
        ImGui::Text("Num 7 - Super Jump Height");
        ImGui::SameLine(320);
        ImGui::Checkbox("##opt7", &state.Option_Num7);
        ImGui::SetNextItemWidth(200);
        ImGui::SliderFloat("##jump", &state.Option_Num7_Value, 1.0f, 20.0f, "%.1fx");
        
        ImGui::Spacing();
        ImGui::Text("Num 8 - Zero Equip Load");
        ImGui::SameLine(320);
        ImGui::Checkbox("##opt8", &state.Option_Num8);
        
        ImGui::Text("Num 9 - No Fall Damage");
        ImGui::SameLine(320);
        ImGui::Checkbox("##opt9", &state.Option_Num9);
        
        ImGui::Text("Num 0 - Infinite Items Usage");
        ImGui::SameLine(320);
        ImGui::Checkbox("##opt10", &state.Option_Num0);
    }
    
    ImGui::Spacing();
    
    if (ImGui::CollapsingHeader("Combat", ImGuiTreeNodeFlags_DefaultOpen))
    {
        ImGui::Text("F1 - One Hit Kill");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optF1", &state.Option_F1);
        
        ImGui::Text("F2 - Damage Multiplier");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optF2", &state.Option_F2);
        ImGui::SetNextItemWidth(200);
        ImGui::SliderFloat("##dmgmult", &state.Option_F2_Value, 1.0f, 200.0f, "%.0fx");
        
        ImGui::Text("F3 - Defense Multiplier");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optF3", &state.Option_F3);
        ImGui::SetNextItemWidth(200);
        ImGui::SliderFloat("##defmult", &state.Option_F3_Value, 0.1f, 10.0f, "%.1fx");
        
        ImGui::Spacing();
        ImGui::Text("F4 - No Damage Taken");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optF4", &state.Option_F4);
        
        ImGui::Text("F5 - Infinite Poise");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optF5", &state.Option_F5);
        
        ImGui::Text("F6 - 100%% Item Discovery");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optF6", &state.Option_F6);
    }
    
    ImGui::Spacing();
    
    if (ImGui::CollapsingHeader("Currency & Progression", ImGuiTreeNodeFlags_DefaultOpen))
    {
        ImGui::Text("F7 - Add Runes");
        ImGui::SameLine(250);
        if (ImGui::Button("Add##addRunes", ImVec2(50, 0)))
        {
            // Visual only
        }
        ImGui::SetNextItemWidth(150);
        ImGui::InputInt("##runesAmount", &state.Option_F7_Amount, 0, 0);
        
        ImGui::Text("F8 - Runes Multiplier on Gain");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optF8", &state.Option_F8);
        ImGui::SetNextItemWidth(200);
        ImGui::SliderFloat("##runesmult", &state.Option_F8_Value, 1.0f, 100.0f, "%.0fx");
        
        ImGui::Text("F9 - No Rune Loss on Death");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optF9", &state.Option_F9);
    }
    
    ImGui::Spacing();
    
    if (ImGui::CollapsingHeader("Advanced", ImGuiTreeNodeFlags_DefaultOpen))
    {
        ImGui::Text("F10 - Infinite Great Rune Effect");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optF10", &state.Option_F10);
        
        ImGui::Text("F11 - Always Regenerate HP/FP/Stamina");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optF11", &state.Option_F11);
        
        ImGui::Text("F12 - Freeze All Enemies");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optF12", &state.Option_F12);
        
        ImGui::Spacing();
        ImGui::Text("INS - Game Speed");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optINS", &state.Option_INS);
        ImGui::SetNextItemWidth(200);
        ImGui::SliderFloat("##gamespeed", &state.Option_INS_Value, 0.1f, 5.0f, "%.1fx");
        
        ImGui::Spacing();
        ImGui::Text("DEL - Easy Craft / No Materials");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optDEL", &state.Option_DEL);
        
        ImGui::Text("HOME - Unlimited Arrows & Bolts");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optHOME", &state.Option_HOME);
        
        ImGui::Text("PGUP - Infinite Spirit Summons");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optPGUP", &state.Option_PGUP);
        
        ImGui::Text("PGDN - Instant Respawn");
        ImGui::SameLine(320);
        ImGui::Checkbox("##optPGDN", &state.Option_PGDN);
    }
    
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    
    ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), "INSERT - show/hide   |   END - exit   |   No memory access");

    ImGui::End();

    return windowOpen;
}
