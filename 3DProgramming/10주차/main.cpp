#include "MuSoenMath.h" //MuSoenMath.h를 불러옴
#include <iostream> //입출력 관련함수
#include <math.h> //수학 관련 헤더파일

int main(void) {
	//(3, 5)이동
	mat3 Translate(new float[3][3]{ //헤더파일에 있는 mat3이라는 클래스를 선언해 전치된 행렬값을 넣어줌
		{ 1, 0, 0 },
		{ 0, 1, 0 },
		{ 3, 5, 1 } });

	//30도 회전
	mat3 Rotate(new float[3][3]{
		{ (float)cos(PI / 6), -(float)sin(PI / 6), 0}, //30도 이동은 호도법으로 30도는 180/30->PI/6  
		{ (float)sin(PI / 6), (float)cos(PI / 6), 0},  //따라서 헤더파일에 선언한 PI를 사용함
		{ 0, 0, 1 } });

	//2배 커짐
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

	vec3 v(new float[3]{ 1, 1, 1 }); //v변수의 좌표값
	vec3 a(new float[3]{ 3, 5, 1 }); 
	vec3 p(new float[3]{ 0, 0, 0 }); //연산된 값을 저장할 곳

	vec4 vec4_v(new float[4]{ 1, 1, 1, 1 });
	vec4 vec4_t(new float[4]{ 3, 5, 1, 1 });
	vec4 vec4_p(new float[4]{ 0, 0, 0, 0 });

	vec1x3 vec1x3_v(new float[1][3]{ { 1, 1, 1 } });
	vec1x3 vec1x3_t(new float[1][3]{ { 3, 5, 1 } });
	vec1x3 vec1x3_p(new float[1][3]{ { 0, 0, 0 } });

	vec1x4 vec1x4_v(new float[1][4]{ { 1, 1, 1, 1 } });
	vec1x4 vec1x4_t(new float[1][4]{ { 3, 5, 1, 1 } });
	vec1x4 vec1x4_p(new float[1][4]{ { 0, 0, 0, 0 } });

	p = v * a; //벡터끼리 곱
	for (int i = 0; i < 3; i++) {
		std::cout << p.vec[i];
		std::cout << " ";
	}

	//class mat3
	//Translate.Transpose();
	//p = v * Translate * Rotate * Scale; //연산
	//for (int i = 0; i < 3; i++) { //곱하기 연산 출력
	//	std::cout << p.vec[i];
	//	std::cout << " ";
	//}

	//p = Translate * v;
	//for (int i = 0; i < 3; i++) { //곱하기 연산 출력
	//	std::cout << p.vec[i];
	//	std::cout << " ";
	//}

	//Translate.Transpose();
	//sum = Translate * Scale; //행렬 곱셈
	////sum = Translate + Scale; //행렬 덧셈
	//sum = Translate - Scale; //행렬 뺄셈
	//sum = Translate / 2; //mat3 나눗셈 상수 출력
	//sum = Translate * 2; //mat3 곱셈 상수 출력
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
	//for (int i = 0; i < 4; i++) { //곱하기 연산 출력
	//	std::cout << vec4_p.vec[i];
	//	std::cout << " ";
	//}

	//mat4_sum = mat4_Scale + mat4_Translate; //3차원 덧셈 행렬
	//mat4_sum = mat4_Scale - mat4_Translate; //3차원 뺄셈 행렬
	//mat4_sum = mat4_Scale * mat4_Translate; //3차원 곱셈 행렬 
	//mat4_sum = mat4_Translate / 2; //3차원 상수 나눗셈
	//mat4_sum = mat4_Translate * 2; //3차원 상수 곱셈
	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		std::cout << mat4_sum.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//mat4_Translate.Identitymatrix(); //3차원 항등 행렬
	//for (int i = 0; i < 4; i++) { //항등 행렬 출력
	//	for (int j = 0; j < 4; j++) {
	//		std::cout << mat4_Translate.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	/*mat4_Translate.Transpose(); //3차원 전치 행렬
	for (int i = 0; i < 4; i++) { //전치 행렬 출력
		for (int j = 0; j < 4; j++) {
			std::cout << mat4_Translate.mat[i][j];
			std::cout << " ";
		}
		std::cout << std::endl;
	}*/

	//p = v * Translate; //벡터 곱셈
	//p = v + a; //벡터 덧셈
	//p = v - a; //백터 뺄셈
	//p = a / 2; //벡터 상수 나눗셈 연산 출력
	//p = a * 2; //벡터 상수 곱셈 연산 출력
	//for (int i = 0; i < 3; i++) { //벡터 연산 출력
	//	std::cout << p.vec[i];
	//	std::cout << " ";
	//}

	//vec4_p = vec4_v * mat4_Translate; //벡터4 곱셈
	//vec4_p = vec4_v + vec4_t; //벡터 덧셈
	//vec4_p = vec4_v - vec4_t; //백터 뺄셈
	//vec4_p = vec4_t / 2; //상수 나눗셈
	//vec4_p = vec4_t * 2; //상수 곱셈
	//for (int i = 0; i < 4; i++) { //벡터 연산 출력
	//	std::cout << vec4_p.vec[i];
	//	std::cout << " ";
	//}

	//vec1x3_p.Transpose(vec1x3_p);
	//vec1x3_v.Transpose(vec1x3_v);
	//vec1x3_p = vec1x3_v * Translate; //곱셈
	//vec1x3_p = vec1x3_v + vec1x3_t; //덧셈
	//vec1x3_p = vec1x3_v - vec1x3_t; //뺄셈
	//vec1x3_p = vec1x3_t / 2; //상수 나눗셈
	//vec1x3_p = vec1x3_t * 2; //상수 곱셈
	//for (int i = 0; i < 3; i++) {
	//	std::cout << vec1x3_p.vec[0][i];
	//	std::cout << " ";
	//}
	
	//vec1x4_p.Transpose(vec1x4_p);
	//vec1x4_v.Transpose(vec1x4_v);
	//vec1x4_p = vec1x4_v * mat4_Translate; //곱셈
	//vec1x4_p = vec1x4_v + vec1x4_t; //덧셈
	//vec1x4_p = vec1x4_v - vec1x4_t; //뺄셈
	//vec1x4_p = vec1x4_t / 2; //상수 나눗셈
	//vec1x4_p = vec1x4_t * 2; //상수 곱셈
	//for (int i = 0; i < 4; i++) {
	//	std::cout << vec1x4_p.vec[0][i];
	//	std::cout << " ";
	//}
}