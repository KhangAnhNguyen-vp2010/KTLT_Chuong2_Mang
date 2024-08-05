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
void DoiCho(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void SapXep(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) DoiCho(a[i], a[j]);
		}
	}
}
void LinearSearch(int a[], int n, int& x) {
	printf("\nMoi nhap vao x:");
	scanf("%d", &x);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) {
			printf("\nTim thay x:%d va vi tri:%d", a[i], i); return;
		}
	}
	printf("\nKhong tim thay x va vi tri:-1!");
}
void BinarySearch(int a[], int n, int& x) {
	printf("\nMoi nhap vao x:");
	scanf("%d", &x);
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (a[mid] == x) {
			printf("\nTim thay x:%d va vi tri:%d", a[mid], mid);
			return;
		}
		else
			if (a[mid] > x) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
	}
	printf("\nKhong tim thay x va vi tri:-1");
}
void Demx(int a[], int n, int& x) {
	printf("\nMoi nhap vao x:");
	scanf("%d", &x);
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) dem++;
	}
	printf("\nPhan tu %d xuat hien:%d", x, dem);
}
void Demlonhonx(int a[], int n, int& x) {
	printf("\nMoi nhap vao x:");
	scanf("%d", &x);
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x) dem++;
	}
	printf("\nCo %d phan tu lon hon %d", dem, x);
}
void Sum(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	printf("\nGia tri cua tong phan tu trong a:%d", sum);
}
int KTSNT(int a) {
	int dem = 0;
	for (int i = 0; i < a; i++)
	{
		if (a % i == 0) dem++;
	}
	return dem;
}
void XuatSNT(int a[], int n) {
	int dem = 0;
	printf("\nCac so nguyen to:\n");
	for (int i = 0; i < n; i++)
	{
		if (KTSNT(a[i] == 0)) {
			printf("%d\t", a[i]); dem++;
		}
	}
	if (dem == 0) printf("\nMang khong co so nguyen to!");
}
int KTSHT(int a) {
	int tong = 0;
	for (int i = 0; i <= a; i++)
	{
		if (a % i == 0) tong += i;
	}
	if (tong == a) return 1; else return 0;
}
void XuatSHT(int a[], int n) {
	int dem = 0;
	printf("\nCac so hoan thien:\n");
	for (int i = 0; i < n; i++)
	{
		if (KTSHT(a[i]) == 1) { printf("%d\t", a[i]); dem++; }
	}
	if (dem == 0) printf("\nMang khong chua so hoan thien!");
}
void XuatVTChan(int a[], int n) {
	printf("\nCac phan tu o vi tri chan:\n");
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) printf("%d\t", a[i]);
	}
}
void XuatVTLe(int a[], int n) {
	printf("\nCac phan tu o vi tri le:\n");
	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0) printf("%d\t", a[i]);
	}
}
void TimMaxMin_ViTri(int a[], int n) {
	int max = a[0], min = a[0];
	int IndexMax = -1, IndexMin = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max) { max = a[i]; IndexMax = i; }
		if (a[i] < min) { min = a[i]; IndexMin = i; }
	}
	printf("\nPhan tu Max:%d va vi tri:%d", max, IndexMax);
	printf("\nPhan tu Max:%d va vi tri:%d", min, IndexMin);
}
void GhepMangTangDan(int b[], int c[], int a[], int n1, int n2, int& n3) {
	n3 = n1 + n2;
	int i1 = 0, i2 = 0, i3 = 0;
	printf("\n");
	while (i3 < n3)
	{
		if (i1 >= n1) {
			a[i3] = c[i2];
			i2++;
		}
		else {
			a[i3] = b[i1];
			i1++;
		}
		i3++;
	}
	SapXep(a, n3);
}
int main() {
	int a[100], n,x;
	int b[100], c[100], d[100];
	NhapM(a, n);
	XuatM(a, n);
	TimMaxMin(a, n);
	DemPTChanLe(a, n);
	SapXep(a, n);
	LinearSearch(a, n, x);
	BinarySearch(a, n, x);
	Demx(a, n, x);
	Demlonhonx(a, n, x);
	Sum(a, n);
	XuatSNT(a, n);
	XuatSHT(a, n);
	XuatVTChan(a, n);
	XuatVTLe(a, n);
	int n1, n2, n3;
	NhapM(b, n1);
	XuatM(b, n1);
	printf("\n");
	NhapM(c, n2);
	XuatM(c, n2);
	GhepMangTangDan(b, c, d, n1, n2, n3);
	XuatM(d, n3);
}