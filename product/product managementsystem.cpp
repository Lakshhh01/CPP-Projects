#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>

//------------------------------------------Colours------------------------------------------//

// Define color escape sequences
#define RESET   "\033[0m"
#define RED     "\033[91m"
#define YELLOW  "\033[93m"
#define MAGENTA "\033[95m"
#define CYAN    "\033[96m"

using namespace std;

struct Product {
//---------------------------------------------------------state:---------------------------------------------------------//
	
    char pname[30];
    int id;
    int quantity;
    double pr;
    int rating;
    
//---------------------------------------------------------Behaviours:---------------------------------------------------------//
    
    //constructors

    Product() {
        strcpy(this->pname, "not given");
        this->id = 0;
        this->quantity=0;
        this->pr = 0.0;
        this->rating = 0;
    }

    Product(int i,char* nm, int q, double p, int r) {
        this->id = i;
        strcpy(this->pname, nm);
        this->quantity=q;
        this->pr = p;
        this->rating = r;
    }
	//setters
    void setId(int i) {
        this->id = i;
    }

    void setName(char* nm) {
        strncpy(this->pname, nm, sizeof(this->pname) - 1);
        this->pname[sizeof(this->pname) - 1] = '\0';
    }

    void setPrice(double p) {
        this->pr = p;
    }

    void setRating(int r) {
        this->rating = r;
    }

    void setQuantity(int q) {
        this->quantity=q;
    }
	//getters:
    int getId() {
        return this->id;
    }

    char* getName() {
        return this->pname;
    }

    double getPrice() {
        return this->pr;
    }

    int getRating() {
        return this->rating;
    }

    int getQuantity(){
    	return this->quantity;
	}
    
//----------------------------------------------------Update()--------------------------------------------------------//


	void update() {
    int ch;
    cout << "Enter if you want to update: 1)Quantity\n2)Price : ";
    cin >> ch;

    if (ch == 1) {
        int qunt;
        cout << "Enter the new Quantity ";
        cin >> qunt;
        this->quantity = qunt;

    } else if (ch == 2) {
        int prc;
        cout << "Enter the new Price ";
        cin >> prc;
        this->pr = prc;

    } else {
        cout << "\nEnter valid choice!!";
    }

    cout << "\n-------------------------------------------------------------------------------------------------\n";
    cout << setw(4) << "ID" << " | " << setw(30) << "Product Name" << " | " << setw(20) << "Quantity" << " | " << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
    cout << "\n-------------------------------------------------------------------------------------------------\n";
	
	this->display();
	}

//--------------------------------------------------Display()------------------------------------//
	
	void display(){																//for every object in loop , this fubction will be called
		  cout << setw(4) << this->id << " | " << setw(30) << this->pname << " | "
		  << setw(20) << this->quantity << " | " << setw(8) << fixed << setprecision(2) << this->pr << " | " 
		  << setw(6) << this->rating << endl;
		
	}
};




//---------------------------------------------------------Store---------------------------------------------------------//
//void store(Product* p, int* n) {
//    p[(*n)++] = Product(01,"Patanjali Kehskanti", 1, 90.0, 4);
//    p[(*n)++] = Product(02,"Dettol Anticeptic", 3, 40.0, 5);
//    p[(*n)++] = Product(03,"Bourbon", 3,  20.0, 3);
//    p[(*n)++] = Product(04,"Dark Fantasy", 5 ,  60.0, 4);
//    p[(*n)++] = Product(05,"Maggie", 2, 12.0, 2);
//}


void store(Product* b, int *n) {
	char pname[30];
    int id;
    int quantity;
    double pr;
    int rating;
    for (int i = 0; i < *n; i++) {
    	
    	fflush(stdin);
        cout<<"Enter ProductName: ";
        cin>>pname;

        cout<<"Enter Product ID: ";
        cin>>id;
		

        cout<<"Enter Product price: ";
        cin>>pr;

        cout<<"Enter rating (out of five) for Product: ";
        cin>>rating;

        cout<<"Data stored successfully...\n";
	(*n)++;
    }
    for(int i=0;i<*n;i++){
    	b[i].display();
	}
}

//---------------------------------------------------------Add Product---------------------------------------------------------//
void add_Product(Product* p, int* n) {
	if (*n == 0) {
        cout << "\nCart is currently empty. Please add the first product.";
    }
//    if (*n >= 100) {
//    	int num;
//    	cout<<"\n Enter the number of new entries: "
//    	cin>>_ num;
//    	Product* new_arr = realloc ( p , sizeof(Product)*num);
		
//	        cout << "Maximum number of Products reached. Cannot add more Products.\n";
//	        return;
//    }
    cout << "\n\n---------Enter the details for the new Product entry--------:\n\n";
    char pName[50];
    int id;
    int qunt;
    double price;
    int rt;
	
	fflush(stdin);
    cout << "Enter Product Name: ";
    gets(pName);

	cout<<"Enter Quanity of product: ";
	cin>>qunt;
	
    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Product Price: ";
    cin >> price;

    cout << "Enter Rating (out of five) for the Product: ";
    cin >> rt;

    p[*n].setId(id);
    p[*n].setQuantity(qunt);
    p[*n].setName(pName);
    p[*n].setPrice(price);
    p[*n].setRating(rt);
    (*n)++;
    cout << "\n-------------------------------------------------------------------------------------------------\n";
    cout << setw(4) << "ID" << " | " << setw(30) << "Product Name" << " | " << setw(20) << "Quantity" << " | " << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
    cout << "\n-------------------------------------------------------------------------------------------------\n";
	
	for(int i=0;i<*n;i++){		//for every object p[i] , display will be called from structure
		p[i].display();
	}
//    display(b, *n);
    cout << "\nNew Product entry added successfully!\n";
}
//---------------------------------------------------------Search Product---------------------------------------------------------//
void search_Product(Product* p, int n) {
    int choice;
    cout << "Search 1. By id \n 2. By Name: \n ";
    cin >> choice;

    if (choice == 1) {
        int user_id;
        cout << "Enter the id of Product to search: ";
        cin >> user_id;

        int Productfound = 0;

        for (int i = 0; i < n; i++) {
            if (user_id == p[i].getId()) {
                Productfound = 1;
                cout << "Product found!!:\n";
                cout << "\n-------------------------------------------------------------------------------------------------\n";
                cout << setw(4) << "ID" << " | " << setw(30) << "Product Name" << " | " << setw(20) << "Quantity" << " | "  << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
                cout << "\n-------------------------------------------------------------------------------------------------\n";
                cout << setw(4) << p[i].getId() << " | " << setw(30) << p[i].getName() << " | " << setw(20) << p[i].getQuantity() << " | " << setw(8) << fixed << setprecision(2) << p[i].getPrice() << " | " << setw(6) << p[i].getRating() << endl;
                break;
            }
        }

        if (!Productfound) {
            cout << "\nProduct not found with id number " << user_id << "\n";
        }
    } else if (choice == 2) {
        char user_pname[30];
        fflush(stdin);
        cout << "Enter the Name of the Product to search: ";
        gets(user_pname);

        int Productfound = 0;

        for (int i = 0; i < n; i++) {
            if (stricmp(p[i].getName(), user_pname) == 0) {
                Productfound = 1;
                cout << "\nProduct found!!:\n";
                cout << "\n-------------------------------------------------------------------------------------------------\n";
                cout << setw(4) << "ID" << " | " << setw(30) << "Product Name" << " | " << setw(20) << "Quantity" << " | "  << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
                cout << "\n-------------------------------------------------------------------------------------------------\n";
                cout << setw(4) << p[i].getId() << " | " << setw(30) << p[i].getName() << " | " << setw(20) << p[i].getQuantity() << " | " << setw(8) << fixed << setprecision(2) << p[i].getPrice() << " | " << setw(6) << p[i].getRating() << endl;
                break;
            }
        }

        if (!Productfound) {
            cout << "\nProduct not found with name  " << user_pname << "\n";
        }
    }
}
//---------------------------------------------------------Top 3----------------------------------------------------------//
void top_ratings(Product* p, int n) {
    Product sortedstructurearray[n];									//creating temporary array for this fucn^ for sorting 

    for (int i = 0; i < n; i++) {
        sortedstructurearray[i].setQuantity(p[i].getQuantity());
        sortedstructurearray[i].setId(p[i].getId());
        sortedstructurearray[i].setName(p[i].getName());
        sortedstructurearray[i].setPrice(p[i].getPrice());
        sortedstructurearray[i].setRating(p[i].getRating());
    }

    Product tempstructure;												//creating temstructure for swaping,while sorting

    int ch;
    cout << "Enter choice to display according to \n1.Rating  2.Price :";
    cin >> ch;

    if (ch == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sortedstructurearray[j].getRating() > sortedstructurearray[i].getRating()) {
                	//sorting structures according to Ratings
                    tempstructure = sortedstructurearray[j];
                    sortedstructurearray[j] = sortedstructurearray[i];
                    sortedstructurearray[i] = tempstructure;
                }
            }
        }

        cout << "\n----------TOP 3 Products in cart according to Ratings----------\n";
        cout << "\n---Products---\n";
        cout << "\n-------------------------------------------------------------------------------------------------\n";
        cout << setw(4) << "ID" << " | " << setw(30) << "Product Name" << " | " << setw(20) << "Quantity" << " | "   << " | " << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
        cout << "\n-------------------------------------------------------------------------------------------------\n";

        for (int i = 0; i < 3 && i < n; i++) {
            cout << setw(4) << sortedstructurearray[i].getId() << " | " << setw(30) << sortedstructurearray[i].getName()
			 << " | " << setw(20) << sortedstructurearray[i].getQuantity() << " | " << setw(8) << fixed << setprecision(2) 
			<< sortedstructurearray[i].getPrice() << " | " << setw(6) << sortedstructurearray[i].getRating() ;
        }
        cout << "\n";
    } else if (ch == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sortedstructurearray[j].getPrice() > sortedstructurearray[i].getPrice()) {
                	//sorting structures according to Price
                    tempstructure = sortedstructurearray[j];
                    sortedstructurearray[j] = sortedstructurearray[i];
                    sortedstructurearray[i] = tempstructure;
                }
            }
        }

        cout << "\n----------Your TOP 3 Products in Cart according to Price----------\n";
       
        cout << "\n-------------------------------------------------------------------------------------------------\n";
        cout << setw(4) << "ID" << " | " << setw(30) << "Product Name" << " | " << setw(4) << "ID" << " | "  << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
        cout << "\n-------------------------------------------------------------------------------------------------\n";

        for (int i = 0; i < 3 && i < n; i++) {
    	cout << setw(4) << sortedstructurearray[i].getId() << " | "
        << setw(30) << sortedstructurearray[i].getName() << " | "
        << setw(20) << sortedstructurearray[i].getQuantity() << " | "
        << setw(8) << fixed << setprecision(2) << sortedstructurearray[i].getPrice() << " | "
        << setw(6) << sortedstructurearray[i].getRating() << endl;
		}

        cout << "\n";
    } else {
        cout << "\nEnter valid choice";
    }
}

//---------------------------------------------------------Delete Product---------------------------------------------------------//

void remove_Product(Product* p, int* n) {
    int prod_id;
    cout << "Enter the id of Product to Delete: ";
    cin >> prod_id;

    int Productfound = 0;

    for (int i = 0; i < *n; i++) {
        if (prod_id == p[i].getId()) {
            Productfound = 1;
            for (int j = i; j < (*n) - 1; j++) {		
                p[j] = p[j + 1];				
            }
            (*n)--;						//decreasing the original size
            cout << "Record deleted successfully...";
            break;
        }
    }

    if (!Productfound) {
        cout << "\nProduct not found with id number " << prod_id << "\n";
    } else {
        cout<<"\n\n...***Updated Product list***...\n\n";
        for(int i=0;i<*n;i++)
            {
            	p[i].display();
			}

    }
}


//----------------------------------------Calculate total Bill-------------------------------------------
void cart_Total(Product* p,int n){
	
	if(n==0){
		cout<<"Empty Cart!!!\nShop now??";
		
	}
	double Total_amt=0;
	
	for(int i=0;i<n;i++){
		Total_amt = Total_amt + (p[i].getQuantity()*p[i].getPrice());
	}
	cout<<"\n Your Total Bill Amount : "<<Total_amt;
	
	
}

//------------------------------------------------Choice------------------------------------------------//

void Choice(Product* p,int n){
	 
			
		
}
//---------------------------------------------------------main---------------------------------------------------------//

int main() {
    int n = 0;							//current size
	 
//    printf("Enter number of Products:");
//    scanf("%d", &n);
//	  Product* p = new Product[n];
		
	Product* p;
	p=new Product [100]; 				//created array of 100 objects on heap                              ("new" called default constructor 100 times)
    store(p,&n);
    int choice;
//   	Choice(p,n);
	
		do{
	        cout << "\n\n" << "\033[96m" << "=================================================\n";
			cout << "     ...***Product Management System***...       \n";
			cout << "=================================================\n" << "\033[0m";
			cout << "\033[96m" << "       1. Display Cart\n";
			cout << "       2. Update Product Information\n";
			cout << "       3. Add New Product\n";
			cout << "       4. Search for a Product\n";
			cout << "       5. Top 3 Favourite Products List \n";
			cout << "       6. Delete Product Entry\n";
			cout << "       7. Calculate Total Cart Price\n";
			cout << "\033[93m" << "       8. Quit\n";
			cout << "\033[96m" << "================================================\n" << "\033[0m";
			cout << "Enter your choice: ";

			cin>>choice;
				
			    switch (choice) {		
			        
			        case 1:{
			            cout<<"You selected option 1.\n";
			            cout << "\n-------------------------------------------------------------------------------------------------\n";
					    cout << setw(4) << "ID" << " | " << setw(30) << "Product Name" << " | " << setw(20) << "Quantity" << " | "  << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
					    cout << "\n-------------------------------------------------------------------------------------------------\n";
	      
			            for(int i=0;i<n;i++){
			            	p[i].display();
						}
	 
						break;
			        	}
			        case 2:{
			            cout<<"You selected option 2.\n";
			            int id;
			            cout<<"Enter id of product you want to update: ";
						cin>>id;
						int Productfound=0;
						for(int i=0;i<n;i++){
							if(p[i].getId()== id){
								Productfound=1;
								p[i].update();
							}		
						}if(Productfound==0){
							cout<<"Product not found can't update!!";
						}
						
						break;
					}
			            
		            case 3:{
			            cout<<"You selected option 3.\n";
			            add_Product(p, &n);
						break;
					}
		            
					case 4:{
			            cout<<"You selected option 4.\n";
			            search_Product(p, n);
						break;
					}
			           
					case 5:{
			            cout<<"You selected option 5.\n";
			            top_ratings(p, n);
						break;
					}
			           
			        case 6:{
			        	cout<<"You selected option 6.\n";
			            remove_Product(p, &n);
						break;
					}
			           
			        case 7:{
			        	cout<<"\nCalculating total amount...\n";
			        	cart_Total(p,n);
			        
			        	break;
					}
					case 8:{
			        	cout << "\033[93m" << "Quiting...\n";
						break;
					}
			        	
			        default:
			            cout<<"Please enter valid choice!!\n";
			    }
    	}while(choice!=8);
	
	return 0;
    delete[] p;
}







//----------------------------------------store--------------------------------------------------------------//


////----------------------------------------------------Display---------------------------------------------------------//
//void display(Product* b, int n) {
//    cout << "\n-------------------------------------------------------------------------------------------------\n";
//    cout << setw(4) << "ID" << " | " << setw(30) << "Product Name" << " | " << setw(20) << "Author" << " | " << setw(8) << "Price" << " | " << setw(6) << "Rating" << endl;
//    cout << "\n-------------------------------------------------------------------------------------------------\n";
//    for (int i = 0; i < n; i++) {
//        cout << setw(4) << p[i].getId() << " | " << setw(30) << p[i].getName() << " | " << setw(20) << p[i].getAuthor() << " | " << setw(8) << fixed << setprecision(2) << p[i].getPrice() << " | " << setw(6) << p[i].getRating() << endl;
//    }
//    cout << "\n";
//}   

//-----------------------------------------------update----------------------------------------------------//

//    void update_Product(Product* b, int n) {
//        int userid;
//        cout << "Enter the id of the Product you want to update: ";
//        cin >> userid;
//
//        int Productfound = 0;
//
//        for (int i = 0; i < n; i++) {
//            if (userid == p[i].getId()) {
//                Productfound = 1;
//                cout << "Enter if you want to update:\n1) Price of Product\n2) Rating of Product:\n ";
//                int choice;
//                cin >> choice;
//
//                if (choice == 1) {
//                    cout << "Enter Product price: ";
//                    cin >> p[i].pr;
//                } else if (choice == 2) {
//                    cout << "Enter rating (out of 5) for the Product : ";
//                    cin >> p[i].rating;
//                } else {
//                    cout << "Invalid choice!\n";
//                }
//            }
//        }
//
//        if (!Productfound) {
//            cout << "\nProduct not found... Can't update.\n";
//        } else {
//            cout << "\n----------Updated Product details:---------\n";
//            
//	        //display
//	        std::cout << "\n-------------------------------------------------------------------------------------------------\n";
//		    std::cout << std::setw(4) << "ID" << " | " << std::setw(30) << "Product Name" << " | " << std::setw(20) << "Author" << " | "
//		    << std::setw(8) << "Price" << " | " << std::setw(6) << "Rating" << std::endl;
//		    std::cout << "-------------------------------------------------------------------------------------------------\n";
//
//		    for (int i = 0; i < n; i++) {
//		      std::cout << std::setw(4) << p[i].getId() << " | " << std::setw(30) << p[i].getName() << " | "
//              << std::setw(20) << p[i].getAuthor() << " | " << std::setw(8) << std::fixed << std::setprecision(2)
//              << p[i].getPrice() << " | " << std::setw(6) << p[i].getRating() << std::endl;
//    }
//
//    cout << "\n";
//
//        }
//    }
 

