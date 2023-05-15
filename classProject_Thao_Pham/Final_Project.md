For this portion of the assignment assignment you will implement the EXCEPTION handling techniques covered in Chapter 9. Your application must handle at least three EXCEPTIONs. You will decide how to implement these EXCEPTIONs. Details for submitting your final project are provided below:
Submit your project using the assignment template
Include a copy of your completed pseudocode (50pts)  
Include a screen shot illustration the full execution of each menu item in your project  (40 pts)
Include a 4-6 sentence summary of your experience creating this application (40 pts) 
For me, creating a console application is not difficult, especially after knowing what my program is for. After that is how to the program run with the knowledge I have learn, such as the program’s containers, functions, algorithms and etc. The thing that I spent more time on was using the STL to make my code shorter and works better. For example, using the copy() algorithm to copy the elements from a container with other containers, or some algorithms don’t work with a type of container. While creating this application, I become more flexible at using the STL and debugging the code. 
Submit your full project in a compressed zipped folder (70 pts)
BONUS
Create a custom data type (struct) to store the objects contained in your container. The struct should have at least three attributes, for example, a car struct could have make, model, year as it's attributes. The bonus component will add 10 additional points to your final project.

 
CALL displayItems with menu
	PRINT Menu Item
	SET index to 0
	FOR go through menu
		Increment index by 1
		PRINT elements in menu
	ENDFOR

CALL displayOption
	PRINT “a - Adding an item to cart." // count()
		<< "\nd - Deleting an item from cart." // remove() & copy()
		<< "\ns - Sorting the cart in ascending price." //sort()
		<< "\nl - Lowest price item." // min_element()
		<< "\nh - Highest price item." // max_element()
		<< "\nt - Display the total value." //accumulate()
		<< "\nq - Quantity editing." // find()
		<< "\ne - exiting."
		<< "\nPlease select an option: "

CALL displayCart with cart
	PRINT Your Cart
	SET j to 0
	For go through cart
		PRINT elements in cart
	ENDFOR

CALL comparePrice with pair a and pair b
	RETURN value of pair a smaller value of pair b

CALL sorting with map cart
	SET index to 0
	SET vector items 
Copy the elements of map cart to vector items
	Use sort() with items
	PRINT “\n --- Your Cart in Ascending Price --- \n”
	For every element of items
		Increment index by 1
		PRINT elements in items
	ENDFOR

CALL minmax with map cart and char option
	IF option equals to l
		Use min_element() with cart
		PRINT the pair with smallest value
	ELSE
		Use max_element() with cart
		PRINT the pair with largest value
	ENDIF

CALL addItem with map menu and map cart
	SET index 
	PRINT “\nEnter the item’s index in menu: “
	OBTAIN index
	
	IF the pair with the index does not exist in cart THEN
Use insert() to add the pair with the index to cart
	ELSE
		Throw "\nThe item has already been added to the cart.”
	ENDIF
	RETURN cart

CALL deleteItem with map menu and map cart
	SET name, index
	SET vector items 
Copy the elements of map cart to vector items
	PRINT "\nEnter an item's index in cart: “.
	OBTAIN index
	Decrement the index
	Erase the elements in map cart
	Use remove() and erase to remove pair which has the input index from vector items
	Adding the elements in vector items to map cart
	RETURN cart

CALL quantity() with map menu and map cart
	SET index
	PRINT “\nEnter an item’s index in cart: “
	OBTAIN index
	Search for a pair which has the same index as input index in menu and cart
	PRINT “\nEnter the item’s quantity
	SET quantity
	OBTAIN quantity
	COMPUTING the value of the searched pair with quantity
	RETURN cart

CALL totalPrice with total and cart
	RETURN the sum of total and value of elements in cart.

CALL main
PRINT Pastry Store
SET menu, cart, option, sum
CALL displayItem with menu
CALL displayOptions
OBTAIN option
Begin
	WHILE option not equal ‘e’
		IF option equal ‘s’ THEN
IF map cart is not empty THEN
				CALL sorting
WHEN cart is empty
				 “Empty cart”
		ELSE IF option equal ‘a’ THEN
			CALL addItem with menu and cart
		ELSE IF option equal ‘d’ THEN 
IF map cart is not empty THEN
				CALL displayCart(cart)
				CALL deleteItem with menu and cart
WHEN cart is empty
				 “Empty cart”
		ELSE IF option equal ‘l’ THEN
IF map cart is not empty THEN
				CALL minmax with cart, option
WHEN cart is empty
				 “Empty cart”
		ELSE IF option equal ‘h’ THEN
IF map cart is not empty THEN
				CALL minmax cart, option
WHEN cart is empty
				 “Empty cart”
		Elise IF option equal ‘t’ THEN
			IF cart is not empty THEN
				CALL displayCart(cart)
				SET sum
				Calculate Sum using accumulate() with cart and CALL totalPrice
				PRINT sum
				Erase all elements of cart
			WHEN cart is empty
				“Empty cart”
		ELSE IF option equals ‘q’ THEN
			IF map cart is not empty THEN 
				CALL quantity with cart and menu
			WHEN cart is empty
				 “Empty cart”
		EXCEPTION 
			WHEN option is not equal to any character from above IF conditions 
 “Invalid option”
		ENDIF
		displayCart(cart)
		IF option equals to ‘t’ THEN
			PRINT “Your cart is empty”
		ENDIF
		displayItems(menu)
		displayOptions()
		OBTAIN option	
	ENDWHILE
END
PRINT “Bye!”
RETURN 0

            
