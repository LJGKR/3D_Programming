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
        glBegin(GL_LINE_STRIP); //���� �߰����ָ� �ٷιٷ� ������ ���� �����Ͽ� ���� ������ش�.

        for (int i = 0; i < 360; i++)
        {
            double angle;
            angle = i * 3.141592 / 180;  //���� ��ǥ�� ���ϱ� ���� sin,cos�� ����� ������ ���Ѵ�.
            x = rad * cos(angle);      //cos�� �غ�/����(������) �̱� ������ �������� ���ϸ� �غ��� ���´�.
            y = rad * sin(angle);      //sin�� ����/����(������) �̱� ������ �������� ���ϸ� ���̰� ���´�.
            glVertex2f(x, y);      //������ ���� �غ�(x),����(y)�� ��ǥ�� ���� ���� �ϼ��ɶ����� ����ش�.
        }                          //LINE_STRIP���� ���� �����ɶ����� ������ �̾��־� ����� ���� �ϼ��ȴ�. ��
        


        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}