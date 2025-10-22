# Git协作提交方案 - xt & mt

## 📋 分工明细

### 组长（xt）负责的模块：
- ✅ 成绩计算模块（`score_calculate.c/h`）
- ✅ 数据存储模块（`data_storage.c/h`）
- ✅ 主程序框架（`main.c`）
- ✅ 项目文档（`README.md`）

### 组员（mt）负责的模块：
- ✅ 学生信息录入模块（`student_info.c/h`）
- ✅ 成绩查询模块（`score_query.c/h`）

---

## 🎯 分批提交策略（推荐方案）

### 第一阶段：各自在功能分支开发

#### xt（组长）的操作：

**分支1：feature-成绩计算**
```bash
# 1. 创建并切换到成绩计算分支
git checkout -b feature-成绩计算

# 2. 添加成绩计算相关文件
git add src/score_calculate.c src/score_calculate.h

# 3. 第一次提交（基础功能）
git commit -m "添加成绩计算基础功能：计算总分和平均分"

# 4. 继续修改，添加更多功能
git add src/score_calculate.c

# 5. 第二次提交（扩展功能）
git commit -m "添加成绩等级评定功能"

# 6. 推送到远程
git push origin feature-成绩计算
```

**分支2：feature-数据存储**
```bash
# 1. 切换回main，创建新分支
git checkout main
git checkout -b feature-数据存储

# 2. 添加数据存储相关文件
git add src/data_storage.c src/data_storage.h

# 3. 第一次提交（保存功能）
git commit -m "实现学生数据保存到文件功能"

# 4. 继续开发
git add src/data_storage.c

# 5. 第二次提交（读取功能）
git commit -m "添加数据读取和追加功能"

# 6. 推送到远程
git push origin feature-数据存储
```

---

#### mt（组员）的操作：

**分支1：feature-学生信息录入**
```bash
# 1. 克隆仓库（如果还没克隆）
git clone https://github.com/你的用户名/git-team-xt-mt.git
cd git-team-xt-mt

# 2. 创建并切换到学生信息录入分支
git checkout -b feature-学生信息录入

# 3. 添加学生信息录入相关文件
git add src/student_info.c src/student_info.h

# 4. 第一次提交（姓名和学号录入）
git commit -m "实现学生姓名和学号录入功能"

# 5. 继续开发
git add src/student_info.c

# 6. 第二次提交（成绩录入）
git commit -m "添加各科成绩录入和数据验证"

# 7. 推送到远程
git push origin feature-学生信息录入
```

**分支2：feature-成绩查询**
```bash
# 1. 切换回main，创建新分支
git checkout main
git checkout -b feature-成绩查询

# 2. 添加成绩查询相关文件
git add src/score_query.c src/score_query.h

# 3. 第一次提交（学号查询）
git commit -m "实现按学号查询学生功能"

# 4. 继续开发
git add src/score_query.c

# 5. 第二次提交（姓名查询）
git commit -m "添加按姓名查询和信息显示功能"

# 6. 推送到远程
git push origin feature-成绩查询
```

---

## 🔥 制造冲突场景（重要！）

### 场景设计：同时修改主函数

**xt（组长）的操作：**
```bash
# 1. 在main分支上修改
git checkout main
git pull origin main

# 2. 修改 main.c 的菜单部分
# 添加一个新的菜单选项：8. 统计班级平均分

# 3. 提交并推送
git add src/main.c
git commit -m "在主菜单添加统计功能选项"
git push origin main
```

**mt（组员）的操作（同时进行）：**
```bash
# 1. 在本地main分支修改（故意不先pull）
git checkout main
# 不要执行 git pull！

# 2. 修改 main.c 的同一部分
# 修改菜单显示格式，美化界面

# 3. 提交
git add src/main.c
git commit -m "优化主菜单显示样式"

# 4. 尝试推送（会失败，因为远程有新的提交）
git push origin main
# 提示：Updates were rejected because the remote contains work...
```

**mt 解决冲突：**
```bash
# 1. 拉取远程最新代码
git pull origin main

# 此时会提示冲突：
# Auto-merging src/main.c
# CONFLICT (content): Merge conflict in src/main.c
# Automatic merge failed; fix conflicts and then commit the result.

# 2. 打开 src/main.c，会看到冲突标记：
# <<<<<<< HEAD
# （你的修改：美化的菜单格式）
# =======
# （远程的修改：添加的统计功能）
# >>>>>>> xxxxx

# 3. 手动编辑文件，保留两个人的修改
# 删除冲突标记，合并两个功能

# 4. 添加解决后的文件
git add src/main.c

# 5. 提交合并结果
git commit -m "解决主菜单修改冲突：合并统计功能和样式优化"

# 6. 推送
git push origin main
```

**📸 需要截图的地方：**
1. 冲突提示信息
2. 带冲突标记的代码
3. 解决后的代码
4. 成功合并的提交记录

---

## 📦 完整提交顺序（推荐）

### 时间线方案：

**第1天：项目初始化（xt）**
```bash
git checkout main
git add README.md .gitignore compile.bat
git commit -m "初始化项目：添加README和基础配置"
git push origin main
```

**第2天：xt开发成绩计算模块**
```bash
git checkout -b feature-成绩计算
git add src/score_calculate.c src/score_calculate.h
git commit -m "添加成绩计算基础功能"
# 继续开发...
git commit -m "完善成绩等级评定"
git push origin feature-成绩计算
```

**第3天：mt开发学生信息录入模块**
```bash
git checkout -b feature-学生信息录入
git add src/student_info.c src/student_info.h
git commit -m "实现学生信息录入功能"
# 继续开发...
git commit -m "添加批量录入功能"
git push origin feature-学生信息录入
```

**第4天：xt开发数据存储模块**
```bash
git checkout main
git checkout -b feature-数据存储
git add src/data_storage.c src/data_storage.h
git commit -m "实现数据保存功能"
git commit -m "添加数据读取功能"
git push origin feature-数据存储
```

**第5天：mt开发成绩查询模块**
```bash
git checkout main
git checkout -b feature-成绩查询
git add src/score_query.c src/score_query.h
git commit -m "实现按学号查询功能"
git commit -m "添加按姓名查询功能"
git push origin feature-成绩查询
```

**第6天：制造并解决冲突**
```bash
# xt 和 mt 同时修改 main.c
# 按照上面的冲突场景操作
```

**第7天：合并所有分支到main**
```bash
# xt（组长）操作
git checkout main
git merge feature-成绩计算
git merge feature-数据存储
git push origin main

# mt 发起PR，xt审核后合并
# 或者 xt 直接合并：
git merge feature-学生信息录入
git merge feature-成绩查询
git push origin main
```

---

## 🎯 当前状态的快速提交方案

既然您现在所有代码都已经完成，我建议这样操作：

### 方案A：模拟真实开发流程（推荐）

**步骤1：xt 提交成绩计算模块**
```bash
git checkout -b feature-成绩计算
git add src/score_calculate.c src/score_calculate.h
git commit -m "feat: 添加成绩计算功能

- 实现总分计算
- 实现平均分计算
- 添加成绩等级评定
- 负责人：xt"
git push origin feature-成绩计算
```

**步骤2：xt 提交数据存储模块**
```bash
git checkout main
git checkout -b feature-数据存储
git add src/data_storage.c src/data_storage.h data/students.txt
git commit -m "feat: 实现数据存储功能

- 添加保存数据到文件功能
- 添加从文件读取数据功能
- 添加数据追加和备份功能
- 负责人：xt"
git push origin feature-数据存储
```

**步骤3：mt 提交学生信息录入模块**
```bash
git checkout main
git checkout -b feature-学生信息录入
git add src/student_info.c src/student_info.h
git commit -m "feat: 实现学生信息录入功能

- 实现单个学生信息录入
- 实现批量学生信息录入
- 添加输入验证
- 负责人：mt"
git push origin feature-学生信息录入
```

**步骤4：mt 提交成绩查询模块**
```bash
git checkout main
git checkout -b feature-成绩查询
git add src/score_query.c src/score_query.h
git commit -m "feat: 实现成绩查询功能

- 实现按学号查询
- 实现按姓名查询
- 添加成绩展示功能
- 负责人：mt"
git push origin feature-成绩查询
```

**步骤5：xt 提交主程序和文档**
```bash
git checkout main
git add src/main.c README.md compile.bat .gitignore
git commit -m "feat: 完成主程序集成和项目文档

- 集成所有功能模块
- 完善README文档
- 添加编译脚本
- 团队：xt & mt"
git push origin main
```

**步骤6：添加辅助文件**
```bash
git checkout main
git add 操作指南.md 推送到GitHub的方法.md 安装编译器指南.md
git commit -m "docs: 添加项目文档和操作指南"

git add student_system.py student_system_online.c 运行程序.bat
git commit -m "feat: 添加Python版本和在线编译版本"

git add 演示程序.md 系统功能说明.md
git commit -m "docs: 添加使用演示和功能说明文档"

git push origin main
```

---

## 📊 Git提交记录示例

完成后，您的Git历史应该类似这样：

```
* docs: 添加使用演示和功能说明文档 (xt)
* feat: 添加Python版本和在线编译版本 (xt)
* docs: 添加项目文档和操作指南 (xt)
* feat: 完成主程序集成和项目文档 (xt)
* Merge branch 'feature-成绩查询' (mt)
* Merge branch 'feature-学生信息录入' (mt)
* Merge branch 'feature-数据存储' (xt)
* Merge branch 'feature-成绩计算' (xt)
* 解决主菜单修改冲突 (mt)
* feat: 实现成绩查询功能 (mt)
* feat: 实现学生信息录入功能 (mt)
* feat: 实现数据存储功能 (xt)
* feat: 添加成绩计算功能 (xt)
* 初始化项目 (xt)
```

---

## 💡 小贴士

1. **提交信息格式**：建议使用规范的提交信息
   - `feat:` 新功能
   - `fix:` 修复bug
   - `docs:` 文档更新
   - `style:` 代码格式调整

2. **每个分支至少2次提交**：满足作业要求

3. **保留所有分支**：方便展示协作过程

4. **截图保存**：冲突解决过程要截图

---

需要我帮您执行这些提交操作吗？我可以逐步帮您完成！😊

