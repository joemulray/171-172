/**Joseph Mulray
 *Homework #4
 *January 10 2015**/


public class SoftwareSales {
	int quantity;
	double discount;
	int price;
	double total;
	double newTotal;





	public double getDiscount()
	{

    	 	if (quantity>=10 && quantity<=19)
    	 		discount = .2;
    	 	else if (quantity>=20 && quantity<=49)
    	 		discount = .3;
    	 	else if (quantity>=50 && quantity<=99)
    	 		discount = .4;
    	 	else if (quantity>=100)
    	 		discount = .5;
    	 	return discount;
			}
	public int getPrice()
	{
		price=99;
		return price;
	}

    public double total()
    {
		newTotal = ((getPrice() - (getPrice()*getDiscount());
    		return newTotal;
    }



}