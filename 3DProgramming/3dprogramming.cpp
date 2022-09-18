#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


#pragma comment(lib, "OpenGL32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

}


int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        

        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.4f, 0.5f, 0.5f);

        double rad = 1.0;
        double x, y;
        glBegin(GL_LINE_STRIP); //점을 추가해주면 바로바로 직전의 점과 연결하여 선을 만들어준다.

        for (int i = 0; i < 360; i++)
        {
            double angle;
            angle = i * 3.141592 / 180;  //점의 좌표를 구하기 위해 sin,cos에 사용할 각도를 구한다.
            x = rad * cos(angle);      //cos은 밑변/빗변(반지름) 이기 때문에 반지름을 곱하면 밑변이 나온다.
            y = rad * sin(angle);      //sin은 높이/빗변(반지름) 이기 떄문에 반지름을 곱하면 높이가 나온다.
            glVertex2f(x, y);      //위에서 구한 밑변(x),높이(y)의 좌표로 점을 원이 완성될때까지 찍어준다.
        }                          //LINE_STRIP으로 인해 생성될때마다 선으로 이어주어 연결된 원이 완성된다. 끝
        


        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}