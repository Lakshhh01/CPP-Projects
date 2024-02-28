#include "player.h"	



Player::Player() {
    strcpy(this->pname, "not given");
    this->jersey_no = 0;
    this->runs;
    this->wickets = 0;
    this->matches = 0;
}

Player::Player(char* nm, int i, int rns, int w, int m) {
    strcpy(this->pname, nm);
    this->jersey_no = i;
    this->runs=rns;
    this->wickets = w;
    this->matches = m;
}


//////////////////////////////////////////<<--Setters/Getters-->>//////////////////////////////////////////////////////


void Player::setjersey_no(int i) {
    this->jersey_no = i;
}

void Player::setName(char* nm) {
    strncpy(this->pname, nm, sizeof(this->pname) - 1);
    this->pname[sizeof(this->pname) - 1] = '\0';
}
void Player::setRuns(int r) {
    this->runs=r;
}

void Player::setWickets(int w) {
    this->wickets = w;
}

void Player::setMatches(int m) {
    this->matches = m;
}

int Player::getjersey_no() {
    return this->jersey_no;
}

char* Player::getName() {
    return this->pname;
}

int Player::getRuns() {
    return this->runs;
}
int Player::getWickets() {
    return this->wickets;
}

int Player::getMatches() {
    return this->matches;
}
    
/////////////////////////////////////////////////<<--Update-->>//////////////////////////////////////////////////////
void Player::update(){
		
			int ch;
			cout<<"Enter if you want to update:\n1)Runs\n2)Wickets\n3)Matches : ";
			cin>>ch;
			if(ch==1){
				int r;
				cout<<"Enter the new Runs ";
				cin>>r;
				this->runs=r;
				
			}
			else if(ch==2){
				int w;
				cout<<"Enter the new number of Wickets ";
				cin>>w;
				this->wickets=w ;           
				
			}
			else if(ch==3){
				int m;
				cout<<"Enter new number of matches: ";
				cin>>m;
				this->matches=m;
			}
			else{
				cout<<"\nEnter valid choice!!";
			}
			cout << "\n-------------------------------------------------------------------------------------------------\n";
		    cout << setw(4) << "Jersey no." << " | " << setw(30) << "Player Name" << " | " << setw(20) << "Runs" << " | " << setw(7) << "Wickets" << " | " << setw(6) << "Matches" << endl;
		    cout << "\n-------------------------------------------------------------------------------------------------\n";

			
			this->display();
			
}

////////////////////////////////////////////////<<--Display-->>//////////////////////////////////////////////////////
void Player::display(){
		
		        cout << setw(10) << this->jersey_no << " | " 
				<< setw(30) << this->pname << " | " << setw(20) << this->runs 
				<< " | " << setw(8) << fixed << setprecision(2) << this->wickets
				<< " | " << setw(6) << this->matches << endl;	
		
	}
  


/////////////////////////////////////////////////<<--Store-->>//////////////////////////////////////////////////////

void store(Player* b, int* n) {
	b[(*n)++] = Player("Virat Kohli", 18, 346, 4,10);			//parameterised constructor called
	b[(*n)++] = Player("Rohit Sharma",53, 111, 3,13);
	b[(*n)++] = Player("Jasprit Bumrah", 92, 457, 5,14);
	b[(*n)++] = Player("Ravindra Jadeja", 17, 150, 4,16);
	b[(*n)++] = Player("MS Dhoni", 7, 400, 15,30);

}
////////////////////////////////////////////////<<--Add-->>//////////////////////////////////////////////////////


void add_Player(Player* b, int* n) {
    if (*n >= 100) {
        cout << "Maximum number of Players reached. Cannot add more Players.\n";
        return;
    }

    cout << "\n\n---------Enter the details for the new Player entry--------:\n\n";
    char pname[50];
    int jersey_no;
    int rns;
    int wks;
    int mts;
	
	fflush(stdin);
    cout << "Enter Player Name: ";
//    cin>>pname;
	gets(pname);

    cout << "Enter jersey_no: ";
    cin >> jersey_no;

    fflush(stdin);

    cout << "Enter Runs made: ";
    cin>>rns;

    cout << "Enter Wickets taken: ";
    cin >> wks;

    cout << "Enter matches played: ";
    cin >> mts;

	
    b[*n].setjersey_no(jersey_no);
    b[*n].setName(pname);
    b[*n].setRuns(rns);
    b[*n].setWickets(wks);
    b[*n].setMatches(mts);
    (*n)++;								//increasing og. size

//    display(b, *n);
    cout << "\nNew Player entry added successfully!\n";
    for(int i=0;i<(*n);i++){					//this will call display() everytime for every i'th object in array b
    	b[i].display();
	}
}

////////////////////////////////////////////////<<--Search-->>//////////////////////////////////////////////////////

void search_Player(Player* b, int n) {
    int choice;
    cout << "Search 1. By jersey_no \n 2. By Name: \n ";
    cin >> choice;

    if (choice == 1) {
        int user_jersey_no;
        cout << "Enter the jersey_no of Player to search: ";
        cin >> user_jersey_no;

        int Playerfound = 0;

        for (int i = 0; i < n; i++) {
            if (user_jersey_no == b[i].getjersey_no()) {
                Playerfound = 1;
                cout << "Player found!!:\n";
                cout << "\n-------------------------------------------------------------------------------------------------\n";
			    cout << setw(4) << "Jersey no." << " | " << setw(30) << "Player Name" << " | " << setw(20) << "Runs" << " | " << setw(7) << "Wickets" << " | " << setw(6) << "Matches" << endl;
			    cout << "\n-------------------------------------------------------------------------------------------------\n";
    
				cout << setw(10) << b[i].getjersey_no() << " | " << setw(30) << b[i].getName() << " | " << setw(20) << b[i].getRuns() << " | " << setw(8) << fixed << setprecision(2) << b[i].getWickets() << " | " << setw(6) << b[i].getMatches() << endl;
                break;
            }
        }

        if (!Playerfound) {
            cout << "\nPlayer not found with jersey_no number " << user_jersey_no << "\n";
        }
    } else if (choice == 2) {
        char user_pname[30];
        fflush(stdin);
        cout << "Enter the Name of the Player to search: ";
        cin>>user_pname;

        int Playerfound = 0;

        for (int i = 0; i < n; i++) {
            if (strcmp(b[i].getName(), user_pname) == 0) {
                Playerfound = 1;
                cout << "\nPlayer found!!:\n";
                cout << "\n-------------------------------------------------------------------------------------------------\n";
			    cout << setw(4) << "Jersey no." << " | " << setw(30) << "Player Name" << " | " << setw(20) << "Runs" << " | " << setw(7) << "Wickets" << " | " << setw(6) << "Matches" << endl;
			    cout << "\n-------------------------------------------------------------------------------------------------\n";
    
				cout << setw(10) << b[i].getjersey_no() << " | " << setw(30) << b[i].getName() << " | " << setw(20) << b[i].getRuns() << " | " << setw(8) << fixed << setprecision(2) << b[i].getWickets() << " | " << setw(6) << b[i].getMatches() << endl;
                break;
            }
        }

        if (!Playerfound) {
            cout << "\nPlayer not found with name  " << user_pname << "\n";
        }
    }
}

////////////////////////////////////////////////<<--Top3-->>//////////////////////////////////////////////////////

void top_ratings(Player* b, int n) {
    Player sortedstructurearray[n];					//creating temporary array for this fucn^ 


//	copy all structures in this array
    for (int i = 0; i < n; i++) {
        sortedstructurearray[i].setjersey_no(b[i].getjersey_no());
        sortedstructurearray[i].setName(b[i].getName());
        sortedstructurearray[i].setRuns(b[i].getRuns());
        sortedstructurearray[i].setWickets(b[i].getWickets());
        sortedstructurearray[i].setMatches(b[i].getMatches());
    }

    Player tempstructure;			//tempstructure for swaping ,while sorting

    int ch;
    cout << "Enter choice to display Top 3 according to \n1)Runs \n2)Wickets\n";
    cin >> ch;

    if (ch == 1) {
    		//sorting structures according to wickets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sortedstructurearray[j].getRuns() > sortedstructurearray[i].getRuns()) {
                    tempstructure = sortedstructurearray[j];
                    sortedstructurearray[j] = sortedstructurearray[i];
                    sortedstructurearray[i] = tempstructure;
                }
            }
        }

        cout << "\n----------TOP 3 Players according to Runs----------\n";
        cout << "\n-------------------------------------------------------------------------------------------------\n";
	    cout << setw(4) << "Jersey no." << " | " << setw(30) << "Player Name" << " | " << setw(20) << "Runs" << " | " << 
		setw(7) << "Wickets" << " | " << setw(6) << "Matches" << endl;
	    cout << "\n-------------------------------------------------------------------------------------------------\n";
    
        for (int i = 0; i < 3 && i < n; i++) {
            cout << setw(10) << sortedstructurearray[i].getjersey_no() << " | " << setw(30) << sortedstructurearray[i].getName() <<  
			" | " << setw(20) << sortedstructurearray[i].getRuns() << " | " << 
			setw(8) << fixed << setprecision(2) << sortedstructurearray[i].getWickets()
			<< " | " << setw(6) << sortedstructurearray[i].getMatches() << endl;
        }
        cout << "\n";
    	}
		else if (ch == 2) {
		//sorting structures according to wickets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sortedstructurearray[j].getWickets() > sortedstructurearray[i].getWickets()) {
                    tempstructure = sortedstructurearray[j];
                    sortedstructurearray[j] = sortedstructurearray[i];
                    sortedstructurearray[i] = tempstructure;
                }
            }
        }

        cout << "\n----------TOP 3 Players according to Wickets----------\n";
       
        
        cout << "\n-------------------------------------------------------------------------------------------------\n";
	    cout << setw(4) << "Jersey no." << " | " << setw(30) << "Player Name" << " | " << setw(20) << "Runs" << " | " << 
		setw(7) << "Wickets" << " | " << setw(6) << "Matches" << endl;
	    cout << "\n-------------------------------------------------------------------------------------------------\n";
    
        for (int i = 0; i < 3 && i < n; i++) {
            cout << setw(10) << sortedstructurearray[i].getjersey_no() << " | " << setw(30) << sortedstructurearray[i].getName() << " | " << 
			" | " << setw(20) << sortedstructurearray[i].getRuns() << " | " << 
			setw(8) << fixed << setprecision(2) << sortedstructurearray[i].getWickets()
			<< " | " << setw(6) << sortedstructurearray[i].getMatches() << endl;
        }
        cout << "\n";
    } else {
        cout << "\nEnter valid choice";
    }
}

////////////////////////////////////////////////<<--Delete-->>//////////////////////////////////////////////////////

void remove_Player(Player* b, int* n) {
    int user_jersey_no;
    cout << "Enter the jersey_no of Player to Delete: ";
    cin >> user_jersey_no;

    int Playerfound = 0;

    for (int i = 0; i < *n; i++) {
        if (user_jersey_no == b[i].getjersey_no()) {
            Playerfound = 1;
            for (int j = i; j < (*n) - 1; j++) {
                b[j] = b[j + 1];
            }
            (*n)--;		//decreasing th original size
            cout << "\nRecord deleted successfully...";
            break;
        }
    }

    if (!Playerfound) {
        cout << "\nPlayer not found with jersey_no number " << user_jersey_no << "\n";
    } else {
        cout << "\n\nUpdated List of Players:\n";
//        display(b, *n);
		for(int i=0;i<(*n);i++){			//this will call display() evrytime ofr every i'th object in array b;
			b[i].display();
		}
    }
}
