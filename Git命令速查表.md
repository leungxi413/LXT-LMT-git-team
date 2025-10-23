# Git命令速查表

## 🚀 常用Git命令（按使用频率排序）

### 📦 基础操作

```bash
# 克隆仓库
git clone https://github.com/用户名/仓库名.git

# 查看当前状态
git status

# 查看所有分支
git branch

# 查看远程仓库
git remote -v

# 查看提交历史
git log
git log --oneline  # 简洁版
git log --graph --oneline --all  # 图形化显示
```

### 🌿 分支操作

```bash
# 创建新分支
git branch 分支名

# 切换分支
git checkout 分支名

# 创建并切换到新分支（推荐）
git checkout -b 分支名

# 删除本地分支
git branch -d 分支名      # 安全删除
git branch -D 分支名      # 强制删除

# 删除远程分支
git push origin --delete 分支名

# 查看当前分支
git branch
```

### 💾 提交操作

```bash
# 添加文件到暂存区
git add 文件名           # 添加单个文件
git add .               # 添加所有修改
git add src/            # 添加整个目录

# 提交
git commit -m "提交说明"

# 修改最后一次提交
git commit --amend -m "新的提交说明"

# 查看修改内容
git diff                # 查看未暂存的修改
git diff --staged       # 查看已暂存的修改
```

### 🔄 同步操作

```bash
# 拉取远程更新
git pull origin main
git pull origin 分支名

# 推送到远程
git push origin main
git push origin 分支名

# 推送新分支到远程
git push -u origin 分支名

# 获取远程更新但不合并
git fetch origin
```

### 🔀 合并操作

```bash
# 合并指定分支到当前分支
git merge 分支名

# 取消合并
git merge --abort

# 查看合并冲突的文件
git status
```

## ⚔️ 冲突解决流程

### 步骤1：发现冲突
```bash
git merge feature-xxx
# 输出：CONFLICT (content): Merge conflict in xxx.c
```

### 步骤2：查看冲突文件
```bash
git status
# 显示：both modified: xxx.c
```

### 步骤3：打开文件查看冲突标记
```c
<<<<<<< HEAD
// 当前分支的代码
=======
// 要合并的分支的代码
>>>>>>> 分支名
```

### 步骤4：手动解决冲突
- 删除冲突标记（`<<<<<<<`、`=======`、`>>>>>>>`）
- 保留需要的代码或综合双方改动

### 步骤5：标记为已解决
```bash
git add 文件名
```

### 步骤6：提交合并
```bash
git commit -m "解决冲突：具体说明"
```

### 步骤7：推送
```bash
git push origin main
```

## 📋 阶段二专用命令流程

### 组长：创建仓库并开发

```bash
# 1. 克隆仓库
git clone https://github.com/你的用户名/git-team-LXT-LMT.git
cd git-team-LXT-LMT

# 2. 创建项目结构
mkdir src data docs
git add .
git commit -m "初始化项目结构"
git push origin main

# 3. 开发成绩计算模块
git checkout -b feature-成绩计算
# ... 编写代码 ...
git add src/score_calculate.c
git commit -m "实现成绩计算功能"
git push origin feature-成绩计算

# 4. 合并到main
git checkout main
git merge feature-成绩计算
git push origin main

# 5. 开发数据存储模块（重复步骤3-4）
```

### 组员：克隆仓库并开发

```bash
# 1. 克隆仓库
git clone https://github.com/组长用户名/git-team-LXT-LMT.git
cd git-team-LXT-LMT

# 2. 开发学生信息录入模块
git checkout -b feature-学生信息录入
# ... 编写代码 ...
git add src/student_info.c
git commit -m "实现学生信息录入：基础功能"
git push origin feature-学生信息录入

# 3. 继续完善（第二次提交）
# ... 继续编写 ...
git add src/student_info.c
git commit -m "完善学生信息录入：添加验证"
git push origin feature-学生信息录入

# 4. 在GitHub上创建Pull Request，等待组长审核

# 5. 开发成绩查询模块
git checkout main
git pull origin main  # 先拉取最新代码
git checkout -b feature-成绩查询
# ... 重复步骤2-4 ...
```

### 制造并解决冲突

```bash
# 组长：先修改main.c并合并到main
git checkout main
git checkout -b feature-优化菜单
# 修改 src/main.c 的 showMenu()
git add src/main.c
git commit -m "优化菜单显示（组长版本）"
git checkout main
git merge feature-优化菜单
git push origin main

# 组员：基于旧版本修改同一个地方
git checkout main
# 不要pull！使用旧版本
git checkout -b feature-美化菜单
# 修改 src/main.c 的 showMenu()（不同的改法）
git add src/main.c
git commit -m "美化菜单显示（组员版本）"

# 尝试合并到main（会产生冲突）
git checkout main
git pull origin main  # 拉取组长的修改
git merge feature-美化菜单  # 产生冲突！

# 解决冲突
# 1. 打开 src/main.c，手动修改
# 2. 删除冲突标记
# 3. 综合双方改动
git add src/main.c
git commit -m "解决冲突：综合双方的菜单改进"
git push origin main
```

## 🆘 常见问题解决

### 问题1：忘记切换分支就开始修改了

```bash
# 保存当前修改
git stash

# 切换到正确的分支
git checkout 正确的分支名

# 恢复修改
git stash pop
```

### 问题2：提交了不想提交的文件

```bash
# 撤销最后一次提交，但保留修改
git reset --soft HEAD~1

# 或者：修改提交（添加/删除文件后）
git add 遗漏的文件
git commit --amend
```

### 问题3：想撤销某个文件的修改

```bash
# 撤销未暂存的修改
git checkout -- 文件名

# 取消暂存
git reset HEAD 文件名
```

### 问题4：推送被拒绝（远程有更新）

```bash
# 先拉取远程更新
git pull origin main

# 如果有冲突，解决冲突后再推送
git push origin main
```

### 问题5：不小心合并错了

```bash
# 取消合并（还未提交）
git merge --abort

# 已经提交了
git reset --hard HEAD~1  # 危险！会丢失修改
```

## 📝 提交信息规范

### 好的提交信息示例

```bash
git commit -m "实现学生信息录入功能"
git commit -m "修复：成绩计算结果精度问题"
git commit -m "优化：改进查询功能的性能"
git commit -m "文档：更新README的使用说明"
git commit -m "重构：简化数据存储模块代码结构"
```

### 提交信息模板

```
[类型] 简短描述（不超过50字）

详细说明（可选）：
- 为什么做这个修改
- 修改了什么内容
- 有什么注意事项

相关文件：
- src/xxx.c
- src/xxx.h
```

### 提交类型

- **功能**：新增功能
- **修复**：修复bug
- **优化**：性能优化
- **重构**：代码重构
- **文档**：文档更新
- **测试**：测试相关
- **样式**：代码格式调整

## 🎯 阶段二任务快速检查

### 组长检查清单

```bash
# 检查仓库是否创建
# 访问 https://github.com/你的用户名/git-team-LXT-LMT

# 检查协作者是否添加
# Settings → Collaborators

# 检查分支
git branch -a  # 应该看到 main 和各个 feature 分支

# 检查提交记录
git log --oneline --graph --all

# 检查每个功能分支的提交次数
git log feature-成绩计算 --oneline | wc -l  # 应该 >= 2
git log feature-数据存储 --oneline | wc -l  # 应该 >= 2
```

### 组员检查清单

```bash
# 检查是否成为协作者
# 访问仓库应该有写入权限

# 检查本地分支
git branch  # 应该有 feature-学生信息录入 和 feature-成绩查询

# 检查提交记录
git log feature-学生信息录入 --oneline | wc -l  # 应该 >= 2
git log feature-成绩查询 --oneline | wc -l      # 应该 >= 2

# 检查是否创建了PR
# 访问 GitHub 仓库 → Pull requests 标签
```

### 冲突检查清单

- [ ] 是否制造了冲突（同时修改同一文件同一位置）
- [ ] 是否使用 git merge 触发了冲突
- [ ] 是否截图了冲突标记
- [ ] 是否手动解决了冲突
- [ ] 是否使用 git add 标记已解决
- [ ] 是否提交了合并结果
- [ ] 是否记录了完整过程

## 💡 实用技巧

### 1. 美化Git日志显示

```bash
# 添加到 ~/.gitconfig
git config --global alias.lg "log --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"

# 使用
git lg
```

### 2. 快速查看文件修改历史

```bash
# 查看某个文件的修改历史
git log -p 文件名

# 查看某个文件每次提交的统计
git log --stat 文件名
```

### 3. 查找特定内容的提交

```bash
# 查找包含特定字符串的提交
git log --grep="关键字"

# 查找修改了特定代码的提交
git log -S"函数名"
```

### 4. 比较两个分支的差异

```bash
# 查看两个分支的文件差异
git diff main feature-xxx

# 只显示文件名
git diff --name-only main feature-xxx
```

---

**打印此文档，随时查阅！** 📖

记住：**实践是最好的老师**，多用几次就熟练了！

