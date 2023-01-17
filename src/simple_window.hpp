#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <memory>
#include <string>

class Context;

class SimpleWindow
{
public:
    SimpleWindow(std::shared_ptr<Context> context = nullptr);

    std::shared_ptr<Context> getContext();

    void run();
    void setTitle(const std::string &title);
    void setSize(size_t width, size_t height);
    void setFullScreen(bool flag = true);
    void setBorderless(bool flag = true);

private:
    std::shared_ptr<GLFWwindow> window_;

    size_t width_;
    size_t height_;
    size_t posX_;
    size_t posY_;
};