#include <simple_window.hpp>

#include <context.hpp>

SimpleWindow::SimpleWindow(std::shared_ptr<Context> context) : width_{640}, height_{480}
{
    if (!context)
    {
        context = Context::getInstance();
    }

    window_ = context->createWindow(width_, height_, "Example");
}

std::shared_ptr<Context> SimpleWindow::getContext()
{
    return Context::getInstance();
}

void SimpleWindow::run()
{
    // Main loop
    while (!glfwWindowShouldClose(window_.get()))
    {
        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window_.get());

        // Poll for and process events
        glfwPollEvents();
    }
}

void SimpleWindow::setTitle(const std::string &title)
{
    glfwSetWindowTitle(window_.get(), title.c_str());
}

void SimpleWindow::setSize(size_t width, size_t height)
{
    glfwSetWindowSize(window_.get(), width, height);
}

void SimpleWindow::setFullScreen(bool flag)
{
    if (flag)
    {
        int width;
        int height;
        GLFWmonitor *monitor = glfwGetPrimaryMonitor();

        glfwGetMonitorPhysicalSize(monitor, &width, &height);
        glfwGetMonitorPos(monitor, reinterpret_cast<int *>(&posX_), reinterpret_cast<int *>(&posY_));

        glfwSetWindowMonitor(window_.get(), glfwGetPrimaryMonitor(), 0, 0, width, height, GLFW_DONT_CARE);
    }
    else
    {
        glfwSetWindowMonitor(window_.get(), glfwGetPrimaryMonitor(), posX_, posY_, width_, height_, GLFW_DONT_CARE);
    }
}

void SimpleWindow::setBorderless(bool flag)
{
    if (flag)
    {
        glfwSetWindowAttrib(window_.get(), GLFW_DECORATED, GLFW_FALSE);
    }
    else
    {
        glfwSetWindowAttrib(window_.get(), GLFW_DECORATED, GLFW_TRUE);
    }
}
