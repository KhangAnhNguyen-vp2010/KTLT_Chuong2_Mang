#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
struct SinhVien
{
	char maSo[MAXSIZE], hoTen[MAXSIZE];
	int soTT;
	double diemTL, diemKT;
};

void nhap_MotSV(SinhVien &a)
{
	printf("Nhap so thu tu:");
	scanf("%d", &a.soTT);
	printf("Nhap ma so:"); getchar();
	gets(a.maSo);
	printf("Nhap ho ten:"); 
	gets(a.hoTen);
	printf("Nhap diem tieu luan:");
	scanf("%lf", &a.diemTL);
	printf("Nhap diem ket thuc mon hoc:");
	scanf("%lf", &a.diemKT);
	printf("\n========================\n");
}

void nhap_DSSinhVien(SinhVien a[], int &n)
{
	printf("Nhap so luong sinh vien:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		nhap_MotSV(a[i]);
	}
}

void xuat_MotSV(SinhVien a)
{
	printf("SO THU TU:%d\n", a.soTT);
	printf("Ma So:%s\n", a.maSo);
	printf("Ho Ten:%s\n", a.hoTen);
	printf("Diem Tieu Luan:%.2f\n", a.diemTL);
	printf("Diem Ket Thuc Mon Hoc:%.2f\n", a.diemKT);
	printf("\n========================\n");
}

void xuat_DSSinhVien(SinhVien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		xuat_MotSV(a[i]);
	}
}

void nhapFile(SinhVien a[], int n, char tenFile[MAXSIZE])
{
	FILE *f;
	f=fopen(tenFile,"w");
	for (int i = 0; i < n; i++)
	{
		fprintf(f,"%d\n",a[i].soTT);
		fprintf(f,"%s\n",a[i].maSo);
		fprintf(f,"%s\n",a[i].hoTen);
		fprintf(f,"%.2f\n",a[i].diemTL);
		fprintf(f,"%.2f\n",a[i].diemKT);
	}
	fclose(f);
}

int main()
{
	SinhVien a[MAXSIZE];
	int n;
	nhap_DSSinhVien(a,n);
	xuat_DSSinhVien(a,n);
	nhapFile(a,n,"SinhVien.txt");
	getch();
	return 0;
}