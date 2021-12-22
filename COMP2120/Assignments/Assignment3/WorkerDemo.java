/*
Assignment 3
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Wed Dec 08 2021
*/

/**
 * Tester class for ProductionWorker
 */
public class WorkerDemo {
    public static void main(String[] args){
        // "Hire" new workers
        ProductionWorker worker1 = new ProductionWorker("John Smith", "123-A", "11-15-2005", 1, 16.50);
        ProductionWorker worker2 = new ProductionWorker("Joan Jones", "222-L", "12-12-2005", 2, 18.50);

        // Print the workers info

        System.out.println("Here's the first production worker.\n" + worker1);
        System.out.println("Here's the second production worker.\n" + worker2);
    }
}
