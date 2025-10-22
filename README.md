# LXT-LMT-git-team
第一个Git协作仓库的建立和项目实现
// 录入单个学生信息
void input_student_info(Student *stu) {
    printf("\n========== 录入学生信息 ==========\n");
    
    printf("请输入学生姓名：");
    scanf("%s", stu->name);
    
    printf("请输入学号：");
    scanf("%s", stu->student_id);
    
    printf("请输入语文成绩：");
    scanf("%f", &stu->chinese);
    
    printf("请输入数学成绩：");
    scanf("%f", &stu->math);
    
    printf("请输入英语成绩：");
    scanf("%f", &stu->english);
    
    stu->total = 0;
    stu->average = 0;
    
    printf("学生信息录入成功！\n");
}

// 批量录入学生信息
void input_multiple_students() {
    if (student_count >= MAX_STUDENTS) {
        printf("\n错误：学生数量已达上限（%d人）！\n", MAX_STUDENTS);
        return;
    }
    
    int num;
    printf("\n请输入要录入的学生人数：");
    scanf("%d", &num);
    
    if (student_count + num > MAX_STUDENTS) {
        printf("\n错误：超过最大学生数量限制！\n");
        return;
    }
    
    for (int i = 0; i < num; i++) {
        printf("\n--- 录入第 %d 个学生 ---\n", i + 1);
        input_student_info(&students[student_count]);
        student_count++;
    }
    
    printf("\n成功录入 %d 名学生信息！\n", num);
    printf("太优秀了");
}
