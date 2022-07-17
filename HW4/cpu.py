import process
from collections import namedtuple

class CPU:
    def __init__(self):
        # Initializing
        self.clockCycle = 0
        self.ganntLog = []
        self.idleprocess = process.Process(["IDLE", 0, 0, 0])
        self.totalCycles = 0

    def cycle(self, process):
        if process.arrival > self.clockCycle or process.complete:
            CPU.log(self, self.idleprocess)
            self.clockCycle = self.clockCycle + 1
        else:
            if process.start == -1:
                process.start = self.clockCycle

            process.counter = process.counter + 1
            if process.counter == process.burst:
                process.end = self.clockCycle + 1
                process.complete = True

            CPU.log(self, process)
            self.clockCycle = self.clockCycle + 1

    def log(self, process):
        self.ganntLog.append(process)

    def printGanntChart(self):
        lastProcess = self.ganntLog[0]
        start = 0
        end = 0
        pid = 0
        self.totalCycles = len(self.ganntLog)

        # Printing the Gantt Chart
        print("Gantt Chart is:")
        for l in enumerate(self.ganntLog):
            if l[1].pid != lastProcess.pid:
                end = l[0]
                print("[{:^6}]--{:^6}--[{:^6}]".format(start, lastProcess.pid, end))
                start = l[0]
                lastProcess = l[1]

            if l[0] == (self.totalCycles - 1):
                print("[{:^6}]--{:^6}--[{:^6}]\n".format(start, l[1].pid, l[0]+1))

    def getTotalCycles(self):
        return self.totalCycles

    def getCurrentCycle(self):
        return self.clockCycle