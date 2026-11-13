public class Money {
    private double amt;

    public Money(){
        this.amt = 0;
    }

    public Money(double amount){
        this.amt = amount;
    }

    public Money minus(Money amount){
        return new Money(this.amt - amount.amt);
    }

    public void add(Money amount){
        this.amt += amount.amt;
    }

    public Money times(int quantity){
        return new Money(this.amt * quantity);
    }

    public Money times(float f){
        return new Money(this.amt * f);
    }

    public String toString(){
        return "$" + String.format("%.2f", amt);
    }
}