## Semaphore

- Controll access to a critical zone
- Can work with a capacity (for example 10 processes max)
- Everytime a process leaves
- If a semaphore is used with capacity = 1, it's being used like a mutex
- No thread owns the semaphore, so any thread can unlock the semaphore

## Mutex

- Mutual exclusion, there can't be more than one process in the same region
- The process is locked and only the owner can unlock it (the current process)