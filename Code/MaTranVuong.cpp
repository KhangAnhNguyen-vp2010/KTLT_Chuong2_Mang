#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXSIZE 100

void tao_MaTranVuong(int a[][MAXSIZE], int &n)
{
	printf("Nhap kick co n:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j]=rand()%100;
		}
	}
}

void xuat_MaTranVuong(int a[][MAXSIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// Hàm tính tổng các phần tử nằm trên đường chéo chính
int sum_main_diagonal(int matrix[][MAXSIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

// Hàm tính tổng các phần tử nằm trên đường chéo phụ
int sum_secondary_diagonal(int matrix[][MAXSIZE], int n) {
    int sum = 0;
	for (int i = 0; i < n; i++) {
        sum += matrix[i][n - i - 1];
    }
    return sum;
}

int main()
{
	int a[MAXSIZE][MAXSIZE];
	int n;
	tao_MaTranVuong(a,n);
	xuat_MaTranVuong(a,n);
	printf("\n--------------------------------------\n");
	printf("Tong cac phan tu nam tren duong cheo chinh la: %d", sum_main_diagonal(a,n));
	printf("\n--------------------------------------\n");
	printf("Tong cac phan tu nam tren duong cheo phu la: %d", sum_secondary_diagonal(a,n));
	getch();
	return 0;
}