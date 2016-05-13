
set(SRC_DEMO_DESKTOP
        desktop/main.cpp
)
#INCLUDE_DIRECTORIES("../../include")

add_executable (desktopDemo ${SRC_DEMO_DESKTOP})

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
target_link_libraries (desktopDemo LINK_PUBLIC ugf)
