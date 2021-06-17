# First Step : MLFQ  
- Each process has priority and tick.
- Making 3level queue.  
- First level queue's full tick is 5, Second level queue's full tick is 10, Third level queue's full tick is 20tick.
- Looking at the ptable, each process puts in the queue that matches process's priority.
- Each queue is stopped when queue which has higher priority is not empty and higher priority queue executes first.
- Process's in each queue level is down when tick is full that allocated each queue.  
- To prevent Starvation, executing priority boost that all process's  level in third level queue is first and tick is clear.
- Each process's tick is incremented in trap.c.
- Boost executes in trap.c.
- Priority boost's frequency is 100ticks.

# Second Step : Combine the *stride scheduling* algorithm with MLFQ  (Stride Scheduler is out of my ability.....)
- New process puts in highest level queue.
- In MLFQ, process puts stride queue when set_cpu_share system call is called.
- set_cpu_share gives ticket to process.
- Process's in stride queue sum of ticket is must no more than 80.
- If process's in stride queue sum of ticket  more than 80, process which allocated ticket is not put in stride queue.
- Processes in MLFQ consider dummyprocess and give the ticket that more than 20. 
- stride scheduling and MLFQ executes by lottery.