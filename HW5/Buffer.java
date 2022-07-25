/*
    This buffer can hold a fixed number of items.
    This buffer needs to be a first-in first-out (FIFO) buffer.
    You should implement this as a Circular Buffer that satisfies the FIFO.
    There should be exactly one instance of the buffer.
    The producer and the consumers must reference the same buffer.

    Note: use an Array to create the buffer.
        Arraylists, linked lists, etc. are not
        suitable to create circular buffers and
        will be marked off points on this requirement if used.
*/

public class Buffer {
    boolean isEmpty = true;
    boolean isFull = false;
    int size = 0;
    double[] sharedBuffer = new double[1000];

    public synchronized void sizeAlterationsInsert(){
        if(this.isEmpty){
            this.isEmpty = false;
        }
        if(++this.size == 1000){
            this.isFull = true;
        }

    }

    public synchronized void sizeAlterationsRemove(){
        if(this.isFull){
            this.isFull = false;
        }
        if(--this.size == 0){
            this.isEmpty = true;
        }
    }

    public synchronized void insert(double food, int position) throws InterruptedException{
        sizeAlterationsInsert();
        sharedBuffer[position] = food;
    }

    public synchronized double remove(int position) throws InterruptedException{
        sizeAlterationsRemove();
        return sharedBuffer[position];
    }
}