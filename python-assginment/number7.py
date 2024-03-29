class StudentGradeCalculator:
    grades_values = {
        'A': 4,
        'B': 3,
        'C': 2,
        'D': 1,
        'F': 0
    }
    student_name = ["John", "Tayitu", "Chaltu", "Mohammed", "kenny"]
    courses = {
        "Computing": ['A', 'A', 'A', 'B', 'C'],
        "Math": ['B', 'B', 'A', 'A', 'B'],
        "Physics": ['B', 'B', 'B', 'C', 'B'],
    }
    credit_hours = {
        "Computing": 3,
        "Math": 3,
        "Physics": 3,
    }

    def group_student_grade_using_tuple(self):
        student_grades = {}
        
        for index , student in enumerate(self.student_name):
            student_grades[student] = []
            
            for course in self.courses:
                student_grades[student].append((course ,self.courses[course][index]))
        print(" A. === Student Grades Grouped ===")
        for student in student_grades:
            print(f"{student} : {student_grades[student]}")
        print("\n\n")
        return student_grades

    def get_grade_point(self, grade):
            return self.grades_values.get(grade, 0)
    
    def calculate_student_gpa(self, grouped_student_grades):
        student_gpa = {}

        total_credit_hours = sum(self.credit_hours.values())

        for student_name, values in grouped_student_grades.items():
            total_grade_points = 0
            for course, grade in values:
                total_grade_points += self.get_grade_point(grade) * self.credit_hours[course]
                cgpa_of_student = total_grade_points / total_credit_hours
                # manage the floating values
                #  3.3333333333333335 to 3.33            
                cgpa_of_student = round(cgpa_of_student, 2)
                student_gpa[student_name] = cgpa_of_student       
    
        print(" B. === Student CGPA ===")
        for student in student_gpa:
            print(f"{student} : {student_gpa[student]}")

        return student_gpa

    def student_result_file_writer(self, cgpa_of_students):
        with open("student_cgpa.txt", "w") as file:
            for student, cgpa in cgpa_of_students.items():
                file.write(f"{student} : {cgpa}\n")
            
                           
if __name__ == "__main__":
    student_grade_calculator = StudentGradeCalculator()
    grouped_student_grade = student_grade_calculator.group_student_grade_using_tuple()
    # CGPA=(credit1*letter1_grade1+credit2*letter_grade2+ credit3*letter_grade3)/total_credit]
    cgpa_of_students = student_grade_calculator.calculate_student_gpa(grouped_student_grade)
    student_grade_calculator.student_result_file_writer(cgpa_of_students)   