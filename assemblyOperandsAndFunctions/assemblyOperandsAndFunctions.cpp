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

//sum and counter of all from 3 positive numbers
void zad1(int a, int b, int c)
{
	int counter;
	int sum;

	__asm {

		mov eax, 0
		cmp a, 0
		jg positiveA
		finishFirst :
		cmp b, 0
			jg positiveB
			finishSecond :
		cmp c, 0
			jg positiveC
			finishThird :
		jmp finish

			positiveA :
		inc ecx
			add eax, a
			jmp finishFirst

			positiveB :
		inc ecx
			add eax, b
			jmp finishSecond

			positiveC :
		inc ecx
			add eax, c
			jmp finishThird

			finish :
		mov sum, eax
			mov counter, ecx
	}

	cout << "The sum of the positive numbers: " << sum << endl;
	cout << "The counter of the positive numbers: " << counter << endl;

}

//the-biggest number from 3
void zad2(int a, int b, int c) {

	int biggest;

	__asm {
		mov eax, a
		cmp eax, b
		//if a is bigger or equal then we 
		//need to simply compare {a} and {c} 
		jge firstPath
		//if its not bigger then should be {b}
		mov eax, b
		jmp secondPath

		secondPath :
		cmp eax, c
			jge biggestB
			//if its not 
			mov eax, c
			jmp biggestC


			firstPath :
		cmp eax, c
			jge biggestA
			//then C is bigger
			mov eax, c
			jmp biggestC

			biggestA :
		mov biggest, eax
			jmp finish

			biggestB :
		mov biggest, eax
			jmp finish

			biggestC :
		mov biggest, eax
			jmp finish

			finish :
	}

	cout << "The biggest number is: " << biggest << endl;

}


//descending order of 3 numbers using nested if in assembly
void zad3(int a, int b, int c)
{
	int start;
	int middle;
	int end;

	__asm {
		mov eax, a
		cmp eax, b
		//a<b
		jle firstPath
		//a>b
		jmp secondPath


		firstPath :
		cmp eax, c
			//a<c
			jle A_smallest
			//a>c
			jmp pathCAB

			secondPath :
		cmp eax, c
			//a<c
			jle pathBAC
			//a>c
			mov end, eax
			jmp A_biggest

			A_smallest :
		mov start, eax
			mov eax, b
			cmp eax, c
			//b<c
			jle pathABC
			//b>c
			jmp pathACB


			A_biggest :
		mov end, eax
			mov eax, b
			cmp eax, c
			// b<c
			jle pathBCA
			//b>c
			jmp pathCBA


			//-------------A-biggest-------------------//
			//b<c<a
		pathBCA:
		mov start, eax
			mov eax, c
			mov middle, eax
			jmp finish

			//c<b<a
			pathCBA :
		mov middle, eax
			mov eax, c
			mov start, eax
			jmp finish
			//-------------A-biggest-------------------//



			//-------------A-smallest-------------------//
			//a<b<c
		pathABC:
		mov middle, eax
			mov eax, c
			mov end, eax
			jmp finish

			//a<c<b
			pathACB :
		mov end, eax
			mov eax, c
			mov middle, eax
			jmp finish
			//-------------A-smallest-------------------//
			

			//-------------A-middle--------------------//

			//c<a<b
		pathCAB:
		mov middle, eax
			mov eax, c
			mov start, eax
			mov eax, b
			mov end, eax
			jmp finish


			//b<a<c
		pathBAC:
		mov middle, eax
			mov eax, c
			mov end, eax
			mov eax, b
			mov start, eax
			jmp finish
			//-------------A-middle--------------------//





		finish:


	}

	cout << "Descending order of the numbers looks like this " << "{ " << start << " | " << middle << " | " << end << " }" << endl;

}


//n! = n.n-1.n-2...1
int factorial(int n) {
	__asm {
		mov eax, 1
		mov ecx, 1

		f:
		imul eax, ecx
			inc ecx
			cmp n, ecx
			jge f
	}
}

static int arr[10];

//array where every item has move {n} from last item 
void multiply(int n) {
	__asm {
		mov eax, n
		mov ecx, 0

		for:
		mov[arr + 4 * ecx], eax
			add eax, n
			inc ecx
			cmp ecx, 10
			jl for
	}

}

static int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };

//every item from the array at pow2 -> item^2
void pow2() {
	__asm {
		mov eax, [arr2]
		imul eax
		mov ecx, 0

		for:
		mov[arr2 + 4 * ecx], eax
			inc ecx
			mov eax, [arr2 + 4 * ecx]
			imul eax
			cmp ecx, 10
			jl for
	}
}

static int arr3[10];


//sum of the n-items from the fibonacci sequence
void fibonacci(int count) {
	int temp = 2;
	__asm {
		mov eax, 1
		mov ebx, 1
		mov[arr3], eax
		mov[arr3 + 4], ebx
		mov ecx, 2


		for:
		add eax, ebx
			add temp, eax
			mov[arr3 + 4 * ecx], eax
			mov eax, [arr3 + 4 * ecx - 4]
			mov ebx, [arr3 + 4 * ecx]
			inc ecx
			cmp ecx, count
			jl for



	}
	cout << temp << endl;
}

//  n!/k! where n>k>1
void factorialDivide(int n, int k) {
	int check = 1;
	int result = 1;


	__asm {
		mov eax, 1
		mov ebx, k
		mov ecx, n

		cmp ecx, ebx
		jl firstPath
		cmp ebx, eax
		jl secondPath
		cmp ebx, ecx
		je thirdPath
		jmp looping



	firstPath:
		mov check, -1
			jmp return

			secondPath :
			mov check, 0
			jmp return

			thirdPath :
			jmp return


			looping :
			inc ebx
			mul ebx
			cmp ecx, ebx
			//n >  k
			jg looping
			jmp return



			return :
		mov result, eax
	}

	if (check == -1) {
		cout << "Please enter different numbers! (k>n)" << endl;
	}
	else if (check == 0) {
		cout << "Please enter different numbers! (k<1)" << endl;
	}
	else {
		cout << "The result from dividing " << n << "! and " << k << "! is " << result << endl;
	}
}


void PrintArray(int* array, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << " | " << array[i];
	}
	cout << " | " << endl;
}

int main()
{

	/*
	cout << perimeter_of_rectangle(10, 5) << endl;
	cout << area_of_rectangle(10, 5) << endl;
	cout << perimeter_of_square(10) << endl;
	cout << area_of_square(10) << endl;
	cout << perimeter_of_triangle(3, 4, 5) << endl;
	cout << perimeter_of_equilateral_triangle(7) << endl;
	cout << perimeter_of_rectangular_triangle(6, 10) << endl;
	cout << area_of_cube(10) << endl;
	cout << area_of_triangle_heron_formula(10, 7, 7) << endl;
	*/

	/*int a = 1;
	int b = 10;
	int c = 12;
	int d = -13;
	zad1(a, d, c);
	zad2(a, d, c);
	zad3(b,a, c);*/

	cout << factorial(5) << endl;
	multiply(2);
	PrintArray(arr, 10);
	pow2();
	cout << endl;
	PrintArray(arr2, 10);
	cout << endl;
	fibonacci(10);
	cout << endl;
	PrintArray(arr3, 10);
	cout << endl;
	factorialDivide(13, 9);
}


