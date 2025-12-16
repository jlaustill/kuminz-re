cmake_minimum_required(VERSION 3.5)

project(kuminz-ui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

# Add clip-core library (CLIP protocol business logic)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../clip-core ${CMAKE_CURRENT_BINARY_DIR}/clip-core)

set(TS_FILES kuminz-ui_en_US.ts)

# NOTE: CLIP protocol sources are now in clip-core library
# kuminz-ui only contains UI-specific code

# CAN adapter sources - only CanDeviceManager (Qt-dependent device discovery)
# SocketCanAdapter is now in clip-core
set(CAN_SOURCES
        src/can/CanDeviceManager.cpp
)

set(CAN_HEADERS
        src/can/CanDeviceManager.h
)

# UI widget sources
set(UI_SOURCES
        src/ui/widgets/ConnectionWidget.cpp
        src/ui/widgets/StatusBarWidget.cpp
)

set(UI_HEADERS
        src/ui/types/EAdapterState.h
        src/ui/types/EAdapterType.h
        src/ui/types/EConnectionState.h
        src/ui/types/TCanDevice.h
        src/ui/types/TConnectionSettings.h
        src/ui/widgets/ConnectionWidget.h
        src/ui/widgets/StatusBarWidget.h
)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${CAN_SOURCES}
        ${CAN_HEADERS}
        ${UI_SOURCES}
        ${UI_HEADERS}
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(kuminz-ui
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET kuminz-ui APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(kuminz-ui SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(kuminz-ui
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

# Include directories for UI code
# Note: clip-core headers are available via PUBLIC include from clip-core library
target_include_directories(kuminz-ui PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/can
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui
)

# Link clip-core library (contains all CLIP protocol logic) and Qt
target_link_libraries(kuminz-ui PRIVATE
    clip-core
    Qt${QT_VERSION_MAJOR}::Widgets
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.kuminz-ui)
endif()
set_target_properties(kuminz-ui PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS kuminz-ui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(kuminz-ui)
endif()
