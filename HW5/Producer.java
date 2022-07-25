// import java.util.Random;

// public class Producer extends java.lang.Thread {
// 	//Necessary variables and object declaration
// 	Random randomWithSeed;

// 	public Producer(Buffer buff, int count, int id, int seed) {
// 		//Assign values to the variables
// 		randomWithSeed = new Random(seed);
// 	}

// 	@Override
// 	public void run() {
// 		/* Your code goes in here
// 		--->To generate a value between 0 (inclusive) and 99 (inclusive) using the seeded random  number generator use the following code
// 		--->          int variable = randomWithSeed.nextInt(100);
// 		*/
// 		int count = 0;
// 		Buffer sharedBuffer;
// 		int runNum = 0;
// 		double runningCount = 0;

// 		while(count < 1000000){
// 			synchronized (buffer) {  
//                     try {  
// 						int nextProduced = new Random().nextInt(99);
// 				        if (  buffer.getIn() == buffer.getOut() && buffer.getBuffercount() == BUFFER_SIZE) {
// 							// The buffer is full 
// 				        	System.out.println(Thread.currentThread().getName() +
// 													": Unable to insert, buffer full, at Time: " + 
// 														Coordinator.getTime());
// 				        	buffer.wait();
// 				        }
// 				        int loc = buffer.makeNewItem(nextProduced);
// 						System.out.println(Thread.currentThread().getName() +
// 												": Placed " + nextProduced +
// 													" at Location " + loc +
// 														" at Time: " + Coordinator.getTime());
// 				        buffer.notifyAll();
// 				        if (debug)
// 				        	System.out.println("[" + buffer.getIn() + ", " + buffer.getOut()+"]");
				        
//                     } catch (InterruptedException ie) {}
                    
//                 }
                
//                 try {
// 		        	Thread.sleep(0, new Random().nextInt(waitTime));
// 		        	//inserting random delays
// 			    } catch(InterruptedException e) {  
// 			        e.printStackTrace();  
// 			} 
			     
// 		}
// 		if (outprint != true) outprint = true; 
// 		else
// 			System.out.println("Producer: Finished producing " + proSize + " items."); 
// 	}  
// }

import java.util.Random;

public class Producer extends Thread{
    Buffer sharedBuffer;
    Random random = new Random();
    int runNum = 0;
    double runningCount = 0;
    public Producer(){

    }
    public Producer(Buffer sharedBuffer){
        this.sharedBuffer = sharedBuffer;
    }
    public void run(){
        while(runNum < 1000000){
            while(sharedBuffer.isFull){
                try {
                    sharedBuffer.wait();
                }
                catch(Exception e){ }
            }
            double ranNum = genRandomNum();
            runningCount += ranNum;
            try {
                sharedBuffer.insert(ranNum, runNum % 1000);
                ++runNum;
                sharedBuffer.notifyAll();
            }
            catch(Exception e){ }

            if(runNum % 100000 == 0){
                System.out.printf("Producer: %d inserted %d at index %d at time %s\n",runNum, runningCount, 1,Coordinator.getTime());
            }
        }


    }

    private double genRandomNum(){
        return random.nextDouble() * 100.0;
    }
}
