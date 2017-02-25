package ConcurrentThreads;

/**
 * Created by Mingyuan Li on 2016/2/15.
 * Package name: ConcurrentThreads.
 * Project name: Thread.
 */
public class ConcurrentThreads
{
    public static void main(String[] args) {
        System.out.println("Main starting...");
        Thread t1 = new MyThread(1);
        Thread t2 = new MyThread(2);

        t1.start();
        t2.start();

        for (int i = 0; i < 5; i++)
            System.out.println("Main running");
        System.out.println("Main ending...");
    }
}
class MyThread extends Thread
{
    private int id;

    public MyThread(int id)
    {
        this.id = id;
    }
    public void run()
    {
        for (int i = 0; i < 5; i++)
            System.out.println("Thread " + id + " running...");
    }
}
