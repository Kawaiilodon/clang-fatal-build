module;

#include "imgui.h"

export module Visualization:WidgetGuard;

export namespace visual {
namespace helpers {

class WidgetGuard
{
public:
  WidgetGuard(const std::string& name, bool* p_open = nullptr, ImGuiWindowFlags flags = 0)
  {
    ImGui::Begin(std::data(name), p_open, flags);
  }

  ~WidgetGuard()
  {
    ImGui::End();
  }
};

} // namespace helpers
} // namespace visual