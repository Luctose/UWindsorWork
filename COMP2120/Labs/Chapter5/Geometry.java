/*
Lab 4 (Chapter 5)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Oct 24 2021
*/

import java.util.Scanner;

/**
   This program demonstrates static methods
*/

public class Geometry
{
   public static void main(String[] args)
   {
      int choice;       // The user's choice
      double value = 0; // The method's return value
      char letter;      // The user's Y or N decision
      double radius;    // The radius of the circle
      double length;    // The length of the rectangle
      double width;     // The width of the rectangle
      double height;    // The height of the triangle
      double base;      // The base of the triangle
      double side1;     // The first side of the triangle
      double side2;     // The second side of the triangle
      double side3;     // The third side of the triangle

      // Create a scanner object to read from the keyboard
      Scanner keyboard = new Scanner(System.in);

      // The do loop allows the menu to be displayed first
      do
      {
         // TASK #1 Call the printMenu method
         printMenu();

         choice = keyboard.nextInt();

         switch(choice)
         {
            case 1:
               System.out.print("Enter the radius of " +
                                "the circle: ");
               radius = keyboard.nextDouble();

               // TASK #3 Call the circleArea method and
               // store the result in the value variable
               value = circleArea(radius);

               System.out.println("The area of the " +
                                  "circle is " + value);
               break;
            case 2:
               System.out.print("Enter the length of " +
                                "the rectangle: ");
               length = keyboard.nextDouble();
               System.out.print("Enter the width of " +
                                "the rectangle: ");
               width = keyboard.nextDouble();

               // TASK #3 Call the rectangleArea method and
               // store the result in the value variable
               value = rectangleArea(length, width);

               System.out.println("The area of the " +
                                  "rectangle is " + value);
               break;
            case 3:
               System.out.print("Enter the height of " +
                                "the triangle: ");
               height = keyboard.nextDouble();
               System.out.print("Enter the base of " +
                                "the triangle: ");
               base = keyboard.nextDouble();

               // TASK #3 Call the triangleArea method and
               // store the result in the value variable
               value = triangleArea(base, height);

               System.out.println("The area of the " +
                                  "triangle is " + value);
               break;
            case 4:
               System.out.print("Enter the radius of " +
                                "the circle: ");
               radius = keyboard.nextDouble();

               // TASK #3 Call the circumference method and
               // store the result in the value variable
               value = circleCircumference(radius);

               System.out.println("The circumference " +
                                  "of the circle is " +
                                  value);
               break;
            case 5:
               System.out.print("Enter the length of " +
                                "the rectangle: ");
               length = keyboard.nextDouble();
               System.out.print("Enter the width of " +
                                "the rectangle: ");
               width = keyboard.nextDouble();

               // TASK #3 Call the perimeter method and
               // store the result in the value variable
               value = rectanglePerimeter(length, width);

               System.out.println("The perimeter of " +
                                  "the rectangle is " +
                                  value);
               break;
            case 6:
               System.out.print("Enter the length of " +
                                "side 1 of the " +
                                "triangle: ");
               side1 = keyboard.nextDouble();
               System.out.print("Enter the length of " +
                                "side 2 of the " +
                                "triangle: ");
               side2 = keyboard.nextDouble();
               System.out.print("Enter the length of " +
                                "side 3 of the " +
                                "triangle: ");
               side3 = keyboard.nextDouble();

               // TASK #3 Call the perimeter method and
               // store the result in the value variable
               value = trianglePerimeter(side1, side2, side3);

               System.out.println("The perimeter of " +
                                  "the triangle is " +
                                  value);
               break;
            default:
               System.out.println("You did not enter " +
                                  "a valid choice.");
         }
         keyboard.nextLine(); // Consume the new line

         System.out.println("Do you want to exit " +
                            "the program (Y/N)?: ");
         String answer = keyboard.nextLine();
         letter = answer.charAt(0);

      } while(letter != 'Y' && letter != 'y');
   }

   // TASK #1 Create the printMenu method here
   /**
    * Displays the menu for the user to choose from
    */
   public static void printMenu(){
       // Print the menu to the user
       System.out.print("This is a geometry calculator\n"
       + "Choose what you would like to calculate\n"
       + "1.  Find the area of a circle\n"
       + "2.  Find the area of a rectangle\n"
       + "3.  Find the area of a triangle\n"
       + "4.  Find the circumference of a circle\n"
       + "5.  Find the perimeter of a rectangle\n"
       + "6.  Find the perimeter of a triangle\n"
       + "Enter the number of our choice: ");
   }
   // TASK #2 Create the value-returning methods here
   /**
    * Returns the area of a circle with the given radius
    * The radius must be a double
    * @param radius The radius of a circle as a double
    * @return The area of a circle as a double
    */
   public static double circleArea(double radius){
      // Return the area of a circle
      return Math.PI * radius * radius;
   }
   
   /**
    * Returns the area of a rectangle with the given length and width
    * The length and width must be a double
    * @param length The length of a rectangle as a double
    * @param width The width of a rectangle as a double
    * @return The area of a rectangle as a double
    */
   public static double rectangleArea(double length, double width){
      // Return the area of a rectangle
      return length * width;
   }

   /**
    * Returns the area of a triangle with the given base and height
    * The base and height must be a double
    * @param base The base of a triangle as a double
    * @param height The height of a triangle as a double
    * @return The area of a triangle as a double
    */
   public static double triangleArea(double base, double height){
      // Return the area of the triangle
      return (base * height) / 2;
   }

   /**
    * Returns the circumference of a circle with given radius
    * The radius must be a double
    * @param radius The radius of a circle as a double
    * @return The circumference of a circle as a double
    */
   public static double circleCircumference(double radius){
      // Return the circumference of the circle
      return 2 * Math.PI * radius;
   }

   /**
    * Returns the perimeter of a rectangle with given length and width
    * The length and width must be a double
    * @param length The length of a rectangle as a double
    * @param width The width of a rectangle as a double
    * @return The perimeter of a rectangle as a double
    */
   public static double rectanglePerimeter(double length, double width){
      // Return the perimeter of the rectangle
      return 2 * (length + width);
   }

   /**
    * Returns the perimeter of a triangle with three given sides
    * s1, s2, and s3 must be a double
    * @param s1 The first side of a triangle as a double
    * @param s2 The second side of a triangle as a double
    * @param s3 The third side of a triangle as a double
    * @return The perimeter of a triangle as a double
    */
   public static double trianglePerimeter(double s1, double s2, double s3){
      // Return the perimeter of the triangle
      return s1 + s2 + s3;
   }
   // TASK #4 Write javadoc comments for each method
}