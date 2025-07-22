#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace std;


const char *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform mat4 transform;\n"
"void main()\n"
"{\n"
"    gl_Position = transform * vec4(aPos, 1.0);\n"
"}\0";

const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourcolor;\n"
"void main()\n"
"{\n"
"    FragColor = ourcolor;\n"
"}\0";

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Breakout Game", NULL, NULL);
    if (!window) {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }
    ///////////////////////////vertices/////////////////////
    float vertices[] = {
        0.25f,  -0.88f, 0.0f,  // top right  
        0.25f, -1.0f, 0.0f,  // bottom right
        -0.25f, -1.0f, 0.0f,  // bottom left
        -0.25f,  -0.88f, 0.0};
    float vertices3[] = { 
        0.15f,  0.84f, 0.0f,  // top right  
        0.15f, 0.59f, 0.0f,  // bottom right
        -0.15f, 0.59f, 0.0f,  // bottom left
        -0.15f,  0.84f, 0.0};
    float vertices6[] = { 
        0.15f,  0.39f, 0.0f,  // top right  
        0.15f, 0.14f, 0.0f,  // bottom right
        -0.15f, 0.14f, 0.0f,  // bottom left
        -0.15f,  0.39f, 0.0};
    float vertices7[] = { 
        0.35f,  0.39f, 0.0f,  // top right  
        0.35f, 0.14f, 0.0f,  // bottom right
        0.65f, 0.14f, 0.0f,  // bottom left
        0.65f,  0.39f, 0.0};
    float vertices4[] = { 
        0.35f,  0.84f, 0.0f,  // top right  
        0.35f, 0.59f, 0.0f,  // bottom right
        0.65f, 0.59f, 0.0f,  // bottom left
        0.65f,  0.84f, 0.0};
    float vertices5[] = {
        -0.35f,  0.39f, 0.0f,  // top right  
        -0.35f, 0.14f, 0.0f,  // bottom right
        -0.65f, 0.14f, 0.0f,  // bottom left
        -0.65f,  0.39f, 0.0};
    float vertices2[] = {
        -0.35f,  0.84f, 0.0f,  // top right  
        -0.35f, 0.59f, 0.0f,  // bottom right
        -0.65f, 0.59f, 0.0f,  // bottom left
        -0.65f,  0.84f, 0.0
    };
    ///////////////////////////////////////////////////////////////////////
    //boolean vector
    vector<bool> bricksExist(6, true);
    unsigned int indices[] = {  
        0, 1, 3,  // First triangle (top right, bottom right, top left)
        1, 2, 3   // Second triangle (bottom right, bottom left, top left)
    };

    unsigned int VBO, EBO, VBO2,VBO3,VBO4,VBO5,VBO6,VBO7;
    glGenBuffers(1, &VBO);glGenBuffers(1, &EBO);
    glGenBuffers(1, &VBO2);glGenBuffers(1, &VBO3);glGenBuffers(1, &VBO4);
    glGenBuffers(1, &VBO5);glGenBuffers(1, &VBO6);glGenBuffers(1, &VBO7); 

    unsigned int VAO1,VAO2,VAO3,VAO4,VAO5,VAO6,VAO7;

    glGenVertexArrays(1, &VAO1);
    glGenVertexArrays(1, &VAO2);
    glGenVertexArrays(1, &VAO3); 
    glGenVertexArrays(1, &VAO4); 
    glGenVertexArrays(1, &VAO5); 
    glGenVertexArrays(1, &VAO6); 
    glGenVertexArrays(1, &VAO7);
    // Setup VAO1 for paddle
    glBindVertexArray(VAO1);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //
    glBindVertexArray(VAO2);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(VAO3);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO3);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Setup VAO2 for bricks or second object
    glBindVertexArray(VAO4);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO4);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices4), vertices4, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    //
    glBindVertexArray(VAO5);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO5);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices5), vertices5, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //
    glBindVertexArray(VAO6);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO6);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices6), vertices6, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //
    glBindVertexArray(VAO7);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO7);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices7), vertices7, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //
    
    //for ball
    const int numSegments = 60;  // More segments = smoother circle
    const float radius = 0.05f;  // Ball size

    std::vector<float> ballVertices;

    // Center of circle
    ballVertices.push_back(0.0f); // x
    ballVertices.push_back(-0.83f); // y
    ballVertices.push_back(0.0f); // z

    for (int i = 0; i <= numSegments; ++i)
    {
        float angle = (2.0f * M_PI * i) / numSegments;
        float x = radius * cos(angle);
        float y = -0.83f + radius * sin(angle);

        ballVertices.push_back(x);
        ballVertices.push_back(y);
        ballVertices.push_back(0.0f); // z-coordinate (2D ball)
    }

    unsigned int ballVBO, ballVAO;
    glGenVertexArrays(1, &ballVAO);
    glGenBuffers(1, &ballVBO);

    glBindVertexArray(ballVAO);

    glBindBuffer(GL_ARRAY_BUFFER, ballVBO);
    glBufferData(GL_ARRAY_BUFFER, ballVertices.size() * sizeof(float), ballVertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    // Compile vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Compile fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    //minx point of the paddle
    float minp = -0.25f;
    //maxx point of paddle
    float maxp = 0.25f;
    float xOffset = 0.0f;
    float Ballposx = 0.0f;
    float Ballposy = 0.0f;
    float factorx = 0.015f;
    float factory = 0.015f;
    float maxx = 0.0f;

    ////////////////////////////////
    vector<std::tuple<float, float>> brickswalls1;
    brickswalls1.push_back(std::make_tuple(-0.65f, -0.35f));
    brickswalls1.push_back(std::make_tuple(-0.15f, 0.15f));
    brickswalls1.push_back(std::make_tuple(0.35f, 0.65f));
    vector<std::tuple<float, float>> brickswalls2;
    brickswalls2.push_back(std::make_tuple(0.59f, 0.84f));
    brickswalls2.push_back(std::make_tuple(0.14f, 0.39f));
    













    // Render loop
    while (!glfwWindowShouldClose(window)) {
        // Get uniform location
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourcolor");

        // Set the color every frame (e.g., time-based green changing)
        float timeValue = glfwGetTime();
        float greenValue = (sin(timeValue) / 2.0f) + 0.5f;


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        //keys pressed
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
            xOffset -= 0.015f; // Move left

        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
            xOffset += 0.015f; // Move right

        float limit = 0.75f; // Half width to avoid the center crossing the boundary

        if (xOffset > limit)
            xOffset = limit;

        if (xOffset < -limit)
            xOffset = -limit;

        
        
        //sending the uniform

        // Send color to shader (R, G, B, A)
        glUniform4f(vertexColorLocation, 1.0f, greenValue, 0.0f, 1.0f);
        //paddle
        glm::mat4 trans = glm::mat4(1.0f);
        int transformLoc = glGetUniformLocation(shaderProgram, "transform");
        glm::mat4 paddleTransform = glm::translate(trans, glm::vec3(xOffset, 0.0f, 0.0f));
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(paddleTransform)); 
        
        glBindVertexArray(VAO1);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //////
        bool booolean = false;
        for (size_t i = 0; i < bricksExist.size(); i++) {
            booolean = bricksExist[i] || booolean;
        }
        //draw circle
        Ballposx +=factorx;
        Ballposy +=factory;
         float limit2 = 0.95f;
        if (Ballposx > limit2){
            Ballposx = limit2;
            factorx = -0.015f;
        }
        if (Ballposx < -limit2 ){
            Ballposx = -limit2;
            //std::cout << Ballposy << std::endl;
            factorx = 0.015f;
        }
        if (Ballposy > 1.78f){
            //factorx = -1*factorx;
            Ballposy = 1.78f;
            factory = -0.015f;
        }
        if (Ballposy <= 0.0f && Ballposx >= minp+xOffset && Ballposx <= maxp+xOffset){
            //std :: cout << "Happy" << std::endl;
            factory = 0.015f;
            
            //std:: cout << "Happy";
        }else if (Ballposy < 0.0f or booolean==false){
            glfwSetWindowShouldClose(window, true);
        }

        glm::mat4 bricks = glm::translate(trans, glm::vec3(0.0f, 0.0f, 0.0f));
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(bricks));
        
        float BallRealY = Ballposy - 0.83f;

        bool check = false;
        // For top/bottom of the bricks (brickswalls1)
        for (size_t i = 0; i < brickswalls1.size(); i++) {
            float low = get<0>(brickswalls1[i]);
            float up = get<1>(brickswalls1[i]);

            if (Ballposx >= low && Ballposx <= up) {
                // Top row bricks
                if (BallRealY >= 0.84f && (BallRealY - 0.84f) <= radius && bricksExist[i] == 1){
                    bricksExist[i] = 0;
                    check = 1;
                    cout << 1 << endl;
                    //Ballposy = 0.84f+radius;
                    factory = -factory; // Reflect vertically
                }
                // Middle row bricks
                else if (BallRealY <= 0.59f && (0.59f - BallRealY) <= radius  && bricksExist[i] == 1) {
                    bricksExist[i] = 0;
                    //Ballposy = 0.59f-radius;
                    factory = -factory; // Reflect vertically
                    check = 1;
                    cout << 2 << endl;
                }
                // Lower row bricks
                else if (BallRealY >= 0.39f && (BallRealY-0.39f) <= radius  && bricksExist[i+3] == 1) {
                    bricksExist[i + 3] = 0;
                    //Ballposy = 0.39f+radius;
                    factory = -factory; // Reflect vertically
                    check = 1;
                    cout << 3 << ' ' << i << ' ' << Ballposy << ' ' << BallRealY << ' ' << radius <<  endl;
                }
                else if (BallRealY <= 0.14f && (0.14f - BallRealY) <= radius  && bricksExist[i+3] == 1) {
                    bricksExist[i + 3] = 0;
                    //Ballposy = 0.14f-radius;
                    factory = -factory; // Reflect vertically
                    check = 1;
                    cout << 4 << endl;
                }
            }
        }
        if (check == 0){
        // For left/right walls of the bricks (brickswalls2)
        for (size_t i = 0; i < brickswalls2.size(); i++) {
            float low = get<0>(brickswalls2[i]);
            float up = get<1>(brickswalls2[i]);

            int h = (i == 1) ? 2 : 0;

            if (BallRealY >= low && BallRealY <= up) {
                // Left wall of left brick
                if (Ballposx <= -0.65f && (-0.65f - Ballposx) <= radius && bricksExist[i + h] == 1) {
                    factorx = -factorx; // Reflect horizontally
                    //Ballposx = -0.65f - radius;
                    bricksExist[i + h] = 0;
                }
                // Right wall of left brick
                else if (Ballposx >= -0.35f && (Ballposx - (-0.35f)) <= radius && bricksExist[i + h] == 1) {
                    factorx = -factorx;
                    //Ballposx = -0.35f + radius;
                    bricksExist[i + h] = 0;
                }
                // Left wall of middle brick
                else if (Ballposx <= -0.15f && (-0.15f - Ballposx) <= radius && bricksExist[i + 1+ h] == 1) {
                    factorx = -factorx;
                    //Ballposx = -0.15f - radius;
                    bricksExist[i + 1 + h] = 0;
                }
                // Right wall of middle brick
                else if (Ballposx >= 0.15f && (Ballposx - 0.15f) <= radius && bricksExist[i + 1 + h] == 1) {
                    factorx = -factorx;
                    //Ballposx = 0.15f + radius;
                    bricksExist[i + 1 + h] = 0;
                }
                // Left wall of right brick
                else if (Ballposx <= 0.35f && (0.35f - Ballposx) <= radius && bricksExist[i + 2 + h] == 1) {
                    factorx = -factorx;
                    //Ballposx = 0.35f - radius;
                    bricksExist[i + 2 + h] = 0;
                }
                // Right wall of right brick
                else if (Ballposx >= 0.65f && (Ballposx - 0.65f) <= radius && bricksExist[i + 2 + h] == 1) {
                    factorx = -factorx;
                    //Ballposx = 0.65f + radius;
                    bricksExist[i + 2 + h] = 0;
                }
            }
        }}


        if (bricksExist[0]){
        glBindVertexArray(VAO2);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);}
        if (bricksExist[1]){
        glBindVertexArray(VAO3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);}
        if (bricksExist[2]){
        glBindVertexArray(VAO4);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);}
        if (bricksExist[3]){
        glBindVertexArray(VAO5);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);}
        if (bricksExist[4]){
        glBindVertexArray(VAO6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);}
        if (bricksExist[5]){
        glBindVertexArray(VAO7);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);}

        glm::mat4 BallTransform = glm::translate(trans, glm::vec3(Ballposx, Ballposy, 0.0f));
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(BallTransform)); 
        glBindVertexArray(ballVAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, numSegments + 2);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // Cleanup
    glDeleteVertexArrays(1, &VAO1);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO2);
    glDeleteVertexArrays(1, &VAO3);
    glDeleteVertexArrays(1, &VAO4);
    glDeleteVertexArrays(1, &VAO5);
    glDeleteVertexArrays(1, &VAO6);
    glDeleteVertexArrays(1, &VAO7);
    glDeleteBuffers(1, &VBO2);
    glDeleteBuffers(1, &VBO3);
    glDeleteBuffers(1, &VBO4);
    glDeleteBuffers(1, &VBO5);
    glDeleteBuffers(1, &VBO6);
    glDeleteBuffers(1, &VBO7);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return 0;
}
