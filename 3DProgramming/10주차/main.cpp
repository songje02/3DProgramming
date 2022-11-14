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

	mat3 sum(new float[3][3]{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1} });

	mat4 mat4_sum(new float[4][4]{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1} });

	mat4 mat4_Translate(new float[4][4]{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{3, 5, 1, 1} });

	mat4 mat4_Scale(new float[4][4]{
		{2, 0, 0, 0},
		{0, 2, 0, 0},
		{0, 0, 2, 0},
		{0, 0, 0, 1} });

	vec3 v(new float[3]{ 1, 1, 1 }); //v������ ��ǥ��
	vec3 a(new float[3]{ 3, 5, 1 }); 
	vec3 p(new float[3]{ 0, 0, 0 }); //����� ���� ������ ��

	vec4 vec4_v(new float[4]{ 1, 1, 1, 1 });
	vec4 vec4_t(new float[4]{ 3, 5, 1, 1 });
	vec4 vec4_p(new float[4]{ 0, 0, 0, 0 });

	vec1x3 vec1x3_v(new float[1][3]{ { 1, 1, 1 } });
	vec1x3 vec1x3_t(new float[1][3]{ { 3, 5, 1 } });
	vec1x3 vec1x3_p(new float[1][3]{ { 0, 0, 0 } });

	vec1x4 vec1x4_v(new float[1][4]{ { 1, 1, 1, 1 } });
	vec1x4 vec1x4_t(new float[1][4]{ { 3, 5, 1, 1 } });
	vec1x4 vec1x4_p(new float[1][4]{ { 0, 0, 0, 0 } });

	p = v * a; //���ͳ��� ��
	for (int i = 0; i < 3; i++) {
		std::cout << p.vec[i];
		std::cout << " ";
	}

	//class mat3
	//Translate.Transpose();
	//p = v * Translate * Rotate * Scale; //����
	//for (int i = 0; i < 3; i++) { //���ϱ� ���� ���
	//	std::cout << p.vec[i];
	//	std::cout << " ";
	//}

	//p = Translate * v;
	//for (int i = 0; i < 3; i++) { //���ϱ� ���� ���
	//	std::cout << p.vec[i];
	//	std::cout << " ";
	//}

	//Translate.Transpose();
	//sum = Translate * Scale; //��� ����
	////sum = Translate + Scale; //��� ����
	//sum = Translate - Scale; //��� ����
	//sum = Translate / 2; //mat3 ������ ��� ���
	//sum = Translate * 2; //mat3 ���� ��� ���
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		std::cout << sum.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//class mat4
	//mat4_Translate.Transpose();						
	//vec4_p = vec4_v * mat4_Translate * mat4_Scale;
	//for (int i = 0; i < 4; i++) { //���ϱ� ���� ���
	//	std::cout << vec4_p.vec[i];
	//	std::cout << " ";
	//}

	//mat4_sum = mat4_Scale + mat4_Translate; //3���� ���� ���
	//mat4_sum = mat4_Scale - mat4_Translate; //3���� ���� ���
	//mat4_sum = mat4_Scale * mat4_Translate; //3���� ���� ��� 
	//mat4_sum = mat4_Translate / 2; //3���� ��� ������
	//mat4_sum = mat4_Translate * 2; //3���� ��� ����
	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		std::cout << mat4_sum.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//mat4_Translate.Identitymatrix(); //3���� �׵� ���
	//for (int i = 0; i < 4; i++) { //�׵� ��� ���
	//	for (int j = 0; j < 4; j++) {
	//		std::cout << mat4_Translate.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	/*mat4_Translate.Transpose(); //3���� ��ġ ���
	for (int i = 0; i < 4; i++) { //��ġ ��� ���
		for (int j = 0; j < 4; j++) {
			std::cout << mat4_Translate.mat[i][j];
			std::cout << " ";
		}
		std::cout << std::endl;
	}*/

	//p = v * Translate; //���� ����
	//p = v + a; //���� ����
	//p = v - a; //���� ����
	//p = a / 2; //���� ��� ������ ���� ���
	//p = a * 2; //���� ��� ���� ���� ���
	//for (int i = 0; i < 3; i++) { //���� ���� ���
	//	std::cout << p.vec[i];
	//	std::cout << " ";
	//}

	//vec4_p = vec4_v * mat4_Translate; //����4 ����
	//vec4_p = vec4_v + vec4_t; //���� ����
	//vec4_p = vec4_v - vec4_t; //���� ����
	//vec4_p = vec4_t / 2; //��� ������
	//vec4_p = vec4_t * 2; //��� ����
	//for (int i = 0; i < 4; i++) { //���� ���� ���
	//	std::cout << vec4_p.vec[i];
	//	std::cout << " ";
	//}

	//vec1x3_p.Transpose(vec1x3_p);
	//vec1x3_v.Transpose(vec1x3_v);
	//vec1x3_p = vec1x3_v * Translate; //����
	//vec1x3_p = vec1x3_v + vec1x3_t; //����
	//vec1x3_p = vec1x3_v - vec1x3_t; //����
	//vec1x3_p = vec1x3_t / 2; //��� ������
	//vec1x3_p = vec1x3_t * 2; //��� ����
	//for (int i = 0; i < 3; i++) {
	//	std::cout << vec1x3_p.vec[0][i];
	//	std::cout << " ";
	//}
	
	//vec1x4_p.Transpose(vec1x4_p);
	//vec1x4_v.Transpose(vec1x4_v);
	//vec1x4_p = vec1x4_v * mat4_Translate; //����
	//vec1x4_p = vec1x4_v + vec1x4_t; //����
	//vec1x4_p = vec1x4_v - vec1x4_t; //����
	//vec1x4_p = vec1x4_t / 2; //��� ������
	//vec1x4_p = vec1x4_t * 2; //��� ����
	//for (int i = 0; i < 4; i++) {
	//	std::cout << vec1x4_p.vec[0][i];
	//	std::cout << " ";
	//}
}