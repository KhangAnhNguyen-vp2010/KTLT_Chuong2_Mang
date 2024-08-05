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
void TimMaxMin(int a[], int n) {
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}
	printf("\nMax:%d\tMin:%d", max, min);
}
void DemPTChanLe(int a[], int n) {
	int demchan = 0, demle = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0) demchan++;
		if (a[i] % 2 != 0) demle++;
	}
	printf("\nSo phan tu chan:%d", demchan);
	printf("\nSo phan tu le:%d", demle);
}
int main() {
	int a[100], n;
	NhapM(a, n);
	XuatM(a, n);
	TimMaxMin(a, n);
	DemPTChanLe(a, n);
}