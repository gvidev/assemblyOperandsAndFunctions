#include <iostream>

using namespace std;



//The triangle for the next cases is a,b,c where A is versus a, B is versus b and C is versus c

//calculates perimeter of rectangle
int perimeter_of_rectangle(int a, int b) {
	__asm {
		mov eax, a
		add eax, a
		add eax, b
		add eax, b
	}
}
//calculates the area of rectangle
int area_of_rectangle(int a, int b) {
	__asm {
		mov eax, a
		mul b
	}
}
//calculates perimeter of square
int perimeter_of_square(int a) {
	__asm {
		mov eax, a
		mov ebx, 4
		mul ebx
	}
}
//calculates the area of square
int area_of_square(int a) {
	__asm {
		mov eax, a
		mul a

	}
}
//calculates perimeter of triangle
int perimeter_of_triangle(int a, int b, int c) {
	__asm {
		mov eax, a
		add eax, b
		add eax, c
	}
}
//calculates perimeter of equilateral  triangle
int perimeter_of_equilateral_triangle(int a) {
	__asm {
		mov eax, a
		mov ebx, 3
		mul ebx
	}
}

//not the best optimized variant because i use integer and possible loss of data
// calculates perimeter of rectangular triangle
int perimeter_of_rectangular_triangle(int a, int b) {

	int result = 0;
	int temp = 0;
	int c = 0;

	__asm {
		mov eax, a
		mul a
		mov ebx, eax
		mov eax, b
		mul b
		add ebx, eax
		mov temp, ebx
		mov eax, a
		add eax, b
		mov result, eax
	}
	c = sqrt(temp);
	return result += c;
}

//calculates perimeter of triangle from side length and height
int perimeter_of_triangle(int a, int h) {
	__asm {
	}
	return 0;
}

//calculates surface area of a cube.
int area_of_cube(int a) {
	__asm {
		mov eax, a
		mov ebx, 6
		mul ebx
		mul a
	}
}

 //not the best optimized variant because i use integer and possible loss of data
 // P = sqrt(s*(s-a)*(s-b)*(s-c) ); s = (a + b + c)/2
int area_of_triangle_heron_formula(int a, int b, int c) {

	int result = 0;
	int temp = 0;
	int const divider = 2;

	__asm {
		mov eax, a
		add eax, b
		add eax, c

		mov ecx, 2
		mov edx, 0
		div ecx    // eax => s = (a+b+c)/2
		mov ecx, eax


		sub ecx, a //s-a
		mul ecx    //eax = s*(s-a)

		add ecx, a // get back to s

		sub ecx, b //s-b
		mul ecx    //eax = s * (s - a) * (s - b)

		add ecx, b // get back to s

		sub ecx, c //s-c
		mul ecx    //eax = s*(s-a)*(s-b)*(s-c)

		mov result, eax 
	}

	return sqrt(result);
}

int main()
{
	
	cout << perimeter_of_rectangle(10, 5) << endl;
	cout << area_of_rectangle(10, 5) << endl;
	cout << perimeter_of_square(10) << endl;
	cout << area_of_square(10) << endl;
	cout << perimeter_of_triangle(3, 4, 5) << endl;
	cout << perimeter_of_equilateral_triangle(7) << endl;
	cout << perimeter_of_rectangular_triangle(6, 10) << endl;
	cout << area_of_cube(10) << endl;
	cout << area_of_triangle_heron_formula(10, 7, 7) << endl;


}
