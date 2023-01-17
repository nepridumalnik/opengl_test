#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <memory>

class Context
{
public:
    Context();
    ~Context();

    std::shared_ptr<GLFWwindow> createWindow(int width, int height, const char *title);
    static std::shared_ptr<Context> getInstance();

private:
    static std::shared_ptr<Context> instance_;
};
