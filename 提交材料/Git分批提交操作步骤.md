# Git分批提交操作步骤

## 📋 项目信息
- **项目名称：** 学生成绩管理系统
- **仓库名称：** git-team-xt-mt
- **组长：** xt（负责成绩计算、数据存储模块）
- **组员：** mt（负责学生信息录入、成绩查询模块）

---

## 📂 文件分工说明

### xt负责的文件（4个模块文件）
```
src/score_calculate.c      # 成绩计算实现
src/score_calculate.h      # 成绩计算头文件
src/data_storage.c         # 数据存储实现
src/data_storage.h         # 数据存储头文件
```

### mt负责的文件（4个模块文件）
```
src/student_info.c         # 学生信息录入实现
src/student_info.h         # 学生信息录入头文件
src/score_query.c          # 成绩查询实现
src/score_query.h          # 成绩查询头文件
```

### 共同文件（由xt作为组长整合）
```
src/main.c                 # 主程序
README.md                  # 项目文档
操作指南.md                # 操作指南
.gitignore                 # Git忽略文件
compile.bat                # 编译脚本
data/students.txt          # 数据文件
```

---

## 🚀 第一阶段：xt（组长）的操作步骤

### 步骤1：创建并切换到成绩计算分支
```bash
git checkout main
git pull origin main
git checkout -b feature-成绩计算
```

### 步骤2：提交成绩计算模块（第1次提交）
```bash
git add src/score_calculate.c
git add src/score_calculate.h
git commit -m "实现成绩计算模块：添加总分和平均分计算功能"
```

### 步骤3：优化成绩计算模块（第2次提交）
```bash
# 如果有修改，继续提交
git add src/score_calculate.c
git commit -m "添加成绩等级评定功能"
```

### 步骤4：推送成绩计算分支
```bash
git push origin feature-成绩计算
```

### 步骤5：在GitHub创建Pull Request
1. 访问GitHub仓库
2. 点击 "Pull requests" → "New pull request"
3. 选择 base: `main` ← compare: `feature-成绩计算`
4. 填写标题：`[feature-成绩计算] 成绩计算模块 - xt`
5. 填写描述：说明完成的功能
6. 点击 "Create pull request"

### 步骤6：切换到数据存储分支
```bash
git checkout main
git pull origin main
git checkout -b feature-数据存储
```

### 步骤7：提交数据存储模块（第1次提交）
```bash
git add src/data_storage.c
git add src/data_storage.h
git commit -m "实现学生数据保存到文件功能"
```

### 步骤8：完善数据存储模块（第2次提交）
```bash
git add src/data_storage.c
git commit -m "添加数据读取和追加功能"
```

### 步骤9：推送数据存储分支
```bash
git push origin feature-数据存储
```

### 步骤10：创建Pull Request（同步骤5）

---

## 🚀 第二阶段：mt（组员）的操作步骤

### 前置步骤：克隆仓库（如果还没有）
```bash
git clone https://github.com/你的用户名/git-team-xt-mt.git
cd git-team-xt-mt
```

### 步骤1：创建并切换到学生信息录入分支
```bash
git checkout main
git pull origin main
git checkout -b feature-学生信息录入
```

### 步骤2：提交学生信息录入模块（第1次提交）
```bash
git add src/student_info.c
git add src/student_info.h
git commit -m "实现学生姓名和学号录入功能"
```

### 步骤3：完善学生信息录入（第2次提交）
```bash
git add src/student_info.c
git commit -m "添加各科成绩录入和数据验证"
```

### 步骤4：推送学生信息录入分支
```bash
git push origin feature-学生信息录入
```

### 步骤5：在GitHub创建Pull Request
1. 访问GitHub仓库
2. 点击 "Pull requests" → "New pull request"
3. 选择 base: `main` ← compare: `feature-学生信息录入`
4. 填写标题：`[feature-学生信息录入] 学生信息录入模块 - mt`
5. 填写描述：说明完成的功能
6. 点击 "Create pull request"
7. **等待组长xt审核**

### 步骤6：切换到成绩查询分支
```bash
git checkout main
git pull origin main
git checkout -b feature-成绩查询
```

### 步骤7：提交成绩查询模块（第1次提交）
```bash
git add src/score_query.c
git add src/score_query.h
git commit -m "实现按学号查询学生功能"
```

### 步骤8：完善成绩查询模块（第2次提交）
```bash
git add src/score_query.c
git commit -m "添加按姓名查询和信息显示功能"
```

### 步骤9：推送成绩查询分支
```bash
git push origin feature-成绩查询
```

### 步骤10：创建Pull Request（同步骤5）

---

## ⚔️ 第三阶段：制造并解决冲突场景

### 场景设计：同时修改主函数的菜单显示

#### xt的操作（在本地）：
```bash
# 1. 切换到main分支
git checkout main
git pull origin main

# 2. 修改 src/main.c 的 display_menu() 函数
# 在菜单中添加：printf("  8. 统计班级平均分\n");

# 3. 提交并推送
git add src/main.c
git commit -m "在主菜单添加统计功能选项"
git push origin main
```

#### mt的操作（同时进行，不知道xt已推送）：
```bash
# 1. 在main分支（不要pull！）
git checkout main

# 2. 修改 src/main.c 的 display_menu() 函数
# 修改菜单样式或添加其他选项

# 3. 尝试提交并推送
git add src/main.c
git commit -m "优化主菜单显示样式"
git push origin main
# ❌ 这时会提示需要先pull
```

#### mt解决冲突：
```bash
# 1. 拉取最新代码（会产生冲突）
git pull origin main

# 2. 打开 src/main.c，会看到冲突标记：
<<<<<<< HEAD
（mt的修改）
=======
（xt的修改）
>>>>>>> 远程分支

# 3. 手动编辑文件，合并双方的修改
# 保留两人的修改，删除冲突标记

# 4. 解决后提交
git add src/main.c
git commit -m "解决主菜单修改冲突：合并统计功能和样式优化"
git push origin main
```

### 🔍 需要截图的地方：
1. ❗ 冲突提示信息（git pull时的错误）
2. 📝 带冲突标记的代码文件
3. ✅ 解决后的代码
4. 🎯 成功合并的提交记录（git log）

---

## 📊 第四阶段：xt（组长）审核和合并

### 步骤1：审核mt的Pull Request

1. 访问GitHub仓库的 "Pull requests" 页面
2. 点击mt提交的PR
3. 查看 "Files changed" 选项卡，检查代码
4. 如果有问题，在代码行上添加评论
5. 如果没问题，点击 "Review changes" → "Approve"

### 步骤2：合并PR到main分支

1. 在PR页面点击 "Merge pull request"
2. 选择合并方式（推荐：Squash and merge）
3. 填写合并提交信息
4. 点击 "Confirm merge"
5. 删除已合并的分支（可选）

### 步骤3：本地更新

```bash
git checkout main
git pull origin main
```

---

## 📦 提交材料清单

### 1. 代码文件
- [ ] 所有源代码文件（.c 和 .h）
- [ ] README.md
- [ ] 操作指南.md
- [ ] compile.bat
- [ ] .gitignore

### 2. Git操作截图
- [ ] 分支创建截图
- [ ] 提交记录截图（git log）
- [ ] 推送成功截图
- [ ] Pull Request创建截图
- [ ] 冲突提示截图
- [ ] 冲突代码截图
- [ ] 冲突解决后截图
- [ ] 成功合并截图
- [ ] GitHub仓库截图

### 3. 文档说明
- [ ] Git分批提交操作步骤.md（本文件）
- [ ] Git操作记录.md（记录每次操作的时间、命令、结果）

---

## ⚙️ 常用Git命令速查

### 查看状态
```bash
git status              # 查看当前状态
git branch              # 查看所有分支
git log --oneline       # 查看提交历史
```

### 分支操作
```bash
git branch 分支名        # 创建分支
git checkout 分支名      # 切换分支
git checkout -b 分支名   # 创建并切换分支
git branch -d 分支名     # 删除分支
```

### 提交操作
```bash
git add 文件名           # 添加文件到暂存区
git add .               # 添加所有文件
git commit -m "说明"    # 提交
git push origin 分支名   # 推送到远程
```

### 同步操作
```bash
git pull origin main    # 拉取远程最新代码
git fetch origin        # 获取远程更新
git merge 分支名         # 合并分支
```

### 冲突处理
```bash
git pull                # 拉取代码（可能出现冲突）
# 手动编辑冲突文件
git add 文件名           # 标记冲突已解决
git commit              # 提交合并
git push                # 推送
```

---

## ⚠️ 注意事项

### 1. 提交规范
- ✅ 提交信息要清晰明确
- ✅ 一次提交只做一件事
- ✅ 提交前先测试代码
- ✅ 不要提交编译生成的文件

### 2. 分支管理
- ✅ 每个功能使用独立分支
- ✅ 开发前先从main创建分支
- ✅ 功能完成后发起PR
- ✅ 合并后删除功能分支

### 3. 协作规范
- ✅ 开发前先 `git pull` 拉取最新代码
- ✅ 不要直接在main分支开发
- ✅ 发现冲突及时沟通
- ✅ 代码审核要认真负责

### 4. 冲突预防
- ✅ 避免同时修改同一文件
- ✅ 提交前先拉取最新代码
- ✅ 小步提交，频繁同步
- ✅ 做好任务分工

---

## 📞 遇到问题怎么办？

### 问题1：推送时提示需要先pull
**解决：**
```bash
git pull origin main
# 如果有冲突，解决后再推送
git push origin main
```

### 问题2：不知道当前在哪个分支
**解决：**
```bash
git branch  # 带*号的是当前分支
```

### 问题3：提交了不该提交的文件
**解决：**
```bash
git reset HEAD 文件名   # 取消暂存
git restore 文件名      # 恢复文件
```

### 问题4：PR被拒绝怎么办
**解决：**
1. 查看审核意见
2. 在原分支继续修改
3. 提交后自动更新PR
4. 等待重新审核

---

## 🎯 完成标准

### xt（组长）需要完成：
- [x] feature-成绩计算分支（至少2次提交）
- [x] feature-数据存储分支（至少2次提交）
- [x] 审核mt的所有PR
- [x] 解决至少1次分支冲突
- [x] 合并所有功能分支到main
- [x] 推送最终代码到GitHub

### mt（组员）需要完成：
- [x] feature-学生信息录入分支（至少2次提交）
- [x] feature-成绩查询分支（至少2次提交）
- [x] 发起至少2个Pull Request
- [x] 参与解决分支冲突
- [x] 代码通过组长审核

### 共同完成：
- [x] GitHub仓库完整代码
- [x] 完整的提交历史记录
- [x] 清晰的分支结构
- [x] 冲突解决的完整截图
- [x] 项目说明文档

---

## 📅 建议时间安排

| 阶段 | 负责人 | 时间 | 任务 |
|-----|-------|------|------|
| 第1天 | xt | 2小时 | 完成成绩计算模块 |
| 第1天 | xt | 2小时 | 完成数据存储模块 |
| 第2天 | mt | 2小时 | 完成学生信息录入模块 |
| 第2天 | mt | 2小时 | 完成成绩查询模块 |
| 第3天 | 双方 | 1小时 | 制造并解决冲突 |
| 第3天 | xt | 1小时 | 审核PR并合并 |
| 第4天 | 双方 | 1小时 | 整理提交材料 |

---

## ✅ 检查清单

完成后请逐一检查：

### 代码部分
- [ ] 所有模块都能正常编译
- [ ] 程序可以正常运行
- [ ] 代码有适当的注释
- [ ] 没有提交编译生成的文件

### Git操作部分
- [ ] 每个模块至少2次提交
- [ ] 提交信息清晰明确
- [ ] 至少2个Pull Request
- [ ] 成功解决1次冲突
- [ ] 所有分支已合并到main

### 文档部分
- [ ] README.md完整
- [ ] 操作指南详细
- [ ] 有完整的截图记录
- [ ] 提交材料整理完毕

---

祝顺利完成！🎉

如有问题，及时沟通解决！


