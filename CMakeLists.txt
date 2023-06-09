cmake_minimum_required(VERSION 3.25)

project(sp VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(sp)

target_include_directories(sp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(sp
    PRIVATE
        main.cpp
        cell.cpp cell.h
        spreadsheet.cpp spreadsheet.h
        finddialog.cpp finddialog.h
        gotocelldialog.cpp gotocelldialog.h gotocell.ui
        sortdialog.cpp sortdialog.h sort.ui
        window.h window.cpp window.ui


        
    PUBLIC
        sp.qrc
)

set_target_properties(sp PROPERTIES AUTORCC on) #enable Resource Compiler

target_compile_features(sp PRIVATE cxx_std_20)

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET sp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation


target_link_libraries(sp
    PRIVATE 
        Qt6::Widgets
)












































# set_target_properties(sp PROPERTIES
#     MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

# install(TARGETS sp
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(sp)
# endif()





#qt_add_executable(sp)  //Creates and finalizes an application target of a platform-specific type.
#This command performs the following tasks:

#    1. Create a CMake target of the appropriate type for the target platform.
#    2. Link the target to the Qt::Core library.
#    3. Handle finalization of the CMake target.



# qt_standard_project_setup()     #set(CMAKE_AUTOUIC ON)  set(CMAKE_AUTOMOC ON)  set(CMAKE_AUTORCC ON)

