/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

public abstract class BankAccount {
    // Fields
    private double bal;
    private int numOfDep;
    private int numOfWith;
    private double annualInterest;
    private double monthlySrvChrg;

    // Methods
    public BankAccount(){
        bal = 0;
        numOfDep = 0;
        numOfWith = 0;
        annualInterest = 0;
        monthlySrvChrg = 0;
    }

    public BankAccount(double bal, double annualInterest){
        this.bal = bal;
        this.annualInterest = annualInterest;
    }

    public double getBal(){
        return bal;
    }

    public double getNumOfWith(){
        return numOfWith;
    }

    public void deposit(double amount){
        bal += amount;
        numOfDep++;
    }

    public void withdraw(double amount){
        try{
            if(bal - amount < 0){
                throw new BankAccountException("Not enough funds");
            }
            bal -= amount;
            numOfWith++;
        }catch(BankAccountException e){
            System.out.println(e.getMessage());
        }
    }

    public void calcInterest(){
        bal = bal + ((annualInterest / 12) * bal);
    }

    public void monthlyProcess(){
        bal -= monthlySrvChrg;
        calcInterest();
        numOfDep = 0;
        numOfWith = 0;
        monthlySrvChrg = 0;
    }

    public void addSrvChrg(){
        monthlySrvChrg++;
    }
}
