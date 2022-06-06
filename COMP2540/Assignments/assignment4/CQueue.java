import java.lang.reflect.Array;

/*
Lab 4
COMP-2540
By: Lucas Sarweh
ID: 110042658 
*/

public class CQueue<Type> {
    // Private members
    private Type[] array;
    private int front;
    private int back;

    // Constructors
    /**
     * Default constructor, sets array size to 20
     */
    public CQueue(Class<Type> c){
        @SuppressWarnings("unchecked")
        final Type[] array = (Type[]) Array.newInstance(c, 20);
        this.array = array;
        front = 0;
        back = 0;
    }

    /**
     * Constructor given array size
     * @param size size of the array
     */
    public CQueue(Class<Type> c, int size){
        @SuppressWarnings("unchecked")
        final Type[] array = (Type[]) Array.newInstance(c, size);
        this.array = array;
        front = 0;
        back = 0;
    }

    // Public members
    /**
     * Returns whether the circular queue is empty
     * @return A boolean: true = empty, false = not empty
     */
    public boolean isEmpty(){
        // Check if the front equals the back
        if(front == back){
            return true;
        }
        return false;
    }

    /**
     * Returns whether the circular queue is full
     * @return A boolean: true = full, false = not full
     */
    public boolean isFull(){
        if(((back + 1) % array.length) == front){
            return true;
        }
        return false;
    }

    /**
     * Returns the current size of the queue
     * @return Current size of the queue
     */
    public int size(){
        return (back - front + array.length) % array.length;
    }

    /**
     * Adds an element to the circular queue given enough room
     * @param value Value to add to the queue
     */
    public void enqueue(Type value){
        // Make sure the queue is not full
        if(this.isFull()){
            // Error
            System.out.println("Error: Queue is full.");
            System.out.println("Cannot add " + value + " to the queue.");
            return;
        }
        // No error
        // Add the given value to the back
        array[back] = value;
        System.out.println("Item queued: " + array[back]);
        // Set the back to one index past
        back = (back + 1) % array.length;
    }

    /**
     * Delete the item at the front of the queue and return it's value
     * @return The item deleted
     */
    public Type dequeue(){
        // Make sure the queue is not empty
        if(this.isEmpty()){
            // Error
            return null;
        }
        // Temporary variable to store the item deleted
        Type temp = array[front];
        array[front] = null;
        // Shift up the front one index in the circular queue
        front = (front + 1) % array.length;
        System.out.println("Item dequeued: " + temp);
        // Return the deleted item
        return temp;
    }

    /**
     * Returns the front of the queue
     * @return The object in the front of the queue
     */
    public Type front(){
        return array[front];
    }

    public String toString(){
        // Initialize a string to return
        String mystring = "<  ";
        // Loop through each element in the queue
        for(Type item : array){
            // Add item to the string with a double space
            mystring = mystring + item + "  ";
        }
        // Add gt to close
        mystring = mystring + ">";
        // Return string made
        return mystring;
    }
}
