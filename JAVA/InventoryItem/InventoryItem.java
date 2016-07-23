

public class InventoryItem
{
	int quantity;
	double price;
	String name;

public  InventoryItem(double p, int q, String n)
{
	name=n;
	price=p;
	quantity=q;
}
	public InventoryItem()
	{
		name="unknown";
		price=0.0;
		quantity=0;
	}
	public String toString()
	{
		String str = "Name: " + name + "\nQuantity: "
			+ quantity +"\nPrice: " + price;
		return str;
	}
	public boolean equals(InventoryItem i)
	{
		if(name.equals(i.name) && quantity == i.quantity && price==i.price)
			return true;
		else
			return false;
	}

}
