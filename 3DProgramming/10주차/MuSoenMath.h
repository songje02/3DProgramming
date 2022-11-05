#pragma once
#include <iostream> //입출력 관련 함수 
#include <math.h> //수학 관련 헤더파일

#define PI 3.14159 //PI 근사값으로 소수점 5자리까지  

//mat3클래스
class mat3 {
public: //외부 접근 가능함
	float mat[3][3]; //float형 3x3행렬 변수
	mat3(float m[3][3]); //생성자
	mat3 operator*(mat3& ref); //mat 오버로딩 함수
};

mat3::mat3(float m[3][3]) { //생성자, Matrix.cpp에서 클래스 생성할 때 float형 3x3행렬을 받아옴
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->mat[i][j] = m[i][j]; //class mat3에 있는 변수 mat에 받아온 행렬을 넣어줌
		}
	}
}

mat3 mat3::operator*(mat3& ref) { //3x3행렬 곱셈 오버로딩 함수

	mat3 result(new float[3][3]{ {1, 0, 0}, {0, 1, 0}, {0, 0, 1} }); //계산된 값을 저장해줄 곳

	for (int i = 0; i < 3; i++) { //for문을 통해 값을 곱하고 계산해줌
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				result.mat[i][j] += (mat[k][j] * ref.mat[i][k]);
		}
	}
	return result; //연산이 끝난 값을 반환해줌
}

//vec3 클래스
class vec3
{
public:
	float vec[3]; //float형 1차원 배열 
	vec3(float v[3]); //생성자
	vec3 operator*(const mat3& ref); //vec의 오버로딩 함수
};

vec3::vec3(float v[3]) { //생성자, Matrix.cpp에서 클래스 생성할 때 float형 1차원 배열을 받아옴
	for (int i = 0; i < 3; i++) { //받아온 배열을 vec3에 있는 vec변수에 넣어줌
		this->vec[i] = v[i];
	}
}

vec3 vec3::operator*(const mat3& ref) //3x1와 3x3행렬 곱셈 오버로딩 함수
{
	vec3 result(new float[3]{ 0, 0, 0 }); //새로운 배열 생성, 계산된 값을 넣어줄 곳

	for (int i = 0; i < 3; i++) { //vec3은 3x1와 3x3행렬을 곱해 값을 저장해줌
		for (int j = 0; j < 3; j++) {
			result.vec[i] += (vec[j] * ref.mat[j][i]);
		}
	}
	return result; //연산이 끝난 값을 반환해줌
}