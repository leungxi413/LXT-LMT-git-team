#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
学生成绩管理系统 - Python版本
开发团队：xt & mt
开发时间：2025-10-22
"""

import os
import json

class Student:
    """学生类"""
    def __init__(self, name="", student_id="", chinese=0.0, math=0.0, english=0.0):
        self.name = name
        self.student_id = student_id
        self.chinese = chinese
        self.math = math
        self.english = english
        self.total = 0.0
        self.average = 0.0
    
    def calculate_scores(self):
        """计算总分和平均分"""
        self.total = self.chinese + self.math + self.english
        self.average = self.total / 3.0
    
    def get_grade(self):
        """获取等级"""
        if self.average >= 90:
            return "优秀"
        elif self.average >= 80:
            return "良好"
        elif self.average >= 70:
            return "中等"
        elif self.average >= 60:
            return "及格"
        else:
            return "不及格"
    
    def to_dict(self):
        """转换为字典"""
        return {
            'name': self.name,
            'student_id': self.student_id,
            'chinese': self.chinese,
            'math': self.math,
            'english': self.english,
            'total': self.total,
            'average': self.average
        }
    
    @classmethod
    def from_dict(cls, data):
        """从字典创建学生对象"""
        student = cls(
            data['name'],
            data['student_id'],
            data['chinese'],
            data['math'],
            data['english']
        )
        student.total = data['total']
        student.average = data['average']
        return student


class StudentManagementSystem:
    """学生成绩管理系统"""
    
    def __init__(self):
        self.students = []
        self.data_file = "data/students.json"
        self.load_data()
    
    def display_menu(self):
        """显示主菜单"""
        os.system('cls' if os.name == 'nt' else 'clear')
        print("\n")
        print("****************************************")
        print("*                                      *")
        print("*      学生成绩管理系统 v1.0           *")
        print("*                                      *")
        print("*      开发团队：xt & mt               *")
        print("*                                      *")
        print("****************************************")
        print("\n========================================")
        print("          学生成绩管理系统              ")
        print("========================================")
        print("  1. 录入学生信息")
        print("  2. 计算成绩（总分/平均分）")
        print("  3. 查询学生信息")
        print("  4. 显示所有学生")
        print("  5. 保存数据到文件")
        print("  6. 从文件加载数据")
        print("  7. 退出系统")
        print("========================================")
        print(f"  当前学生数量：{len(self.students)}")
        print("========================================")
    
    def input_student_info(self):
        """录入学生信息"""
        print("\n========== 录入学生信息 ==========")
        try:
            name = input("请输入学生姓名：").strip()
            student_id = input("请输入学号：").strip()
            chinese = float(input("请输入语文成绩："))
            math = float(input("请输入数学成绩："))
            english = float(input("请输入英语成绩："))
            
            student = Student(name, student_id, chinese, math, english)
            student.calculate_scores()
            self.students.append(student)
            
            print("学生信息录入成功！")
            return True
        except ValueError:
            print("错误：成绩必须是数字！")
            return False
        except Exception as e:
            print(f"错误：{e}")
            return False
    
    def input_multiple_students(self):
        """批量录入学生信息"""
        try:
            num = int(input("\n请输入要录入的学生人数："))
            success_count = 0
            
            for i in range(num):
                print(f"\n--- 录入第 {i + 1} 个学生 ---")
                if self.input_student_info():
                    success_count += 1
            
            print(f"\n成功录入 {success_count} 名学生信息！")
        except ValueError:
            print("错误：请输入有效的数字！")
    
    def calculate_all_scores(self):
        """计算所有学生成绩"""
        if not self.students:
            print("\n提示：暂无学生数据！")
            return
        
        for student in self.students:
            student.calculate_scores()
        
        print(f"\n成功计算 {len(self.students)} 名学生的总分和平均分！")
    
    def query_student(self):
        """查询学生信息"""
        if not self.students:
            print("\n提示：暂无学生数据！")
            return
        
        print("\n========== 查询方式 ==========")
        print("1. 按学号查询")
        print("2. 按姓名查询")
        
        try:
            choice = int(input("请选择查询方式（1-2）："))
            
            if choice == 1:
                student_id = input("请输入学号：").strip()
                student = self.query_by_student_id(student_id)
            elif choice == 2:
                name = input("请输入姓名：").strip()
                student = self.query_by_name(name)
            else:
                print("\n输入错误！")
                return
            
            if student:
                self.display_student_info(student)
                self.display_score_statistics(student)
            else:
                print("\n未找到该学生！")
        except ValueError:
            print("错误：请输入有效的数字！")
    
    def query_by_student_id(self, student_id):
        """按学号查询"""
        for student in self.students:
            if student.student_id == student_id:
                return student
        return None
    
    def query_by_name(self, name):
        """按姓名查询"""
        for student in self.students:
            if student.name == name:
                return student
        return None
    
    def display_student_info(self, student):
        """显示学生信息"""
        print("\n========== 学生信息 ==========")
        print(f"姓名：{student.name}")
        print(f"学号：{student.student_id}")
        print(f"语文成绩：{student.chinese:.2f}")
        print(f"数学成绩：{student.math:.2f}")
        print(f"英语成绩：{student.english:.2f}")
        print(f"总分：{student.total:.2f}")
        print(f"平均分：{student.average:.2f}")
        print("==============================")
    
    def display_score_statistics(self, student):
        """显示成绩统计"""
        print(f"\n========== {student.name} 的成绩统计 ==========")
        print(f"学号：{student.student_id}")
        print("-----------------------------------")
        print(f"语文成绩：{student.chinese:.2f} 分")
        print(f"数学成绩：{student.math:.2f} 分")
        print(f"英语成绩：{student.english:.2f} 分")
        print("-----------------------------------")
        print(f"总分：{student.total:.2f} 分")
        print(f"平均分：{student.average:.2f} 分")
        print(f"等级：{student.get_grade()}")
        print("===================================")
    
    def display_all_students(self):
        """显示所有学生"""
        if not self.students:
            print("\n暂无学生信息！")
            return
        
        print("\n" + "="*100)
        print(" 所有学生成绩 ".center(100, "="))
        print("="*100)
        print(f"{'姓名':<10} {'学号':<15} {'语文':<10} {'数学':<10} {'英语':<10} {'总分':<10} {'平均分':<10} {'等级':<10}")
        print("-"*100)
        
        for student in self.students:
            print(f"{student.name:<10} {student.student_id:<15} "
                  f"{student.chinese:<10.2f} {student.math:<10.2f} {student.english:<10.2f} "
                  f"{student.total:<10.2f} {student.average:<10.2f} {student.get_grade():<10}")
        
        print("="*100)
    
    def save_data(self):
        """保存数据到文件"""
        if not self.students:
            print("\n提示：暂无数据需要保存！")
            return
        
        try:
            # 确保data目录存在
            os.makedirs(os.path.dirname(self.data_file), exist_ok=True)
            
            data = [student.to_dict() for student in self.students]
            with open(self.data_file, 'w', encoding='utf-8') as f:
                json.dump(data, f, ensure_ascii=False, indent=2)
            
            print(f"\n成功保存 {len(self.students)} 名学生的数据到文件 {self.data_file}")
        except Exception as e:
            print(f"错误：保存文件失败 - {e}")
    
    def load_data(self):
        """从文件加载数据"""
        try:
            if os.path.exists(self.data_file):
                with open(self.data_file, 'r', encoding='utf-8') as f:
                    data = json.load(f)
                    self.students = [Student.from_dict(item) for item in data]
                print(f"\n成功从文件 {self.data_file} 读取 {len(self.students)} 名学生的数据")
            else:
                print(f"提示：文件 {self.data_file} 不存在，将创建新文件")
        except Exception as e:
            print(f"提示：读取文件失败 - {e}")
            self.students = []
    
    def run(self):
        """运行系统"""
        while True:
            self.display_menu()
            
            try:
                choice = int(input("\n请选择功能（1-7）："))
                
                if choice == 1:
                    self.input_multiple_students()
                elif choice == 2:
                    self.calculate_all_scores()
                elif choice == 3:
                    self.query_student()
                elif choice == 4:
                    self.display_all_students()
                elif choice == 5:
                    self.save_data()
                elif choice == 6:
                    self.load_data()
                elif choice == 7:
                    print("\n感谢使用学生成绩管理系统！")
                    print("退出前自动保存数据...")
                    self.save_data()
                    break
                else:
                    print("\n输入错误！请输入1-7之间的数字。")
            except ValueError:
                print("\n输入错误！请输入有效的数字。")
            except KeyboardInterrupt:
                print("\n\n程序被中断，正在保存数据...")
                self.save_data()
                break
            except Exception as e:
                print(f"\n发生错误：{e}")
            
            input("\n按回车键继续...")


def main():
    """主函数"""
    system = StudentManagementSystem()
    system.run()


if __name__ == "__main__":
    main()


