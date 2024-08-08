#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
#include<string.h>
struct MonHoc
{
	char MaMon[10];
	char TenMon[30];
	int STC;
	float Diem;
};
struct SV {
	char Mssv[10];
	char Hoten[30];
	float DNMLT,DToanA1,DToanA2,DVLKT,DAV,DTB;
};
void Nhap1SV(SV& a) {
	printf("\n");
	printf("Nhap vao ma so sinh vien:");
	fgets(a.Mssv, sizeof(a.Mssv), stdin);
	printf("Nhap vao ten cua sinh vien:");
	fgets(a.Hoten, sizeof(a.Hoten), stdin);
	printf("Nhap diem mon KTLTL:");
	scanf("%f", &a.DNMLT);
	getchar();
	printf("Nhap diem mon toan A1:");
	scanf("%f", &a.DToanA1);
	getchar();
	printf("Nhap diem mon toan A2:");
	scanf("%f", &a.DToanA2);
	getchar();
	printf("Nhap diem mon VLKT:");
	scanf("%f", &a.DVLKT);
	getchar();
	printf("Nhap diem mon anh van:");
	scanf("%f", &a.DAV);
	getchar();
}
void TKDauRot(SV a) {
	int dau = 0;
	int rot = 0;
	if (a.DNMLT >= 5) dau++; else rot++;
	if (a.DToanA1 >= 5) dau++; else rot++;
	if (a.DToanA2 >= 5) dau++; else rot++;
	if (a.DVLKT >= 5) dau++; else rot++;
	if (a.DAV >= 5) dau++; else rot++;
	printf("\nSo mon dau:%d va So mon rot:%d", dau, rot);
}
void Xuat1SV(SV a) {
	a.DTB = (a.DNMLT + a.DToanA1 + a.DToanA2 + a.DVLKT + a.DAV) / 5;
	printf("\nMSSV:%s", a.Mssv);
	printf("Ho ten:%s", a.Hoten);
	printf("\nNMLT:%.2f\tToan A1:%.2f\tToan A2:%.2f\tVLKT:%2.f\tAnh Van:%.2f",a.DNMLT,a.DToanA1,a.DToanA2,a.DVLKT,a.DAV);
	printf("\nDiem trung binh:%.2f", a.DTB);
	TKDauRot(a);
	if (a.DTB > 8.0) printf("\nHoc luc:Gioi"); else if (a.DTB > 6.5) printf("\nHoc luc:Kha"); else if (a.DTB > 5) printf("\nHoc luc:Trung binh"); else printf("\nHoc luc:Yeu");
	printf("\n");
}
void NhapDSSV(SV a[], int& n) {
	printf("Nhap so luong SV:");
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		Nhap1SV(a[i]);
	}
}
void XuatDSSV(SV a[], int n) {
	printf("\nDanh sach SV:");
	for (int i = 0; i < n; i++)
	{
		printf("\nSinh vien thu %d", i + 1);
		Xuat1SV(a[i]);
	}
}
void XoaXuongDong(char a[]) {
	int str = strlen(a);
	for (int i = 0; i <= str; i++)
	{
		if (a[i] == '\n') a[i] = '\0';
	}
}
void TimSV(SV a[], int n, SV &x) {
	printf("Nhap mssv can tim:");
	fgets(x.Mssv, sizeof(x.Mssv), stdin);
	XoaXuongDong(x.Mssv);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].Mssv, x.Mssv)) {
			printf("\nTim thay SV");
			Xuat1SV(a[i]);
		}
	}
}
void SVDTBMAX(SV a[], int n) {
	float max = a[0].DTB;
	int index;
	for (int i = 0; i < n; i++)
	{
		if (a[i].DTB > max) {
			max = a[i].DTB;
			index = i;
		}
	}
	printf("\nSinh vien co diem trung binh cao nhat:%.2f",max);
	Xuat1SV(a[index]);
}
void DoiCho(SV& a, SV& b) {
	SV temp = a;
	a = b;
	b = temp;
}
void SapXepDTB(SV a[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			if (a[i].DTB > a[j].DTB) DoiCho(a[i], a[j]);
		}
	}
	XuatDSSV(a, n);
}
void Them1SV(SV a[], int &n) {
	int index;
	SV x;
	printf("\nChon vi tri them vao:");
	scanf("%d", &index);
	getchar();
	if (index == 0) {
		n++;
		Nhap1SV(x);
		for (int i = n; i >= index; i--)
		{
			DoiCho(a[i + 1], a[i]);
		}
		a[index] = x;
	} else
	if (index == n) {
		n++;
		Nhap1SV(x);
		a[index]=x;
	} else
	if (index < n) {
		n++;
		Nhap1SV(x);
		for (int i = n; i >= index; i--)
		{
			DoiCho(a[i + 1], a[i]);
		}
		a[index] = x;
	}
	else {
		printf("\nThem vi tri khong hop le!");
		return;
	}
}
void Xoa1SV(SV a[], int &n) {
	int index;
	printf("\nChon vi tri xoa:");
	scanf("%d", &index);
	getchar();
	if (index == 0) {
		for (int i = 0; i < n-1; i++)
		{
			DoiCho(a[i + 1], a[i]);
		}
		n--;
	} else
	if (index == n-1) {
		n--;
	} else
	if (index < n-1) {
		for (int i = index; i < n-1; i++)
		{
			DoiCho(a[i + 1], a[i]);
		}
		n--;
	}
}
int main() {
	SV a[100];
	SV x;
	int n;
	NhapDSSV(a, n);
	XuatDSSV(a, n);
	Xoa1SV(a, n);
	XuatDSSV(a, n);
}