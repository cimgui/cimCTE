#include "imgui.h"
#include "imgui_internal.h"
#include "./ImGuiColorTextEdit/TextEditor.h"
#include "./ImGuiColorTextEdit/TextDiff.h"
#include "./ImGuiColorTextEdit/extras/TrieAutoComplete.h"
#include "./ImGuiColorTextEdit/extras/Notifications.h"
#include "./ImGuiColorTextEdit/example/dejavu.h"
#include "cimCTE.h"
#include <cstring>


#include "auto_funcs.cpp"
////////////////manually generated
CIMGUI_API Palette* Palette_Palette()
{
    return IM_NEW(Palette)();
}
CIMGUI_API void Palette_destroy(Palette* self)
{
    IM_DELETE(self);
}
CIMGUI_API void Palette_set(Palette* self,ImU32 col,int pos)
{
    (*self)[pos] = col;
}
CIMGUI_API ImU32 Palette_const_get(const Palette* self,Color color)
{
    return self->get(color);
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
    static std::string str;
    str.assign(self->GetText());
    return str.c_str();
}

CIMGUI_API void SetDejavu()
{
    auto& io = ImGui::GetIO();
    ImFontConfig config;
    std::memcpy(config.Name, "DejaVu", 7);
    config.FontDataOwnedByAtlas = false;
    config.OversampleH = 1;
    config.OversampleV = 1;
#ifdef IMGUI_ENABLE_FREETYPE
    config.FontLoaderFlags = ImGuiFreeTypeLoaderFlags_MonoHinting | ImGuiFreeTypeLoaderFlags_Monochrome | ImGuiFreeTypeLoaderFlags_Bold;
#endif
    io.Fonts->Clear();
    io.Fonts->AddFontFromMemoryCompressedTTF((void*) &dejavu, dejavuSize, 15.0f, &config);
#ifdef IMGUI_ENABLE_FREETYPE
    io.Fonts->SetFontLoader(ImGuiFreeType::GetFontLoader());
#else
    io.Fonts->SetFontLoader(ImFontAtlasGetFontLoaderForStbTruetype());
#endif
}




