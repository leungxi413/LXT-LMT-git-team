#ifndef SCORE_QUERY_H
#define SCORE_QUERY_H

#include "student_info.h"

// 函数声明：按学号查询学生
int query_by_student_id(Student students[], int count, char *student_id);

// 函数声明：按姓名查询学生
int query_by_name(Student students[], int count, char *name);

// 函数声明：显示学生详细信息
void display_student_info(Student *stu);

// 函数声明：显示所有学生信息
void display_all_students(Student students[], int count);

#endif

