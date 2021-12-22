/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

public class SavingsAccount extends BankAccount{
    // Fields
    private boolean status;

    // Methods
    public SavingsAccount(){
        super();
        status = false;
    }

    public SavingsAccount(double bal, double annualInterest){
        super(bal, annualInterest);
        if(bal < 25){
            status = false;
        }else{
            status = true;
        }
    }

    public void withdraw(double amount){
        try{
            if(status == false){
                throw new BankAccountException("Account is inactive you must deposit above $25");
            }else if(super.getBal() - amount < 0){
                throw new BankAccountException("Not enough funds");
            }else{
                super.withdraw(amount);
            }
        }catch(BankAccountException e){
            System.out.println(e.getMessage());
        }finally{
            if(super.getBal() < 25){
                status = false;
            }
        }
    }

    public void deposit(double amount){
        if(status == false && super.getBal() + amount >= 25){
            status = true;
        }
        super.deposit(amount);
    }

    public void monthlyProcess(){
        if(super.getNumOfWith() > 4){
            for(int i = 0; i < super.getNumOfWith() - 4; i++){
                super.addSrvChrg();
            }
            if(super.getBal() < 25){
                status = false;
            }
        }
        monthlyProcess();
    }
}
