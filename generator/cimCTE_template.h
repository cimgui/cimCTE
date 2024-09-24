#ifndef CIMGUICTE_INCLUDED
#define CIMGUICTE_INCLUDED

#include "cimgui.h"

#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#include "imgui_structs.h"
#else
#endif // CIMGUI_DEFINE_ENUMS_AND_STRUCTS

#include "auto_funcs.h"

///////////////manual generated
CIMGUI_API void TextEditor_SetText(TextEditor* self,const char* aText);
CIMGUI_API const char* TextEditor_GetText(TextEditor* self);
CIMGUI_API void TextEditor_ImGuiDebugPanel(TextEditor* self,const char* panelName);
#endif //CIMGUICTE_INCLUDED




