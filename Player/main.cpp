#include "player.h"

int main() {
    int n = 0;							//current size
	Player* b;
	b=new Player [100]; 				//created array of 100 objects on heap                              ("new" called default constructor 100 times)
    store(b,&n);
    
    int choice;
    do{
		cout<<"\n=====================================\n";
		cout<<"       Player Management System       \n";
		cout<<"=====================================\n";
		cout<<"  1. Display List of Players\n";
		cout<<"  2. Update Player Information\n";
		cout<<"  3. Add New Player\n";
		cout<<"  4. Search for a Player\n";
		cout<<"  5. Top 3 Players List\n";
		cout<<"  6. Delete Player Entry\n";
		cout<<"  7. Quit\n";
		cout<<"=====================================\n";
		cout<<"Enter your choice: ";    
		cin>>choice;
			
		    switch (choice) {		
		        
		        case 1:{
		            cout<<"You selected option 1.\n";
		            cout << "\n-------------------------------------------------------------------------------------------------\n";
				    cout << setw(4) << "Jersey no." << " | " << setw(30) << "Player Name" << " | "
					<< setw(20) << "Runs" << " | " << setw(7) << "Wickets" << " | " 
					<< setw(6) << "Matches" << endl;
		    		cout << "\n-------------------------------------------------------------------------------------------------\n";
		    		for(int i=0;i<n;i++){
		    			b[i].display();
					}
		            	
		            break;
		        	}
		        case 2:{
		            cout<<"You selected option 2.\n";
		            int jn;
		            cout<<"Enter Jersey no. you want to update: ";
					cin>>jn;
					int playerfound=0;
					for(int i=0;i<n;i++){
						if(b[i].getjersey_no()== jn){
							playerfound=1;
							b[i].update();
						}		
					}if(playerfound==0){
						cout<<"Player not found can't update!!";
					}
					break;
				}
		            
	            case 3:{
		            cout<<"You selected option 3.\n";
		            add_Player(b, &n);
					break;
				}
	            
				case 4:{
		            cout<<"You selected option 4.\n";
		            search_Player(b, n);
					break;
				}
		           
				case 5:{
		            cout<<"You selected option 5.\n";
		            top_ratings(b, n);
					break;
				}
		           
		        case 6:{
		        	cout<<"You selected option 6.\n";
		            remove_Player(b, &n);
					break;
				}
		           
		        case 7:{
		        	cout<<"Quiting.... \n";
					break;
				}
		        	
		        default:
		            cout<<"Please enter valid choice!!\n";
		    }
    	}while(choice!=7);		
	
	return 0;
    delete[] b;
}




