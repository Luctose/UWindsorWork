/*
Assignment 2
Lucas Sarweh
ID: 110042658
COMP-2120
Due: Sun Nov 14 2021
*/

/**
 * Stores information about a person
 */
public class Person implements Comparable<Person>{
    // Fields
    private String firstName;
    private String lastName;
    private String number;
    private String birthday;

    // Methods

    /**
     * Constructor intializes fields
     * @param firstName First name of the person
     * @param lastName Last name of the person
     * @param number The phone number of the person
     * @param birthday The birthday of the person
     */
    public Person(String firstName, String lastName, String number, String birthday){
        this.firstName = firstName;
        this.lastName = lastName;
        this.number = number;
        this.birthday = birthday;
    }

    /**
     * Returns either the first or last name of the specified person
     * @param first True to return first name false to return surname
     * @return The first or last name of the person
     */
    public String getName(boolean first){
        if(first){
            return firstName;
        }else{
            return lastName;
        }
    }

    /**
     * Gives the phone number of the person
     * @return The person's phone number
     */
    public String getNumber(){
        return number;
    }

    /**
     * Gets the birthday of the person
     * @return The person's birthday
     */
    public String getBirthday(){
        return birthday;
    }
    
    /**
     * Changes the phone number of the person
     * @param num The number to change to
     */
    public void changeNumber(String num){
        number = num;
    }

    /**
     * Changes the name of the person
     * @param firstName First name to change
     * @param lastName Last name to change
     */
    public void changeName(String firstName, String lastName){
        this.firstName = firstName;
        this.lastName = lastName;
    }

    /**
     * Changes the birthday of the person
     * @param birthday Birthday to change to
     */
    public void changeBirthday(String birthday){
        this.birthday = birthday;
    }

    /**
     * Checks if the two Person objects are the same
     * @param friend The Person to compare against
     * @return Wether or not they are equal or not (true or false)
     */
    public boolean equals(Person friend){
        if(firstName.equals(friend.firstName) && lastName.equals(friend.lastName)
        && number.equals(friend.number) && birthday.equals(friend.birthday)){
            return true;
        }
        return false;
    }

    /**
     * Gives an integer indicating how the calling Person object 
     * compares to the parameter object. 1, 0 , and -1 means the 
     * caller is first, equal, and last alphebetically, respectively
     * @param friend The Person object to comapre to
     * @return An integer indicating the alphebtical order
     */
    public int compareTo(Person friend){
        // Counter
        int count = 0;
        for(char letter : lastName.toCharArray()){
            if(letter > friend.lastName.charAt(count)){
                return -1;
            }else if(letter < friend.lastName.charAt(count)){
                return 1;
            }
            // Increment count
            count++;
        }
        // Return 0 as they are equal
        return 0;
    }

    /**
     * Sends the object information to a String
     * @return A String containing Person info
     */
    public String toString(){
        return "Name: " + firstName + " " + lastName +
        "\nDate of Birth: " + birthday +
        "\nPhone Number:" + number + "\n";
    }
}
