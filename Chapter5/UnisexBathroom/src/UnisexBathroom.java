import java.util.concurrent.Semaphore;

/**
 * Created by Mingyuan Li on 2016/3/21.
 * Package name: PACKAGE_NAME.
 * Project name: UnisexBathroom.
 */
public class UnisexBathroom {
    private static Semaphore semaphoreMan;
    private static Semaphore semaphoreWoman;

    static int totMen = 0;
    static int totWomen = 0;


    public static void main(String[] args) {
        if (args.length != 2) {
            printUsage();
        }


        try {
            totMen = Integer.parseInt(args[0]);
            totWomen = Integer.parseInt(args[1]);
            semaphoreMan = new Semaphore(totMen, true);
            semaphoreWoman = new Semaphore(totWomen, true);
        } catch (NumberFormatException e) {
            printUsage();
        }

        System.out.println("Working        Entering        In Bathroom        Leaving");

        Thread[] men = new Thread[totMen];
        for (int i = 0; i < totMen; i++) {
            men[i] = new ManThread(i);
            men[i].start();
        }
        Thread[] women = new Thread[totWomen];
        for (int i = 0; i < totWomen; i++) {
            women[i] = new WomanThread(i);
            women[i].start();
        }

        for (int i = 0; i < totMen; i++) {
            try {
                men[i].join();
            } catch (InterruptedException e) {
            }
        }
        for (int i = 0; i < totWomen; i++) {
            try {
                women[i].join();

            } catch (InterruptedException e) {
            }
        }
        System.exit(0);
    }

    private static void printUsage() {
        System.out.println("Usage: java UnisexBathroom<totMen><totWomen>");
        System.out.println("<totMen>: Total number of men");
        System.out.println("<totWomen>: Total number of women");
        System.exit(-1);
    }

    public static void randomSleep(int max) {
        try {
            Thread.sleep((int) (Math.random() * max));
        } catch (Exception e) {

        }
    }
    private static class ManThread extends Thread {
        private int id;

        public ManThread(int id) {
            this.id = id;
        }

        public void run() {
            doWork();
            try {
                //If women permits < total women, mean there are women in bathroom
                //man thread do nothing, wait woman thread finish
                while (semaphoreWoman.availablePermits() < totWomen);
                semaphoreMan.acquire();
                useBathroom();
                semaphoreMan.release();
            } catch (InterruptedException e) {}
            doWork();
        }

        private void doWork() {
            System.out.println("Man " + id);
            UnisexBathroom.randomSleep(10000);
        }

        private void useBathroom() {
            System.out.println("               Man " + id);
            UnisexBathroom.randomSleep(100);
            System.out.println("                                Man " + id);
            UnisexBathroom.randomSleep(500);
            System.out.println("                                                  Man " + id);
            UnisexBathroom.randomSleep(100);
        }
    }

    private static class WomanThread extends Thread {
        private int id;

        public WomanThread(int id) {
            this.id = id;
        }

        public void run() {
            doWork();
            try {
                //if man permit < total man, means there are mem in bathroom
                //women thread do nothing, wait man thread finish
                while (semaphoreMan.availablePermits() < totMen);
                semaphoreWoman.acquire();
                useBathroom();
                semaphoreWoman.release();
            } catch (InterruptedException e) {}
            doWork();
        }

        private void doWork() {
            System.out.println("Woman " + id);
            UnisexBathroom.randomSleep(10000);
        }

        private synchronized void useBathroom() {
            System.out.println("               Woman " + id);
            UnisexBathroom.randomSleep(100);
            System.out.println("                                Woman " + id);
            UnisexBathroom.randomSleep(500);
            System.out.println("                                                  Woman " + id);
            UnisexBathroom.randomSleep(100);
        }
    }
}
