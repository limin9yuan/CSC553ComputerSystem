package FirstThread;

public class TestThread {

    public static void main(String[] args) {
	// write your code here
        System.out.println("Main thread running...");
        Thread t1 = new MyThread(1);
        t1.start();
        System.out.println("Main thread finished...");
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
        System.out.println("Thread " + id + " running...");
    }
}
