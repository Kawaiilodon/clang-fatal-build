project(VisualizationLibraryModule)

if ("${FORCE_INCLUDE_PCH}" STREQUAL "ON") 
        add_compile_definitions(COMMON_ENABLE_PCH)
endif()

find_package(SDL2 REQUIRED)

set(IMGUI_SRC
        imgui/backends/imgui_impl_sdl2.cpp
        imgui/backends/imgui_impl_opengl3.cpp
        imgui/imgui.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp)

add_library(Visualization)

target_sources(Visualization 
        PRIVATE ${IMGUI_SRC}
        PUBLIC FILE_SET CXX_MODULES FILES
        src/Visualization/Helpers/WidgetGuard.cppm
        src/Visualization/TestWidget.cppm
        src/Visualization/Widget.cppm
        src/Visualization/Window.cppm
        src/Visualization/Module.cppm
)

target_link_libraries(Visualization PRIVATE ${SDL2_LIBRARIES})
target_include_directories(Visualization PRIVATE ${MODULES_DIR}/Visualization/imgui)
target_include_directories(Visualization PRIVATE ${VISUALIZATION_DIR})
target_include_directories(Visualization PRIVATE ${SDL2_INCLUDE_DIRS})
target_precompile_headers(Visualization PRIVATE src/stable.h)