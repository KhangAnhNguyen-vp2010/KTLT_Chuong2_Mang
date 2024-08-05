#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
#include<string.h>
void Timx(int a[], int n, int x) {
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) { printf("\nDa tim thay x=%d va vi tri:%d", a[i],i); return; }
	}
	printf("\nKhong tim thay x");
}
int main() {
	int a[100] = { 7,9,13,17,27,30,31,35,38,40};
	size_t n = sizeof(a);
	int x1 = 17, x2 = 35, x3 = 40;
	Timx(a, n, x1);
	Timx(a, n, x2);
	Timx(a, n, x3);
}