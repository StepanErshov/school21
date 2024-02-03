#include <stdio.h>

#define LEN 100

int input(int *a, int *n);
void output(int *a, int *b, int len1, int len2);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main() {
    int n, m, len1, len2;
    int arr1[LEN], arr2[LEN], res1[LEN + 1], res2[LEN + 1];
    int check1 = input(arr1, &n);
    int check2 = input(arr2, &m);
    if (check1 || check2) {
        printf("n/a");
        return 1;
    }
    len1 = ((n >= m) ? n : m);
    if (n == LEN || m == LEN) {
        len1 = LEN + 1;
    }

    sum(arr1, n, arr2, m, res1, &len1);

    len2 = ((n >= m) ? n : -1);
    if (len2 == (-1)) {
        printf("n/a");
        return 1;
    }
    sub(arr1, n, arr2, m, res2, &len2);
    if (len2 == (-1)) {
        printf("n/a");
        return 1;
    }
    output(res1, res2, len1, len2);
}

int input(int *a, int *n) {
    int check = 0, len = 0;
    char ch = ' ';
    for (int *p = a; p - a < LEN; p++) {
        int count = scanf("%d%c", p, &ch);
        len++;
        if (count == 2 && (p - a == LEN - 1) && ch != '\n') {
            check = 1;
        }
        if (count == 2 && ch != ' ' && ch != '\n') {
            check = 1;
        }
        if (count != 2 || *p >= 10 || *p < 0) {
            check = 1;
        }
        if (ch == '\n') {
            break;
        }
    }
    *n = len;
    return check;
}
void output(int *a, int *b, int len1, int len2) {
    int flag = 0;
    for (int *p = a; p - a < len1; p++) {
        if (*p != 0) {
            flag = 1;
        }
        if (flag == 1) {
            (p - a == len1 - 1) ? printf("%d\n", *p) : printf("%d ", *p);
        }
    }
    if (flag == 0) {
        printf("0\n");
    }
    flag = 0;
    for (int *c = b; c - b < len2; c++) {
        if (*c != 0) {
            flag = 1;
        }
        if (flag == 1) {
            (c - b == len2 - 1) ? printf("%d", *c) : printf("%d ", *c);
        }
    }
    if (flag == 0) {
        printf("0");
    }
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int x1 = len1 - 1;
    int x2 = len2 - 1, ost = 0, val;
    int res = *result_length - 1;
    while (x1 >= 0 || x2 >= 0) {
        if (x1 >= x2 && x2 < 0) {
            result[res] = buff1[x1];
        } else if (x1 <= x2 && x1 < 0) {
            result[res] = buff2[x2];
        } else {
            val = buff1[x1] + buff2[x2];
            result[res] = (buff1[x1] + buff2[x2] + ost) % 10;
            ost = (val >= 10) ? 1 : 0;
        }
        x1--;
        x2--;
        res--;
    }
    if (*result_length == LEN + 1 && ost) {
        result[0] = 1;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int x1 = len1 - 1, y, x;
    int x2 = len2 - 1, ost = 0, flag;
    int res = *result_length - 1;
    while (x1 >= 0 || x2 >= 0) {
        y = (x2 >= 0) ? buff2[x2] : 0;
        x = buff1[x1];
        flag = (x >= y) ? 0 : 10;
        result[res] = x + flag - y - ost;
        ost = flag ? 1 : 0;
        if (result[res] < 0) {
            *result_length = -1;
        }
        x1--;
        x2--;
        res--;
        if (x1 < 0 && y > x) {
            *result_length = -1;
        }
    }
}

