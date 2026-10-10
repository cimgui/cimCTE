#include <stdio.h>
#include <assert.h>
#include <string.h>
//#include "cimgui.h"
#include "../cimCTE.h"

#ifdef IMGUI_HAS_IMSTR
#define igBegin igBegin_Str
#define igSliderFloat igSliderFloat_Str
#define igCheckbox igCheckbox_Str
#define igColorEdit3 igColorEdit3_Str
#define igButton igButton_Str
#define igDebugCheckVersionAndDataLayout igDebugCheckVersionAndDataLayout_Str
#endif

#define igGetIO igGetIO_Nil

// completes \alpha to α from the last backslash, like the Julia REPL
static void latex_callback(AutoCompleteState* state)
{
  AutoCompleteState_ClearSuggestions(state);
  const char* term = AutoCompleteState_GetSearchTerm(state);
  const char* backslash = strrchr(term, '\\');
  if (!backslash)
    return;

  // only replace from the backslash to the cursor (DocPos indices count codepoints, not bytes)
  DocPos_c start = AutoCompleteState_GetSearchTermStart(state);
  for (const char* c = term; c < backslash; c++)
    if ((*c & 0xc0) != 0x80)
      start.index++;
  AutoCompleteState_SetReplacementStart(state, start);
  AutoCompleteState_SetReplacementEnd(state, AutoCompleteState_GetSearchTermEnd(state));

  if (strncmp("\\alpha", backslash, strlen(backslash)) == 0)
    AutoCompleteState_AddSuggestion(state, "\xce\xb1", "\\alpha  \xce\xb1");
}

static void render_editor(TextEditor* editor)
{
  igNewFrame();
  igBegin("editor", NULL, 0);
  ImVec2_c size = {0, 0};
  TextEditor_Render(editor, "editor", size, 0, 0);
  igEnd();
  igRender();
}

static int test_autocomplete(ImGuiIO* io, const char* text, const char* input, const char* expected)
{
  TextEditor* editor = TextEditor_TextEditor();
  TextEditor_SetText_std_string_view(editor, text);
  TextEditor_SetLanguage(editor, TextEditor_LookupLanguage("Julia"));

  AutoCompleteConfig* config = AutoCompleteConfig_AutoCompleteConfig();
  AutoCompleteConfig_SetTriggerCharacters(config, "\\");
  AutoCompleteConfig_SetWordCharacters(config, "\\^_");
  AutoCompleteConfig_SetTriggerDelay(config, 0);
  AutoCompleteConfig_SetCallback(config, latex_callback);
  TextEditor_SetAutoCompleteConfig(editor, config);
  AutoCompleteConfig_destroy(config);

  const char* suggestions[] = {"unused"};
  TextEditor_SetAutoCompleteSuggestions_array(editor, suggestions, NULL, 1);

  TextEditor_SetFocus(editor);
  render_editor(editor);

  for (const char* c = input; *c; c++) {
    ImGuiIO_AddInputCharacter(io, *c);
    render_editor(editor);
    render_editor(editor);
  }

  ImGuiIO_AddKeyEvent(io, ImGuiKey_Tab, true);
  render_editor(editor);
  ImGuiIO_AddKeyEvent(io, ImGuiKey_Tab, false);
  render_editor(editor);

  const char* result = TextEditor_GetText_static(editor);
  printf("autocomplete result: '%s'\n", result);
  int ok = strcmp(result, expected) == 0;
  TextEditor_destroy(editor);
  return ok;
}

int main(void)
{
  assert(igDebugCheckVersionAndDataLayout(igGetVersion(), sizeof(ImGuiIO), sizeof(ImGuiStyle),
                                          sizeof(ImVec2), sizeof(ImVec4), sizeof(ImDrawVert),
                                          sizeof(ImDrawIdx)));
  printf("CreateContext() - v%s\n", igGetVersion());
  igCreateContext(NULL);
  ImGuiIO *io = igGetIO();

  // unsigned char *text_pixels = NULL;
  // int text_w, text_h;
  // ImFontAtlas_GetTexDataAsRGBA32(io->Fonts, &text_pixels, &text_w, &text_h, NULL);
  io->BackendFlags |= ImGuiBackendFlags_RendererHasTextures;
  
  const Palette* lpal = TextEditor_GetLightPalette();
  ImU32 a = Palette_const_get(lpal, 1);

  for (int n = 0; n < 20; n++) {
    printf("NewFrame() %d\n", n);

    ImVec2 display_size;
    display_size.x = 1920;
    display_size.y = 1080;
    io->DisplaySize = display_size;
	printf("DisplaySice %f, %f\n", io->DisplaySize.x, io->DisplaySize.y);
    io->DeltaTime = 1.0f / 60.0f;
    igNewFrame();
    
    igBegin("mainwindow",NULL,ImGuiWindowFlags_NoTitleBar);
    static float f = 0.0f;
    igText("Hello World!");
    igSliderFloat("float", &f, 0.0f, 1.0f, "%.3f", 0);
    igText("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io->Framerate, io->Framerate);
    igEnd();
    igShowDemoWindow(NULL);

    igRender();
  }
  printf("%llu\n",ImGuiWindowFlags_NoTitleBar);
  printf("size: %d\n",sizeof(ImGuiWindowFlags_NoTitleBar));
  if (!test_autocomplete(io, "", "x\\al", "x\xce\xb1\n") ||
      !test_autocomplete(io, "^2", "x\\al", "x\xce\xb1^2\n")) {
    printf("autocomplete test failed\n");
    return 1;
  }

  printf("DestroyContext()\n");
  igDestroyContext(NULL);

  return 0;
}
