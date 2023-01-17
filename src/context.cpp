#include <context.hpp>

#include <stdexcept>

std::shared_ptr<Context> Context::instance_;

std::shared_ptr<Context> Context::getInstance()
{
    if (!instance_)
    {
        instance_ = std::make_shared<Context>();
    }

    return instance_;
}

Context::Context()
{
    if (GLFW_TRUE != glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }
}

Context::~Context()
{
    glfwTerminate();
}

std::shared_ptr<GLFWwindow> Context::createWindow(int width, int height, const char *title)
{
    std::shared_ptr<GLFWwindow> window(glfwCreateWindow(width, height, title, nullptr, nullptr), glfwDestroyWindow);

    if (!window)
    {
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window.get());

    if (GLEW_OK != glewInit())
    {
        throw std::runtime_error("Failed to initialize GLEW");
    }

    return window;
}
