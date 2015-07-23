project(IPAInfo)
 
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(
    wxWidgets COMPONENTS core base REQUIRED
)
 
find_package(
    libplist REQUIRED
)

include( 
    "${wxWidgets_USE_FILE}" 
    "${libplist_INCLUDE_DIR}"
)
 
add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/MainApp.cpp
    src/MainFrame.cpp
    src/wui.cpp
    src/Ipa.cpp
)
 
target_link_libraries(
    ${PROJECT_NAME}
    ${wxWidgets_LIBRARIES}
    ${libplist_LIBRARIES}
)