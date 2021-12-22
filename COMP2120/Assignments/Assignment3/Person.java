/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

public class Person {
    // Fields
    private String name;
    private String address;
    private String number;

    // Methods
    public Person(){
        name = null;
        address = null;
        number = null;
    }

    public Person(String name, String address, String number){
        this.name = name;
        this.address = address;
        this.number = number;
    }

    public String getName(){
        return name;
    }

    public String getAddress(){
        return address;
    }

    public String getNumber(){
        return number;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setAddress(String address){
        this.address = address;
    }

    public void setNumber(String number){
        this.number = number;
    }

    public String toString(){
        return String.format("Name: %s\n", name) +
               String.format("Address: %s\n", address) +
               String.format("Telephone: %s\n", number);
    }
}
