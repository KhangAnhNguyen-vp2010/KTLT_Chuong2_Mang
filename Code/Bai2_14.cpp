#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
#include<string.h>
void Timc(char a[], char x) {
	int str = strlen(a);
	for (int i = 0; i < str; i++)
	{
		if (a[i] == x) { printf("\nDa tim thay ki tu x=%c va vi tri:%d", a[i],i); return; }
	}
	printf("\nKhong tim thay ki tu x");
}
int main() {
	char a[] = "ZRLKHFEGA";
	char x1 = 'R', x2 = 'C';
	char x3 = 'D', x4 = 'Q';
	Timc(a, x1);
	Timc(a, x2);
	Timc(a, x3);
	Timc(a, x4);
}