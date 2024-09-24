#target_include_directories(ImGuiColorTextEdit/vendor/regex/include)
#list(APPEND IMGUI_SOURCES ./cimCTE/cimCTE.cpp)
#list(APPEND IMGUI_SOURCES ./cimCTE/ImGuiColorTextEdit/TextEditor.cpp)
set(cimCTE_SRCS 
./cimCTE/cimCTE.cpp 
./cimCTE/ImGuiColorTextEdit/TextEditor.cpp
./cimCTE/ImGuiColorTextEdit/LanguageDefinitions.cpp
./cimCTE/ImGuiColorTextEdit/UnitTests.cpp
./cimCTE/ImGuiColorTextEdit/ImGuiDebugPanel.cpp
 PARENT_SCOPE)
set(cimCTE_inc cimCTE/ImGuiColorTextEdit/vendor/regex/include  PARENT_SCOPE)


