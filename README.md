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
