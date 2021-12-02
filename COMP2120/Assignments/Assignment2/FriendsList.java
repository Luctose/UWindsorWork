/*
Assignment 2
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 14 2021
*/

import java.util.ArrayList;
import java.util.Collections;

/**
 * Stores a list of friends and organizes them
 */
public class FriendsList{
    // Field
    private ArrayList<Person> list; // List of people that are friends

    // Methods

    /**
     * Constructor initializes the list
     */
    public FriendsList(){
        list = new ArrayList<Person>();
    }

    /**
     * Copy constructor creates a copy of a FriendList
     * @param copy Object to be copied
     */
    public FriendsList(FriendsList copy){
        this();
        for(Person val : copy.list){
            list.add(val);
        }
    }

    /**
     * Add a friend to the list
     * @param friend The Person to be added 
     */
    public void add(Person friend){
        list.add(friend);
        Collections.sort(list);
    }

    /**
     * Deletes an object at an index
     * @param index Index to be deleted
     */
    public void delete(int index){
        list.remove(index);
    }

    /**
     * Deletes an object from their firt name field
     * @param name The name associated with the object to delete
     */
    public void delete(String name){
        for(Person val : list){
            if(val.getName(true).equals(name)){
                list.remove(val);
            }
        }
    }

    /**
     * Modifies fields of an existing object 
     * Requires there be at least a first and last name and 
     * must take the order first, last, number, birthday
     * @param index Index to modify
     * @param item String list of 2 to 4 Strings to input for modification
     * @return True if all items are changed, false if not
     * @throws ArrayIndexOutOfBoundsException
     */
    public boolean modify(int index, String ... item) throws ArrayIndexOutOfBoundsException{
        for(int i = 0; i < item.length; i++){
            switch(i){
                case 0:
                case 1:
                    list.get(index).changeName(item[0], item[1]);
                    Collections.sort(list);
                    break;
                case 2:
                    list.get(index).changeNumber(item[2]);
                    break;
                case 3:
                    list.get(index).changeBirthday(item[3]);
                    break;
                default:
                    return false;
            }
        }
        return true;
    }

    /**
     * Returns an alphebetical list of friends
     * @return List of friends
     */
    public ArrayList<Person> getAllFriends(){
        // Return null when the list is empty
        if(list.isEmpty()){
            return null;
        }
        // List holding all friends in order
        ArrayList<Person> myfriends = new ArrayList<Person>();
        // Loop through each friend
        for(int i = 0; i < list.size(); i++){
            myfriends.add(list.get(i));
        }
        return myfriends;
    }

    /**
     * Returns the size of the list of friends
     * @return
     */
    public int friendCount(){
        // Return the size of their friends list
        return list.size();
    }

    /**
     * Gives a list of Person objects that all share the same 
     * birthday month and in order of birthday days
     * @param month The month of the birthday
     * @return An ArrayList of Person objects
     * @throws ArrayIndexOutOfBoundsException
     */
    public ArrayList<Person> bornInMonth(int month) throws ArrayIndexOutOfBoundsException{
        if(list.isEmpty()){
            return null;
        }

        ArrayList<Person> myfriends = new ArrayList<Person>();
        String[] splitStrings = new String[2];
        int currentSize = 0;
        
        for(Person val : list){
            splitStrings = val.getBirthday().split("/");

            if(Integer.parseInt(splitStrings[0]) == month){
                if(myfriends.size() > 0){
                    currentSize = myfriends.size();
                    for(int j = 0; j < currentSize; j++){
                        if(Integer.parseInt(splitStrings[1]) <= 
                        Integer.parseInt(myfriends.get(j).getBirthday().substring(3))){
                            myfriends.add(j, val);
                            break;
                        }else if(j + 1 >= currentSize){
                            myfriends.add(val);
                        }
                    }
                }else{
                    myfriends.add(val);
                }
            }
        }

        if(myfriends.isEmpty()){
            return null;
        }else{
            return myfriends;
        }
    }

    /**
     * Gives a list of Person objects that all share the same 
     * birthday day number in order of last name
     * @param day The day they share
     * @return The ArrayList of Person objects
     */
    public ArrayList<Person> bornOnDay(int day){
        if(list.isEmpty()){
            return null;
        }

        ArrayList<Person> myfriends = new ArrayList<Person>();
        int count = 0;

        for(Person val : list){
            if(Integer.parseInt(val.getBirthday().substring(3)) == day){
                myfriends.add(count, val);
                count++;
            }
        }
        if(myfriends.isEmpty()){
            return null;
        }else{
            return myfriends;
        }
    }

    /**
     * Gets the phone number of an object given it's name
     * @param first First name
     * @param last Last name
     * @return The phone number as a String
     */
    public String getNumber(String first, String last){
        for(Person val : list){
            if(val.getName(true).equals(first) && val.getName(false).equals(last)){
                return val.getNumber();
            }
        }
        return null;
    }
}
