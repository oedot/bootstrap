//

#include <glad/glad.h>
#include <GLFW/glfw3.h>


int main() {
    // initialize the GLFW library
    if (glfwInit() == GLFW_FALSE) {
        return 1;
    }

    class terminate_t {
    public:

        ~terminate_t() noexcept {
            // make sure the 'glfwTerminate()' is called
            glfwTerminate();
        }

    } terminate = {};

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // choose OpenGL major version (just a hint)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4); // choose OpenGL minor version (just a hint)

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

    // create a windowed mode window and its OpenGL context
    auto wnd = glfwCreateWindow(1280, 720, "OpenGL", nullptr, nullptr);
    if (!wnd) {
        return 1;
    }

    // make the window's context current
    glfwMakeContextCurrent(wnd);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        // failed to initialize the OpenGL Context
        return 1;
    }

    // loop until the user closes the window
    while (!glfwWindowShouldClose(wnd)) {

        glClearColor(0.875, 0.875, 0.875, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // swap front and back buffers
        glfwSwapBuffers(wnd);
        // poll for and process events
        glfwPollEvents();
    }

    return 0;
}
