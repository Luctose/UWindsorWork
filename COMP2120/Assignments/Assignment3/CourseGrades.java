/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

import java.util.ArrayList;

public class CourseGrades implements Analyzable{
    // Fields
    private ArrayList<GradedActivity> grades;

    // Methods
    public CourseGrades(){
        grades = new ArrayList<GradedActivity>();
        for(int i = 0; i < 4; i++){
            grades.add(new GradedActivity());
        }
    }

    public void setLab(GradedActivity gr){
        grades.set(0, gr);
    }

    public void setPassFailExam(PassFailExam gr){
        grades.set(1, gr);
    }

    public void setEssay(GradedActivity gr){
        grades.set(2, gr);
    }

    public void setFinalExam(FinalExam gr){
        grades.set(3, gr);
    }

    public String toString(){
        return String.format("Lab Score: %.1f   Grade: %c\n", grades.get(0).getScore(), grades.get(0).getGrade())
        +      String.format("Pass/Fail Exam Score: %.1f   Grade: %c\n", grades.get(1).getScore(), grades.get(1).getGrade())
        +      String.format("Essay Score: %.1f   Grade: %c\n", grades.get(2).getScore(), grades.get(2).getGrade())
        +      String.format("Final Exam Score: %.1f   Grade: %c\n", grades.get(3).getScore(), grades.get(3).getGrade());
    }

    public double getAverage(){
        double sum = 0;
        for(int i = 0; i < grades.size(); i++){
            sum += grades.get(i).getScore();
        }
        return sum / grades.size();
    }

    public GradedActivity getHighest(){
        double highest = Double.MIN_VALUE;
        int index = 0;
        for(int i = 0; i < grades.size(); i++){
            if(highest < grades.get(i).getScore()){
                highest = grades.get(i).getScore();
                index = i;
            }
        }
        return grades.get(index);
    }

    public GradedActivity getLowest(){
        double lowest = Double.MAX_VALUE;
        int index = 0;
        for(int i = 0; i < grades.size(); i++){
            if(lowest > grades.get(i).getScore()){
                lowest = grades.get(i).getScore();
                index = i;
            }
        }
        return grades.get(index);
    }
}
