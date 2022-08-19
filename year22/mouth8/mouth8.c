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

/**
 * https://leetcode.cn/problems/deepest-leaves-sum/
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int day18(struct TreeNode* root){

}

/**
 * https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/
 * 给你两个整数数组 startTime（开始时间）和 endTime（结束时间），并指定一个整数 queryTime 作为查询时间。

已知，第 i 名学生在 startTime[i] 时开始写作业并于 endTime[i] 时完成作业。

请返回在查询时间 queryTime 时正在做作业的学生人数。形式上，返回能够使 queryTime 处于区间 [startTime[i], endTime[i]]（含）的学生人数。
 * @return
 */
int day19(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime){
    int count = 0;
    for (int i = 0; i < startTimeSize; ++i) {
        if(startTime[i]<=queryTime){
            if(endTime[i]>=queryTime){
                count++;
            }
        }
    }
    return count;
}