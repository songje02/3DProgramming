#include "MuSoenMath.h" //MuSoenMath.h�� �ҷ���
#include <iostream> //����� �����Լ�
#include <math.h> //���� ���� �������

int main(void) {
	//(3, 5)�̵�
	mat3 Translate(new float[3][3]{ //������Ͽ� �ִ� mat3�̶�� Ŭ������ ������ ��ġ�� ��İ��� �־���
		{ 1, 0, 0 },
		{ 0, 1, 0 },
		{ 3, 5, 1 } });

	//30�� ȸ��
	mat3 Rotate(new float[3][3]{
		{ (float)cos(PI / 6), -(float)sin(PI / 6), 0}, //30�� �̵��� ȣ�������� 30���� 180/30->PI/6  
		{ (float)sin(PI / 6), (float)cos(PI / 6), 0},  //���� ������Ͽ� ������ PI�� �����
		{ 0, 0, 1 } });

	//2�� Ŀ��
	mat3 Scale(new float[3][3]{
		{ 2, 0, 0 },
		{ 0, 2, 0 },
		{ 0, 0, 1 } });

	vec3 v(new float[3]{ 1, 1, 1 }); //v������ ��ǥ��
	vec3 p(new float[3]{ 0, 0, 0 }); //����� ���� ������ ��

	p = v * Translate * Rotate * Scale; //����

	for (int i = 0; i < 3; i++) { //����� ���� ����ϴ� ��
		std::cout << p.vec[i];
		std::cout << " ";
	}
}
