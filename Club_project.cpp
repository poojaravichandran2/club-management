#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <cstdlib>


using namespace std;

fstream fp1, fp2,fp3, fp4, fp5;
char buffer1[100], buffer2[100];
int counter = 0, k;
int ID;
char tempID1[11];

class member
{
   public:
				char Name[20];
 	 	 	 	char MemberID[11];
 	 	 	 	char Address[5];
 	 	 	 	char Department[15];
 	 	 	 	
    
};
member m,m1[20];

void pack(member m)
{
		fp1.open("std.txt", ios :: out | ios :: app );
		counter++;

		strcpy(buffer1, m.Name);
		strcat(buffer1, "|");
		strcat(buffer1, m. MemberID);
		strcat(buffer1, "|");
		strcat(buffer1, m. Address);
		strcat(buffer1, "|");
		strcat(buffer1, m. Department);
		strcat(buffer1, "|");

		 int l = strlen(buffer1);

		 for(int i = 0; i < 50 - l;i++)
		 {
			 strcat(buffer1,"*");
		 }


		 fp1 << counter << "|" << buffer1 << endl;
		 fp1.close();

               fp2.open("ind.txt", ios :: out | ios :: app);

		 		strcpy(buffer2, m.MemberID);
		 		strcat(buffer2, "|");

		 		int l1 = strlen(buffer2);

		 		for(int i = 0; i < 50 - l1;i++)
		 		{
		 			 strcat(buffer2,"*");
		 		 }


		 		fp2 << counter << "|" << buffer2 << endl;
		 		fp2.close();




}


void add(int i)
{
		cout << "Enter  Name" << endl;
		cin >> m.Name;

		if(i == 0){
		cout << "Enter Member ID" << endl;
		cin >> m. MemberID;
		}

		cout << "Enter Address" << endl;
		cin >> m. Address;

		cout << "Enter Department" << endl;
		cin >> m.Department;

		if(i == 0){
                char temp_ID[11], tempID[11];
                fp4.open("ind.txt", ios::in);
                while(1){
                char buffer[100];
                if(fp4.getline(buffer, 100).fail())
                      break;
                sscanf(buffer, "%[^|]|%[^|]|" , &temp_ID, &tempID);
               
                if(strcmp(tempID, m.MemberID) == 0){
                        cout << "Entry not accepted since record with MemberID " << m.MemberID << " already exists (no duplicates)" << endl;
                        fp4.close();
                        return;
                }
                }
                fp4.close();
		pack(m);
		}

}

void search()
{
	int offset;
	char temp_ID[5], tempID[11],buffer1[100];

	fp1.open("std.txt", ios :: in);
	fp2.open("ind.txt", ios :: in);

	cout << "Enter the  MemberID key to search" << endl;
	cin >> tempID;

	for(k = 0; k < counter; k++)
	{

		
		fp2.getline(buffer2, 100);
		if(buffer2[0] != '*'){
		sscanf(buffer2, "%[^|]|%[^|]|" ,temp_ID,m.MemberID);	
                
		if(strcmp(tempID,m.MemberID) == 0)
		{
			ID = atoi(temp_ID);
			offset = (ID - 1) * 53;
			fp1.seekg(offset, ios :: beg);							
			fp1.getline(buffer1, 100);
			
			sscanf(buffer1, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]" ,temp_ID, m1[k].Name, m1[k].MemberID, m1[k].Address, m1[k].Department);
			
			if(m1[k].Department[0] == '*'){
			    sscanf(buffer1, "%[^|]|%[^|]|%[^|]|%[^|]|" ,m1[k].Name, m1[k].MemberID, m1[k].Address, m1[k].Department);
			}

			 cout << "Record Found" << endl;
			 cout << "Name \t\t MemberID \t\t Address \t\t Department" << endl;
			 cout << m1[k].Name << "\t\t " << m1[k].MemberID<<"\t\t "<< m1[k].Address << "\t\t "<< m1[k].Department << endl;

			 break;

		}
		}
	}
	if(k == counter)
	 		 cout << "Member Not Found!!" << endl;

	 fp1.close();
     fp2.close();


}
void display()
{

char trash[100];
fp1.open("std.txt", ios :: in);
fp2.open("ind.txt", ios :: in);
cout << "Name \t\t MemberID \t\t Address \t\t Department" << endl;
for(k = 0; k < counter; k++)
{
fp1.getline(buffer1, 100);
if(buffer1[0] != '*'){
sscanf(buffer1, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]*", trash, m1[k].Name, m1[k].MemberID, m1[k].Address, m1[k].Department);


if(m1[k].Department[0] == '*'){
sscanf(buffer1, "%[^|]|%[^|]|%[^|]|%[^|]|" ,m1[k].Name, m1[k].MemberID, m1[k].Address, m1[k].Department); 
}

cout << m1[k].Name << "\t\t " << m1[k].MemberID<<"\t\t "<< m1[k].Address << "\t\t "<< m1[k].Department << endl;
}
}
if(k == counter)
cout << "Done...!!" << endl;
fp1.close();
     fp2.close();

}



void remove()
{
	k=0;
	search();

	int offset,temp_ID;
	if(k == counter)
			return;

	fp1.open("std.txt", ios :: out|ios::in );
	fp2.open("ind.txt", ios :: out | ios :: in);

	offset = (ID - 1) * 53;
	fp1.seekp(offset, ios :: beg);
        fp2.seekp(offset, ios :: beg);
	strcpy(buffer1, "$");
	for(int i = 1; i < 52; i++)
	{
		strcat(buffer1, "*");

	}

	fp1 << buffer1 << endl;
        fp2 << buffer1 << endl;
	fp1.close();
	fp2.close();

	cout << "Member Deleted" << endl;


	}



 string convert_to_str(char* a, int size){

    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}


void modify(){
      char temp_ID[11], tempID[11], inputMemID[11], tempNAME[100];
      fp5.open("std.txt", ios::in);
      cout << "Enter Id of the member whose details has to be modified" << endl;
      cin >> inputMemID;
      int isModified = 0;
      while(1){
              char buffer[100], buffer1[100];
              if(fp5.getline(buffer, 100).fail())
                      break;
              if(buffer[0] != '*'){
              sscanf(buffer, "%[^|]|%[^|]|%[^|]|",&temp_ID, &tempNAME, &tempID);
             
              if(strcmp(tempID, inputMemID) == 0){
                        add(1);
                        strcpy(buffer1, temp_ID);
                        strcat(buffer1, "|");
                        strcat(buffer1, m.Name);
		        strcat(buffer1, "|");
		        strcat(buffer1, inputMemID);
		        strcat(buffer1, "|");
		        strcat(buffer1, m.Address);
		        strcat(buffer1, "|");
		        strcat(buffer1, m.Department);
		        strcat(buffer1, "|");

		        int l = strlen(buffer1);

		        for(int i = 0; i < 50 - l;i++)
		        {
			        strcat(buffer1,"*");
		        }
                      string strReplace = convert_to_str(buffer, strlen(buffer)/sizeof(char));
                      string strNew = convert_to_str(buffer1, strlen(buffer1)/sizeof(char));
                     
                      ifstream filein("std.txt"); //File to read from
                      ofstream fileout("std_new.txt"); //Temporary file
                        if(!filein || !fileout)
                        {
                                cout << "Error opening files!" << endl;
                        }

                        string strTemp;

                        while(filein >> strTemp)
                        {
                                if(strTemp == strReplace){
                                 strTemp = strNew;

                         }
                                strTemp += "\n";
                                fileout << strTemp;

                         }

                         isModified = 1;
                         break;
              }
              }
      }

      fp5.close();
      if(isModified == 0)
        cout << "No record found for given MemberID" << endl;
      else{
        remove("std.txt");
        rename("std_new.txt", "std.txt");
        cout << "Modification successfull" << endl;
      }

}


int main()
{
		fp1.open("std.txt", ios :: out);
		
	  	fp1.close();
	  	fp2.open("ind.txt", ios :: out);
	  	
	  	fp2.close();
	  	fp3.open("c.txt", ios :: out);
	  	fp3.close();

	  	int ch;

	  	  	while(1)
	  	  	{
	  	  		cout << "************IT CLUB MANAGEMENT SYSTEM**********" << endl;
	  	  		cout<<"-------------------------------------------------------"<<endl;
	  	  		
	  	  		cout << "Enter your choice" << endl
	  	  			<< "1]ADD member"  << endl
	  	  			<< "2]VIEW member" << endl
	  	  			<< "3]SEARCH member"  << endl
	  	  		        << "4]MODIFY member" << endl
	  	  			<< "5]DELETE member" << endl
					<< "6]Exit" << endl;

	  	  		cin >> ch;

	  	  		switch(ch)
	  	  		{
	  	  			case 1 :
	  	  						add(0);
	  	  						break;

                    case 2 :
                                display();
                                break;

                    case 3 :
                                search();
                                break;

                   	case 4 :     modify();
	  	  		         		 break;

	  	  			case 5 :	remove();
                                break;

	  	  			case 6 : 	exit(0);
	  	  			         	
                    default :	cout << "Invalid Input" << endl;
	  	  			                exit(0);

	  	  		}
	  	  	}

	  	 return 0;
}