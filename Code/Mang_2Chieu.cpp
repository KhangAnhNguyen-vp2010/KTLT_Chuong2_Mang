#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXSIZE 100


void tao_Mang2C(int a[][MAXSIZE], int &n, int &m)
{
	printf("Nhap so dong:");
	scanf("%d", &n);
	printf("Nhap so cot:");
	scanf("%d", &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j]=rand()%100;
		}
	}
}

void xuat_Mang2C(int a[][MAXSIZE], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// tinh tong cac phan tu co chu so dau la chu so le

int Tach(int n)
{
	while (n/10 != 0)
	{
		n=n/10;
	}
	return n;
}

void tinhTong(int a[][MAXSIZE], int n, int m)
{
	int tong=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Tach(a[i][j])%2 != 0)
			{
				tong+=a[i][j];
			}
		}
	}

	printf("Ket Qua: %d", tong);
}


// Hàm kiểm tra số hoàn thiện
int isPerfectNumber(int num) {
    if (num < 2) return 0;
    int sum = 1; // 1 luôn là ước số của mọi số nguyên dương
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

// Hàm liệt kê các số hoàn thiện trong ma trận
void listPerfectNumbersInMatrix(int matrix[100][100], int rows, int cols) {
    printf("Cac so hoan thien trong ma tran la: ");
    int found = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isPerfectNumber(matrix[i][j])) {
                printf("%d ", matrix[i][j]);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Khong co so hoan thien nao trong ma tran.");
    }
    printf("\n");
}

int main()
{
	int a[MAXSIZE][MAXSIZE];
	int n, m;
	tao_Mang2C(a,n,m);
	xuat_Mang2C(a,n,m);
	printf("\n---------------------------\n");
	tinhTong(a,n,m);
	printf("\n---------------------------\n");
	listPerfectNumbersInMatrix(a,n,m);
	getch();
	return 0;
}