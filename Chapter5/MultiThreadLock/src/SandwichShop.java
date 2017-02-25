/**
 * Created by Mingyuan Li on 2016/3/15.
 * Package name: PACKAGE_NAME.
 * Project name: MultiThreadLock.
 */
public class SandwichShop
{
    public static void main(String[] args) {
        if (args.length != 1)
        {
            printUsage();
        }
        int num = 0;
        try {
            num = Integer.parseInt(args[0]);
        }
        catch (NumberFormatException e) {
            printUsage();
        }
        System.out.println("Customer:\t\t\t\t\t\t\t\t\t\t\t| Employee");
        System.out.print("Traveling\tArrived\t\tOrdering\tBrowsing\tAt Register\tLeaving");
        System.out.println("\t\t| Waiting\tSandwich Making\t\tAt Register\tPayment Accepted");
        System.out.println();

        Thread emp = new EmployeeThread();
        emp.start();

        Thread[] custs = new Thread[num];
        for (int i = 0; i < num; i++)
        {
            custs[i] = new CustomerThread(i);
            custs[i].start();
        }
        for (int i = 0; i < num; i++)
        {
            try
            {
                custs[i].join();
            }
            catch (InterruptedException e)
            {

            }
        }
        System.exit(0);
    }
    private static void printUsage()
    {
        System.out.println("Usage: java SandwichShop <num>");
        System.out.println("  <num>: Number of customers");
        System.exit(-1);
    }
    public static void randomSleep(int max)
    {
        try
        {
            Thread.sleep((int) (Math.random() * max));
        }
        catch (InterruptedException e)
        {

        }
    }
}
class CustomerThread extends Thread
{
    private int id;

    public CustomerThread(int id)
    {
        this.id = id;
    }
    public void run()
    {
        travelToShop();
        arriveAtShop();
        placeOrder();
        browseShop();
        atRegister();
        leaveShop();
    }
    private void travelToShop()
    {
        System.out.println("Customer " + id + "\t\t\t\t\t\t\t\t\t\t\t|");
        SandwichShop.randomSleep(1000);
    }
    private void arriveAtShop()
    {
        System.out.println("\t\tCustomer " + id + "\t\t\t\t\t\t\t\t\t|");
    }
    private void placeOrder()
    {
        System.out.println("\t\t\t\tCustomer " + id + "\t\t\t\t\t\t\t|");
    }
    private void browseShop()
    {
        System.out.println("\t\t\t\t\t\tCustomer " + id + "\t\t\t\t\t|");
        SandwichShop.randomSleep(1000);
    }
    private void atRegister()
    {
        System.out.println("\t\t\t\t\t\t\t\tCustomer " + id + "\t\t\t|");
    }
    private void leaveShop()
    {
        System.out.println("\t\t\t\t\t\t\t\t\t\tCustomer " + id + "\t|");
    }
}
class EmployeeThread extends Thread
{
    public void run()
    {
        while (true)
        {
            waitForCustomer();
            makeSandwich();
            atCashRegister();
            paymentAccepted();
        }
    }
    private void waitForCustomer()
    {
        System.out.println("\t\t\t\t\t\t\t\t\t\t\t\t| Employee");
    }
    private void makeSandwich()
    {
        System.out.println("\t\t\t\t\t\t\t\t\t\t\t\t| \t\tEmployee");
        SandwichShop.randomSleep(1000);
    }
    private void atCashRegister()
    {
        System.out.println("\t\t\t\t\t\t\t\t\t\t\t\t| \t\t\t\t\tEmployee");
    }
    private void paymentAccepted()
    {
        System.out.println("\t\t\t\t\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\tEmployee");
    }
}
