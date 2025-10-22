/*
 * 成绩计算模块
 * 负责人：xt
 * 功能：计算总分、平均分和成绩统计
 * 开发时间：2025-10-22
 */

#include <stdio.h>
#include "score_calculate.h"

/**
 * 函数名：calculate_scores
 * 功能：计算单个学生的总分和平均分
 * 参数：stu - 指向学生结构体的指针
 * 返回值：无
 */
void calculate_scores(Student *stu) {
    // 计算总分
    stu->total = stu->chinese + stu->math + stu->english;
    
    // 计算平均分
    stu->average = stu->total / 3.0;
}

/**
 * 函数名：calculate_all_scores
 * 功能：计算所有学生的总分和平均分
 * 参数：students - 学生数组
 *       count - 学生总数
 * 返回值：无
 */
void calculate_all_scores(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        calculate_scores(&students[i]);
    }
    printf("\n成功计算 %d 名学生的总分和平均分！\n", count);
}

/**
 * 函数名：display_score_statistics
 * 功能：显示单个学生的成绩统计信息
 * 参数：stu - 指向学生结构体的指针
 * 返回值：无
 */
void display_score_statistics(Student *stu) {
    printf("\n========== %s 的成绩统计 ==========\n", stu->name);
    printf("学号：%s\n", stu->student_id);
    printf("-----------------------------------\n");
    printf("语文成绩：%.2f 分\n", stu->chinese);
    printf("数学成绩：%.2f 分\n", stu->math);
    printf("英语成绩：%.2f 分\n", stu->english);
    printf("-----------------------------------\n");
    printf("总分：%.2f 分\n", stu->total);
    printf("平均分：%.2f 分\n", stu->average);
    
    // 成绩等级评定
    if (stu->average >= 90) {
        printf("等级：优秀\n");
    } else if (stu->average >= 80) {
        printf("等级：良好\n");
    } else if (stu->average >= 70) {
        printf("等级：中等\n");
    } else if (stu->average >= 60) {
        printf("等级：及格\n");
    } else {
        printf("等级：不及格\n");
    }
    printf("===================================\n");
}

