# thread_create 
- This function creates thread. 
- Mix fork, exec function.  
- Delete copyuvm and directly point parent's pgdir.  
- Start_routine function pointer puts in eip.
- Part of exec, only use allocuvm and sp, esp control.  
- Using allocuvm, thread's stack is accumulated on proc's stack in order.
- sp is down and put the arg, fake return address.  
- esp register also is down and thread's start_routine starts there that esp points.  

# thread_exit  
- This function exits thread.
- Similar exit function.
- Retval that give to thread_join is saved some variable of proc structure.  

# thread_join
- This function waits until some thread is exit.  
- Similar wait function.  
- Process waits thread that having received tid.  
- Value can get through variable in proc by thread_exit. 
- freevm(t->pgdir) is deleted because t->pgdir is proc->pgdir by pointer, removing t->pgdir is removing proc->pgdir. 