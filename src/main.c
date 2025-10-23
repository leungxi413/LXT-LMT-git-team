#include <stdio.h>
#include <stdlib.h>
#include "student_info.h"
#include "score_calculate.h"
#include "score_query.h"
#include "data_storage.h"

#define MAX_STUDENTS 100
#define DATA_FILE "../data/students.txt"

// 全局变量
Student students[MAX_STUDENTS];  // 学生数组
int student_count = 0;           // 当前学生数量

// 函数声明
void display_menu();
void add_student();
void calculate_all();
void query_student();
void show_all_students();
void save_data();
void load_data();

/**
 * 主函数
 */
int main() {
    int choice;
    
    printf("\n");
    printf("****************************************\n");
    printf("*                                      *\n");
    printf("*      学生成绩管理系统 v1.0           *\n");
    printf("*                                      *\n");
    printf("*      开发团队：LXT & LMT             *\n");
    printf("*                                      *\n");
    printf("****************************************\n");
    
    // 启动时自动加载数据
    load_data();
    
    while (1) {
        display_menu();
        printf("\n请选择功能（1-7）：");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                calculate_all();
                break;
            case 3:
                query_student();
                break;
            case 4:
                show_all_students();
                break;
            case 5:
                save_data();
                break;
            case 6:
                load_data();
                break;
            case 7:
                printf("\n感谢使用学生成绩管理系统！\n");
                printf("退出前自动保存数据...\n");
                save_data();
                exit(0);
            default:
                printf("\n输入错误！请输入1-7之间的数字。\n");
        }
        
        printf("\n按回车键继续...");
        getchar();
        getchar();
    }
    
    return 0;
}

/**
 * 显示主菜单
 */
void display_menu() {
    printf("\n");
    printf("========================================\n");
    printf("          学生成绩管理系统              \n");
    printf("========================================\n");
    printf("  1. 录入学生信息\n");
    printf("  2. 计算成绩（总分/平均分）\n");
    printf("  3. 查询学生信息\n");
    printf("  4. 显示所有学生\n");
    printf("  5. 保存数据到文件\n");
    printf("  6. 从文件加载数据\n");
    printf("  7. 退出系统\n");
    printf("========================================\n");
    printf("  当前学生数量：%d\n", student_count);
    printf("========================================\n");
}

/**
 * 录入学生信息
 */
void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("\n错误：学生数量已达上限（%d人）！\n", MAX_STUDENTS);
        return;
    }
    
    input_multiple_students(students, &student_count);
    
    // 录入后自动计算成绩
    calculate_all_scores(students, student_count);
}

/**
 * 计算所有学生成绩
 */
void calculate_all() {
    if (student_count == 0) {
        printf("\n提示：暂无学生数据！\n");
        return;
    }
    
    calculate_all_scores(students, student_count);
}

/**
 * 查询学生信息
 */
void query_student() {
    if (student_count == 0) {
        printf("\n提示：暂无学生数据！\n");
        return;
    }
    
    int choice;
    printf("\n========== 查询方式 ==========\n");
    printf("1. 按学号查询\n");
    printf("2. 按姓名查询\n");
    printf("请选择查询方式（1-2）：");
    scanf("%d", &choice);
    
    int index = -1;
    
    if (choice == 1) {
        char student_id[20];
        printf("请输入学号：");
        scanf("%s", student_id);
        index = query_by_student_id(students, student_count, student_id);
    } else if (choice == 2) {
        char name[50];
        printf("请输入姓名：");
        scanf("%s", name);
        index = query_by_name(students, student_count, name);
    } else {
        printf("\n输入错误！\n");
        return;
    }
    
    if (index != -1) {
        display_student_info(&students[index]);
        display_score_statistics(&students[index]);
    } else {
        printf("\n未找到该学生！\n");
    }
}

/**
 * 显示所有学生信息
 */
void show_all_students() {
    display_all_students(students, student_count);
}

/**
 * 保存数据到文件
 */
void save_data() {
    if (student_count == 0) {
        printf("\n提示：暂无数据需要保存！\n");
        return;
    }
    
    save_to_file(students, student_count, DATA_FILE);
}

/**
 * 从文件加载数据
 */
void load_data() {
    load_from_file(students, &student_count, DATA_FILE);
}

