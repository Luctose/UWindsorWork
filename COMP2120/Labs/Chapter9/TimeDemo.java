/*
Lab 8 (Chapter 9)
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 21 2021
*/

import java.util.Scanner;

/**
   This program demonstrates the Time class.
*/

public class TimeDemo
{
   public static void main(String[] args)
   {
      Scanner keyboard = new Scanner(System.in);
      char answer = 'Y';
      String enteredTime;
      String response;

      while (Character.toUpperCase(answer) == 'Y')
      {
         System.out.print("Enter a military time " +
                          "using the ##:## format: ");
         enteredTime = keyboard.nextLine();
         Time now = new Time (enteredTime);
         System.out.println("Do you want to enter " +
                            "another (Y/N)? ");
         response = keyboard.nextLine();
         answer = response.charAt(0);
      }
   }
}