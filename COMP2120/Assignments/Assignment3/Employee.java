/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

/**
 * Parent class of all employee's
 */
public class Employee
{
    // Fields
    private String name;
    private String number;
    private String hireDate;

    // Methods
    /**
     * No arg constructor sets all to null
     */
    public Employee(){
        name = null;
        number = null;
        hireDate = null;
    }

    /**
     * Sets the instance fields of the object
     * @param name Employee name
     * @param number Employee number
     * @param hireDate Date hired
     */
    public Employee(String name, String number, String hireDate){
        // Set fields
        this.name = name;
        this.hireDate = hireDate;
        // Make sure Employee number is correct
        try{
            if(number.length() != 5){
                throw new EmployeeNumberException("wrong String length");
            }else if(number.charAt(3) != '-'){
                throw new EmployeeNumberException("hyphen in wrong spot");
            }else if(!Character.isDigit(number.charAt(0))){
                throw new EmployeeNumberException("First three characters must be digits");
            }else if(!Character.isDigit(number.charAt(1))){
                throw new EmployeeNumberException("First three characters must be digits");
            }else if(!Character.isDigit(number.charAt(2))){
                throw new EmployeeNumberException("First three characters must be digits");
            }else if(!(number.charAt(4) >= 'A' && number.charAt(4) <= 'M')){
                throw new EmployeeNumberException("Last character not from A - M");
            }else{
                // No Exceptions thrown set the number
                this.number = number;
            }
        }catch(EmployeeNumberException e){ // Set to null if not
            System.out.println(e.getMessage());
            this.number = null;
        }
    }

    /**
     * Gets the name of the employee
     * @return Employee name
     */
    public String getName(){
        // Return name
        return name;
    }

    /**
     * Gets the number of the employee
     * @return Employee number
     */
    public String getNumber(){
        // Return number
        return number;
    }

    /**
     * Gets the date the employee was hired
     * @return Employee hire date
     */
    public String getDateHired(){
        // Return Date
        return hireDate;
    }

    /**
     * Sets a new employee name
     * @param name Name to change to
     */
    public void setName(String name){
        // Set employees new name
        this.name = name;
    }

    /**
     * Sets a new hire date
     * @param hireDate Date to change to
     */
    public void setDate(String hireDate){
        // Set the new date
        this.hireDate = hireDate;
    }

    public void setNumber(String number){
        // Make sure Employee number is correct
        try{
            if(number.length() != 5){
                throw new EmployeeNumberException("wrong String length");
            }else if(number.charAt(3) != '-'){
                throw new EmployeeNumberException("hyphen in wrong spot");
            }else if(Character.isDigit(number.charAt(0))){
                throw new EmployeeNumberException("First three characters must be digits");
            }else if(Character.isDigit(number.charAt(1))){
                throw new EmployeeNumberException("First three characters must be digits");
            }else if(Character.isDigit(number.charAt(2))){
                throw new EmployeeNumberException("First three characters must be digits");
            }else if(number.charAt(4) >= 'A' && number.charAt(4) <= 'M'){
                throw new EmployeeNumberException("Last character not from A - M");
            }else{
                // No Exceptions thrown set the number
                this.number = number;
            }
        }catch(EmployeeNumberException e){ // Set to null if not
            System.out.println(e.getMessage());
            // Number doesn't change
            System.out.println("Number did not change");
        }
    }

    public String toString(){
        // Return a string of the data
        return "Name: " + name + "\n" + "Employee Number: " + number + "\n" +
                "Hire Date: " + hireDate + "\n";
    }
}