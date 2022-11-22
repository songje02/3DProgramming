#pragma once
#include <iostream> //����� ���� �Լ� 
#include <math.h> //���� ���� �������

#define PI 3.14159 //PI �ٻ簪���� �Ҽ��� 5�ڸ�����  

//mat3Ŭ����
class mat3 {
public:
	mat3() {};
	float mat[3][3]{ //float�� 3x3��� ���� 
		{0,0,0},
		{0,0,0},
		{0,0,0} };
	mat3(float m[3][3]); //������ 
	mat3 operator*(mat3& ref); //���� �����ε� �Լ�
	mat3 operator+(mat3& ref); //���� �����ε� �Լ�
	mat3 operator-(mat3& ref); //���� �����ε� �Լ�
	mat3 operator/(float ref); //��� ������ �����ε� �Լ� 
	mat3 operator*(float ref); //��� ���� �����ε� �Լ�

	void Identitymatrix() { //���� ��� �Լ�
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) mat[i][j] = 1;
				else mat[i][j] = 0;
			}
		}
	}
	mat3 Transpose() { //��ġ ��� �Լ�
		float tranpose;
		for (int i = 0; i < 3; i++)
			for (int j = i; j < 3; j++) {
				tranpose = mat[i][j];
				this->mat[i][j] = this->mat[j][i];
				this->mat[j][i] = tranpose;
			}
		return *this; //��ġ �� ����
	}
};
mat3::mat3(float m[3][3]) { //������ 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->mat[i][j] = m[i][j]; //�Ű������� �޾ƿ� ��� ���� ���������� ����
		}
	}
}
mat3 mat3::operator*(mat3& ref) { //2���� ��İ� ���� �����ε� �Լ�
	float mulresult[3][3]{ //���� ���� �������� ��
		{0,0,0},
		{0,0,0},
		{0,0,0} };
	for (int i = 0; i < 3; i++) { //��� �����ϴ� �κ�
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				mulresult[i][j] += (mat[i][k] * ref.mat[k][j]);
		}
	}
	return mulresult; //���� �� ����
}
mat3 mat3::operator+(mat3& ref) { //2���� ��İ� ���� �����ε� �Լ�
	float addresult[3][3]{ //���� ���� �������� ��
		{0,0,0},
		{0,0,0},
		{0,0,0} };
	for (int i = 0; i < 3; i++) { //��� �����ϴ� �κ�
		for (int j = 0; j < 3; j++) {
			addresult[i][j] = (mat[i][j] + ref.mat[i][j]);
		}
	}
	return addresult; //���� �� ����
}
mat3 mat3::operator-(mat3& ref) { //2���� ��İ� ���� �����ε� �Լ�
	float subresult[3][3]{ //���� ���� �������� ��
		{0,0,0},
		{0,0,0},
		{0,0,0} };
	for (int i = 0; i < 3; i++) { //��� �����ϴ� �κ�
		for (int j = 0; j < 3; j++) {
			subresult[i][j] = mat[i][j] - ref.mat[i][j];
		}
	}
	return subresult; //���� �� ����
}
mat3 mat3::operator/(float ref) { //2���� ��� ��� ������ �����ε� �Լ� 
	float divresult[3][3]{ //���� ���� �������� ��
		{0,0,0},
		{0,0,0},
		{0,0,0} };
	for (int i = 0; i < 3; i++) { //��� �������ϴ� �κ�
		for (int j = 0; j < 3; j++) {
			divresult[i][j] = mat[i][j] / ref;
		}
	}
	return divresult; //������ �� ����
}
mat3 mat3::operator*(float ref) { //2���� ��� ��� ���� �����ε� �Լ�
	float mulresult[3][3]{ //���� ���� �������� ��
		{0,0,0},
		{0,0,0},
		{0,0,0} };
	for (int i = 0; i < 3; i++) { //��� �����ϴ� �κ�
		for (int j = 0; j < 3; j++) {
			mulresult[i][j] = mat[i][j] * ref;
		}
	}
	return mulresult; //���� �� ����
}

//mat4Ŭ����
class mat4
{
public:
	mat4() {};
	float mat[4][4]{ //4x4��� ����
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}};
	mat4(float m[4][4]); //������
	mat4 operator*(mat4& ref); //���� �����ε� �Լ�
	mat4 operator+(mat4& ref); //���� �����ε� �Լ�
	mat4 operator-(mat4& ref); //���� �����ε� �Լ�
	mat4 operator/(float ref); //��� ������ �����ε� �Լ�
	mat4 operator*(float ref); //��� ���� �����ε� �Լ�

	void Identitymatrix() { //���� ��� �Լ�
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == j) mat[i][j] = 1;
				else mat[i][j] = 0;
			}
		}
	}
	mat4 Transpose() { //��ġ ��� �Լ�
		float tranpose;
		for (int i = 0; i < 4; i++)
			for (int j = i; j < 4; j++) {
				tranpose = mat[i][j];
				this->mat[i][j] = this->mat[j][i];
				this->mat[j][i] = tranpose;
			}
		return *this; //��ġ �� ����
	}
};
mat4::mat4(float m[4][4]) //������
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->mat[i][j] = m[i][j]; //�Ű������� �޾ƿ� ��� ���� ���������� ����
		}
	}
}
mat4 mat4::operator*(mat4& ref) { //3���� ��İ� ���� �����ε� �Լ�
	float mulresult[4][4]{ //���� ���� �������� ��
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0} };
	for (int i = 0; i < 4; i++) { //��� �����ϴ� �κ�
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++)
				mulresult[i][j] += mat[i][k] * ref.mat[k][j];
		}
	}
	return mulresult; //���� �� ����
}
mat4 mat4::operator+(mat4& ref) { //3���� ��İ� ���� �����ε� �Լ�
	float addresult[4][4]{ //���� ���� �������� ��
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0} };
	for (int i = 0; i < 4; i++) { //��� �����ϴ� �κ�
		for (int j = 0; j < 4; j++) {
			addresult[i][j] = (mat[i][j] + ref.mat[i][j]);
		}
	}
	return addresult; //���� �� ����
}
mat4 mat4::operator-(mat4& ref) { //3���� ��İ� ���� �����ε� �Լ�
	float subresult[4][4]{ //���� ���� �������� ��
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0} };
	for (int i = 0; i < 4; i++) { //��� �����ϴ� �κ�
		for (int j = 0; j < 4; j++) {
			subresult[i][j] = (mat[i][j] - ref.mat[i][j]);
		}
	}
	return subresult; //���� �� ����
}
mat4 mat4::operator/(float ref) { //3���� ��� ��� ������ �����ε� �Լ� 
	float divresult[4][4]{ //���� ���� �������� ��
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0} };
	for (int i = 0; i < 4; i++) { //��� �������ϴ� �κ�
		for (int j = 0; j < 4; j++) {
			divresult[i][j] = mat[i][j] / ref;
		}
	}
	return divresult; //������ �� ����
}
mat4 mat4::operator*(float ref) { //��� �����ε� ����
	float mulresult[4][4]{ //���� ���� �������� ��
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0} };
	for (int i = 0; i < 4; i++) { //��� �����ϴ� �κ�
		for (int j = 0; j < 4; j++) {
			mulresult[i][j] = mat[i][j] * ref;
		}
	}
	return mulresult; //���� �� ����
}

//vec3 Ŭ����
class vec3
{
public:
	vec3() {};
	float vec[3]{ //float�� 2���� �迭 
		{0} };
	vec3(float v[3]); //������
	vec3 operator*(mat3& ref); //���� �����ε� �Լ�
	vec3 operator+(vec3& ref); //���� �����ε� �Լ�
	vec3 operator-(vec3& ref); //���� �����ε� �Լ�
	vec3 operator*(vec3& ref); //���ͳ��� ����
	vec3 operator/(float ref); //��� �����ε� ������
	vec3 operator*(float ref); //��� �����ε� ����
	friend vec3 operator*(mat3& ref, const vec3 ref2); //mat * vec ���ϱ�

	vec3 Transpose() { //��ġ ���
		float transpose[1][3];
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < 3; j++) {
				transpose[i][j] = this->vec[j];
			}
		}
		return *transpose;
	}
};
vec3::vec3(float v[3]) { //������
	for (int i = 0; i < 3; i++) { //�Ű������� �޾ƿ� ��� ���� ���������� ����
		this->vec[i] = v[i];
	}
}
vec3 vec3::operator*(mat3& ref) //���� ���� �����ε� �Լ�
{
	float mulresult[3]{ //���� ���� �������� ��
		0,0,0 };
	for (int i = 0; i < 3; i++) {  //��� �����ϴ� �κ�
		for (int j = 0; j < 3; j++) {
			mulresult[i] += (vec[j] * ref.mat[j][i]);
		}
	}
	return mulresult; //���� �� ����
}
vec3 vec3::operator+(vec3& ref) //���Ͱ� ���� �����ε� �Լ�
{
	float addresult[3]{ //���� ���� �������� ��
		0,0,0 };
	for (int i = 0; i < 3; i++) { //��� �����ϴ� �κ�
		addresult[i] = (vec[i] + ref.vec[i]);
	}
	return addresult; //���� �� ����
}
vec3 vec3::operator-(vec3& ref) //���Ͱ� ���� �����ε� �Լ�
{
	float subresult[3]{ //���� ���� �������� ��
		0,0,0 };
	for (int i = 0; i < 3; i++) { //��� �����ϴ� �κ�
		subresult[i] = (vec[i] - ref.vec[i]);
	}
	return subresult; //���� �� ����
}
vec3 vec3::operator*(vec3& ref) { //����x���� ����
	float mulresult[3]{ //���� ���� �������� ��
		0,0,0 };
	mulresult[0] = vec[1] * ref.vec[2] - vec[2] * ref.vec[1];
	mulresult[1] = vec[2] * ref.vec[0] - vec[0] * ref.vec[2];
	mulresult[2] = vec[0] * ref.vec[1] - vec[1] * ref.vec[0];

	return mulresult; //���� �� ����
}
vec3 vec3::operator/(float ref) { //��� ������ �����ε� �Լ�
	float divresult[3]{ //���� ���� �������� ��
		0,0,0 };
	for (int i = 0; i < 3; i++) { //��� �������ϴ� �κ�
		divresult[i] = vec[i] / ref;
	}
	return divresult; //������ �� ����
}
vec3  vec3::operator*(float ref) { //��� ���� �����ε� �Լ�
	float mulresult[3]{ //���� ���� �������� ��
		0,0,0 };
	for (int i = 0; i < 3; i++) { //��� �������ϴ� �κ�
		mulresult[i] = vec[i] * ref;
	}
	return mulresult; //���� �� ����
}

vec3 operator*(mat3& ref, const vec3 ref2) //mat * vec ���ϱ�
{
	float mulresult[3]{ //���� ���� �������� ��
		0,0,0 };
	for (int i = 0; i < 3; i++) { //��� �����ϴ� �κ�
		for (int j = 0; j < 3; j++)
			mulresult[i] += ref.mat[i][j] * ref2.vec[j];
	}
	return mulresult; //���� ��
}

//vec4 Ŭ����
class vec4
{
public:
	float vec[4]{ //float�� 3���� �迭 
		{0} };
	vec4(float v[4]); //������
	vec4 operator*(mat4& ref); //���� �����ε� �Լ�
	vec4 operator+(vec4& ref); //���� �����ε� �Լ�
	vec4 operator-(vec4& ref); //���� �����ε� �Լ�
	vec4 operator/(float ref); //��� �����ε� ������
	vec4 operator*(float ref); //��� �����ε� ����

	vec4 Transpose() {
		float transpose[1][4];
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < 4; j++) {
				transpose[i][j] = this->vec[j];
				//std::cout << transpose[i][j];
			}
		}
		return *transpose;
	}
};
vec4::vec4(float v[4]) { //������
	for (int i = 0; i < 4; i++) { //�Ű������� �޾ƿ� ��� ���� ���������� ����
		this->vec[i] = v[i];
	}
}
vec4 vec4::operator*(mat4& ref) //���� ���� �����ε� �Լ�
{
	float mulresult[4]{ //���� ���� �������� ��
		0,0,0,0 };
	for (int i = 0; i < 4; i++) { //��� �����ϴ� �κ�
		for (int j = 0; j < 4; j++) {
			mulresult[i] += (vec[j] * ref.mat[j][i]);
		}
	}
	return mulresult; //���� �� ����
}
vec4 vec4::operator+(vec4& ref) //���Ͱ� ���� �����ε� �Լ�
{
	float addresult[4]{ //���� ���� �������� ��
		0,0,0,0 };
	for (int i = 0; i < 4; i++) { //��� �����ϴ� �κ�
		addresult[i] = (vec[i] + ref.vec[i]);
	}
	return addresult; //���� �� ����
}
vec4 vec4::operator-(vec4& ref) //���Ͱ� ���� �����ε� �Լ�
{
	float subresult[4]{ //���� ���� �������� ��
		0,0,0,0 };
	for (int i = 0; i < 4; i++) { //��� �����ϴ� �κ�
		subresult[i] = (vec[i] - ref.vec[i]);
	}
	return subresult; //���� �� ����
}
vec4 vec4::operator/(float ref) //��� ������ �����ε� �Լ�
{
	float divresult[4]{ //���� ���� �������� ��
		0,0,0,0 };
	for (int i = 0; i < 4; i++) { //��� �������ϴ� �κ�
		divresult[i] = vec[i] / ref;
	}
	return divresult; //������ �� ����
}
vec4 vec4::operator*(float ref) //��� ���� �����ε� �Լ�
{
	float mulresult[4]{ //���� ���� �������� ��
		0,0,0,0 };
	for (int i = 0; i < 4; i++) { //��� �������ϴ� �κ�
		mulresult[i] = vec[i] * ref;
	}
	return mulresult; //���� �� ����
}

//vec1x3 Ŭ����
//class vec1x3 {
//public:
//	float vec[1][3];  //float�� 1���� �迭 
//	vec1x3(float v[1][3]); //������
//	vec1x3 operator*(mat3& ref); //���� �����ε� �Լ�
//	vec1x3 operator+(vec1x3& ref); //���� �����ε� �Լ�
//	vec1x3 operator-(vec1x3& ref); //���� �����ε� �Լ�
//	vec1x3 operator/(float ref); //��� �����ε� ������
//	vec1x3 operator*(float ref); //��� �����ε� ����
//
//	vec1x3 Transpose(vec1x3 v) { //��ġ ���
//		vec1x3 transpose(new float[1][3]);
//		for (int j = 0; j < 3; j++) {
//			transpose.vec[0][j] = v.vec[0][j];
//			//std::cout << transpose[i][j];
//		}
//		return transpose;
//	}
//};
//vec1x3::vec1x3(float v[1][3]) { //������
//	for (int i = 0; i < 3; i++) { //�Ű������� �޾ƿ� ��� ���� ���������� ����
//		this->vec[0][i] = v[0][i];
//	}
//}
//vec1x3 vec1x3::operator*(mat3& ref) //���� ���� �����ε� �Լ�
//{
//	vec1x3 mulresult(new float[1][3]{ 0, 0, 0 }); //���� ���� �������� ��
//	for (int i = 0; i < 3; i++) { //��� �����ϴ� �κ�
//		for (int j = 0; j < 3; j++) {
//			mulresult.vec[0][i] += (vec[0][j] * ref.mat[j][i]);
//		}
//	}
//	return mulresult; //���� �� ����
//}
//vec1x3 vec1x3::operator+(vec1x3& ref) { //���Ͱ� ���� �����ε� �Լ�
//	vec1x3 addresult(new float[1][3]); //���� ���� �������� ��
//	for (int i = 0; i < 3; i++) { //��� �����ϴ� �κ�
//		addresult.vec[0][i] = (vec[0][i] + ref.vec[0][i]);
//	}
//	return addresult; //���� �� ����
//}
//vec1x3 vec1x3::operator-(vec1x3& ref) { //���Ͱ� ���� �����ε� �Լ�
//	vec1x3 addresult(new float[1][3]); //���� ���� �������� ��
//	for (int i = 0; i < 3; i++) { //��� �����ϴ� �κ�
//		addresult.vec[0][i] = (vec[0][i] - ref.vec[0][i]);
//	}
//	return addresult; //���� �� ����
//}
//vec1x3 vec1x3::operator/(float ref) { //��� ������ �����ε� �Լ�
//	vec1x3 value(new float[1][3]); //���� ���� �������� ��
//	for (int i = 0; i < 3; i++) { //��� �������ϴ� �κ�
//		value.vec[0][i] = vec[0][i] / ref;
//	}
//	return value; //������ �� ����
//}
//vec1x3 vec1x3::operator*(float ref) { //��� ���� �����ε� �Լ�
//	vec1x3 mulresult(new float[1][3]); //���� ���� �������� ��
//	for (int i = 0; i < 3; i++) { //��� �������ϴ� �κ�
//		mulresult.vec[0][i] = vec[0][i] * ref;
//	}
//	return mulresult; //���� �� ����
//}

//vec1x4 Ŭ����
//class vec1x4 {
//public:
//	float vec[1][4]; //float�� 1���� �迭 
//	vec1x4(float v[1][4]); //������
//	vec1x4 operator*(mat4& ref); //���� �����ε� �Լ�
//	vec1x4 operator+(vec1x4& ref); //���� �����ε� �Լ�
//	vec1x4 operator-(vec1x4& ref); //���� �����ε� �Լ�
//	vec1x4 operator/(float ref); //��� �����ε� ������
//	vec1x4 operator*(float ref); //��� �����ε� ����
//
//	vec1x4 Transpose(vec1x4 v) {
//		vec1x4 transpose(new float[1][4]);
//		for (int j = 0; j < 4; j++) {
//			transpose.vec[0][j] = v.vec[0][j];
//			//std::cout << transpose[i][j];
//		}
//		return transpose;
//	}
//};
//vec1x4::vec1x4(float v[1][4]) { //������
//	for (int i = 0; i < 4; i++) { //�Ű������� �޾ƿ� ��� ���� ���������� ����
//		this->vec[0][i] = v[0][i];
//	}
//}
//vec1x4 vec1x4::operator*(mat4& ref) //���� ���� �����ε� �Լ�
//{
//	vec1x4 mulresult(new float[1][4]{ 0, 0, 0, 0 }); //���� ���� �������� ��
//	for (int i = 0; i < 4; i++) { //��� �����ϴ� �κ�
//		for (int j = 0; j < 4; j++) {
//			mulresult.vec[0][i] += (vec[0][j] * ref.mat[j][i]);
//		}
//	}
//	return mulresult; //���� �� ����
//}
//vec1x4 vec1x4::operator+(vec1x4& ref) { //���Ͱ� ���� �����ε� �Լ�
//	vec1x4 addresult(new float[1][4]); //���� ���� �������� ��
//	for (int i = 0; i < 4; i++) { //��� �����ϴ� �κ�
//		addresult.vec[0][i] = (vec[0][i] + ref.vec[0][i]);
//	}
//	return addresult; //���� �� ����
//}
//vec1x4 vec1x4::operator-(vec1x4& ref) { //���Ͱ� ���� �����ε� �Լ�
//	vec1x4 addresult(new float[1][4]); //���� ���� �������� ��
//	for (int i = 0; i < 4; i++) { //��� �����ϴ� �κ�
//		addresult.vec[0][i] = (vec[0][i] - ref.vec[0][i]);
//	}
//	return addresult; //���� �� ����
//}
//vec1x4 vec1x4::operator/(float ref) { //��� ������ �����ε� �Լ�
//	vec1x4 divresult(new float[1][4]); //���� ���� �������� ��
//	for (int i = 0; i < 4; i++) { //��� �������ϴ� �κ�
//		divresult.vec[0][i] = vec[0][i] / ref;
//	}
//	return divresult;  //������ �� ����
//}
//vec1x4 vec1x4::operator*(float ref) { //��� ���� �����ε� �Լ�
//	vec1x4 mulresult(new float[1][4]); //���� ���� �������� ��
//	for (int i = 0; i < 4; i++) { //��� �������ϴ� �κ�
//		mulresult.vec[0][i] = vec[0][i] * ref;
//	}
//	return mulresult; //���� �� ����
//}