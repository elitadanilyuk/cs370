import sys
from copy import deepcopy

import algorithms
import process

# Input validation
if len(sys.argv) != 3:
    print(f"Invalid number of arguments, should be 2. Found: {len(sys.argv) - 1}\nExiting.")
    exit()

# Get Process objects
processes = process.getProcesses(sys.argv[1])

# Run processes with First Come First Serve
fcfs_processes = deepcopy(processes)
fcfs = algorithms.FCFS(fcfs_processes)
fcfs.run()

# Run processes with Priority Based Scheduling
ps_processes = deepcopy(processes)
ps = algorithms.PBS(ps_processes)
ps.run()

# Run processes with Round Robin
rr_processes = deepcopy(processes)
rr = algorithms.RR(rr_processes, sys.argv[2])
rr.run()

exit()