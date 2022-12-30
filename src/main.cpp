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
    const char *vertexShaderSource="#version 330 core\n"
    "layout (location=0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\n";

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);    

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader); 

    int success; 
    char infoLog[512]; 
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
        
       

        glfwPollEvents(); 
        
        glfwSwapBuffers(window);     
    }
    glfwMakeContextCurrent(window);
    glfwTerminate(); 
    return 0;  
}