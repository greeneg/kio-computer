cmake_minimum_required(VERSION 3.16)

project(kio-computer)
set(PROJECT_VERSION "1.0")
set(PROJECT_VERSION_MAJOR 1)

set(QT_MIN_VERSION "5.15.2")
set(KF5_MIN_VERSION "5.98.0")
set(KDE_COMPILERSETTINGS_LEVEL "5.82")

option(WITH_X11 "Build with X11 support. Building without is experimental" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ECM ${KF5_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(ECMMarkNonGuiExecutable)
include(FeatureSummary)

add_library(kio_computer MODULE computer.cpp)
find_package(KF5 ${KF5_MIN_VERSION} REQUIRED KIO)
target_link_libraries(kio_computer KF5::KIOCore)
set_target_properties(kio_computer PROPERTIES OUTPUT_NAME "computer")

install(TARGETS kio_computer DESTINATION ${KDE_INSTALL_PLUGINDIR}/kf5/kio )
