//
//
#include "imgui.h"
#include "imgui_internal.h"
#include "./ImGuiColorTextEdit/TextEditor.h"
#include "cimCTE.h"

CIMGUI_API TextEditor* TextEditor_TextEditor()
{
	return new(TextEditor)();
}
CIMGUI_API void TextEditor_destroy(TextEditor * self)
{
	self->~TextEditor();
}

CIMGUI_API void TextEditor_SetLangDef(TextEditor* self, LangDef* lang)
{
	self->SetLanguageDefinition(*lang);
}
CIMGUI_API void TextEditor_SetText(TextEditor* self, const char* text)
{
	self->SetText(std::string(text));
}
CIMGUI_API Coordinates* TextEditor_GetCursorPosition(TextEditor* self)
{
	static TextEditor::Coordinates co = self->GetCursorPosition();
	return &(co);
}
CIMGUI_API void TextEditor_Render(TextEditor* self, const char *title)
{
	 self->Render(title);
}

CIMGUI_API int TextEditor_GetTotalLines(TextEditor* ed)
{
	return ed->GetTotalLines();
}
CIMGUI_API bool TextEditor_IsOverwrite(TextEditor* ed)
{
	return ed->IsOverwrite();
}
CIMGUI_API bool TextEditor_CanUndo(TextEditor* ed)
{
	return ed->CanUndo();
}
CIMGUI_API bool TextEditor_CanRedo(TextEditor* ed)
{
	return ed->CanRedo();
}
CIMGUI_API bool TextEditor_IsReadOnly(TextEditor* ed)
{
	return ed->IsReadOnly();
}
CIMGUI_API void TextEditor_SetReadOnly(TextEditor* ed,bool aValue)
{
	ed->SetReadOnly(aValue);
}
CIMGUI_API void TextEditor_Undo(TextEditor* ed, int aSteps)
{
	ed->Undo(aSteps);
}
CIMGUI_API void TextEditor_Redo(TextEditor* ed, int aSteps)
{
	ed->Redo(aSteps);
}
CIMGUI_API bool TextEditor_HasSelection(TextEditor* ed)
{
	return ed->HasSelection();
}
CIMGUI_API void TextEditor_Copy(TextEditor* ed)
{
	ed->Copy();
}
CIMGUI_API void TextEditor_Cut(TextEditor* ed)
{
	ed->Cut();
}
CIMGUI_API void TextEditor_Paste(TextEditor* ed)
{
	ed->Paste();
}
CIMGUI_API void TextEditor_Delete(TextEditor* ed)
{
	ed->Delete();
}
CIMGUI_API void TextEditor_SetSelection(TextEditor* ed, Coordinates* aStart, Coordinates* aEnd, SelectionMode sem)
{
	ed->SetSelection(*aStart, *aEnd, sem);
}

CIMGUI_API LangDef* TextEditor_GetLanguageDefinition(TextEditor* ed)
{
	static TextEditor::LanguageDefinition lang1 = ed->GetLanguageDefinition();
	return &lang1;
}


CIMGUI_API LangDef* LanguageDefinition_CPlusPlus()
{
	//return &(TextEditor::LanguageDefinition::CPlusPlus());
	static TextEditor::LanguageDefinition lang1 = TextEditor::LanguageDefinition::CPlusPlus();
	return &lang1;
}
CIMGUI_API LangDef* LanguageDefinition_Lua()
{
	static TextEditor::LanguageDefinition lang1 = TextEditor::LanguageDefinition::Lua();
	return &lang1;
}
CIMGUI_API const char* LanguageDefinition_getName(LangDef* self)
{
	return self->mName.c_str();
}
CIMGUI_API void LanguageDefinition_PIdentifiers_insert(LangDef *self, const char* ppnames, const char* ppvalues)
{
	TextEditor::Identifier id;
	id.mDeclaration = ppvalues ;//std::string(ppvalues);
	(*self).mPreprocIdentifiers.insert(std::make_pair(std::string(ppnames), id));
}
CIMGUI_API void LanguageDefinition_Identifiers_insert(LangDef *self, const char* identifier, const char* idcl)
{
	TextEditor::Identifier id;
	id.mDeclaration = std::string(idcl);
	(*self).mPreprocIdentifiers.insert(std::make_pair(std::string(identifier), id));
}
CIMGUI_API ErrorMarkers* TextEditor_ErrorMarkers()
{
	return IM_NEW(TextEditor::ErrorMarkers)();
}
CIMGUI_API void ErrorMarkers_destroy(ErrorMarkers *mark)
{
	IM_DELETE(mark);
}
CIMGUI_API void ErrorMarkers_insert(ErrorMarkers *mark, int n,const char* text)
{
	mark->insert(std::make_pair(n, std::string(text)));
}
CIMGUI_API void TextEditor_SetErrorMarkers(TextEditor* ed, ErrorMarkers* mark)
{
	ed->SetErrorMarkers(*mark);
}
CIMGUI_API Coordinates* TextEditor_Coordinates_Nil()
{
	return IM_NEW(TextEditor::Coordinates)();
}
CIMGUI_API Coordinates* TextEditor_Coordinates_Int(int aLine, int aColumn)
{
	return IM_NEW(TextEditor::Coordinates)(aLine, aColumn);
}
CIMGUI_API void TextEditor_Coordinates_destroy(Coordinates * co)
{
	IM_DELETE(co);
}
CIMGUI_API void TextEditor_SetPalette_DarkPalette(TextEditor* ed)
{
	ed->SetPalette(TextEditor::GetDarkPalette());
}
CIMGUI_API void TextEditor_SetPalette_LightPalette(TextEditor* ed)
{
	ed->SetPalette(TextEditor::GetLightPalette());
}
CIMGUI_API void TextEditor_SetPalette_RetroBluePalette(TextEditor* ed)
{
	ed->SetPalette(TextEditor::GetRetroBluePalette());
}
/*
#include <iostream>
static const char* ppnames[] = { "NULL", "PM_REMOVE"};
static const char* ppvalues[] = { "NULLval", "PM_REMOVEval"};
CIMGUI_API void Test()
{
	
	TextEditor::LanguageDefinition lang1 = TextEditor::LanguageDefinition::CPlusPlus();
	for (int i = 0; i < sizeof(ppnames) / sizeof(ppnames[0]); ++i)
	{
		TextEditor::Identifier id;
		id.mDeclaration = ppvalues[i];
		lang1.mPreprocIdentifiers.insert(std::make_pair(std::string(ppnames[i]), id));
	}
	auto lang2 = TextEditor::LanguageDefinition::CPlusPlus();
	
	printf("langs %p, %p\n",&lang1,&lang2);
	
	auto print_key_value = [](const auto& key, const auto& value)
    {
        std::cout << "Key:[" << key << "] Value:[" << value.mDeclaration << "]\n";
    };
 
    std::cout << "Iterate and print key-value pairs of unordered_map, being\n"
                 "explicit with their types:\n";
    for (const std::pair<const std::string, TextEditor::Identifier>& n : lang1.mPreprocIdentifiers)
        print_key_value(n.first, n.second);
 
    std::cout << "\nIterate and print key-value pairs using C++17 structured binding:\n";
    for (const std::pair<const std::string, TextEditor::Identifier>& n : lang2.mPreprocIdentifiers)
        print_key_value(n.first, n.second);
}*/