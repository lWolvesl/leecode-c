//
// Created by wolves on 2022/8/14.
//

#include "string.h"
#include "stdio.h"

/**
 * 给你一个由若干 0 和 1 组成的字符串 s ，请你计算并返回将该字符串分割成两个 非空 子字符串（即 左 子字符串和 右 子字符串）所能获得的最大得分。

「分割字符串的得分」为 左 子字符串中 0 的数量加上 右 子字符串中 1 的数量。
 * @return max
 */
int day14(char *s) {
    int max = 0;
    int index = 0;
    int length = strlen(s);
    while (index < length - 1) {
        int pear = 0;
        int rear = 0;
        for (int i = 0; i <= index; i++) {
            if (s[i] == '0') {
                pear++;
            }
        }
        for (int i = index + 1; i < length; i++) {
            if (s[i] == '1') {
                rear++;
            }
        }
        ++index;
        max = max < pear + rear ? pear + rear : max;
    }
    return max;
}

void day14Run() {
    char *a = "00";
    printf("%d\n", day14(a));
}