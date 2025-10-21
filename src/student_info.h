#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

// 学生信息结构体定义
typedef struct {
    char name[50];          // 学生姓名
    char student_id[20];    // 学号
    float chinese;          // 语文成绩
    float math;             // 数学成绩
    float english;          // 英语成绩
    float total;            // 总分
    float average;          // 平均分
} Student;

// 函数声明：录入单个学生信息
void input_student_info(Student *stu);

// 函数声明：批量录入学生信息
void input_multiple_students(Student students[], int *count);

#endif

