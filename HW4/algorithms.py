import cpu
import process

from scheduler import Scheduler

# First Come First Served Scheduler
class FCFS(Scheduler):

    def __init__(self, processes):
        super().__init__()
        self.processes = processes
        self.cpu = cpu.CPU()
        self.idleprocess = process.Process(["IDLE", 0, 0, 0])

    def run(self):
        # Run until all processes finished
        while not self.allProcessesComplete(self.processes):
            nextprocess = FCFS.getNextProcess(self)
            self.cpu.cycle(nextprocess)

        # Print stats
        self.printStats(self.processes, " FCFS ")
        self.cpu.printGanntChart()
        self.printAvgs(self.processes, self.cpu.getTotalCycles())

    def getNextProcess(self):
        # Sort by Arrival and then PID
        self.processes.sort(key=lambda x: (x.arrival, x.pid))

        # Return processes that aren't done in order
        for p in enumerate(self.processes):
            if not p[1].complete:
                return p[1]

        return self.idleprocess


# Priority Scheduler
class PBS(Scheduler):

    def __init__(self, processes):
        super().__init__()
        self.processes = processes
        self.cpu = cpu.CPU()
        self.currentProcess = -1
        self.idleprocess = process.Process(["IDLE", 0, 0, 0])

    def run(self):
        # Run until all processes have finished
        while not self.allProcessesComplete(self.processes):
            nextprocess = PBS.getNextProcess(self)
            self.cpu.cycle(nextprocess)

        # Print stats
        self.printStats(self.processes, " PBS ")
        self.cpu.printGanntChart()
        self.printAvgs(self.processes, self.cpu.getTotalCycles())

    def getNextProcess(self):
        # Sort by Priority and arrival
        self.processes.sort(key=lambda x: (x.priority, x.arrival))

        # Check if there's a current process not completed
        if not self.currentProcess == -1:
            if not self.currentProcess.complete:
                return self.currentProcess

        # Get next process
        for p in enumerate(self.processes):
            if not p[1].complete:
                if p[1].arrival <= (self.cpu.getCurrentCycle()):
                    return p[1]

        return self.idleprocess


# Round Robin Scheduler
class RR(Scheduler):

    def __init__(self, processes, quantum):
        super().__init__()
        self.processes = processes
        self.cpu = cpu.CPU()
        self.currentProcess = -1
        self.timeQuantum = int(quantum)
        self.quantumProgress = 1
        self.idleprocess = process.Process(["IDLE", 0, 0, 0])

    def run(self):
        # Run until all processes have finished
        while not self.allProcessesComplete(self.processes):
            nextprocess = RR.getNextProcess(self)
            self.cpu.cycle(nextprocess)

        # Print stats
        self.printStats(self.processes, " Round Robin ")
        self.cpu.printGanntChart()
        self.printAvgs(self.processes, self.cpu.getTotalCycles())

    def getNextProcess(self):
        # Sort by arrival and PID
        self.processes.sort(key=lambda x: (x.arrival, x.pid))

        # See if there's a current process with valid time quantum to keep running
        if not self.currentProcess == -1:
            if not self.currentProcess.complete:
                if self.quantumProgress < self.timeQuantum:
                    self.quantumProgress = self.quantumProgress + 1
                    return self.currentProcess
                else:
                    self.quantumProgress = 1

        # Get a new process for next time quantum
        for p in enumerate(self.processes):
            if not self.currentProcess == p[1]:
                if not p[1].complete:
                    if p[1].arrival <= (self.cpu.getCurrentCycle()):
                        self.currentProcess = p[1]
                        return p[1]

        # No new processes ready apart from current
        for p in enumerate(self.processes):
            if not p[1].complete:
                if p[1].arrival <= (self.cpu.getCurrentCycle()):
                    self.currentProcess = p[1]
                    return p[1]

        self.quantumProgress = 1
        return self.idleprocess