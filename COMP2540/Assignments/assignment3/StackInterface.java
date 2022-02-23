/*
Lab 3
COMP-2540
By: Lucas Sarweh
ID: 110042658 
*/

interface StackInterface {
    /**
     * Pops the top off the stack
     * @return The object popped (null on failure)
     */
    public Object pop();

    /**
     * Pushes given object to the stack
     * @param obj Object to push
     * @return Bool based on success or fail (true / false)
     */
    public boolean push(Object obj);

    /**
     * Show the top of the stack
     * @return The top of the stack (null on failure)
     */
    public Object top();

    /**
     * Gives the amount of elements currently on the stack
     * @return The current elements on the stack
     */
    public int size();

    /**
     * Check if the stack is empty
     * @return Wether the stack is empty (true / false)
     */
    public boolean isEmpty();

    /**
     * Check if the stack is full
     * @return Wether the stack is full (true / false)
     */
    public boolean isFull();
}
