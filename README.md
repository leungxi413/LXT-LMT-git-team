# 学生成绩管理系统

## 项目简介
这是一个基于C语言开发的学生成绩管理系统，实现学生信息录入、成绩计算、成绩查询和数据存储等核心功能。

## 团队成员
- **组长**：（LXT）
- **组员**：（LMT）

## 分支规范

### 主分支
- `main`：主分支，存放稳定可运行的代码

### 功能分支
功能分支命名格式：`feature-具体功能名`

本项目使用的功能分支：
- `feature-学生信息录入`（mt负责）
- `feature-成绩查询`（mt负责）
- `feature-成绩计算`（xt负责）
- `feature-数据存储`（xt负责）

### 分支操作规范
1. 从 `main` 分支创建新的功能分支
2. 在功能分支上开发，每完成一个小功能就提交一次// 录入单个学生信息
3. 功能开发完成后，向 `main` 分支发起 Pull Request
4. 经过代码审核后，由组长合并到 `main` 分支

### 致谢


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



