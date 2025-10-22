/*
 * 数据存储模块
 * 负责人：xt
 * 功能：学生数据的保存、读取和持久化管理
 */

#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include "student_info.h"

// 函数声明：保存学生数据到文件
int save_to_file(Student students[], int count, char *filename);

// 函数声明：从文件读取学生数据
int load_from_file(Student students[], int *count, char *filename);

// 函数声明：追加学生数据到文件
int append_to_file(Student *stu, char *filename);

// 函数声明：备份学生数据
int backup_data(Student students[], int count, char *backup_filename);

#endif


