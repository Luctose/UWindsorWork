# This is a class which is called student
class Student:
    # Constructor method, figure out the rest
    def __init__(self, studentID, name = "unknown", gpa = 0.0, courses = 0):
        self.studentID = studentID
        self.name = name
        self.gpa = gpa
        self.courses = courses
    
    def getCourses(self):
        return self.courses
    
    def add_Mark(self, x):
        if self.courses >= 40:
            print(f"{self.name} has 40 courses already included. Mark not added.")
            print(f"{self.name} new gpa: {self.gpa:.1f}")
            return self.gpa
        
        self.courses += 1
        self.gpa = (self.gpa * (self.courses - 1) + x) / self.courses
        print(f"{self.name} new gpa: {self.gpa:.1f}")
        return self.gpa
    
    def del_Mark(self, x):
        if self.courses <= 0:
            print(f"There are no course marks to delete for {self.name}!")
            print(f"{self.name} new gpa: {self.gpa:.1f}")
            return self.gpa
        
        self.courses -= 1
        self.gpa = (self.gpa * (self.courses + 1) - x) / self.courses
        print(f"{self.name} new gpa: {self.gpa:.1f}")
        return self.gpa
    
    def __str__(self):
        return f"{self.studentID}({self.name}): {self.gpa:.1f}"

class GradStudent(Student):
    def __init__(self, studentID, name, gpa, courses, _extra = 10):
        super().__init__(studentID, name, gpa, courses)
        self._extra = _extra
    
    def add_Mark(self, x):
        if self.courses >= 40 + self._extra:
            print(f"{self.name} has {40 + self._extra} courses already included. Mark not added.")
            print(f"{self.name} new gpa: {self.gpa:.1f}")
            return self.gpa
        elif self.courses < 40 + self._extra and self.courses >= 40:
            print(f"Warning for {self.name}: {self.courses - 40 + 1} extra courses added")

        self.courses += 1
        self.gpa = (self.gpa * (self.courses - 1) + x) / self.courses
        print(f"{self.name} new gpa: {self.gpa:.1f}")
        return self.gpa

def main():
    return 0

if __name__ == "__main__":
    main()