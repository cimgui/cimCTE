#ifndef CIMCTE_INCLUDED
#define CIMCTE_INCLUDED

#include "cimgui.h"

#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS
typedef struct LanguageDefinition LangDef;
typedef struct TextEditor TextEditor;
typedef struct Coordinates Coordinates;
typedef struct ErrorMarkers ErrorMarkers;
struct Coordinates
{
    int mLine, mColumn;
};
typedef enum SelectionMode_
	{
		Normal,
		Word,
		Line
	} SelectionMode;
#else
typedef TextEditor::LanguageDefinition LangDef;
typedef TextEditor::Coordinates Coordinates;
typedef TextEditor::ErrorMarkers ErrorMarkers;
typedef TextEditor::SelectionMode SelectionMode;
#endif
CIMGUI_API TextEditor* TextEditor_TextEditor();
CIMGUI_API void TextEditor_destroy(TextEditor * self);
CIMGUI_API void TextEditor_SetLangDef(TextEditor* self, LangDef* lang);
CIMGUI_API void TextEditor_SetText(TextEditor* self,const char* text);
CIMGUI_API Coordinates* TextEditor_GetCursorPosition(TextEditor* self);
CIMGUI_API void TextEditor_Render(TextEditor* self, const char *title);
CIMGUI_API bool TextEditor_HasSelection(TextEditor* ed);
CIMGUI_API void TextEditor_Copy(TextEditor* ed);
CIMGUI_API void TextEditor_Cut(TextEditor* ed);
CIMGUI_API void TextEditor_Paste(TextEditor* ed);
CIMGUI_API void TextEditor_Delete(TextEditor* ed);
CIMGUI_API LangDef* TextEditor_GetLanguageDefinition(TextEditor* ed);
CIMGUI_API LangDef* LanguageDefinition();
CIMGUI_API LangDef* LanguageDefinition_CPlusPlus();
CIMGUI_API LangDef* LanguageDefinition_Lua();
CIMGUI_API LangDef* LanguageDefinition_HLSL();
CIMGUI_API LangDef* LanguageDefinition_GLSL();
CIMGUI_API LangDef* LanguageDefinition_C();
CIMGUI_API LangDef* LanguageDefinition_SQL();
CIMGUI_API LangDef* LanguageDefinition_AngelScript();
CIMGUI_API const char* LanguageDefinition_getName(LangDef* self);
CIMGUI_API void LanguageDefinition_PIdentifiers_insert(LangDef *self, const char* ppnames, const char* ppvalues);
CIMGUI_API void LanguageDefinition_Identifiers_insert(LangDef *self, const char* identifier, const char* idcl);
CIMGUI_API ErrorMarkers* TextEditor_ErrorMarkers();
CIMGUI_API void ErrorMarkers_destroy(ErrorMarkers *mark);
CIMGUI_API void ErrorMarkers_insert(ErrorMarkers *mark, int n,const char* text);
CIMGUI_API void TextEditor_SetErrorMarkers(TextEditor* ed, ErrorMarkers* mark);
CIMGUI_API int TextEditor_GetTotalLines(TextEditor* ed);
CIMGUI_API bool TextEditor_IsOverwrite(TextEditor* ed);
CIMGUI_API bool TextEditor_CanUndo(TextEditor* ed);
CIMGUI_API bool TextEditor_CanRedo(TextEditor* ed);
CIMGUI_API bool TextEditor_IsReadOnly(TextEditor* ed);
CIMGUI_API void TextEditor_SetReadOnly(TextEditor* ed,bool aValue);
CIMGUI_API void TextEditor_Undo(TextEditor* ed, int aSteps);
CIMGUI_API void TextEditor_Redo(TextEditor* ed, int aSteps);
CIMGUI_API void TextEditor_SetSelection(TextEditor* ed, Coordinates* aStart, Coordinates* aEnd, SelectionMode sem);
CIMGUI_API Coordinates* TextEditor_Coordinates_Nil();
CIMGUI_API Coordinates* TextEditor_Coordinates_Int(int aLine, int aColumn);
CIMGUI_API void TextEditor_Coordinates_destroy(Coordinates * co);
CIMGUI_API void TextEditor_SetPalette_DarkPalette(TextEditor* ed);
CIMGUI_API void TextEditor_SetPalette_LightPalette(TextEditor* ed);
CIMGUI_API void TextEditor_SetPalette_RetroBluePalette(TextEditor* ed);
#endif //CIMCTE_INCLUDED
