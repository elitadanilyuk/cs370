import java.lang.Exception;
import java.util.Random;
import java.time.Instant;
import java.time.Clock;
import java.time.Duration;

class Coordinator {
	public static void main(String[] args) {
		/* 
		 * Your code goes in here
		 */

		// Buffer buffer = new Buffer(BUFFER_SIZE);
		// Producer[] producer = new Producer[numProducers];
		// Comsumer[] consumer = new Comsumer[numConsumers];
        // for(int i = 0; i < numProducers; i++){
		// 	producer[i] = new Producer();
		// 	producer[i].setName("Producer " + i);
		// 	System.out.println(producer[i].getName() + " starting...");
		// 	producer[i].start();
		// }
		// for(int i = 0; i < numConsumers; i++){
		// 	consumer[i] = new Comsumer();
		// 	consumer[i].setName("Comsumer " + i);
		// 	System.out.println(consumer[i].getName() + " starting...");
		// 	consumer[i].start();
		// } 

			Buffer sharedBuffer = new Buffer();
            Producer myProducer = new Producer(sharedBuffer);
            Consumer myConsumer = new Consumer(sharedBuffer);
            myProducer.start();
            myConsumer.start();
            while(myProducer.isAlive() || myConsumer.isAlive()){

            }
            System.out.printf("Producer(s): Finished producing %d items with checksum being %d\n", myProducer.runNum);
            System.out.printf("Consumer(s): Finished consuming %d items\n with checksums being %d", myConsumer.runNum);
	}

	//Call this function from your producer or your consumer to get the time stamp to be displayed
	public static String getTime() {
		Clock offsetClock = Clock.offset(Clock.systemUTC(), Duration.ofHours(-9));
		Instant time = Instant.now(offsetClock);
		String timeString = time.toString();
		timeString = timeString.replace('T', ' ');
		timeString = timeString.replace('Z', ' ');
		return(timeString);
	}
}