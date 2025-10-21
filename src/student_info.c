#include <stdio.h>
#include <string.h>
#include "student_info.h"

/**
 * 函数名：input_student_info
 * 功能：录入单个学生的基本信息和成绩
 * 参数：stu - 指向学生结构体的指针
 * 返回值：无
 */
void input_student_info(Student *stu) {
    printf("\n========== 录入学生信息 ==========\n");
    
    // 录入学生姓名
    printf("请输入学生姓名：");
    scanf("%s", stu->name);
    
    // 录入学号
    printf("请输入学号：");
    scanf("%s", stu->student_id);
    
    // 录入语文成绩
    printf("请输入语文成绩：");
    scanf("%f", &stu->chinese);
    
    // 录入数学成绩
    printf("请输入数学成绩：");
    scanf("%f", &stu->math);
    
    // 录入英语成绩
    printf("请输入英语成绩：");
    scanf("%f", &stu->english);
    
    // 初始化总分和平均分（后续由成绩计算模块计算）
    stu->total = 0;
    stu->average = 0;
    
    printf("学生信息录入成功！\n");
}

/**
 * 函数名：input_multiple_students
 * 功能：批量录入多个学生的信息
 * 参数：students - 学生数组
 *       count - 指向学生数量的指针
 * 返回值：无
 */
void input_multiple_students(Student students[], int *count) {
    int num;
    printf("\n请输入要录入的学生人数：");
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++) {
        printf("\n--- 录入第 %d 个学生 ---\n", i + 1);
        input_student_info(&students[*count]);
        (*count)++;
    }
    
    printf("\n成功录入 %d 名学生信息！\n", num);
}

