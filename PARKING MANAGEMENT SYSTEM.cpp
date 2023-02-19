#include <iostream>
#include<windows.h>
#include<fstream>
#include<string.h>


using namespace std;

struct cars
{
    string vehicle_no;
    string vehicle_type;
    string owner_name;
    string lastname;
    string cnic_no;
    string cell_no;
};

cars c;

void rateList();
void add_vehicle();
void searcher();
void deleter();
void total();
void earntotal();
void display();
void record_delete();
void endup();

int main()
{
    system("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);        
    SetConsoleTextAttribute(h,FOREGROUND_RED );
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t*      *      *       *******       *              *****        ******          ****** ******        ****** "<<endl;
    cout<<"\t\t\t*      *      *      *              *             *            *      *        *      *      *      *       "<<endl;
    cout<<"\t\t\t*      *      *      *              *            *            *        *       *      *      *      *       "<<endl;
    SetConsoleTextAttribute(h,0x6 );
    cout<<"\t\t\t*      *      *      ********       *            *            *        *       *      *      *       ****** "<<endl;
    cout<<"\t\t\t*      *      *      *              *            *            *        *       *      *      *      *       "<<endl;
    cout<<"\t\t\t*      *      *      *              *             *            *      *        *      *      *      *       "<<endl;
   SetConsoleTextAttribute(h,FOREGROUND_GREEN );
    cout<<"\t\t\t ****** ******        ******         *******       *****        ******         *      *      *       ****** "<<endl;
    cin.ignore();
    cin.get();

    label:
    system ("cls");
   SetConsoleTextAttribute(h,FOREGROUND_BLUE );
    cout<<endl<<endl<<endl;
    cout<<"\t\t<--------------------------------------------------------->"<<endl;
    cout<<"\t\t  |        Press 1 to see Rate List.                    |"<<endl;
    cout<<"\t\t<--------------------------------------------------------->"<<endl;
    cout<<"\t\t  |        Press 2 to add vehicle.                      |"<<endl;
    cout<<"\t\t<--------------------------------------------------------->"<<endl;
    cout<<"\t\t  |        Press 3 to search a vehicle.                 |"<<endl;
    cout<<"\t\t<--------------------------------------------------------->"<<endl;
    cout<<"\t\t  |        Press 4 to delete the vehicle.               |"<<endl;
    cout<<"\t\t<--------------------------------------------------------->"<<endl;
    cout<<"\t\t  |        Press 5 to show total vehicles & Amount.     |"<<endl;
    cout<<"\t\t<--------------------------------------------------------->"<<endl;
    cout<<"\t\t  |        Press 6 to show the record.                  |"<<endl;
    cout<<"\t\t<--------------------------------------------------------->"<<endl;
    cout<<"\t\t  |        Press 7 to show Amount Earned.               |"<<endl;
    cout<<"\t\t<--------------------------------------------------------->"<<endl;
    cout<<"\t\t  |        Press 8 to Delete The Whole Record.          |"<<endl;
    cout<<"\t\t<--------------------------------------------------------->"<<endl;
    cout<<"\t\t  |        Press 9 to Exit.                             |"<<endl;
    cout<<"\t\t<--------------------------------------------------------->"<<endl<<endl;
    int choice;
    cout<<"\t\tEnter your Choice: ";
    cin>>choice;
    while (choice < 0 || choice > 9)
    {
        cout<<"\t\tInvalid!  Re-Enter your Choice: ";
        cin>>choice;
    }

    switch (choice)
    {
     case 1:
        system ("cls");
        rateList();
        goto label;
        break;

     case 2:
        system ("cls");
        add_vehicle();
        goto label;
        break;
     case 3:
        system ("cls");
        searcher();
        goto label;
        break;
     case 4:
        system ("cls");
        deleter();
        goto label;
        break;
     case 5:
        system ("cls");
        total();
        goto label;
        break;
     case 6:
        system ("cls");
        display();
        goto label;
        break;
     case 7:
        system ("cls");
        earntotal();
        goto label;
        break;
     case 8:
        system ("cls");
        record_delete();
        goto label;
        break;
     case 9:
        system ("cls");
        endup();
        exit(0);
        return 0;
     
    }

    return 0;
}

void rateList()
{
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\t|             RATE LIST               |"<<endl;
    cout<<"\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\t| BIKE.\t|\tCAR.\t|\tBUS."<<"  |"<<endl;
    cout<<"\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\t| "<<100<<"\t|\t"<<200<<"\t|\t"<<300<<"   |"<<endl;
    cout<<"\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\t|                                     |"<<endl;
    cout<<"\t\t\t|   Maximum Parking = 50 Vehicles.    |"<<endl;
    cout<<"\t\t\t|                                     |"<<endl;
    cout<<"\t\t\t---------------------------------------"<<endl;
    cin.ignore();
    cin.get();
}



void add_vehicle()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);        
    int type;
    ofstream write;
    write.open("vehicles.txt", ios::app );
    if(write.fail())
    {
    	SetConsoleTextAttribute(h,FOREGROUND_RED );
        cout<<"\t\t\t\tNO DATA IN FILE."<<endl<<endl;
        cout<<"\t\t\tPress Enter to continue..............";
        cin.ignore();
        cin.get();
    }
    SetConsoleTextAttribute(h,FOREGROUND_BLUE );
    cout<<endl<<endl<<endl;
    cout<<"\t\t\tPlease Enter vehicle Number      (ABC-0000)                      >==>  ";
    cin>>c.vehicle_no;
    cout<<"\n\t\t\tPlease Enter vehicle type(1 for Bike / 2 for Car / 3 for Bus)    >==>  ";
    cin>>type;
    while (type < 1 ||  type > 3)
    {
    	SetConsoleTextAttribute(h,FOREGROUND_RED );
        cout<<"\t\t\tPlease Enter vehicle type(1 for Bike / 2 for Car / 3 for Bus)  >==>  ";
        cin>>type;
    }
    switch(type)
    {
        case 1:
        c.vehicle_type = "Bike";
        break;
        case 2:
        c.vehicle_type = "Car";
        break;
        case 3:
        c.vehicle_type = "Bus";
    }
    SetConsoleTextAttribute(h,FOREGROUND_BLUE );
    cout<<"\n\t\t\tPLease enter your name        (First,Last)                     >==>  ";
    cin.ignore();
    getline(cin>>c.owner_name,c.lastname);
    if(c.lastname.empty())
    {
        c.lastname="NO_lastname";
    }
    cout<<"\n\t\t\tPLease enter your CNIC NO. ( 00000-0000000-0 )                   >==>  ";
    cin>>c.cnic_no;
    cout<<"\n\t\t\tPLease enter car Phone NO.  ( 0000-0000000 )                     >==>  ";
    cin>>c.cell_no;
    write <<c.vehicle_no<<" "<<c.vehicle_type<<" "<<c.owner_name<<" "<<c.lastname<<" "<<c.cnic_no<<" "<<c.cell_no<<"\n";
    write.close();
    cout<<endl<<endl<<"\t\t\t\tyour vehicle is successfully parked....... "<<endl;
    cin.ignore();
    cin.get();

}


void searcher()
{
    cout<<endl<<endl<<endl;
    string x;
    bool check=false;
    cout<<"\t\t\tPlease Enter vehicle Number  to search       (ABC-0000)             >==>  ";
    cin>>x;
    cout<<endl<<endl;
    ifstream read;
    read.open("vehicles.txt");
    if(read.fail())
    {
    	system("color 4");
        cout<<"\t\t\t\tNO DATA IN FILE."<<endl<<endl;
        cout<<"\t\t\tPress Enter to continue..............";
        cin.ignore();
        cin.get();
    }
    else
    {
        while( read>>c.vehicle_no>>c.vehicle_type>>c.owner_name>>c.lastname>>c.cnic_no>>c.cell_no)
        {
            if(c.vehicle_no == x)
                {
                	system("color 0");
                    cout<<"\t\t\t---------------------------------------------------------"<<endl;
                    cout<<"\t\t\t                        RECORD                           "<<endl;
                    cout<<"\t\t\t---------------------------------------------------------"<<endl;
                    cout<<"\t\t\t|  Vehicle Number           >==>  "<<c.vehicle_no<<endl;
                    cout<<"\t\t\t---------------------------------------------------------"<<endl;
                    cout<<"\t\t\t|  Vehicle Type             >==>  "<<c.vehicle_type<<endl;
                    cout<<"\t\t\t---------------------------------------------------------"<<endl;
                    if(c.lastname=="NO_lastname")
                    { 
                        cout<<"\t\t\t|  Owner  Name              >==>  "<<c.owner_name<<endl;
                        cout<<"\t\t\t---------------------------------------------------------"<<endl;   
                    }
                    else
                    { 
                        cout<<"\t\t\t|  Owner  Name              >==>  "<<c.owner_name<<' '<<c.lastname<<endl;   
                        cout<<"\t\t\t---------------------------------------------------------"<<endl;
                    }
                    cout<<"\t\t\t|  CNIC Number              >==>  "<<c.cnic_no<<endl;
                    cout<<"\t\t\t---------------------------------------------------------"<<endl;
                    cout<<"\t\t\t|  Contact No.              >==>  "<<c.cell_no<<endl;
                    cout<<"\t\t\t---------------------------------------------------------"<<endl;
                    cout<<"\t<--------------------------------------------------------------------------------------->"<<endl;
                    check = true;
                }
        }
        if(check==false)
        {
        	system("color 4");
            cout<<"\n\n\t\t\t\tVehicle Not Found"<<endl<<endl;
            cout<<"\t\t\tPress Enter Key..........";
        }
        cin.ignore();
        cin.get();
    }
    read.close();
    
}

void deleter()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<endl<<endl<<endl;
    string x;
    bool check=false;
    cout<<"\t\t\tPlease Enter vehicle Number to delete       (ABC-0000)             >==>  ";
    cin>>x;
    cout<<endl<<endl;
    ifstream read;
    ofstream temp;
    ofstream earn;
    read.open("vehicles.txt");
    temp.open("temp.txt",ios::app);
    earn.open("earn.txt",ios::app);
    if(read.fail())
    {
    	system("color 4");
        cout<<"\t\t\t\tNO DATA IN FILE."<<endl<<endl;
        cout<<"\t\t\tPress Enter to continue..............";
        cin.ignore();
        cin.get();
    }
    else
    {
        while(read>>c.vehicle_no>>c.vehicle_type>>c.owner_name>>c.lastname>>c.cnic_no>>c.cell_no)
        {
            if(c.vehicle_no==x)
            {
            	system("color 4");
                cout<<"\t\t\t---------------------------------------------------------"<<endl;
                cout<<"\t\t\t                        RECORD                           "<<endl;
                cout<<"\t\t\t---------------------------------------------------------"<<endl;
                cout<<"\t\t\t|  Vehicle Number           >==>  "<<c.vehicle_no<<endl;
                cout<<"\t\t\t---------------------------------------------------------"<<endl;
                cout<<"\t\t\t|  Vehicle Type             >==>  "<<c.vehicle_type<<endl;
                cout<<"\t\t\t---------------------------------------------------------"<<endl;
                if(c.lastname=="NO_lastname")
                { 
                    cout<<"\t\t\t|  Owner  Name              >==>  "<<c.owner_name<<endl;
                    cout<<"\t\t\t---------------------------------------------------------"<<endl;   
                }
                else
                { 
                    cout<<"\t\t\t|  Owner  Name              >==>  "<<c.owner_name<<' '<<c.lastname<<endl;   
                    cout<<"\t\t\t---------------------------------------------------------"<<endl;
                }
                cout<<"\t\t\t|  CNIC Number              >==>  "<<c.cnic_no<<endl;
                cout<<"\t\t\t---------------------------------------------------------"<<endl;
                cout<<"\t\t\t|  Contact No.              >==>  "<<c.cell_no<<endl;
                cout<<"\t\t\t---------------------------------------------------------"<<endl;
                cout<<"\t<--------------------------------------------------------------------------------------->"<<endl;
                earn<<c.vehicle_no<<" "<<c.vehicle_type<<" "<<c.owner_name<<" "<<c.lastname<<" "<<c.cnic_no<<" "<<c.cell_no<<"\n";
                check=true;
            }
            else
            {
                temp<<c.vehicle_no<<" "<<c.vehicle_type<<" "<<c.owner_name<<" "<<c.lastname<<" "<<c.cnic_no<<" "<<c.cell_no<<"\n";
            }
        }
        if(check==false)
        {
        	system("color 4");
            cout<<"\n\n\t\t\t\tVehicle Not Found"<<endl<<endl;
            cout<<"\t\t\tPress Enter Key..........";
        }
        else
        {
        	SetConsoleTextAttribute(h,0x6 );
            cout<<"\n\t\t\t\tVehicle Deleted Successfully."<<endl<<endl;
            cout<<"\t\t\tPress Enter Key..........";
        }
        cin.ignore();
        cin.get();
    }
    earn.close();
    temp.close();
    read.close();
    remove ("vehicles.txt");
    rename ("temp.txt","vehicles.txt");
    
}

void total()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,0x6 );
    int car=0; int bike=0; int bus=0; int total_vehicle=0; int sum=0;
    cout<<endl<<endl<<endl;
    bool check = false;
    ifstream read;
    read.open("vehicles.txt");
    if(read.fail())
    {
    	system("color 4");
        cout<<"\t\t\t\t\tNO DATA IN FILE."<<endl<<endl;
        cout<<"\t\t\tPress Enter to continue..............";
        cin.ignore();
        cin.get();
    }
    else
    {
        while(read>>c.vehicle_no>>c.vehicle_type>>c.owner_name>>c.lastname>>c.cnic_no>>c.cell_no)
        {
            if(c.vehicle_type == "Bike")
            {
                bike++;
                total_vehicle++;
                sum = sum + 100;
            }
            else if (c.vehicle_type == "Car")
                {
                    car++;
                    total_vehicle++;
                    sum = sum + 200;
                }
            else
                {
                    bus++;
                    total_vehicle++;
                    sum = sum + 300;
                }
            check=true;
        }
        if(check==false)
        {
        	system("color 4");
            cout<<"\t\t\tVehicles Record Not Found.\n\n\t\t\tPress Enter Key to continue.........."<<endl;
        }
        else
        {
            cout<<"\t\t\t-----------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t|                     TOTAL VEHICLES & AMOUNT.                        |"<<endl;
            cout<<"\t\t\t-----------------------------------------------------------------------"<<endl<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl;
            cout<<"\t\t\t\t|  BIKES             >==>   "<<bike<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl;
            cout<<"\t\t\t\t|  Cars              >==>   "<<car<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl;
            cout<<"\t\t\t\t|  Buses             >==>   "<<bus<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl;
            cout<<"\t\t\t\t|  Total Vehicles    >==>   "<<total_vehicle<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl;
            cout<<"\t\t\t\t| "<<endl;
            cout<<"\t\t\t\t|       Current Amount     >==>  "<<sum<<endl;
            cout<<"\t\t\t\t| "<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl;
        }
        cin.ignore();
        cin.get();
    }
    read.close();
    
}


void earntotal()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,0x2 );
    int car=0; int bike=0; int bus=0; int total_vehicle=0; int sum=0;
    cout<<endl<<endl<<endl;
    bool check = false;
    ifstream read;
    read.open("earn.txt");
    if(read.fail())
    {
    	system("color 4");
        cout<<"\t\t\t\tNO DATA IN FILE."<<endl<<endl;
        cout<<"\t\t\tPress Enter to continue..............";
        cin.ignore();
        cin.get();
    }
    else
    {
        while( read>>c.vehicle_no>>c.vehicle_type>>c.owner_name>>c.lastname>>c.cnic_no>>c.cell_no)
        {
            if(c.vehicle_type == "Bike")
                   {
                       bike++;
                       total_vehicle++;
                       sum = sum + 100;
                   }
            else if (c.vehicle_type == "Car")
                   {
                       car++;
                       total_vehicle++;
                       sum = sum + 200;
                   }
            else
                   {
                       bus++;
                       total_vehicle++;
                       sum = sum + 300;
                   }
            check=true;
        }
        if(check==false)
        {
        	system("color 4");
            cout<<"\t\t\t\tVehicles Record Not Found.\n\n\t\t\tPress Enter Key to continue.........."<<endl;
            cin.ignore();
            cin.get();
        }
        else
        {
            cout<<"\t\t\t-----------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t|                     TOTAL VEHICLES & AMOUNT.                        |"<<endl;
            cout<<"\t\t\t-----------------------------------------------------------------------"<<endl<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl;
            cout<<"\t\t\t\t|  BIKES             >==>   "<<bike<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl;
            cout<<"\t\t\t\t|  Cars              >==>   "<<car<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl;
            cout<<"\t\t\t\t|  Buses             >==>   "<<bus<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl;
            cout<<"\t\t\t\t|  Total Vehicles    >==>   "<<total_vehicle<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl<<endl;
            cout<<"\t\t\t\t----------------------------------------------------"<<endl;
            cout<<"\t\t\t\t| "<<endl;
            cout<<"\t\t\t\t|     Earned  Amount     >==>  "<<sum<<endl;
            cout<<"\t\t\t\t| "<<endl;
            cout<<"\t\t\t\t--------------------------- ------------------------"<<endl;
        }
        cin.ignore();
        cin.get();    
    }
    read.close();
}




void display()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<endl<<endl<<endl;
    int i = 1;
    bool check = false;
    ifstream read;
    read.open("vehicles.txt");
    if(read.fail())
    {
    	system("color 4");
        cout<<"\t\t\t\tNO DATA IN FILE."<<endl<<endl;
        cout<<"\t\t\tPress Enter to continue..............";
        cin.ignore();
        cin.get();
    }
    else
    {
        while( read>>c.vehicle_no>>c.vehicle_type>>c.owner_name>>c.lastname>>c.cnic_no>>c.cell_no)
        {
        	switch(i){
        		case 1: case 8: case 15: case 22: case 29: case 36: case 43: case 50:
        		SetConsoleTextAttribute(h,0x1 );
				break;
				case 2: case 9: case 16: case 23: case 30: case 37: case 44:
        		SetConsoleTextAttribute(h,0x2 );
				break;
				case 3: case 10: case 17: case 24: case 31: case 38: case 45:
        		SetConsoleTextAttribute(h,0x3 );
				break;
				case 4: case 11: case 18: case 25: case 32: case 39: case 46:
        		SetConsoleTextAttribute(h,0x4 );
				break;
				case 5: case 12: case 19: case 26: case 33: case 40: case 47:
        		SetConsoleTextAttribute(h,0x5 );
				break;
				case 6: case 13: case 20: case 27: case 34: case 41: case 48:
        		SetConsoleTextAttribute(h,0x6 );
				break;
				case 7: case 14: case 21: case 28: case 35: case 42: case 49:
        		SetConsoleTextAttribute(h,0x7 );
				break;
			}
            cout<<"\t\t\t                    RECORD # "<<i<<"                     "<<endl;
            cout<<"\t\t\t---------------------------------------------------------"<<endl;
            cout<<"\t\t\t|  Vehicle Number           >==>  "<<c.vehicle_no<<endl;
            cout<<"\t\t\t---------------------------------------------------------"<<endl;
            cout<<"\t\t\t|  Vehicle Type             >==>  "<<c.vehicle_type<<endl;
            cout<<"\t\t\t---------------------------------------------------------"<<endl;
            if(c.lastname=="NO_lastname")
            { 
                cout<<"\t\t\t|  Owner  Name              >==>  "<<c.owner_name<<endl;
                cout<<"\t\t\t---------------------------------------------------------"<<endl;   
            }
            else
            { 
                cout<<"\t\t\t|  Owner  Name              >==>  "<<c.owner_name<<' '<<c.lastname<<endl;   
                cout<<"\t\t\t---------------------------------------------------------"<<endl;
            }
            cout<<"\t\t\t|  CNIC Number              >==>  "<<c.cnic_no<<endl;
            cout<<"\t\t\t---------------------------------------------------------"<<endl;
            cout<<"\t\t\t|  Contact No.              >==>  "<<c.cell_no<<endl;
            cout<<"\t\t\t---------------------------------------------------------"<<endl<<endl;
            cout<<"\t<--------------------------------------------------------------------------------------->"<<endl<<endl;
            check = true;
            i++;
        }
        if(check==false)
        {
        	system("color 4");
            cout<<"\t\t\t\tVehicles Record Not Found.\n\n\t\t\tPress Enter Key.......";
        }
        cin.ignore();
        cin.get();
    }
    read.close();
}

void record_delete()
{
	cout<<"\n\n\n";
	char ch;
	cout<<"\t\t\tTHIS PROCESS WILL DELETE YOUR ALL DATA AND RESTART THE PARKING SOFTWARE................"<<endl<<endl;
	cout<<"\t\t\tPress 'y' to Continue....... OR Press 'n' to Cancel The Process........             >==>  ";
	cin>>ch;
	while(ch!='y' && ch!='n')
	{
	  system("color 4");
	  cout<<"\t\t\t\tERROR!.......\n\t\t\tPress 'y' to Continue....... OR Press 'n' to Cancel The Process........             >==>  ";
	  cin>>ch;
	}
	if(ch=='y')
	{
		system("color 6");
		remove ("earn.txt");
		remove ("vehicles.txt");
		cout<<endl<<endl<<endl;
		cout<<"\t\t\tALL THE FILES AND DATA has been deleted SUCCESSFULLY.\n\n\t\t\tPress Enter Key.........";
	}
	else if(ch=='n')
	{
		system("color 2");
		cout<<endl<<endl<<endl;
		cout<<"\t\t\tTHE PROCESS has been CANCELLED.\n\n\t\t\tPress Enter Key..........";
	}
	cin.ignore();
	cin.get();
}

void endup()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,FOREGROUND_GREEN );
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t  *****          ******          ******         ******          ******          *      *         *******"<<endl;
    cout<<"\t\t\t *     *        *      *        *      *        *      *        *      *        *      *        *       "<<endl;
    SetConsoleTextAttribute(h,0x6 );
    cout<<"\t\t\t*              *        *      *        *       *       *       *      *         ******         *       "<<endl;
    cout<<"\t\t\t*              *        *      *        *       *       *       *******                *         *******"<<endl;
    cout<<"\t\t\t*    * *       *        *      *        *       *       *       *      *               *        *       "<<endl;
    SetConsoleTextAttribute(h,FOREGROUND_RED );
    cout<<"\t\t\t *     *        *      *        *      *        *      *        *      *        *      *        *       "<<endl;
    cout<<"\t\t\t  ******         ******          ******         ******          *******          ******          *******"<<endl;
    SetConsoleTextAttribute(h,0 );
    cin.ignore();
    cin.get();
}
