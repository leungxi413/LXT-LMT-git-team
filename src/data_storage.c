#include <stdio.h>
#include <string.h>
#include "data_storage.h"

/**
 * 函数名：save_to_file
 * 功能：将所有学生数据保存到文件（覆盖模式）
 * 参数：students - 学生数组
 *       count - 学生总数
 *       filename - 文件名
 * 返回值：成功返回1，失败返回0
 */
int save_to_file(Student students[], int count, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("错误：无法打开文件 %s\n", filename);
        return 0;
    }
    
    // 写入学生数量
    fprintf(file, "%d\n", count);
    
    // 写入每个学生的数据
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %.2f %.2f %.2f %.2f %.2f\n",
                students[i].name,
                students[i].student_id,
                students[i].chinese,
                students[i].math,
                students[i].english,
                students[i].total,
                students[i].average);
    }
    
    fclose(file);
    printf("\n成功保存 %d 名学生的数据到文件 %s\n", count, filename);
    return 1;
}

/**
 * 函数名：load_from_file
 * 功能：从文件读取学生数据
 * 参数：students - 学生数组
 *       count - 指向学生总数的指针
 *       filename - 文件名
 * 返回值：成功返回1，失败返回0
 */
int load_from_file(Student students[], int *count, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("提示：文件 %s 不存在，将创建新文件\n", filename);
        *count = 0;
        return 0;
    }
    
    // 读取学生数量
    fscanf(file, "%d", count);
    
    // 读取每个学生的数据
    for (int i = 0; i < *count; i++) {
        fscanf(file, "%s %s %f %f %f %f %f",
               students[i].name,
               students[i].student_id,
               &students[i].chinese,
               &students[i].math,
               &students[i].english,
               &students[i].total,
               &students[i].average);
    }
    
    fclose(file);
    printf("\n成功从文件 %s 读取 %d 名学生的数据\n", filename, *count);
    return 1;
}

/**
 * 函数名：append_to_file
 * 功能：追加单个学生数据到文件末尾
 * 参数：stu - 指向学生结构体的指针
 *       filename - 文件名
 * 返回值：成功返回1，失败返回0
 */
int append_to_file(Student *stu, char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("错误：无法打开文件 %s\n", filename);
        return 0;
    }
    
    // 追加学生数据
    fprintf(file, "%s %s %.2f %.2f %.2f %.2f %.2f\n",
            stu->name,
            stu->student_id,
            stu->chinese,
            stu->math,
            stu->english,
            stu->total,
            stu->average);
    
    fclose(file);
    printf("\n成功追加学生 %s 的数据到文件\n", stu->name);
    return 1;
}

