#include "imgui.h"
#include "imgui_internal.h"
#include "./ImGuiColorTextEdit/TextEditor.h"
#include "cimCTE.h"



#include "auto_funcs.cpp"
////////////////manually generated
CIMGUI_API void TextEditor_SetText(TextEditor* self,const char* aText)
{
    return self->SetText(std::string(aText));
}
CIMGUI_API const char* TextEditor_GetText(TextEditor* self)
{
    return self->GetText().c_str();
}
CIMGUI_API void TextEditor_ImGuiDebugPanel(TextEditor* self,const char* panelName)
{
    return self->ImGuiDebugPanel(std::string(panelName));
}


