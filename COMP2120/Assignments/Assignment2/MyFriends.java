/*
Assignment 2
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 14 2021
*/

import javax.swing.JOptionPane;

/**
 * Tester class for FriendsList
 */
public class MyFriends {
    public static void main(String[] args){
        FriendsList lucasList = new FriendsList();

        // Creating
        lucasList.add(new Person("Matthew", "Lars", "7869584848", "04/21"));
        lucasList.add(new Person("Santa", "Clause", "0123456789", "03/15"));
        lucasList.add(new Person("James", "Bond", "0072899900", "07/07"));
        lucasList.add(new Person("Madison", "Duphraigne", "3478675309", "11/01"));
        lucasList.add(new Person("Karl", "Kou", "8007682344", "12/30"));
        lucasList.add(new Person("Seth", "Rogan", "5669098456", "02/29"));
        lucasList.add(new Person("Jim", "Helper", "8902938574", "09/11"));
        lucasList.add(new Person("Guy", "Fiery", "4538272848", "12/10"));
        lucasList.add(new Person("Tam", "Samuel", "2265556767", "08/01"));
        lucasList.add(new Person("Shane", "Dawson", "3429067945", "06/06"));

        // Modifying
        lucasList.modify(3, "Daisy", "Dave");
        lucasList.modify(0, "Sal", "Khan", "2487789089", "01/31");

        // Deleting
        lucasList.delete(4);
        lucasList.delete(5);

        // Getting all friends to print
        JOptionPane.showMessageDialog(null, lucasList.getAllFriends());
        // Printing list of friends born in a given month
        JOptionPane.showMessageDialog(null, lucasList.bornInMonth(12));
        // Printing list of friends born on a given day in a month
        JOptionPane.showMessageDialog(null, lucasList.bornOnDay(1));
        // Getting a friend's phone
        JOptionPane.showMessageDialog(null, "Jim Helper's cell: " + lucasList.getNumber("Jim", "Helper"));

        // Copy the FriendsList
        FriendsList copy = new FriendsList(lucasList);
        // Delete Shane from the copy
        copy.delete("Shane");

        System.exit(0);
    }
}
