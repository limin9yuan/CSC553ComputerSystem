package NumSum;

/**
 * Created by Mingyuan Li on 2016/2/23.
 * Package name: NumSum.
 * Project name: NumSum.
 */
public class NumSum
{
    private static int sum = 0;
    private static int[] list;
    public static void main(String[] args)
    {
        int start = 0;
        int end = 0;
        if (args.length > 0) {
            try {
                start = Integer.parseInt(args[0]);
                end  = Integer.parseInt(args[1]);
            } catch (NumberFormatException e) {
                System.err.println("Argument" + args[0] + " must be an integer.");
                System.exit(1);
            }
        }
        int length = end - start + 1;
        list = new int[length];
        for (int i = 0; i < length - 1; i++) {
            list[i] = i + start;
            System.out.println(list[i]);
        }

        int block = length / 4;
        int size1 = block;
        int size2 = block;
        int size3 = block;
        int size4 = length - (3 * block);
        int start1 = 0;
        int start2 = block;
        int start3 = start2 + block;
        int start4 = start3 + block;

        Thread t1 = new MyThread(1, start1, size1);
        Thread t2 = new MyThread(2, start2, size2);
        Thread t3 = new MyThread(3, start3, size3);
        Thread t4 = new MyThread(4, start4, size4);

        t1.start();
        t2.start();
        t3.start();
        t4.start();
        try
        {
            t1.join();
            t2.join();
            t3.join();
            t4.join();
        }
        catch (Exception e){
            e.printStackTrace();
        }
        System.out.println("Sum is " + sum);
    }
    static class MyThread extends Thread
    {
        private int id;
        private int start;
        private int size;

        public MyThread(int id, int start, int size)
        {
            this.id = id;
            this.start = start;
            this.size = size;
        }
        public void run()
        {
            for (int i = 0; i < size; i++)
            {
                sum += list[i + start];
            }
        }
    }

}
