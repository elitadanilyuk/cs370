public class Consumer extends Thread{
    Buffer sharedBuffer;
    double runningCount = 0;
    int runNum = 0;

    public Consumer(){ }
    public Consumer(Buffer sharedBuffer){
        this.sharedBuffer = sharedBuffer;
    }

    public void run(){
        while(runNum < 1000000){
            while(sharedBuffer.isEmpty){
                try{
                    sharedBuffer.wait();
                }
                catch(Exception e){ }
            }

            try {
                runningCount += sharedBuffer.remove(runNum % 1000);
                ++runNum;
                sharedBuffer.notifyAll();
            }
            catch(Exception e){ }

            if(runNum % 100000 == 0){
                System.out.printf("Consumer: Consumed %,d items, Cumulative value of consumed items=%.3f\n",runNum, runningCount);
            }

        }

    }
}