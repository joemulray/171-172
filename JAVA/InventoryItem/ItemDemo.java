
public class ItemDemo {

    public static void main(String[] args)
    	{
    	InventoryItem x = new InventoryItem(.75,100,"Chips");

    	InventoryItem z= new InventoryItem(.75,100,"Chips");

    	System.out.println(x);
    	System.out.println(z);

		if(x.equals(z))
			System.out.println("The two items are the same. ");
		else
			System.out.println("The two items are the different. ");
    }
}
