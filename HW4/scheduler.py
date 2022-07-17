class Scheduler:
    def __init__(self):
        pass

    @staticmethod
    def printStats(processes, schedName):
        # Method to print stats
        processes.sort(key=lambda x: (x.pid))

        print("{:-^42}".format(schedName))
        print("{:^11}|{:^14}|{:^16}".format('Process ID', 'Waiting Time', ' Turnaround Time'))
        for p in enumerate(processes):
            print("{:^11}|{:^14}|{:^16}".format(p[1].pid, p[1].getWaiting(), p[1].getTurnaroundTime()))

        print()

    @staticmethod
    def printAvgs(processes, totalCycles):
        # Getting and printing averages

        totalWait = 0
        for p in enumerate(processes):
            totalWait = p[1].getWaiting() + totalWait
        avgWait = totalWait / len(processes)

        totalTurnaround = 0
        for p in enumerate(processes):
            totalTurnaround = p[1].getTurnaroundTime() + totalTurnaround
        avgTurnaround = totalTurnaround / len(processes)

        totalClockCycles = 0
        for p in enumerate(processes):
            totalClockCycles = p[1].burst + totalClockCycles
        throughput = len(processes) / totalCycles

        print("Average Waiting Time: {}".format(avgWait))
        print("Average Turnaround Time: {}".format(avgTurnaround))
        print("Throughput: {:.12}\n\n".format(throughput))

    @staticmethod
    def allProcessesComplete(processes):
        for p in enumerate(processes):
            if not p[1].complete:
                return False

        return True