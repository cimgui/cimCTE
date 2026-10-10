#ifndef CIMGUICTE_INCLUDED
#define CIMGUICTE_INCLUDED

#include "cimgui.h"

#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#include "imgui_structs.h"
#else
#endif // CIMGUI_DEFINE_ENUMS_AND_STRUCTS

PLACE_STRUCTS_C

#include "auto_funcs.h"

///////////////manual generated
CIMGUI_API Palette* Palette_Palette();
CIMGUI_API void Palette_destroy(Palette*);
CIMGUI_API void Palette_set(Palette*,ImU32,int);
CIMGUI_API ImU32 Palette_const_get(const Palette*,Color);
//allocates new memory that must be freed with TextEditor_GetText_free
CIMGUI_API char* TextEditor_GetText_alloc(TextEditor* self);
CIMGUI_API void TextEditor_GetText_free(char* ptr);
//returned value must be used to copy value before calling TextEditor_GetText_static again
CIMGUI_API const char* TextEditor_GetText_static(TextEditor* self);
////////////Autocomplete
//TextEditor_SetAutoCompleteConfig copies the config, so it can be destroyed afterwards
//NULL strings are treated as empty
CIMGUI_API AutoCompleteConfig* AutoCompleteConfig_AutoCompleteConfig();
CIMGUI_API void AutoCompleteConfig_destroy(AutoCompleteConfig* self);
CIMGUI_API void AutoCompleteConfig_SetTriggerOnTyping(AutoCompleteConfig* self,bool value);
CIMGUI_API void AutoCompleteConfig_SetTriggerOnShortcut(AutoCompleteConfig* self,bool value);
CIMGUI_API void AutoCompleteConfig_SetTriggerInComments(AutoCompleteConfig* self,bool value);
CIMGUI_API void AutoCompleteConfig_SetTriggerInStrings(AutoCompleteConfig* self,bool value);
CIMGUI_API void AutoCompleteConfig_SetTriggerCharacters(AutoCompleteConfig* self,const char* characters);
CIMGUI_API void AutoCompleteConfig_SetWordCharacters(AutoCompleteConfig* self,const char* characters);
CIMGUI_API void AutoCompleteConfig_SetTriggerShortcut(AutoCompleteConfig* self,ImGuiKeyChord shortcut);
CIMGUI_API void AutoCompleteConfig_SetAutoInsertSingleSuggestions(AutoCompleteConfig* self,bool value);
CIMGUI_API void AutoCompleteConfig_SetTriggerDelay(AutoCompleteConfig* self,int milliseconds);
CIMGUI_API void AutoCompleteConfig_SetNoSuggestionsLabel(AutoCompleteConfig* self,const char* label);
CIMGUI_API void AutoCompleteConfig_SetSuggestionWidth(AutoCompleteConfig* self,size_t width);
CIMGUI_API void AutoCompleteConfig_SetCallback(AutoCompleteConfig* self,void(*cb)(AutoCompleteState*));
CIMGUI_API void AutoCompleteConfig_SetUserData(AutoCompleteConfig* self,void* userData);
//only valid inside the callback, the returned string is valid until the callback returns
CIMGUI_API const char* AutoCompleteState_GetSearchTerm(AutoCompleteState* self);
CIMGUI_API DocPos_c AutoCompleteState_GetSearchTermStart(AutoCompleteState* self);
CIMGUI_API DocPos_c AutoCompleteState_GetSearchTermEnd(AutoCompleteState* self);
//the callback can move the replaced section on the same line (start not after and end not before the cursor)
CIMGUI_API DocPos_c AutoCompleteState_GetReplacementStart(AutoCompleteState* self);
CIMGUI_API void AutoCompleteState_SetReplacementStart(AutoCompleteState* self,DocPos_c pos);
CIMGUI_API DocPos_c AutoCompleteState_GetReplacementEnd(AutoCompleteState* self);
CIMGUI_API void AutoCompleteState_SetReplacementEnd(AutoCompleteState* self,DocPos_c pos);
CIMGUI_API bool AutoCompleteState_InIdentifier(AutoCompleteState* self);
CIMGUI_API bool AutoCompleteState_InNumber(AutoCompleteState* self);
CIMGUI_API bool AutoCompleteState_InComment(AutoCompleteState* self);
CIMGUI_API bool AutoCompleteState_InString(AutoCompleteState* self);
CIMGUI_API const Language* AutoCompleteState_GetLanguage(AutoCompleteState* self);
CIMGUI_API void* AutoCompleteState_GetUserData(AutoCompleteState* self);
CIMGUI_API void AutoCompleteState_ClearSuggestions(AutoCompleteState* self);
//label is shown in the popup instead of the suggestion, it can be NULL
CIMGUI_API void AutoCompleteState_AddSuggestion(AutoCompleteState* self,const char* suggestion,const char* label);
CIMGUI_API size_t AutoCompleteState_GetSuggestionCount(AutoCompleteState* self);
//index is 0-based, returns NULL if it's out of range
CIMGUI_API const char* AutoCompleteState_GetSuggestion(AutoCompleteState* self,size_t index);
//returns NULL if there are no labels or index is out of range
CIMGUI_API const char* AutoCompleteState_GetLabel(AutoCompleteState* self,size_t index);
CIMGUI_API void AutoCompleteState_SetSuggestionsPromise(AutoCompleteState* self,bool value);
//labels can be NULL, otherwise it must have count entries
CIMGUI_API void TextEditor_SetAutoCompleteSuggestions_array(TextEditor* self,const char** suggestions,const char** labels,size_t count);
////////////Dejavu
CIMGUI_API int GetDejavu(void** deja);
CIMGUI_API int Getnotosans(void** noto);
CIMGUI_API void SetDejavu();
#endif //CIMGUICTE_INCLUDED




