import java.util.Scanner;
public class SoftwareSalesDemo {



    public static void main(String[] args)
    	{
    		int quantity;

			SoftwareSales s = new SoftwareSales();

			Scanner keyboard = new Scanner(System.in);

			System.out.print("Enter your quantity: ");
			quantity = keyboard.nextInt();



			System.out.print("Price: " + s.getPrice());
			System.out.print("Discount: " + s.getDiscount());
			//System.out.print("Total: " + s.getTotal());

    }
}
