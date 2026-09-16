/*Following along freeCodeCamp's crash course on OpenGL, available on youtube
https://www.youtube.com/watch?v=45MIykWJ-C4 */

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragementShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";




int main()
{
    // Initialize GLFW
    glfwInit();

    // Tell GLFW what version of OpenGL we are using
    // In this case we are using OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Tell GLFW we are using the CORE profile
    // Thus only have the modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // Defining the coordinates for a equilateral triangle
    GLfloat vertices[] =
    {
        -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
        0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
        0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
    };




    // Creates a GLFWWindow object with a width of 800, height of 800
    // and named YoutubeOpenGL
    GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);

    // Error check if window fails to create
    if(window == NULL)
    {
        std::cerr << "Failed to create GLFW window \n";
        glfwTerminate();
        return -1;
    }
    

    // Bring the window into the current context
    glfwMakeContextCurrent(window);


    // Load GLAD so it configues OpenGL
    gladLoadGL();

    // Specify the viewport of OpenGL in the Window
    // The viewport goes from x = 0, y = 0, to x = 800, y = 800
    glViewport(0, 0, 800, 800);

    // OpenGL version of an unsigned integer (positive integers)
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    // GPU can't understand source code, so we must compile it now into machine code
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragmentShader, 1, &fragementShaderSource, NULL);
     // GPU can't understand source code, so we must compile it now into machine code
    glCompileShader(fragmentShader);

    // In order to actually use the shaders, we need to
    // "wrap" them up into a "shader program"
    GLuint shaderProgram = glCreateProgram();

    // Attaching the shaders to the shader program reference
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    // Wrapping the shader program
    glLinkProgram(shaderProgram);

    // To keep things tidy, we delete the shaders since they are
    // already in the shader program
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Vertex Buffer Object (VBO) is usually an array of references, but since
    // we only have one object, we leave it as an uint
    // Vertex Array Object stores pointers to one or more VBO's and tells
    // OpenGL how to interpret them, allows us to switch quickly between
    // different VBO's
    GLuint VAO, VBO;

    glGenVertexArrays(1, &VAO);

    // Create the buffer, we only have one object, so we pass 1
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);

    // Binding the buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Actually storing the vertex data into VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);




    // Specify the color we want to appear in the window
    glClearColor(0.0f, 0.13f, 0.17f, 1.0f);

    // Clears the back buffer and assigns our new color to it
    glClear(GL_COLOR_BUFFER_BIT);

    // Swaps the back buffer with the front buffer, showing the color we created
    glfwSwapBuffers(window);


    // Main while loop
    while(!glfwWindowShouldClose(window))
    {
        // Take care of all GLFW events, e.g. keyboard/mouse inputs, window resizing, etc.
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);


    // Delete window before ending the program
    glfwDestroyWindow(window);
    
    // Terminate GLFW before ending the program
    glfwTerminate();
    return 0;
}


