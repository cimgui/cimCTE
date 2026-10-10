#include "imgui.h"
#include "imgui_internal.h"
#include "./ImGuiColorTextEdit/TextEditor.h"
#include "./ImGuiColorTextEdit/TextDiff.h"
#include "./ImGuiColorTextEdit/extras/TrieAutoComplete.h"
#include "./ImGuiColorTextEdit/example/dejavu.h"
#include "./ImGuiColorTextEdit/example/notosans.h"
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
////////////Autocomplete
CIMGUI_API AutoCompleteConfig* AutoCompleteConfig_AutoCompleteConfig()
{
    return IM_NEW(AutoCompleteConfig)();
}
CIMGUI_API void AutoCompleteConfig_destroy(AutoCompleteConfig* self)
{
    IM_DELETE(self);
}
CIMGUI_API void AutoCompleteConfig_SetTriggerOnTyping(AutoCompleteConfig* self,bool value)
{
    self->triggerOnTyping = value;
}
CIMGUI_API void AutoCompleteConfig_SetTriggerOnShortcut(AutoCompleteConfig* self,bool value)
{
    self->triggerOnShortcut = value;
}
CIMGUI_API void AutoCompleteConfig_SetTriggerInComments(AutoCompleteConfig* self,bool value)
{
    self->triggerInComments = value;
}
CIMGUI_API void AutoCompleteConfig_SetTriggerInStrings(AutoCompleteConfig* self,bool value)
{
    self->triggerInStrings = value;
}
CIMGUI_API void AutoCompleteConfig_SetTriggerCharacters(AutoCompleteConfig* self,const char* characters)
{
    self->triggerCharacters = characters ? characters : "";
}
CIMGUI_API void AutoCompleteConfig_SetWordCharacters(AutoCompleteConfig* self,const char* characters)
{
    self->wordCharacters = characters ? characters : "";
}
CIMGUI_API void AutoCompleteConfig_SetTriggerShortcut(AutoCompleteConfig* self,ImGuiKeyChord shortcut)
{
    self->triggerShortcut = shortcut;
}
CIMGUI_API void AutoCompleteConfig_SetAutoInsertSingleSuggestions(AutoCompleteConfig* self,bool value)
{
    self->autoInsertSingleSuggestions = value;
}
CIMGUI_API void AutoCompleteConfig_SetTriggerDelay(AutoCompleteConfig* self,int milliseconds)
{
    self->triggerDelay = std::chrono::milliseconds(milliseconds);
}
CIMGUI_API void AutoCompleteConfig_SetNoSuggestionsLabel(AutoCompleteConfig* self,const char* label)
{
    self->noSuggestionsLabel = label ? label : "";
}
CIMGUI_API void AutoCompleteConfig_SetSuggestionWidth(AutoCompleteConfig* self,size_t width)
{
    self->suggestionWidth = width;
}
CIMGUI_API void AutoCompleteConfig_SetCallback(AutoCompleteConfig* self,void(*cb)(AutoCompleteState*))
{
    if (cb)
        self->callback = [cb](AutoCompleteState& state){cb(&state);};
    else
        self->callback = nullptr;
}
CIMGUI_API void AutoCompleteConfig_SetUserData(AutoCompleteConfig* self,void* userData)
{
    self->userData = userData;
}
CIMGUI_API const char* AutoCompleteState_GetSearchTerm(AutoCompleteState* self)
{
    return self->searchTerm.c_str();
}
CIMGUI_API DocPos_c AutoCompleteState_GetSearchTermStart(AutoCompleteState* self)
{
    return ConvertFromCPP_DocPos(self->searchTermStart);
}
CIMGUI_API DocPos_c AutoCompleteState_GetSearchTermEnd(AutoCompleteState* self)
{
    return ConvertFromCPP_DocPos(self->searchTermEnd);
}
CIMGUI_API DocPos_c AutoCompleteState_GetReplacementStart(AutoCompleteState* self)
{
    return ConvertFromCPP_DocPos(self->replacementStart);
}
CIMGUI_API void AutoCompleteState_SetReplacementStart(AutoCompleteState* self,DocPos_c pos)
{
    self->replacementStart = ConvertToCPP_DocPos(pos);
}
CIMGUI_API DocPos_c AutoCompleteState_GetReplacementEnd(AutoCompleteState* self)
{
    return ConvertFromCPP_DocPos(self->replacementEnd);
}
CIMGUI_API void AutoCompleteState_SetReplacementEnd(AutoCompleteState* self,DocPos_c pos)
{
    self->replacementEnd = ConvertToCPP_DocPos(pos);
}
CIMGUI_API bool AutoCompleteState_InIdentifier(AutoCompleteState* self)
{
    return self->inIdentifier;
}
CIMGUI_API bool AutoCompleteState_InNumber(AutoCompleteState* self)
{
    return self->inNumber;
}
CIMGUI_API bool AutoCompleteState_InComment(AutoCompleteState* self)
{
    return self->inComment;
}
CIMGUI_API bool AutoCompleteState_InString(AutoCompleteState* self)
{
    return self->inString;
}
CIMGUI_API const Language* AutoCompleteState_GetLanguage(AutoCompleteState* self)
{
    return self->language;
}
CIMGUI_API void* AutoCompleteState_GetUserData(AutoCompleteState* self)
{
    return self->userData;
}
CIMGUI_API void AutoCompleteState_ClearSuggestions(AutoCompleteState* self)
{
    self->suggestions.clear();
    self->labels.clear();
}
CIMGUI_API void AutoCompleteState_AddSuggestion(AutoCompleteState* self,const char* suggestion,const char* label)
{
    self->suggestions.emplace_back(suggestion);

    // labels are only used if there is one per suggestion, so unlabeled suggestions are labeled with themselves
    if (label) {
        while (self->labels.size() + 1 < self->suggestions.size())
            self->labels.emplace_back(self->suggestions[self->labels.size()]);

        self->labels.emplace_back(label);
    } else if (!self->labels.empty()) {
        self->labels.emplace_back(suggestion);
    }
}
CIMGUI_API size_t AutoCompleteState_GetSuggestionCount(AutoCompleteState* self)
{
    return self->suggestions.size();
}
CIMGUI_API const char* AutoCompleteState_GetSuggestion(AutoCompleteState* self,size_t index)
{
    return index < self->suggestions.size() ? self->suggestions[index].c_str() : nullptr;
}
CIMGUI_API const char* AutoCompleteState_GetLabel(AutoCompleteState* self,size_t index)
{
    // AddSuggestion() keeps labels either empty or one per suggestion
    return index < self->labels.size() ? self->labels[index].c_str() : nullptr;
}
CIMGUI_API void AutoCompleteState_SetSuggestionsPromise(AutoCompleteState* self,bool value)
{
    self->suggestionsPromise = value;
}
CIMGUI_API void TextEditor_SetAutoCompleteSuggestions_array(TextEditor* self,const char** suggestions,const char** labels,size_t count)
{
    std::vector<std::string> s(suggestions, suggestions + count);

    if (labels)
        self->SetAutoCompleteSuggestions(s, std::vector<std::string>(labels, labels + count));
    else
        self->SetAutoCompleteSuggestions(s);
}
////////////Dejavu
CIMGUI_API int Getnotosans(void** noto)
{
	*noto = (void*) &notosans;
	return notosansSize;
}
CIMGUI_API int GetDejavu(void** deja)
{
	*deja = (void*) &dejavu;
	return dejavuSize;
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
    config.FontLoaderFlags = ImGuiFreeTypeLoaderFlags_MonoHinting;
#endif
    io.Fonts->Clear();
    io.Fonts->AddFontFromMemoryCompressedTTF((void*) &dejavu, dejavuSize, 15.0f, &config);
#ifdef IMGUI_ENABLE_FREETYPE
    io.Fonts->SetFontLoader(ImGuiFreeType::GetFontLoader());
#else
    io.Fonts->SetFontLoader(ImFontAtlasGetFontLoaderForStbTruetype());
#endif
}




