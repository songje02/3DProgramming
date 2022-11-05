#pragma once
#include <iostream> //����� ���� �Լ� 
#include <math.h> //���� ���� �������

#define PI 3.14159 //PI �ٻ簪���� �Ҽ��� 5�ڸ�����  

//mat3Ŭ����
class mat3 {
public: //�ܺ� ���� ������
	float mat[3][3]; //float�� 3x3��� ����
	mat3(float m[3][3]); //������
	mat3 operator*(mat3& ref); //mat �����ε� �Լ�
};

mat3::mat3(float m[3][3]) { //������, Matrix.cpp���� Ŭ���� ������ �� float�� 3x3����� �޾ƿ�
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->mat[i][j] = m[i][j]; //class mat3�� �ִ� ���� mat�� �޾ƿ� ����� �־���
		}
	}
}

mat3 mat3::operator*(mat3& ref) { //3x3��� ���� �����ε� �Լ�

	mat3 result(new float[3][3]{ {1, 0, 0}, {0, 1, 0}, {0, 0, 1} }); //���� ���� �������� ��

	for (int i = 0; i < 3; i++) { //for���� ���� ���� ���ϰ� �������
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				result.mat[i][j] += (mat[k][j] * ref.mat[i][k]);
		}
	}
	return result; //������ ���� ���� ��ȯ����
}

//vec3 Ŭ����
class vec3
{
public:
	float vec[3]; //float�� 1���� �迭 
	vec3(float v[3]); //������
	vec3 operator*(const mat3& ref); //vec�� �����ε� �Լ�
};

vec3::vec3(float v[3]) { //������, Matrix.cpp���� Ŭ���� ������ �� float�� 1���� �迭�� �޾ƿ�
	for (int i = 0; i < 3; i++) { //�޾ƿ� �迭�� vec3�� �ִ� vec������ �־���
		this->vec[i] = v[i];
	}
}

vec3 vec3::operator*(const mat3& ref) //3x1�� 3x3��� ���� �����ε� �Լ�
{
	vec3 result(new float[3]{ 0, 0, 0 }); //���ο� �迭 ����, ���� ���� �־��� ��

	for (int i = 0; i < 3; i++) { //vec3�� 3x1�� 3x3����� ���� ���� ��������
		for (int j = 0; j < 3; j++) {
			result.vec[i] += (vec[j] * ref.mat[j][i]);
		}
	}
	return result; //������ ���� ���� ��ȯ����
}