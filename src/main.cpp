#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <developer/developer.h>


static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << 
            (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader." << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }


    return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int main()
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(600, 480, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;


    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);


    float positions[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    // create a vertex buffer
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);



    std::string vertexShader = 
        "#version 330 core \n"
        "\n"
        "layout(location = 0) in vec2 position; \n"
        "\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(position, 0.0, 1.0); \n"
        "}\n";

    std::string fragmentShader = 
        "#version 330 core \n"
        "\n"
        "layout(location = 0) out vec4 fragColor; \n"
        "\n"
        "void main()\n"
        "{\n"
        "   fragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\n";
    
    unsigned int shader = CreateShader(vertexShader, fragmentShader);
    glUseProgram(shader);


    // render loop
    while (!glfwWindowShouldClose(window))
    {

        // Set the clear color
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }


    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

