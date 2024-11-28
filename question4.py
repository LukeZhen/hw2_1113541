#Luke 1113541 2024/11/28

import heapq

# Define a function to schedule tasks for maximum profit
def schedule_tasks(tasks, N):
    # Sort tasks based on profit in descending order
    tasks.sort(key=lambda x: x[0], reverse=True)

    # Create a max-heap based on task profits
    max_profit_queue = []
    
    # Keep track of the maximum deadline
    max_deadline = max(task[1] for task in tasks)
    
    # Create an array to track occupied slots
    slots = [False] * (max_deadline + 1)
    
    # Store the scheduled tasks and total profit
    scheduled_tasks = []
    total_profit = 0
    
    # Go through the sorted tasks and schedule them
    for profit, deadline in tasks:
        # Try to find a free slot for the task before its deadline
        for t in range(deadline, 0, -1):
            if not slots[t]:  # If slot is free
                slots[t] = True  # Mark it as occupied
                scheduled_tasks.append(profit)  # Schedule the task
                total_profit += profit  # Add the profit to total
                break
    
    # Return the maximum profit and the list of scheduled tasks
    return total_profit, scheduled_tasks

# Read input
N = int(input())  # Number of tasks
tasks = []
for _ in range(N):
    profit, deadline = map(int, input().split())
    tasks.append((profit, deadline))

# Get the result
max_profit, scheduled_tasks = schedule_tasks(tasks, N)

# Output the result
print(f"Maximum Profit: {max_profit}")
print(f"Scheduled Tasks: {scheduled_tasks}")
