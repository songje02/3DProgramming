#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>
#include "MuSoenMath.h";

#pragma comment(lib, "OpenGL32")

using namespace std;

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;


struct Vertex
{
    vec3 pos;
    float r, g, b, a;
};

struct Transform
{
    mat3 translate;
    mat3 scale;
    mat3 rotation;

    mat3 t_move;
    mat3 r_rotate;
    mat3 u_scale;
    mat3 d_scale;
};

Vertex star[5];             // static mesh
Vertex transformedStar[5];  //ȭ�鿡 �׸� ������
Vertex circle[360];             // static mesh 
Vertex transformedCircle[360];  // ȭ�鿡 �׷��� ��

Transform transform;  //world ����� �� transform

//<����>////////�������� ���°�////////////////////////////////////////////////////////////

bool change = true; //ũ�� ��ȭ�� ���� ����
float scale_v; //ũ�� �� ����

mat3 t_move = (new float[3][3]{ //�̵� ��� ����
    {1, 0, 0},
    {0, 1, 0},
    {0.001f, 0, 1} });

mat3 r_rotate = (new float[3][3]{ //ȸ�� ��� ����
    {(float)cos((PI / 180) * 1) , -(float)sin((PI / 180) * 1), 0},
    {(float)sin((PI / 180) * 1), (float)cos((PI / 180) * 1), 0},
    {0, 0, 1} });

mat3 u_scale = (new float[3][3]{ //ũ�� Ŀ���� ��� ����
    {1.01f, 0, 0},
    {0, 1.01f, 0},
    {0, 0, 1} });

mat3 d_scale = (new float[3][3]{ //ũ�� �۾����� ��� ����
    {0.99f, 0, 0},
    {0, 0.99f, 0},
    {0, 0, 1} });
//////////////////////////////////////////////////////////////////////////////////////////

void Init();
void Update();
void Release();

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();

    //object������
     /// Star(������) ����
    int i = 0;
    for (float theta = 0; theta < 360; theta += 72)
    {
        star[i].pos.vec[0] = -sin(theta * PI / 180.0f) * 0.5f;
        star[i].pos.vec[1] = cos(theta * PI / 180.0f) * 0.5f;
        star[i].pos.vec[2] = 1.0f;

        //������ �� ����
        star[i].r = 0.5f;
        star[i].g = 0.0f;
        star[i].b = theta / 360.0f;
        star[i].a = 0.7f;

        transformedStar[i] = star[i];

        i++;
    }

    // �� ����
    for (int theta = 0; theta < 360; theta++)
    {
        circle[theta].pos.vec[0] = -sin(theta * PI / 180.0f) * 0.5f;
        circle[theta].pos.vec[1] = cos(theta * PI / 180.0f) * 0.5f;
        circle[theta].pos.vec[2] = 1.0f;

        //�� ����
        circle[theta].r = 0.3f;
        circle[theta].g = 0.0f;
        circle[theta].b = (float)theta / 360.0f;
        circle[theta].a = 0.7f;

        transformedCircle[theta] = circle[theta];
    }

    //Ʈ������ �ʱ�ȭ (�⺻�� ����)
    transform.translate = (new float[3][3]{
       {1, 0, 0},
       {0, 1, 0},
       {0, 0, 1} });

    transform.rotation = (new float[3][3]{
        {cos(0.0f), -sin(0.0f), 0},
        {sin(0.0f), cos(0.0f), 0 },
        {0, 0, 1} });

    transform.scale = (new float[3][3]{
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1} });

}

void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Update()
{
    while (!glfwWindowShouldClose(window))
    {
        //Update����
        //<����>//////////////////////////////////////////////////////////////////////////////////

        //1. translate �� �����Ӵ� ���������� 0.001�� �������Ѽ� ��ü�� �̵��غ�����.
        //2. Rotation �� �����Ӵ� 1���� �������Ѽ� ��ü�� ȸ�����Ѻ�����.
        //3. Scale�� �ʴ� 0.01�� �ִ� 1.3����� �þ�ٰ� 0.7����� �پ�鵵�� ����ÿ� (�ݺ�)
        //   (1.3�� �̻��� �Ǹ� �پ��� 0.7�� ���ϰ� �Ǹ� �ٽ� �þ�� ����ÿ�)

        transform.translate = transform.translate * t_move; //�̵�
        transform.rotation = transform.rotation * r_rotate; //ȸ��
        if (change) {
            transform.scale = transform.scale * u_scale; //ũ�� Ȯ��
            scale_v += 0.01f;
            if (1 + scale_v >= 1.3f) {
                change = false;
            }
        }
        if (!change) {
            scale_v -= 0.01f;
            transform.scale = transform.scale * d_scale; //ũ�� ���
            if (1 + scale_v <= 0.7f) {
                change = true;
            }
        }

        //////////////////////////////////////////////////////////////////////////////////////////

        for (int i = 0; i < 360; i++)
        {
            transformedCircle[i].pos = circle[i].pos * transform.scale * transform.rotation * transform.translate;
        }
        for (int i = 0; i < 5; i++)
        {
            transformedStar[i].pos = star[i].pos * transform.scale * transform.rotation * transform.translate;
        }

        //�� �ʱ�ȭ
        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);
        //���β�
        glLineWidth(7.0f);
        //������ �׸���
        glBegin(GL_LINE_STRIP);
        int a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec[0], transformedStar[a].pos.vec[1], 0.0f);
        a = 3;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec[0], transformedStar[a].pos.vec[1], 0.0f);
        a = 1;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec[0], transformedStar[a].pos.vec[1], 0.0f);
        a = 4;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec[0], transformedStar[a].pos.vec[1], 0.0f);
        a = 2;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec[0], transformedStar[a].pos.vec[1], 0.0f);

        a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec[0], transformedStar[a].pos.vec[1], 0.0f);
        glEnd();

        //���׸���
        glBegin(GL_LINE_STRIP);
        for (int theta = 0; theta < 360; theta++)
        {
            glColor4f(transformedCircle[theta].r, transformedCircle[theta].g, transformedCircle[theta].b, transformedCircle[theta].a);
            glVertex3f(transformedCircle[theta].pos.vec[0], transformedCircle[theta].pos.vec[1], 0.0f);
        }
        glEnd();

        //ȭ�� ����
        glfwSwapBuffers(window);
        glfwPollEvents();

        //�����ð� ����
        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();

        float fps = 1.0 / renderDuration.count();
        if (isFirstFrame == true)
        {
            isFirstFrame = false;
            continue;
        }
        if (renderDuration.count() < (1.0f / 60.0f))
            this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
        /*string fps_s = "FPS : " + to_string(fps);
        cout << fps_s << endl;*/

    }
}

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
    Init();
    Update();
    Release();

    exit(EXIT_SUCCESS);

}