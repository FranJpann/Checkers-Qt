cmake_minimum_required(VERSION 3.5) # Version à adapter si besoin

project(JeuDeDame LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11) # C++ 11, peut-être 14 ou 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED) # QWidget
set(TS_FILES JeuDame_fr_FR.ts JeuDame_en_US.ts)
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

add_executable(${PROJECT_NAME}
    "main.cpp"
    "fenetre.cpp" "fenetre.h"
    "zoneplateau.cpp" "zoneplateau.h"
    "pion.cpp" "pion.h"
    "box.cpp" "box.h"
    "ressources.qrc"
${QM_FILES})

target_link_libraries(JeuDeDame PRIVATE Qt5::Widgets)
