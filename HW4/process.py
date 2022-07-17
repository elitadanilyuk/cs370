import csv

def getProcesses(inputFile):
    # File validation
    try:
        file = open(inputFile, "r", newline='')
    except FileNotFoundError:
        print("File not found.\nExiting.")
        exit()
    except Exception:
        print("Generic File Exception.\nExiting.")
        exit()

    csvReader = csv.reader(file, delimiter=",")

    newProcs = []
    rowIndex = 0

    for row in csvReader:
        if len(row) != 4:
            print(f"Error reading row {rowIndex}")
        if rowIndex != 0:
            newProcs.append(Process(row))
        rowIndex = rowIndex + 1

    return newProcs


class Process:
    def __init__(self, csv):
        # Initializations
        self.pid = csv[0]
        self.arrival = int(csv[1])
        self.burst = int(csv[2])
        self.priority = int(csv[3])
        self.counter = 0
        self.start = -1
        self.end = -1
        self.complete = False

    def __str__(self):
        return 'PID: {pid}'.format(pid=self.pid)

    def getTurnaroundTime(self):
        return self.end - self.arrival

    def getWaiting(self):
        return (Process.getTurnaroundTime(self) - self.burst)
