set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(TARGET opengl_test)

set(SOURCES
    main.cpp

    context.cpp
    simple_window.cpp
)

set(LIBRARIES
    ${CONAN_LIBS}
)

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET} PRIVATE ${LIBRARIES})
