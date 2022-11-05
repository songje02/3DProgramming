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

	vec3 v(new float[3]{ 1, 1, 1 }); //v변수의 좌표값
	vec3 p(new float[3]{ 0, 0, 0 }); //연산된 값을 저장할 곳

	p = v * Translate * Rotate * Scale; //연산

	for (int i = 0; i < 3; i++) { //연산된 값을 출력하는 곳
		std::cout << p.vec[i];
		std::cout << " ";
	}
}
