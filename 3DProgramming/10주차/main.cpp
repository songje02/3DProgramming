#include "MuSoenMath.h" //MuSoenMath.h¸¦ ºÒ·¯¿È
#include <iostream> //ÀÔÃâ·Â °ü·ÃÇÔ¼ö
#include <math.h> //¼öÇÐ °ü·Ã Çì´õÆÄÀÏ

int main(void) {
	//(3, 5)ÀÌµ¿
	mat3 Translate(new float[3][3]{ //Çì´õÆÄÀÏ¿¡ ÀÖ´Â mat3ÀÌ¶ó´Â Å¬·¡½º¸¦ ¼±¾ðÇØ ÀüÄ¡µÈ Çà·Ä°ªÀ» ³Ö¾îÁÜ
		{ 1, 0, 0 },
		{ 0, 1, 0 },
		{ 3, 5, 1 } });

	//30µµ È¸Àü
	mat3 Rotate(new float[3][3]{
		{ (float)cos(PI / 6), -(float)sin(PI / 6), 0}, //30µµ ÀÌµ¿Àº È£µµ¹ýÀ¸·Î 30µµ´Â 180/30->PI/6  
		{ (float)sin(PI / 6), (float)cos(PI / 6), 0},  //µû¶ó¼­ Çì´õÆÄÀÏ¿¡ ¼±¾ðÇÑ PI¸¦ »ç¿ëÇÔ
		{ 0, 0, 1 } });

	//2¹è Ä¿Áü
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

	vec3 v(new float[3]{ 1, 1, 1 }); //vº¯¼öÀÇ ÁÂÇ¥°ª
	vec3 a(new float[3]{ 3, 5, 1 }); 
	vec3 p(new float[3]{ 0, 0, 0 }); //¿¬»êµÈ °ªÀ» ÀúÀåÇÒ °÷

	vec4 vec4_v(new float[4]{ 1, 1, 1, 1 });
	vec4 vec4_t(new float[4]{ 3, 5, 1, 1 });
	vec4 vec4_p(new float[4]{ 0, 0, 0, 0 });

	vec1x3 vec1x3_v(new float[1][3]{ { 1, 1, 1 } });
	vec1x3 vec1x3_t(new float[1][3]{ { 3, 5, 1 } });
	vec1x3 vec1x3_p(new float[1][3]{ { 0, 0, 0 } });

	vec1x4 vec1x4_v(new float[1][4]{ { 1, 1, 1, 1 } });
	vec1x4 vec1x4_t(new float[1][4]{ { 3, 5, 1, 1 } });
	vec1x4 vec1x4_p(new float[1][4]{ { 0, 0, 0, 0 } });

	p = v * a; //º¤ÅÍ³¢¸® °ö
	for (int i = 0; i < 3; i++) {
		std::cout << p.vec[i];
		std::cout << " ";
	}

	//class mat3
	//Translate.Transpose();
	//p = v * Translate * Rotate * Scale; //¿¬»ê
	//for (int i = 0; i < 3; i++) { //°öÇÏ±â ¿¬»ê Ãâ·Â
	//	std::cout << p.vec[i];
	//	std::cout << " ";
	//}

	//p = Translate * v;
	//for (int i = 0; i < 3; i++) { //°öÇÏ±â ¿¬»ê Ãâ·Â
	//	std::cout << p.vec[i];
	//	std::cout << " ";
	//}

	//Translate.Transpose();
	//sum = Translate * Scale; //Çà·Ä °ö¼À
	////sum = Translate + Scale; //Çà·Ä µ¡¼À
	//sum = Translate - Scale; //Çà·Ä »¬¼À
	//sum = Translate / 2; //mat3 ³ª´°¼À »ó¼ö Ãâ·Â
	//sum = Translate * 2; //mat3 °ö¼À »ó¼ö Ãâ·Â
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
	//for (int i = 0; i < 4; i++) { //°öÇÏ±â ¿¬»ê Ãâ·Â
	//	std::cout << vec4_p.vec[i];
	//	std::cout << " ";
	//}

	//mat4_sum = mat4_Scale + mat4_Translate; //3Â÷¿ø µ¡¼À Çà·Ä
	//mat4_sum = mat4_Scale - mat4_Translate; //3Â÷¿ø »¬¼À Çà·Ä
	//mat4_sum = mat4_Scale * mat4_Translate; //3Â÷¿ø °ö¼À Çà·Ä 
	//mat4_sum = mat4_Translate / 2; //3Â÷¿ø »ó¼ö ³ª´°¼À
	//mat4_sum = mat4_Translate * 2; //3Â÷¿ø »ó¼ö °ö¼À
	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		std::cout << mat4_sum.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	//mat4_Translate.Identitymatrix(); //3Â÷¿ø Ç×µî Çà·Ä
	//for (int i = 0; i < 4; i++) { //Ç×µî Çà·Ä Ãâ·Â
	//	for (int j = 0; j < 4; j++) {
	//		std::cout << mat4_Translate.mat[i][j];
	//		std::cout << " ";
	//	}
	//	std::cout << std::endl;
	//}

	/*mat4_Translate.Transpose(); //3Â÷¿ø ÀüÄ¡ Çà·Ä
	for (int i = 0; i < 4; i++) { //ÀüÄ¡ Çà·Ä Ãâ·Â
		for (int j = 0; j < 4; j++) {
			std::cout << mat4_Translate.mat[i][j];
			std::cout << " ";
		}
		std::cout << std::endl;
	}*/

	//p = v * Translate; //º¤ÅÍ °ö¼À
	//p = v + a; //º¤ÅÍ µ¡¼À
	//p = v - a; //¹éÅÍ »¬¼À
	//p = a / 2; //º¤ÅÍ »ó¼ö ³ª´°¼À ¿¬»ê Ãâ·Â
	//p = a * 2; //º¤ÅÍ »ó¼ö °ö¼À ¿¬»ê Ãâ·Â
	//for (int i = 0; i < 3; i++) { //º¤ÅÍ ¿¬»ê Ãâ·Â
	//	std::cout << p.vec[i];
	//	std::cout << " ";
	//}

	//vec4_p = vec4_v * mat4_Translate; //º¤ÅÍ4 °ö¼À
	//vec4_p = vec4_v + vec4_t; //º¤ÅÍ µ¡¼À
	//vec4_p = vec4_v - vec4_t; //¹éÅÍ »¬¼À
	//vec4_p = vec4_t / 2; //»ó¼ö ³ª´°¼À
	//vec4_p = vec4_t * 2; //»ó¼ö °ö¼À
	//for (int i = 0; i < 4; i++) { //º¤ÅÍ ¿¬»ê Ãâ·Â
	//	std::cout << vec4_p.vec[i];
	//	std::cout << " ";
	//}

	//vec1x3_p.Transpose(vec1x3_p);
	//vec1x3_v.Transpose(vec1x3_v);
	//vec1x3_p = vec1x3_v * Translate; //°ö¼À
	//vec1x3_p = vec1x3_v + vec1x3_t; //µ¡¼À
	//vec1x3_p = vec1x3_v - vec1x3_t; //»¬¼À
	//vec1x3_p = vec1x3_t / 2; //»ó¼ö ³ª´°¼À
	//vec1x3_p = vec1x3_t * 2; //»ó¼ö °ö¼À
	//for (int i = 0; i < 3; i++) {
	//	std::cout << vec1x3_p.vec[0][i];
	//	std::cout << " ";
	//}
	
	//vec1x4_p.Transpose(vec1x4_p);
	//vec1x4_v.Transpose(vec1x4_v);
	//vec1x4_p = vec1x4_v * mat4_Translate; //°ö¼À
	//vec1x4_p = vec1x4_v + vec1x4_t; //µ¡¼À
	//vec1x4_p = vec1x4_v - vec1x4_t; //»¬¼À
	//vec1x4_p = vec1x4_t / 2; //»ó¼ö ³ª´°¼À
	//vec1x4_p = vec1x4_t * 2; //»ó¼ö °ö¼À
	//for (int i = 0; i < 4; i++) {
	//	std::cout << vec1x4_p.vec[0][i];
	//	std::cout << " ";
	//}
}