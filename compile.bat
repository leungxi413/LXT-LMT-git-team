@echo off
echo ========================================
echo    编译学生成绩管理系统
echo ========================================
echo.

gcc src/main.c src/student_info.c src/score_calculate.c src/score_query.c src/data_storage.c -o student_system.exe

if %errorlevel% == 0 (
    echo.
    echo ========================================
    echo    编译成功！
    echo ========================================
    echo.
    echo 运行程序: student_system.exe
    echo.
) else (
    echo.
    echo ========================================
    echo    编译失败！请检查错误信息
    echo ========================================
)

pause

