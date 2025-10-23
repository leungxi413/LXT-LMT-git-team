#include <stdio.h>
#include <string.h>
#include "score_query.h"

/**
 * 函数名：query_by_student_id
 * 功能：根据学号查询学生信息
 * 参数：students - 学生数组
 *       count - 学生总数
 *       student_id - 要查询的学号
 * 返回值：找到则返回数组下标，未找到返回-1
 */
int query_by_student_id(Student students[], int count, char *student_id) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            return i;  // 找到学生，返回下标
        }
    }
    return -1;  // 未找到
}

/**
 * 函数名：query_by_name
 * 功能：根据姓名查询学生信息
 * 参数：students - 学生数组
 *       count - 学生总数
 *       name - 要查询的姓名
 * 返回值：找到则返回数组下标，未找到返回-1
 */
int query_by_name(Student students[], int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;  // 找到学生，返回下标
        }
    }
    return -1;  // 未找到
}

/**
 * 函数名：display_student_info
 * 功能：显示单个学生的详细信息
 * 参数：stu - 指向学生结构体的指针
 * 返回值：无
 */
void display_student_info(Student *stu) {
    printf("\n========== 学生信息 ==========\n");
    printf("姓名：%s\n", stu->name);
    printf("学号：%s\n", stu->student_id);
    printf("语文成绩：%.2f\n", stu->chinese);
    printf("数学成绩：%.2f\n", stu->math);
    printf("英语成绩：%.2f\n", stu->english);
    printf("总分：%.2f\n", stu->total);
    printf("平均分：%.2f\n", stu->average);
    printf("==============================\n");
}

/**
 * 函数名：display_all_students
 * 功能：显示所有学生的信息（表格形式）
 * 参数：students - 学生数组
 *       count - 学生总数
 * 返回值：无
 */
void display_all_students(Student students[], int count) {
    if (count == 0) {
        printf("\n暂无学生信息！\n");
        return;
    }
    
    printf("\n============================================ 所有学生成绩 ============================================\n");
    printf("%-10s %-15s %-10s %-10s %-10s %-10s %-10s\n", 
           "姓名", "学号", "语文", "数学", "英语", "总分", "平均分");
    printf("--------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-10s %-15s %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f\n",
               students[i].name,
               students[i].student_id,
               students[i].chinese,
               students[i].math,
               students[i].english,
               students[i].total,
               students[i].average);
    }
    printf("==================================================================================================\n");
}

