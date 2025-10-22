@echo off
chcp 65001 >nul
echo ========================================
echo   学生成绩管理系统 - 分批提交脚本
echo   开发团队：xt & mt
echo ========================================
echo.

echo [提示] 此脚本将按照团队分工分批提交代码
echo.
pause

REM 恢复暂存的更改
echo [步骤0] 恢复暂存的更改...
git stash pop
echo.

REM 切换到main分支
echo [步骤1] 切换到main分支...
git checkout main
if %errorlevel% neq 0 (
    echo 错误：切换分支失败！
    pause
    exit /b 1
)
echo.

REM ========================================
REM xt（组长）第1次提交：成绩计算模块
REM ========================================
echo ========================================
echo [xt - 第1次提交] 成绩计算模块
echo ========================================
git checkout -b feature-成绩计算
git add src/score_calculate.c src/score_calculate.h
git commit -m "feat: 添加成绩计算功能

- 实现总分计算功能
- 实现平均分计算功能
- 添加成绩等级评定（优秀/良好/中等/及格/不及格）
- 支持批量计算所有学生成绩
- 负责人：xt
- 模块：成绩计算（score_calculate）"
git push -u origin feature-成绩计算
echo.
pause

REM ========================================
REM xt（组长）第2次提交：数据存储模块
REM ========================================
echo ========================================
echo [xt - 第2次提交] 数据存储模块
echo ========================================
git checkout main
git checkout -b feature-数据存储
git add src/data_storage.c src/data_storage.h data/students.txt
git commit -m "feat: 实现数据存储功能

- 添加保存数据到文件功能（save_to_file）
- 添加从文件读取数据功能（load_from_file）
- 添加追加数据功能（append_to_file）
- 添加数据备份功能（backup_data）
- 负责人：xt
- 模块：数据存储（data_storage）"
git push -u origin feature-数据存储
echo.
pause

REM ========================================
REM mt（组员）第1次提交：学生信息录入模块
REM ========================================
echo ========================================
echo [mt - 第1次提交] 学生信息录入模块
echo ========================================
git checkout main
git checkout -b feature-学生信息录入
git add src/student_info.c src/student_info.h
git commit -m "feat: 实现学生信息录入功能

- 实现单个学生信息录入（input_student_info）
- 实现批量学生信息录入（input_multiple_students）
- 支持录入姓名、学号和三科成绩（语文、数学、英语）
- 添加输入验证和错误处理
- 负责人：mt
- 模块：学生信息录入（student_info）"
git push -u origin feature-学生信息录入
echo.
pause

REM ========================================
REM mt（组员）第2次提交：成绩查询模块
REM ========================================
echo ========================================
echo [mt - 第2次提交] 成绩查询模块
echo ========================================
git checkout main
git checkout -b feature-成绩查询
git add src/score_query.c src/score_query.h
git commit -m "feat: 实现成绩查询功能

- 实现按学号查询功能（query_by_student_id）
- 实现按姓名查询功能（query_by_name）
- 添加学生详细信息展示（display_student_info）
- 添加所有学生表格展示（display_all_students）
- 负责人：mt
- 模块：成绩查询（score_query）"
git push -u origin feature-成绩查询
echo.
pause

REM ========================================
REM xt（组长）第3次提交：主程序集成
REM ========================================
echo ========================================
echo [xt - 第3次提交] 主程序集成和项目文档
echo ========================================
git checkout main
git add src/main.c README.md compile.bat .gitignore
git commit -m "feat: 完成主程序集成和项目文档

- 集成所有功能模块到主程序
- 实现用户交互菜单
- 完善README项目文档
- 添加编译脚本和Git忽略配置
- 团队：xt & mt
- 模块：主程序（main）"
git push origin main
echo.
pause

REM ========================================
REM 添加辅助文档和工具
REM ========================================
echo ========================================
echo [文档提交] 添加项目文档和操作指南
echo ========================================
git add 操作指南.md 推送到GitHub的方法.md 安装编译器指南.md Git协作提交方案.md
git commit -m "docs: 添加项目文档和操作指南

- 添加详细操作指南
- 添加GitHub推送教程
- 添加编译器安装指南
- 添加Git协作提交方案"
git push origin main
echo.

echo ========================================
echo [功能扩展] 添加Python版本和演示工具
echo ========================================
git add student_system.py student_system_online.c 运行程序.bat 分批提交脚本.bat
git commit -m "feat: 添加Python版本和在线编译版本

- 添加Python完整实现版本（student_system.py）
- 添加在线编译单文件版本（student_system_online.c）
- 添加一键运行脚本（运行程序.bat）
- 添加分批提交脚本（分批提交脚本.bat）"
git push origin main
echo.

echo ========================================
echo [文档完善] 添加演示和功能说明文档
echo ========================================
git add 演示程序.md 系统功能说明.md
git commit -m "docs: 添加使用演示和功能说明文档

- 添加详细的使用演示教程
- 添加完整的系统功能说明
- 包含示例数据和操作截图说明"
git push origin main
echo.

REM ========================================
REM 完成提示
REM ========================================
echo ========================================
echo   ✅ 所有提交完成！
echo ========================================
echo.
echo 提交记录：
echo   ✅ xt - feature-成绩计算
echo   ✅ xt - feature-数据存储
echo   ✅ mt - feature-学生信息录入
echo   ✅ mt - feature-成绩查询
echo   ✅ xt - 主程序集成
echo   ✅ 项目文档和辅助工具
echo.
echo 下一步操作：
echo   1. 在GitHub上合并功能分支的Pull Request
echo   2. 或使用 git merge 命令合并分支到main
echo.
pause

