#pragma once
#include <iostream> //입출력 관련 함수 
#include <math.h> //수학 관련 헤더파일

#define PI 3.14159 //PI 근사값으로 소수점 5자리까지  

//mat3클래스
class mat3 {
public:
	mat3() {};
	float mat[3][3]{ //float형 3x3행렬 변수 
		{0,0,0},
		{0,0,0},
		{0,0,0} };
	mat3(float m[3][3]); //생성자 
	mat3 operator*(mat3& ref); //곱셈 오버로딩 함수
	mat3 operator+(mat3& ref); //덧셈 오버로딩 함수
	mat3 operator-(mat3& ref); //뺄셈 오버로딩 함수
	mat3 operator/(float ref); //상수 나눗셈 오버로딩 함수 
	mat3 operator*(float ref); //상수 곱셈 오버로딩 함수

	void Identitymatrix() { //단위 행렬 함수
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) mat[i][j] = 1;
				else mat[i][j] = 0;
			}
		}
	}
	mat3 Transpose() { //전치 행렬 함수
		float tranpose;
		for (int i = 0; i < 3; i++)
			for (int j = i; j < 3; j++) {
				tranpose = mat[i][j];
				this->mat[i][j] = this->mat[j][i];
				this->mat[j][i] = tranpose;
			}
		return *this; //전치 값 리턴
	}
};
mat3::mat3(float m[3][3]) { //생성자 
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->mat[i][j] = m[i][j]; //매개변수로 받아온 행렬 값을 지역변수에 저장
		}
	}
}
mat3 mat3::operator*(mat3& ref) { //2차원 행렬간 곱셈 오버로딩 함수
	float mulresult[3][3]{ //계산된 값을 저장해줄 곳
		{0,0,0},
		{0,0,0},
		{0,0,0} };
	for (int i = 0; i < 3; i++) { //행렬 곱셈하는 부분
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				mulresult[i][j] += (mat[i][k] * ref.mat[k][j]);
		}
	}
	return mulresult; //곱한 값 리턴
}
mat3 mat3::operator+(mat3& ref) { //2차원 행렬간 덧셈 오버로딩 함수
	float addresult[3][3]{ //계산된 값을 저장해줄 곳
		{0,0,0},
		{0,0,0},
		{0,0,0} };
	for (int i = 0; i < 3; i++) { //행렬 덧셈하는 부분
		for (int j = 0; j < 3; j++) {
			addresult[i][j] = (mat[i][j] + ref.mat[i][j]);
		}
	}
	return addresult; //덧셈 값 리턴
}
mat3 mat3::operator-(mat3& ref) { //2차원 행렬간 뺄셈 오버로딩 함수
	float subresult[3][3]{ //계산된 값을 저장해줄 곳
		{0,0,0},
		{0,0,0},
		{0,0,0} };
	for (int i = 0; i < 3; i++) { //행렬 뺄셈하는 부분
		for (int j = 0; j < 3; j++) {
			subresult[i][j] = mat[i][j] - ref.mat[i][j];
		}
	}
	return subresult; //뺄셈 값 리턴
}
mat3 mat3::operator/(float ref) { //2차원 행렬 상수 나눗셈 오버로딩 함수 
	float divresult[3][3]{ //계산된 값을 저장해줄 곳
		{0,0,0},
		{0,0,0},
		{0,0,0} };
	for (int i = 0; i < 3; i++) { //행렬 나눗셈하는 부분
		for (int j = 0; j < 3; j++) {
			divresult[i][j] = mat[i][j] / ref;
		}
	}
	return divresult; //나눗셈 값 리턴
}
mat3 mat3::operator*(float ref) { //2차원 행렬 상수 곱셈 오버로딩 함수
	float mulresult[3][3]{ //계산된 값을 저장해줄 곳
		{0,0,0},
		{0,0,0},
		{0,0,0} };
	for (int i = 0; i < 3; i++) { //행렬 곱셈하는 부분
		for (int j = 0; j < 3; j++) {
			mulresult[i][j] = mat[i][j] * ref;
		}
	}
	return mulresult; //곱셈 값 리턴
}

//mat4클래스
class mat4
{
public:
	mat4() {};
	float mat[4][4]{ //4x4행렬 변수
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}};
	mat4(float m[4][4]); //생성자
	mat4 operator*(mat4& ref); //곱셈 오버로딩 함수
	mat4 operator+(mat4& ref); //덧셈 오버로딩 함수
	mat4 operator-(mat4& ref); //뺄셈 오버로딩 함수
	mat4 operator/(float ref); //상수 나눗셈 오버로딩 함수
	mat4 operator*(float ref); //상수 곱셈 오버로딩 함수

	void Identitymatrix() { //단위 행렬 함수
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == j) mat[i][j] = 1;
				else mat[i][j] = 0;
			}
		}
	}
	mat4 Transpose() { //전치 행렬 함수
		float tranpose;
		for (int i = 0; i < 4; i++)
			for (int j = i; j < 4; j++) {
				tranpose = mat[i][j];
				this->mat[i][j] = this->mat[j][i];
				this->mat[j][i] = tranpose;
			}
		return *this; //전치 값 리턴
	}
};
mat4::mat4(float m[4][4]) //생성자
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->mat[i][j] = m[i][j]; //매개변수로 받아온 행렬 값을 지역변수에 저장
		}
	}
}
mat4 mat4::operator*(mat4& ref) { //3차원 행렬간 곱셈 오버로딩 함수
	float mulresult[4][4]{ //계산된 값을 저장해줄 곳
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0} };
	for (int i = 0; i < 4; i++) { //행렬 곱셈하는 부분
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++)
				mulresult[i][j] += mat[i][k] * ref.mat[k][j];
		}
	}
	return mulresult; //곱한 값 리턴
}
mat4 mat4::operator+(mat4& ref) { //3차원 행렬간 덧셈 오버로딩 함수
	float addresult[4][4]{ //계산된 값을 저장해줄 곳
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0} };
	for (int i = 0; i < 4; i++) { //행렬 덧셈하는 부분
		for (int j = 0; j < 4; j++) {
			addresult[i][j] = (mat[i][j] + ref.mat[i][j]);
		}
	}
	return addresult; //덧셈 값 리턴
}
mat4 mat4::operator-(mat4& ref) { //3차원 행렬간 뺄셈 오버로딩 함수
	float subresult[4][4]{ //계산된 값을 저장해줄 곳
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0} };
	for (int i = 0; i < 4; i++) { //행렬 뺄셈하는 부분
		for (int j = 0; j < 4; j++) {
			subresult[i][j] = (mat[i][j] - ref.mat[i][j]);
		}
	}
	return subresult; //뺄셈 값 리턴
}
mat4 mat4::operator/(float ref) { //3차원 행렬 상수 나눗셈 오버로딩 함수 
	float divresult[4][4]{ //계산된 값을 저장해줄 곳
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0} };
	for (int i = 0; i < 4; i++) { //행렬 나눗셈하는 부분
		for (int j = 0; j < 4; j++) {
			divresult[i][j] = mat[i][j] / ref;
		}
	}
	return divresult; //나눗셈 값 리턴
}
mat4 mat4::operator*(float ref) { //상수 오버로딩 곱셈
	float mulresult[4][4]{ //계산된 값을 저장해줄 곳
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0} };
	for (int i = 0; i < 4; i++) { //행렬 곱셈하는 부분
		for (int j = 0; j < 4; j++) {
			mulresult[i][j] = mat[i][j] * ref;
		}
	}
	return mulresult; //곱셈 값 리턴
}

//vec3 클래스
class vec3
{
public:
	vec3() {};
	float vec[3]{ //float형 2차원 배열 
		{0} };
	vec3(float v[3]); //생성자
	vec3 operator*(mat3& ref); //곱셈 오버로딩 함수
	vec3 operator+(vec3& ref); //덧셈 오버로딩 함수
	vec3 operator-(vec3& ref); //뺄셈 오버로딩 함수
	vec3 operator*(vec3& ref); //벡터끼리 곱셈
	vec3 operator/(float ref); //상수 오버로딩 나눗셈
	vec3 operator*(float ref); //상수 오버로딩 곱셈
	friend vec3 operator*(mat3& ref, const vec3 ref2); //mat * vec 곱하기

	vec3 Transpose() { //전치 행렬
		float transpose[1][3];
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < 3; j++) {
				transpose[i][j] = this->vec[j];
			}
		}
		return *transpose;
	}
};
vec3::vec3(float v[3]) { //생성자
	for (int i = 0; i < 3; i++) { //매개변수로 받아온 행렬 값을 지역변수에 저장
		this->vec[i] = v[i];
	}
}
vec3 vec3::operator*(mat3& ref) //벡터 곱셈 오버로딩 함수
{
	float mulresult[3]{ //계산된 값을 저장해줄 곳
		0,0,0 };
	for (int i = 0; i < 3; i++) {  //행렬 곱셈하는 부분
		for (int j = 0; j < 3; j++) {
			mulresult[i] += (vec[j] * ref.mat[j][i]);
		}
	}
	return mulresult; //곱한 값 리턴
}
vec3 vec3::operator+(vec3& ref) //백터간 덧셈 오버로딩 함수
{
	float addresult[3]{ //계산된 값을 저장해줄 곳
		0,0,0 };
	for (int i = 0; i < 3; i++) { //행렬 덧셈하는 부분
		addresult[i] = (vec[i] + ref.vec[i]);
	}
	return addresult; //덧셈 값 리턴
}
vec3 vec3::operator-(vec3& ref) //벡터간 뺄셈 오버로딩 함수
{
	float subresult[3]{ //계산된 값을 저장해줄 곳
		0,0,0 };
	for (int i = 0; i < 3; i++) { //행렬 뺄셈하는 부분
		subresult[i] = (vec[i] - ref.vec[i]);
	}
	return subresult; //뺄셈 값 리턴
}
vec3 vec3::operator*(vec3& ref) { //벡터x벡터 곱셈
	float mulresult[3]{ //계산된 값을 저장해줄 곳
		0,0,0 };
	mulresult[0] = vec[1] * ref.vec[2] - vec[2] * ref.vec[1];
	mulresult[1] = vec[2] * ref.vec[0] - vec[0] * ref.vec[2];
	mulresult[2] = vec[0] * ref.vec[1] - vec[1] * ref.vec[0];

	return mulresult; //곱한 값 리턴
}
vec3 vec3::operator/(float ref) { //상수 나눗셈 오버로딩 함수
	float divresult[3]{ //계산된 값을 저장해줄 곳
		0,0,0 };
	for (int i = 0; i < 3; i++) { //행렬 나눗셈하는 부분
		divresult[i] = vec[i] / ref;
	}
	return divresult; //나눗셈 값 리턴
}
vec3  vec3::operator*(float ref) { //상수 곱셈 오버로딩 함수
	float mulresult[3]{ //계산된 값을 저장해줄 곳
		0,0,0 };
	for (int i = 0; i < 3; i++) { //행렬 나눗셈하는 부분
		mulresult[i] = vec[i] * ref;
	}
	return mulresult; //곱셈 값 리턴
}

vec3 operator*(mat3& ref, const vec3 ref2) //mat * vec 곱하기
{
	float mulresult[3]{ //계산된 값을 저장해줄 곳
		0,0,0 };
	for (int i = 0; i < 3; i++) { //행렬 곱셈하는 부분
		for (int j = 0; j < 3; j++)
			mulresult[i] += ref.mat[i][j] * ref2.vec[j];
	}
	return mulresult; //곱한 값
}

//vec4 클래스
class vec4
{
public:
	float vec[4]{ //float형 3차원 배열 
		{0} };
	vec4(float v[4]); //생성자
	vec4 operator*(mat4& ref); //곱셈 오버로딩 함수
	vec4 operator+(vec4& ref); //덧셈 오버로딩 함수
	vec4 operator-(vec4& ref); //뺄셈 오버로딩 함수
	vec4 operator/(float ref); //상수 오버로딩 나눗셈
	vec4 operator*(float ref); //상수 오버로딩 곱셈

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
vec4::vec4(float v[4]) { //생성자
	for (int i = 0; i < 4; i++) { //매개변수로 받아온 행렬 값을 지역변수에 저장
		this->vec[i] = v[i];
	}
}
vec4 vec4::operator*(mat4& ref) //벡터 곱셈 오버로딩 함수
{
	float mulresult[4]{ //계산된 값을 저장해줄 곳
		0,0,0,0 };
	for (int i = 0; i < 4; i++) { //행렬 곱셈하는 부분
		for (int j = 0; j < 4; j++) {
			mulresult[i] += (vec[j] * ref.mat[j][i]);
		}
	}
	return mulresult; //곱한 값 리턴
}
vec4 vec4::operator+(vec4& ref) //백터간 덧셈 오버로딩 함수
{
	float addresult[4]{ //계산된 값을 저장해줄 곳
		0,0,0,0 };
	for (int i = 0; i < 4; i++) { //행렬 덧셈하는 부분
		addresult[i] = (vec[i] + ref.vec[i]);
	}
	return addresult; //덧셈 값 리턴
}
vec4 vec4::operator-(vec4& ref) //벡터간 뺄셈 오버로딩 함수
{
	float subresult[4]{ //계산된 값을 저장해줄 곳
		0,0,0,0 };
	for (int i = 0; i < 4; i++) { //행렬 뺄셈하는 부분
		subresult[i] = (vec[i] - ref.vec[i]);
	}
	return subresult; //뺄셈 값 리턴
}
vec4 vec4::operator/(float ref) //상수 나눗셈 오버로딩 함수
{
	float divresult[4]{ //계산된 값을 저장해줄 곳
		0,0,0,0 };
	for (int i = 0; i < 4; i++) { //행렬 나눗셈하는 부분
		divresult[i] = vec[i] / ref;
	}
	return divresult; //나눗셈 값 리턴
}
vec4 vec4::operator*(float ref) //상수 곱셈 오버로딩 함수
{
	float mulresult[4]{ //계산된 값을 저장해줄 곳
		0,0,0,0 };
	for (int i = 0; i < 4; i++) { //행렬 나눗셈하는 부분
		mulresult[i] = vec[i] * ref;
	}
	return mulresult; //곱셈 값 리턴
}

//vec1x3 클래스
//class vec1x3 {
//public:
//	float vec[1][3];  //float형 1차원 배열 
//	vec1x3(float v[1][3]); //생성자
//	vec1x3 operator*(mat3& ref); //곱셈 오버로딩 함수
//	vec1x3 operator+(vec1x3& ref); //덧셈 오버로딩 함수
//	vec1x3 operator-(vec1x3& ref); //뺄셈 오버로딩 함수
//	vec1x3 operator/(float ref); //상수 오버로딩 나눗셈
//	vec1x3 operator*(float ref); //상수 오버로딩 곱셈
//
//	vec1x3 Transpose(vec1x3 v) { //전치 행렬
//		vec1x3 transpose(new float[1][3]);
//		for (int j = 0; j < 3; j++) {
//			transpose.vec[0][j] = v.vec[0][j];
//			//std::cout << transpose[i][j];
//		}
//		return transpose;
//	}
//};
//vec1x3::vec1x3(float v[1][3]) { //생성자
//	for (int i = 0; i < 3; i++) { //매개변수로 받아온 행렬 값을 지역변수에 저장
//		this->vec[0][i] = v[0][i];
//	}
//}
//vec1x3 vec1x3::operator*(mat3& ref) //벡터 곱셈 오버로딩 함수
//{
//	vec1x3 mulresult(new float[1][3]{ 0, 0, 0 }); //계산된 값을 저장해줄 곳
//	for (int i = 0; i < 3; i++) { //행렬 곱셈하는 부분
//		for (int j = 0; j < 3; j++) {
//			mulresult.vec[0][i] += (vec[0][j] * ref.mat[j][i]);
//		}
//	}
//	return mulresult; //곱한 값 리턴
//}
//vec1x3 vec1x3::operator+(vec1x3& ref) { //백터간 덧셈 오버로딩 함수
//	vec1x3 addresult(new float[1][3]); //계산된 값을 저장해줄 곳
//	for (int i = 0; i < 3; i++) { //행렬 덧셈하는 부분
//		addresult.vec[0][i] = (vec[0][i] + ref.vec[0][i]);
//	}
//	return addresult; //덧셈 값 리턴
//}
//vec1x3 vec1x3::operator-(vec1x3& ref) { //벡터간 뺄셈 오버로딩 함수
//	vec1x3 addresult(new float[1][3]); //계산된 값을 저장해줄 곳
//	for (int i = 0; i < 3; i++) { //행렬 뺄셈하는 부분
//		addresult.vec[0][i] = (vec[0][i] - ref.vec[0][i]);
//	}
//	return addresult; //뺄셈 값 리턴
//}
//vec1x3 vec1x3::operator/(float ref) { //상수 나눗셈 오버로딩 함수
//	vec1x3 value(new float[1][3]); //계산된 값을 저장해줄 곳
//	for (int i = 0; i < 3; i++) { //행렬 나눗셈하는 부분
//		value.vec[0][i] = vec[0][i] / ref;
//	}
//	return value; //나눗셈 값 리턴
//}
//vec1x3 vec1x3::operator*(float ref) { //상수 곱셈 오버로딩 함수
//	vec1x3 mulresult(new float[1][3]); //계산된 값을 저장해줄 곳
//	for (int i = 0; i < 3; i++) { //행렬 나눗셈하는 부분
//		mulresult.vec[0][i] = vec[0][i] * ref;
//	}
//	return mulresult; //곱셈 값 리턴
//}

//vec1x4 클래스
//class vec1x4 {
//public:
//	float vec[1][4]; //float형 1차원 배열 
//	vec1x4(float v[1][4]); //생성자
//	vec1x4 operator*(mat4& ref); //곱셈 오버로딩 함수
//	vec1x4 operator+(vec1x4& ref); //덧셈 오버로딩 함수
//	vec1x4 operator-(vec1x4& ref); //뺄셈 오버로딩 함수
//	vec1x4 operator/(float ref); //상수 오버로딩 나눗셈
//	vec1x4 operator*(float ref); //상수 오버로딩 곱셈
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
//vec1x4::vec1x4(float v[1][4]) { //생성자
//	for (int i = 0; i < 4; i++) { //매개변수로 받아온 행렬 값을 지역변수에 저장
//		this->vec[0][i] = v[0][i];
//	}
//}
//vec1x4 vec1x4::operator*(mat4& ref) //벡터 곱셈 오버로딩 함수
//{
//	vec1x4 mulresult(new float[1][4]{ 0, 0, 0, 0 }); //계산된 값을 저장해줄 곳
//	for (int i = 0; i < 4; i++) { //행렬 곱셈하는 부분
//		for (int j = 0; j < 4; j++) {
//			mulresult.vec[0][i] += (vec[0][j] * ref.mat[j][i]);
//		}
//	}
//	return mulresult; //곱한 값 리턴
//}
//vec1x4 vec1x4::operator+(vec1x4& ref) { //백터간 덧셈 오버로딩 함수
//	vec1x4 addresult(new float[1][4]); //계산된 값을 저장해줄 곳
//	for (int i = 0; i < 4; i++) { //행렬 덧셈하는 부분
//		addresult.vec[0][i] = (vec[0][i] + ref.vec[0][i]);
//	}
//	return addresult; //덧셈 값 리턴
//}
//vec1x4 vec1x4::operator-(vec1x4& ref) { //벡터간 뺄셈 오버로딩 함수
//	vec1x4 addresult(new float[1][4]); //계산된 값을 저장해줄 곳
//	for (int i = 0; i < 4; i++) { //행렬 뺄셈하는 부분
//		addresult.vec[0][i] = (vec[0][i] - ref.vec[0][i]);
//	}
//	return addresult; //뺄셈 값 리턴
//}
//vec1x4 vec1x4::operator/(float ref) { //상수 나눗셈 오버로딩 함수
//	vec1x4 divresult(new float[1][4]); //계산된 값을 저장해줄 곳
//	for (int i = 0; i < 4; i++) { //행렬 나눗셈하는 부분
//		divresult.vec[0][i] = vec[0][i] / ref;
//	}
//	return divresult;  //나눗셈 값 리턴
//}
//vec1x4 vec1x4::operator*(float ref) { //상수 곱셈 오버로딩 함수
//	vec1x4 mulresult(new float[1][4]); //계산된 값을 저장해줄 곳
//	for (int i = 0; i < 4; i++) { //행렬 나눗셈하는 부분
//		mulresult.vec[0][i] = vec[0][i] * ref;
//	}
//	return mulresult; //곱셈 값 리턴
//}