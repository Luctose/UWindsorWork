from student import *

def main():
    # Here is a comment
    s1 = Student(1111, "Alice", 85.7, 35)
    s2 = Student(2222, "Bob", 90)
    s3 = Student(3333, "Cathy", 63, 40)
    gs1 = GradStudent(4444, "Charlie", 55.8, 40, 5)
    gs2 = GradStudent(5555, "Daisy", 74, 40)

    studentList = [s1, s2, s3, gs1, gs2]

    for student in studentList:
        print(student)

    studentList[0].del_Mark(74)
    studentList[1].del_Mark(74)
    # Here is another comment
    for student in studentList:
        print(student)
        student.add_Mark(65)

if __name__ == "__main__":
    main()