    cmake_minimum_required(VERSION 3.8)
    project(HelloWorld)

    set(CMAKE_CXX_STANDARD 17)

    # Include a library search using find_package()
    # via REQUIRED, specify that libraries are required
    find_package(Qt5Core REQUIRED)
    find_package(Qt5Gui REQUIRED)
    find_package(Qt5Widgets REQUIRED)
    set(SOURCE_FILES main.cpp GUI/Button.h GUI/Box.h GUI/CSVparser.h GUI/StratWindow.cpp GUI/StratWindow.h GUI/Normal.cpp GUI/Normal.h GUI/Box.cpp GUI/ScrollArea.cpp GUI/ScrollArea.h GUI/Page.cpp GUI/Page.h NoP/NoPag.cpp NoP/NoPag.h)
    add_executable(HelloWorld ${SOURCE_FILES})

    # specify which libraries to connect
    target_link_libraries(${PROJECT_NAME} Qt5::Core)
    target_link_libraries(${PROJECT_NAME} Qt5::Gui)
    target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

    include_directories(${CPR_INCLUDE_DIRS})

    set(CURL_LIBRARY "-lcurl")
    find_package(CURL REQUIRED)
    include_directories(${CURL_INCLUDE_DIR})
    target_link_libraries(HelloWorld ${CURL_LIBRARIES})










