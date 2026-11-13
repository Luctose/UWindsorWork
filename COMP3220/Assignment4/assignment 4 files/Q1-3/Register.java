public class Register {
    private ProductCatalog catalog;
    private Sale currentSale;

    public Register(ProductCatalog catalog) {
        this.catalog = catalog;
    }

    public void endSale() {
        currentSale.becomeComplete();
    }

    public void enterItem(ItemID id, int quantity) {
        ProductSpecification spec = catalog.getProductSpecification(id);
        currentSale.makeLineItem(spec, quantity);
    }

    public void makeNewSale(String area) {
        currentSale = new Sale(area);
    }

    public void makePayment(Money cashTendered) {
        currentSale.makePayment(cashTendered);
    }
}
