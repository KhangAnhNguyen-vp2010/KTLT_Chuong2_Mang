#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
#include<string.h>
void NhapM(int a[], int& n) {
	printf("Nhap so luong phan tu:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 1000;
	}
}
void XuatM(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}
int KTSNT(int a) {
	if (a < 2) return 1;
	for (int i = 2; i < a; i++)
	{
		if (a % i == 0) return 0;
	}
	return 1;
}
void DemSNT(int a[], int n) {
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if (KTSNT(a[i]) == 1) printf("%d\t", a[i]);
	}
}
int main() {
	int a[100], n;
	NhapM(a, n);
	XuatM(a, n);
	DemSNT(a, n);
}