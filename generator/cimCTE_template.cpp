#include "imgui.h"
#include "imgui_internal.h"
#include "./ImGuiColorTextEdit/TextEditor.h"
#include "cimCTE.h"
#include <cstring>


#include "auto_funcs.cpp"
////////////////manually generated
CIMGUI_API void TextEditor_SetText(TextEditor* self,const char* aText)
{
    return self->SetText(std::string(aText));
}
CIMGUI_API char* TextEditor_GetText_alloc(TextEditor* self)
{
    std::string str = self->GetText();
    char* cStr = (char*)IM_ALLOC(str.size() + 1); // Allocate memory
    std::strcpy(cStr, str.c_str()); // Copy string contents
    return cStr; // Return new C-style string
}
CIMGUI_API void TextEditor_GetText_free(char* ptr)
{
    IM_FREE(ptr); // free memory
}
CIMGUI_API const char* TextEditor_GetText_static(TextEditor* self)
{
    static std::string str = self->GetText();
    return str.c_str();
}
CIMGUI_API const char* TextEditor_GetText(TextEditor* self)
{
    static std::string str = self->GetText();
    return str.c_str();
}
CIMGUI_API void TextEditor_ImGuiDebugPanel(TextEditor* self,const char* panelName)
{
    return self->ImGuiDebugPanel(std::string(panelName));
}


