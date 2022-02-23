/*
Lab 3
COMP-2540
By: Lucas Sarweh
ID: 110042658 
*/

/**
 * This Class implements a Stack using an array for any Object
 */
public class MyStack implements StackInterface{
    // Private members
    // Array to store the stack
    private Object[] array;
    // Total array size
    private int maxSize;
    // Current array size
    private int currentSize = 0;

    // Public members
    /**
     * No-arg constructor, default initialization array size 10
     */
    public MyStack(){
        // Default initialization
        array = new Object[10];
        maxSize = 10;
    }

    /**
     * Parameter constructor initialize stack size with given length
     * @param length The size of the stack
     */
    public MyStack(int length){
        // Initialization with given length
        array = new Object[length];
        maxSize = length;
    }

    /**
     * Copy constructor copies new MyStack from new given argument
     * @param obj MyStack to copy
     */
    public MyStack(MyStack obj){
        // Initialize size to the given objects size
        array = new Object[obj.maxSize];
        maxSize = obj.maxSize;
        // Copy all the elements to the new MyStack
        for(Object i : obj.array){
            push(i);
        }
    }

    /**
     * Pops the top off the stack
     * @return The object popped (null on failure)
     */
    public Object pop(){
        // If the stack is not empty
        if(!isEmpty()){
            // Create temp to return popped object
            Object temp = array[currentSize - 1];
            // Set top of the stack to null
            array[currentSize - 1] = null;
            // Decrement the current size
            --currentSize;
            // Return the popped object
            return temp;
        }else{ // On fail
            System.out.println("Could not pop the stack.");
            return null;
        }
    }

    /**
     * Pushes given object to the stack
     * @param obj Object to push
     * @return Bool based on success or fail (true / false)
     */
    public boolean push(Object obj){
        // Check if we have space to push
        if(!isFull()){
            // Set the current open spot to the object
            array[currentSize] = obj;
            // Add to current spot
            ++currentSize;
        }else{ // On fail
            System.out.println("Could not push " + obj + " to stack.");
            return false;
        }
        // Success
        return true;
    }

    /**
     * Show the top of the stack
     * @return The top of the stack (null on failure)
     */
    public Object top(){
        // Make sure the stack is not empty
        if(!isEmpty()){
            // Return the top
            return array[currentSize - 1];
        }else{ // On fail
            // Return null (empty stack)
            return null;
        }
    }

    /**
     * Gives the amount of elements currently on the stack
     * @return The current elements on the stack
     */
    public int size(){
        // The current elements on the stack
        return currentSize;
    }

    /**
     * Check if the stack is empty
     * @return Wether the stack is empty (true / false)
     */
    public boolean isEmpty(){
        // If stack size is 0
        if(currentSize == 0){
            // It is empty
            return true;
        }
        // Not empty
        return false;
    }

    /**
     * Check if the stack is full
     * @return Wether the stack is full (true / false)
     */
    public boolean isFull(){
        // If current stack size is less than the max stack size
        if(currentSize < maxSize){
            // Stack is not full
            return false;
        }
        // Stack is full
        return true;
    }
}
