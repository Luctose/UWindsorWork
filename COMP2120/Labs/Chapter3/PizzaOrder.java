/*
Lab 2
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Oct 03 2021
*/

import java.util.Scanner;  // Needed for the Scanner class

/**
   This program allows the user to order a pizza.
*/

public class PizzaOrder
{
   public static void main (String[] args)
   {
      // Create a Scanner object to read input.
      Scanner keyboard = new Scanner (System.in);

      String firstName;             // User's first name
      boolean discount = false;     // Flag for discount
      int inches;                   // Size of the pizza
      char crustType;               // For type of crust
      String crust = "Hand-tossed"; // Name of crust
      double cost = 12.99;          // Cost of the pizza
      final double TAX_RATE = .08;  // Sales tax rate
      double tax;                   // Amount of tax
      char choice;                  // User's choice
      String input;                 // User input
      String toppings = "Cheese ";  // List of toppings
      int numberOfToppings = 0;     // Number of toppings

      // Prompt user and get first name.
      System.out.println("Welcome to Mike and " +
                         "Diane's Pizza");
      System.out.print("Enter your first name: ");
      firstName = keyboard.nextLine();

      // Determine if user is eligible for discount by
      // having the same first name as one of the owners.
      // ADD LINES HERE FOR TASK #1
      if(firstName.compareToIgnoreCase("diane") == 0 || firstName.compareToIgnoreCase("mike") == 0){
          discount = true; // Set discount to true when they have the
                           // same name as one of the owners
      }

      // Prompt user and get pizza size choice.
      System.out.println("Pizza Size (inches)   Cost");
      System.out.println("        10            $10.99");
      System.out.println("        12            $12.99");
      System.out.println("        14            $14.99");
      System.out.println("        16            $16.99");
      System.out.println("What size pizza " +
                         "would you like?");
      System.out.print("10, 12, 14, or 16 " +
                       "(enter the number only): ");
      inches = keyboard.nextInt();

      // Set price and size of pizza ordered.
      // ADD LINES HERE FOR TASK #2
      if(inches == 10){ // 10 inch pizza costs 10.99
        cost = 10.99;
      }
      else if(inches == 12){ // 12 inch pizza costs 12.99
        cost = 12.99;
      }
      else if(inches == 14){ // 14 inch pizza costs 14.99
        cost = 14.99;
      }
      else if(inches == 16){ // 16 inch pizza costs 16.99
        cost = 16.99;
      }
      else{ // Incase user inputs something that was not an option
        // Default to the 12 inch pizza
        // Tell the user that this has occured
        System.out.println("You have not chosen one of the options.\n"
        + "Therefore a 12 inch pizza will be made.");
        // Set the inches to 12
        inches = 12;
        // Set the cost to the cost for a 12 inch pizza
        cost = 12.99;
      }

      // Consume the remaining newline character.
      keyboard.nextLine();

      // Prompt user and get crust choice.
      System.out.println("What type of crust " +
                         "do you want? ");
      System.out.print("(H)Hand-tossed, " +
                       "(T) Thin-crust, or " +
                       "(D) Deep-dish " +
                       "(enter H, T, or D): ");
      input = keyboard.nextLine();
      crustType = input.charAt(0);

      // Set user's crust choice on pizza ordered.
      // ADD LINES FOR TASK #3
      switch(crustType){
         // Hand tossed case labels
         case 'H':
         case 'h':
            crust = "Hand-tossed"; // Set crust to Hand-tossed
            break;
         
         // Thin crust case labels
         case 'T':
         case 't':
            crust = "Thin-crust"; // Set crust to Thin-crust
            break;

         // Deep dish case labels
         case 'D':
         case 'd':
            crust = "Deep-dish"; // Set crust to Deep-dish
            break;
         
         // Default when invalid input is entered
         default:
            // Send message to the user that that was not one of the choices
            System.out.println("That was not one of the choices.\n" + "Hand-tossed pizza will be made.");
            // Do Hand-tossed by default
            crustType = 'H';
            crust = "Hand-tossed";
      }

      // Prompt user and get topping choices one at a time.
      System.out.println("All pizzas come with cheese.");
      System.out.println("Additional toppings are " +
                         "$1.25 each, choose from:");
      System.out.println("Pepperoni, Sausage, " +
                         "Onion, Mushroom");

      // If topping is desired,
      // add to topping list and number of toppings
      System.out.print("Do you want Pepperoni? (Y/N): ");
      input = keyboard.nextLine();
      choice = input.charAt(0);
      if (choice == 'Y' || choice == 'y')
      {
         numberOfToppings += 1;
         toppings = toppings + "Pepperoni ";
      }
      System.out.print("Do you want Sausage? (Y/N): ");
      input = keyboard.nextLine();
      choice = input.charAt(0);
      if (choice == 'Y' || choice == 'y')
      {
         numberOfToppings += 1;
         toppings = toppings + "Sausage ";
      }
      System.out.print("Do you want Onion? (Y/N): ");
      input = keyboard.nextLine();
      choice = input.charAt(0);
      if (choice == 'Y' || choice == 'y')
      {
         numberOfToppings += 1;
         toppings = toppings + "Onion ";
      }
      System.out.print("Do you want Mushroom? (Y/N): ");
      input = keyboard.nextLine();
      choice = input.charAt(0);
      if (choice == 'Y' || choice == 'y')
      {
         numberOfToppings += 1;
         toppings = toppings + "Mushroom ";
      }

      // Add additional toppings cost to cost of pizza.
      cost = cost + (1.25 * numberOfToppings);

      // Display order confirmation.
      System.out.println();
      System.out.println("Your order is as follows: ");
      System.out.println(inches + " inch pizza");
      System.out.println(crust + " crust");
      System.out.println(toppings);

      // Apply discount if user is eligible.
      // ADD LINES FOR TASK #4 HERE
      if(discount){
         // Tell user they are eligible for a discount
         System.out.println("Congratulations! You are eligible for a $2.00"
         + " discount.\nIt will be applied automatically.");
         // Reduce the cost by $2.00
         cost -= 2;
      }

      // EDIT PROGRAM FOR TASK #5
      // SO ALL MONEY OUTPUT APPEARS WITH 2 DECIMAL PLACES
      System.out.printf("The cost of your order " +
                        "is: $%.2f\n", cost);

      // Calculate and display tax and total cost.
      tax = cost * TAX_RATE;
      System.out.printf("The tax is: $%.2f\n", tax);
      System.out.printf("The total due is: $%.2f\n",
                        (tax + cost));

      System.out.println("Your order will be ready " +
                         "for pickup in 30 minutes.");
   }
}