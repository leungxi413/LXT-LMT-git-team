
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
2. 在功能分支上开发，每完成一个小功能就提交一次
3. 功能开发完成后，向 `main` 分支发起 Pull Request
4. 经过代码审核后，由组长合并到 `main` 分支

## 系统功能模块划分

### 1. 学生信息录入模块（student_info）
**负责人**：mt  
**功能**：
- 接收用户输入的学生姓名
- 接收用户输入的学号
- 接收用户输入的各科成绩（语文、数学、英语）

### 2. 成绩计算模块（score_calculate）
**负责人**：xt  
**功能**：
- 计算学生总分
- 计算学生平均分
- 提供成绩统计功能

### 3. 成绩查询模块（score_query）
**负责人**：mt  
**功能**：
- 按学号查询学生成绩
- 按姓名查询学生成绩
- 显示学生详细信息

### 4. 数据存储模块（data_storage）
**负责人**：xt  
**功能**：
- 将学生数据保存到本地文件
- 从本地文件读取学生数据
- 数据持久化管理

## 代码文件结构

```
git-team-xt-mt/
├── README.md                   # 项目说明文档
├── src/                        # 源代码目录
│   ├── main.c                  # 主程序入口
│   ├── student_info.c          # 学生信息录入实现
│   ├── student_info.h          # 学生信息录入头文件
│   ├── score_calculate.c       # 成绩计算实现
│   ├── score_calculate.h       # 成绩计算头文件
│   ├── score_query.c           # 成绩查询实现
│   ├── score_query.h           # 成绩查询头文件
│   ├── data_storage.c          # 数据存储实现
│   └── data_storage.h          # 数据存储头文件
└── data/                       # 数据文件目录
    └── students.txt            # 学生数据存储文件
```

## 编译和运行

### 编译命令
```bash
gcc src/main.c src/student_info.c src/score_calculate.c src/score_query.c src/data_storage.c -o student_system
```

### 运行程序
```bash
./student_system        # Linux/Mac
student_system.exe      # Windows
```

## 开发进度

- [x] 项目框架搭建
- [ ] 学生信息录入模块
- [ ] 成绩计算模块
- [ ] 成绩查询模块
- [ ] 数据存储模块
- [ ] 系统集成测试

## Git协作流程

### 创建功能分支
```bash
git checkout -b feature-功能名
```

### 提交代码
```bash
git add .
git commit -m "清晰的提交说明"
git push origin feature-功能名
```

### 合并代码
1. 在GitHub上发起Pull Request
2. 组长审核代码
3. 解决冲突（如有）
4. 合并到main分支

## 注意事项
1. 每次开发前先 `git pull` 拉取最新代码
2. 提交信息要清晰明确，说明本次修改的内容
3. 遇到冲突及时沟通解决
4. 代码要有适当的注释
5.加入冲突内容解决

### 系统功能模块划分
1. **学生信息录入模块** (LMT负责)
   - 接收用户输入姓名、学号、各科成绩
   - 批量录入功能
   
2. **成绩计算模块** (LXT负责)  
   - 计算总分、平均分
   - 成绩等级评定
   
3. **成绩查询模块** (LMT负责)
   - 按学号查询
   - 按姓名查询
   
4. **数据存储模块** (LXT负责)
   - 内存数据管理
   - 文件持久化存储（待开发）

