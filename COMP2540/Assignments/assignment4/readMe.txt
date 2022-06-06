Lab 4
COMP-2540
By: Lucas Sarweh
ID: 110042658 

2) Part B

Q. Compare the average wait time for the two methods. Which seems to be better? 

A. They both are the same.

3) Analysis

Q. Think about the validity of the above experiment. Does it reliably determine the best approach? How might you
improve the experiment to get a better understanding of the differences between the two methods?

A. I think the validity of the experiment is compromised in this assignment. When running the program it queues
just as fast as it dequeues (on average) due to both customers walking in and being served is 1 - 5 seconds.
This experiment would be more accurate if it simulated for it to take longer to serve a customer than a customer
to walk in. Due to this both programs run too fast and don't allow more than one person to be in the queue at a time.
A better approach would be to use a library that implements real time. Simulating an event in real time would give
a better result, even if the waiting was super short. At least nanoseconds could be taken into account.