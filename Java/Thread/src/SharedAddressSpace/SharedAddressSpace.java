package SharedAddressSpace;

/**
 * Created by Mingyuan Li on 2016/2/15.
 * Package name: SharedAddressSpace.
 * Project name: Thread.
 */
public class SharedAddressSpace
{
    public static void main(String[] args) {
        int[] vals = {-1,-1,-1};

        Thread t0 = new MyThread(0, vals);
        Thread t1 = new MyThread(1, vals);
        Thread t2 = new MyThread(2, vals);

        t0.start();
        t1.start();
        t2.start();

        try
        {
            t0.join();
            t1.join();
            t2.join();
        }
        catch (InterruptedException e){}

        System.out.println("Vals[0] = " + vals[0]);
        System.out.println("Vals[1] = " + vals[1]);
        System.out.println("Vals[2] = " + vals[2]);
    }
}
class MyThread extends Thread
{
    private int id;
    private int[] array;

    public MyThread(int id, int[] array) {
        this.id = id;
        this.array = array;
    }

    @Override
    public void run() {
        array[id] = id;
    }
}
