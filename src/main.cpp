#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
 void framebuffer_size_callback(GLFWwindow* window, int width, int height);


 void processInput(GLFWwindow* window)
 {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true); 
    }
    if(glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
    {
         glClearColor(0.2f, 0.3f, 0.3f, 1.0f); 
    }
 }


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
        glViewport(0,0, width, height); 
}
int main()
{
    //initialize shader source variables 
    const char *vertexShaderSource="#version 330 core\n"
    "layout (location=0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\n";

    const char *fragmentShaderSource="#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "FragColor = vec4(1.0f,0.5f,0.2f,1.0f);"
    "\n";




    //initialize vertex shader ID and compile
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);    
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader); 

    //initialize fragment shader ID and compile
    unsigned int fragmentShader; 
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    
    //check if the vertexShader compiled correctly
    int vertexSuccess; 
    char vertexinfoLog[512]; 
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexSuccess);
    if(!vertexSuccess)
    {
        glGetShaderInfoLog(vertexShader,512,NULL,vertexinfoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << vertexinfoLog << std::endl; 
    }

    //check if the fragmentShader compiled correctly 
    int fragmentSuccess; 
    char fragmentinfoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentSuccess);
    if(!fragmentSuccess)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, fragmentinfoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << fragmentinfoLog << std::endl; 
    }

    //initialize shaderProgram and attach both the vertex and fragment shaders 
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader); 
    glAttachShader(shaderProgram, fragmentShader); 
    glLinkProgram(shaderProgram); 


    //check if the shader program linked correctly 
    int shaderProgSuccess;
    char shaderProginfoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &shaderProgSuccess);
    if(!shaderProgSuccess)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, shaderProginfoLog);
        std::cout << "ERROR::SHADER_PROGRAM::COMPILATION_FAILED\n" << shaderProginfoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader); 

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    unsigned int VAO; 
    glGenVertexArrays(1, &VAO);
    


    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 


    GLFWwindow* window = glfwCreateWindow(800,600,"openglwindow", NULL, NULL);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
    
    
    //render triangles 
    float vertices[]{
        -0.5f, -0.5f, 0.0f, 
        0.5f, -0.5f,  0.0f, 
        0.0f, 0.5f, 0.0f
    };  

    //Generate buffer ID using glGenBuffers function 
    unsigned int VBO; 
    glGenBuffers(1, &VBO); 

    //Bind the buffer ID to a GL_ARRAY_BUFFER (name of Vertex Buffer Object)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //Make a call to the glBufferData function that copies previously defined vertex data into the buffer's memory 
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 


    if(window == NULL)
    {
        std::cout << "Failed to create opengl window"; 
        glfwTerminate(); 
        return -1; 
    }
   
    while(!glfwWindowShouldClose(window))
    {
        processInput(window); 
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,3);

        glfwPollEvents(); 
        
        glfwSwapBuffers(window);     
    }
    glfwMakeContextCurrent(window);
    glfwTerminate(); 
    return 0;  
}