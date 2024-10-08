﻿#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <limits.h>
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

// Hàm tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
void sumElementsGreaterThanNextAbs(int matrix[100][100], int rows, int cols) {
    int sum = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Kiểm tra phần tử liền sau trong cùng hàng
            if (j < cols - 1 && matrix[i][j] > abs(matrix[i][j + 1])) {
                sum += matrix[i][j];
            }
            // Kiểm tra phần tử liền sau trong cùng cột
            if (i < rows - 1 && matrix[i][j] > abs(matrix[i + 1][j])) {
                sum += matrix[i][j];
            }
        }
    }
    
	printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no la: %d", sum);
}

int sumRow(int matrix[100][100], int cols, int k) {
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += matrix[k][j];
    }
	return sum;
}

void sumBoundaryElements(int matrix[100][100], int rows, int cols) {
    int sum = 0;

    // Tính tổng các phần tử của hàng đầu tiên và hàng cuối cùng
    for (int j = 0; j < cols; j++) {
        sum += matrix[0][j]; // Hàng đầu tiên
        sum += matrix[rows - 1][j]; // Hàng cuối cùng
    }

    // Tính tổng các phần tử của cột đầu tiên và cột cuối cùng (trừ đi các góc đã tính)
    for (int i = 1; i < rows - 1; i++) {
        sum += matrix[i][0]; // Cột đầu tiên
        sum += matrix[i][cols - 1]; // Cột cuối cùng
    }

	printf("Tong cac gia tri nam tren bien cua ma tran: %d", sum);
}

// Hàm đếm tần suất xuất hiện của giá trị x trong ma trận
int countOccurrences(int matrix[100][100], int rows, int cols, int x) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == x) {
                count++;
            }
        }
    }
    return count;
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void countElements(int matrix[100][100], int rows, int cols, int* even, int* odd, int* negative, int* positive, int* prime) {
    *even = 0;
    *odd = 0;
    *negative = 0;
    *positive = 0;
    *prime = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = matrix[i][j];
            if (value % 2 == 0) {
                (*even)++;
            } else {
                (*odd)++;
            }
            if (value < 0) {
                (*negative)++;
            } else if (value > 0) {
                (*positive)++;
            }
            if (isPrime(value)) {
                (*prime)++;
            }
        }
    }
}

// Hàm tính tổng của từng cột và liệt kê các cột có tổng nhỏ nhất
void listColumnsWithMinSum(int matrix[100][100], int rows, int cols) {
    int colSums[100];
    int minSum = INT_MAX;

    // Tính tổng của từng cột
    for (int j = 0; j < cols; j++) {
        colSums[j] = 0;
        for (int i = 0; i < rows; i++) {
            colSums[j] += matrix[i][j];
        }
        if (colSums[j] < minSum) {
            minSum = colSums[j];
        }
    }

    // Liệt kê các cột có tổng nhỏ nhất
    printf("Cac cot co tong nho nhat (%d): ", minSum);
    for (int j = 0; j < cols; j++) {
        if (colSums[j] == minSum) {
            printf("%d ", j);
        }
    }
    printf("\n");
}

// Hàm liệt kê các dòng có nhiều số hoàn thiện nhất
void listRowsWithMostPerfectNumbers(int matrix[100][100], int rows, int cols) {
    int perfectCount[100] = {0};
    int maxCount = 0;

    // Đếm số lượng số hoàn thiện trong từng dòng
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isPerfectNumber(matrix[i][j])) {
                perfectCount[i]++;
            }
        }
        if (perfectCount[i] > maxCount) {
            maxCount = perfectCount[i];
        }
    }

    // Liệt kê các dòng có số lượng số hoàn thiện nhiều nhất
    printf("Cac dong co nhieu so hoan thien nhat (%d so hoan thien): ", maxCount);
    for (int i = 0; i < rows; i++) {
        if (perfectCount[i] == maxCount) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Hàm liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void listRowsWithAllEvenNumbers(int matrix[100][100], int rows, int cols) {
    int allEven;
    
    // Duyệt qua từng dòng của ma trận
    printf("Cac dong chua toan gia tri chan: ");
    for (int i = 0; i < rows; i++) {
        allEven = 1; // Giả định dòng hiện tại chứa toàn giá trị chẵn
        
        // Kiểm tra các phần tử trong dòng
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 != 0) {
                allEven = 0; // Nếu tìm thấy giá trị lẻ, gán allEven bằng 0
                break;
            }
        }
        
        // Nếu allEven vẫn bằng 1, nghĩa là dòng chứa toàn giá trị chẵn
        if (allEven) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Hàm tìm giá trị xuất hiện nhiều nhất trong ma trận
int findMostFrequentValue(int matrix[MAXSIZE][MAXSIZE], int rows, int cols) {
    int frequency[MAXSIZE * MAXSIZE] = {0};
    int maxValue = matrix[0][0];
    int maxCount = 0;

    // Duyệt qua các phần tử của ma trận và đếm số lần xuất hiện của mỗi giá trị
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            frequency[matrix[i][j]]++;
            if (frequency[matrix[i][j]] > maxCount) {
                maxCount = frequency[matrix[i][j]];
                maxValue = matrix[i][j];
            }
        }
    }

    return maxValue;
}

// Hàm tìm số nguyên tố nhỏ nhất trong ma trận
int findSmallestPrime(int matrix[100][100], int rows, int cols) {
    int smallestPrime = INT_MAX;

    // Duyệt qua tất cả các phần tử của ma trận
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isPrime(matrix[i][j])) {
                if (matrix[i][j] < smallestPrime) {
                    smallestPrime = matrix[i][j];
                }
            }
        }
    }

    // Nếu smallestPrime vẫn là INT_MAX, nghĩa là không có số nguyên tố nào trong ma trận
    if (smallestPrime == INT_MAX) {
        return -1; // Trả về -1 để chỉ ra rằng không có số nguyên tố
    }

    return smallestPrime;
}

// Hàm tìm phần tử lớn nhất và nhỏ nhất trong dòng thứ k của ma trận
void findMinMaxInRow(int matrix[100][100], int rows, int cols, int k) {
    if (k >= rows || k < 0) {
        printf("Chi so dong k khong hop le.\n");
        return;
    }

    int maxElement = INT_MIN;
    int minElement = INT_MAX;

    // Duyệt qua các phần tử của dòng thứ k
    for (int j = 0; j < cols; j++) {
        if (matrix[k][j] > maxElement) {
            maxElement = matrix[k][j];
        }
        if (matrix[k][j] < minElement) {
            minElement = matrix[k][j];
        }
    }

    // In phần tử lớn nhất và nhỏ nhất
    printf("Phan tu lon nhat trong dong %d la: %d\n", k, maxElement);
    printf("Phan tu lon nhat trong dong %d la: %d\n", k, minElement);
}

// Hàm tìm phần tử lớn nhất và nhỏ nhất trong cột thứ k của ma trận
void findMinMaxInColumn(int matrix[100][100], int rows, int cols, int k) {
    if (k >= cols || k < 0) {
        printf("Chi so cot k khong hop le.\n");
        return;
    }

    int maxElement = INT_MIN;
    int minElement = INT_MAX;

    // Duyệt qua các phần tử của cột thứ k
    for (int i = 0; i < rows; i++) {
        if (matrix[i][k] > maxElement) {
            maxElement = matrix[i][k];
        }
        if (matrix[i][k] < minElement) {
            minElement = matrix[i][k];
        }
    }

    // In phần tử lớn nhất và nhỏ nhất
    printf("Phan tu lon nhat trong cot %d la: %d\n", k, maxElement);
    printf("Phan tu lon nhat trong cot %d la: %d\n", k, minElement);
}

// Hàm so sánh để sắp xếp tăng dần
int compareAsc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Hàm so sánh để sắp xếp giảm dần
int compareDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Hàm sắp xếp dòng trong ma trận
void sortMatrixRows(int matrix[MAXSIZE][MAXSIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            // Dòng chẵn: sắp xếp tăng dần
            qsort(matrix[i], cols, sizeof(int), compareAsc);
        } else {
            // Dòng lẻ: sắp xếp giảm dần
            qsort(matrix[i], cols, sizeof(int), compareDesc);
        }
    }
}

// Hàm sắp xếp cột trong ma trận
void sortMatrixColumns(int matrix[MAXSIZE][MAXSIZE], int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        int column[100]; // Mảng để lưu trữ phần tử của cột hiện tại

        // Lưu phần tử của cột vào mảng
        for (int i = 0; i < rows; i++) {
            column[i] = matrix[i][j];
        }

        // Sắp xếp mảng phần tử của cột
        if (j % 2 == 0) {
            // Cột chẵn: sắp xếp tăng dần
            qsort(column, rows, sizeof(int), compareAsc);
        } else {
            // Cột lẻ: sắp xếp giảm dần
            qsort(column, rows, sizeof(int), compareDesc);
        }

        // Ghi lại các phần tử đã sắp xếp vào cột của ma trận
        for (int i = 0; i < rows; i++) {
            matrix[i][j] = column[i];
        }
    }
}

// Hàm sắp xếp ma trận theo thứ tự zic-zac
void sortMatrixZigzag(int matrix[MAXSIZE][MAXSIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        // Duyệt qua các phần tử của hàng i
        if (i % 2 == 0) {
            // Hàng chẵn: sắp xếp tăng dần
            qsort(matrix[i], cols, sizeof(int), compareAsc);
        } else {
            // Hàng lẻ: sắp xếp giảm dần
            qsort(matrix[i], cols, sizeof(int), compareDesc);
        }
    }
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
	printf("\n---------------------------\n");
	sumElementsGreaterThanNextAbs(a,n,m);
	printf("\n---------------------------\n");
	int k;
	 // Nhập số dòng k
    printf("Nhap so dong k: ");
    scanf("%d", &k);

    // Kiểm tra nếu dòng k hợp lệ
	if (k >= 0 && k < n) {
        // Tính tổng giá trị trên dòng k của ma trận
		int result = sumRow(a, m, k);
        // In kết quả
        printf("Tong gia tri tren dong %d cua ma tran: %d\n", k, result);
    } else {
        printf("Dong k khong hop le.\n");
    }
	printf("\n---------------------------\n");
	sumBoundaryElements(a,n,m);
	printf("\n---------------------------\n");
	int x;
	// Nhập giá trị x cần đếm tần suất
    printf("Nhap gia tri x can dem tan suat: ");
    scanf("%d", &x);

    // Đếm tần suất xuất hiện của giá trị x trong ma trận
	int result = countOccurrences(a, n,m, x);

    // In kết quả
    printf("Tan suat xuat hien cua gia tri %d trong ma tran: %d\n", x, result);
	printf("\n---------------------------\n");
	int even, odd, negative, positive, prime;
	// Đếm các phần tử
    countElements(a, n, m, &even, &odd, &negative, &positive, &prime);

    // In kết quả
    printf("So luong so chan: %d\n", even);
    printf("So luong so le: %d\n", odd);
    printf("So luong so am: %d\n", negative);
    printf("So luong so duong: %d\n", positive);
    printf("So luong so nguyen to: %d\n", prime);
	printf("\n---------------------------\n");
	listColumnsWithMinSum(a,n,m);
	printf("\n---------------------------\n");
	listRowsWithMostPerfectNumbers(a,n,m);
	printf("\n---------------------------\n");
	listRowsWithAllEvenNumbers(a,n,m);
	printf("\n---------------------------\n");
	// Tìm giá trị xuất hiện nhiều nhất trong ma trận
    int mostFrequentValue = findMostFrequentValue(a, n, m);

    // In giá trị xuất hiện nhiều nhất
    printf("Gia tri xuat hien nhieu nhat trong ma tran là: %d\n", mostFrequentValue);
	printf("\n---------------------------\n");
	// Tìm số nguyên tố nhỏ nhất trong ma trận
    int smallestPrime = findSmallestPrime(a, n, m);

    // In số nguyên tố nhỏ nhất hoặc thông báo không có số nguyên tố
    if (smallestPrime == -1) {
        printf("Khong co so nguyen to trong ma tran.\n");
    } else {
        printf("So nguyen to nho nhat trong ma tran la: %d\n", smallestPrime);
    }
	printf("\n---------------------------\n");
	// Nhập chỉ số dòng k
	int k1;
    printf("Nhap chi so dong k: ");
    scanf("%d", &k1);

    // Tìm phần tử lớn nhất và nhỏ nhất trong dòng thứ k
    findMinMaxInRow(a, n, m, k1);
	printf("\n---------------------------\n");
	int k2;
	// Nhập chỉ số cột k
    printf("Nhap chi so cot k: ");
    scanf("%d", &k2);

    // Tìm phần tử lớn nhất và nhỏ nhất trong cột thứ k
    findMinMaxInColumn(a, n, m, k2);
	printf("\n---------------------------\n");
    // Sắp xếp các dòng của ma trận
	printf("KET QUA SAU KHI SAP XEP\n");
    sortMatrixRows(a, n, m);
	xuat_Mang2C(a,n,m);
	printf("\n---------------------------\n");
	// Sắp xếp các cột của ma trận
	printf("KET QUA SAU KHI SAP XEP THEO COT\n");
    sortMatrixColumns(a, n, m);
	xuat_Mang2C(a,n,m);
	printf("\n---------------------------\n");
	printf("KET QUA SAU KHI SAP XEP THEO ZIC-ZAC\n");
	 // Sắp xếp ma trận theo thứ tự zic-zac
    sortMatrixZigzag(a, n, m);
	xuat_Mang2C(a,n,m);
	getch();
	return 0;
}