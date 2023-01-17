#include <simple_window.hpp>

#include <iostream>

int main()
{
    try
    {
        SimpleWindow window;

        window.setTitle("Test Window");
        window.setSize(1280, 720);

        window.run();
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }

    return 0;
}
