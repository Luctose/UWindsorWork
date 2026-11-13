public class Sale {
 private List<SalesLineItem> lineItems = 
 new ArrayList()<SalesLineItem>;
    private Date date = new Date();
    private boolean isComplete = false;
    private Payment payment;
    private String area;

    public Sale(String area){
        this.area = area;
    }

    public Money getBalance() {
        return payment.getAmount().minus(getTotal());
    }

    public void becomeComplete() {
        isComplete = true;
    }

    public boolean isComplete() {
        return isComplete;
    }

    public void makeLineItem(ProductSpecification spec, int quantity) {
        lineItems.add(new SalesLineItem(spec, quantity));
    }

    public Money getTotal() {
        Money total = new Money();
        Money subtotal = null;
        for (SalesLineItem lineItem : lineItems) {
            subtotal = lineItem.getSubtotal();
            total.add(subtotal);
        }
        if(area.equals("Ontario")){
            total.add(total.times(GetOntarioTaxRate()));
        }else if(area.equals("Quebec")){
            total.add(total.times(GetQuebecTaxRate()));
        }
        return total;
    }

    public void makePayment(Money cashTendered) {
        payment = new Payment(cashTendered);
    }
}
