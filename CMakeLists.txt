#include_directories(cimCTE/ImGuiColorTextEdit/vendor/regex/include)
#list(APPEND IMGUI_SOURCES ./cimCTE/cimCTE.cpp)
#list(APPEND IMGUI_SOURCES ./cimCTE/ImGuiColorTextEdit/TextEditor.cpp)
set(cimCTE_SRCS ./cimCTE/cimCTE.cpp ./cimCTE/ImGuiColorTextEdit/TextEditor.cpp PARENT_SCOPE)

