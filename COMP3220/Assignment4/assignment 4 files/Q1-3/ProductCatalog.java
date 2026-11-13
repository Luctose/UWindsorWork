public class ProductCatalog {
    private Map<ItemID, ProductSpecification> 
    specifications = new HashMap()<ItemID, ProductSpecification>;

    public ProductCatalog() {
        // sample data
        ItemID id1 = new ItemID(100);
        ItemID id2 = new ItemID(200);
        ItemID id3 = new ItemID(220);
        ItemID id4 = new ItemID(313);
        ItemID id5 = new ItemID(500);
        Money price = new Money(3);
        Money price2 = new Money(5);
        Money price3 = new Money(7);
        ProductSpecification spec;
        spec = new ProductSpecification(id1, price, "product 1");
        specifications.put(id1, spec);
        spec = new ProductSpecification(id2, price, "product 2");
        specifications.put(id2, spec);
        spec = new ProductSpecification(id3, price2, "product 3");
        specifications.put(id3, spec);
        spec = new ProductSpecification(id4, price2, "product 4");
        specifications.put(id4, spec);
        spec = new ProductSpecification(id5, price3, "product 5");
        specifications.put(id5, spec);
    }

    public ProductSpecification getProductSpecification(ItemID id)

    {
        return specifications.get(id);
    }
}