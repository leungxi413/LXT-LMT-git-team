#ifndef SCORE_CALCULATE_H
#define SCORE_CALCULATE_H

#include "student_info.h"

// 函数声明：计算单个学生的总分和平均分
void calculate_scores(Student *stu);

// 函数声明：计算所有学生的总分和平均分
void calculate_all_scores(Student students[], int count);

// 函数声明：显示单个学生的成绩统计
void display_score_statistics(Student *stu);

#endif

