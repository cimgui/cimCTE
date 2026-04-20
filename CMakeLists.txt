cmake_minimum_required(VERSION 3.5)

project(cimCTE)

file(GLOB IMGUI_SOURCES
    ../cimgui/cimgui.cpp
    ../cimgui/imgui/imgui.cpp
    ../cimgui/imgui/imgui_draw.cpp
    ../cimgui/imgui/imgui_demo.cpp
    ../cimgui/imgui/imgui_widgets.cpp
    ../cimgui/imgui/imgui_tables.cpp
    cimCTE.cpp
    ImGuiColorTextEdit/TextEditor.cpp
    ImGuiColorTextEdit/TextDiff.cpp
)

set(IMGUI_STATIC "no" CACHE STRING "Build as a static library")
set(CMAKE_CXX_STANDARD 17)

if (IMGUI_STATIC)
    add_library(cimCTE STATIC ${IMGUI_SOURCES})
else (IMGUI_STATIC)
    add_library(cimCTE SHARED ${IMGUI_SOURCES})
endif (IMGUI_STATIC)

add_definitions("-DIMGUI_USER_CONFIG=\"../cimconfig.h\"")
target_compile_definitions(cimCTE PUBLIC IMGUI_DISABLE_OBSOLETE_FUNCTIONS=1)

target_include_directories(cimCTE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ImGuiColorTextEdit)
target_include_directories(cimCTE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../cimgui/imgui)
target_include_directories(cimCTE PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../cimgui)
set_target_properties(cimCTE PROPERTIES PREFIX "")

install(TARGETS cimCTE
    RUNTIME DESTINATION  .
    LIBRARY DESTINATION  .
    ARCHIVE DESTINATION  .
)
