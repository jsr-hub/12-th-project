//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************


#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <iomanip.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>


//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************



class test
{
public:
clock_t begin[5],end[5];
int right,wrong,p;

double  tim[5], totaltime;
void dotest(int);
void score();
void timetaken();

};
//first class ends here
//Functions inside the class are declared using scope resolution operator


 void test::score()
 {
 p=0;
 clrscr();

 gotoxy(31,8);
 cout<<"RESULT"<<endl;
  cout<<"********************************************************************************"<<endl;
 cout<<"number of correct answers:"<<right<<endl;
 cout<<"number of wrong answers:"<<wrong<<endl;
 p=(right)*(100/5);
 cout<<"percentage:"<<p<<endl;

 }

 void test::timetaken()
 {
 double elapsed[20];
 totaltime=0;
 for(int i=0;i<5;i++)
  {
   elapsed[i]= double(end[i] - begin[i]) / CLOCKS_PER_SEC;
  totaltime+=elapsed[i];
  }
  cout<<"total time taken" <<totaltime<<endl;
  }

void test::dotest(int choice)
{
	 double n1,n2,answer[50],check[50];

	 int i,j,n,c;
	cout <<"select ur level"<<endl;
	cout <<"Enter "<<endl;
	cout << "1-First level "<<endl;
	cout << "2-Second level"<<endl;
	cout << "3-Third level "<<endl;
	cin>>n;
	if(n==1)
	{

	c=10;
	}
	else if(n==2)
	{

	c=100;
	}
	else if(n==3)
	{
	c=1000;
	}
	else
		{
		cout << "Invalid Number!" << endl;
		system("PAUSE");
		}

		clrscr();
		for( i=0;i<5;i++)
		{
		  srand((unsigned)time(0));
		  n1 = rand() % c + 1;
		  n2 = rand() % c + 1;
		  begin[i]=clock();
		  switch(choice)
		  {
		  case 1:
		 cout << "What is " << n1 << " + " << n2 << "?" << endl;
		 cout << "Answer: ";
		 begin[i]=clock();
		 cin >> answer[i];
		 end[i]=clock();
		 check[i]=n1+n2;
		 break;
		 case 2:
		 cout << "What is " << n1 << " - " << n2 << "?" << endl;
		 cout << "Answer: ";
		 begin[i]=clock();
		 cin >> answer[i];
		 end[i]=clock();
		 check[i]=n1-n2;
		 break;
		  case 3:
		 cout << "What is " << n1 << " * " << n2 << "?" << endl;
		 cout << "Answer: ";
		 begin[i]=clock();
		 cin >> answer[i];
			 end[i]=clock();
		 check[i]=n1*n2;
		 break;
		  case 4:
		 cout << "What is " << n1 << " / " << n2 << "?" << endl;
		 cout << "Answer: ";
		 begin[i]=clock();
		 cin >> answer[i];
		 end[i]=clock();
		 check[i]=n1/n2;
		 break;

		 }
		 tim[i]= double(end[i] - begin[i]) / CLOCKS_PER_SEC;

		 }
		 right=0;
		 wrong=0;
		 for( j=0;j<5;j++)
		 {
		 if(answer[j] == check[j])
		 {
		 cout << endl << "Correct!" << "\t \t time taken" <<tim[j]<<   endl;

		 right+=1;
		  }
		   else
		  {
		    cout << endl << "sorry! The right answer was " << check[j] << endl<<"\t time taken" <<tim[j]<<endl;
		  wrong+=1;
		  }

		  }

		      }
//Inheritance is shown between both the class student and test

class Student:public test
{
      private:
	      int studid,age;
	      char name[20];
	      char sex[6];
      protected:
		int allotstudid();
		void showheader();
      public:
	     void getstudent();
	     void showstudent();
	     void addstudent();
	     void viewstudent();
	     void searchstudent();
	     void deletestudent();
	     void modifystudent();
	     void topper();
};
//Seccond class ends here
//Functions inside the class are declared using scope resolution operator
//***************************************************************
//    	function to allot id for students
//****************************************************************

int Student::allotstudid()
{
    ifstream fin;
    Student temp;
    int id=0;
    fin.open("studentfile.txt",ios::in|ios::binary);
    if(!fin)
	    return(id+1);
    else
    {
	fin.read((char*)&temp,sizeof(temp));
	while(!fin.eof())
	{
	 id=temp.studid;
	 fin.read((char*)&temp,sizeof(temp));
	}
	id++;
	return(id);
    }
}
//***************************************************************
//    	function to headings
//****************************************************************

void Student::showheader()
{

     cout<<"\n"<<" ID "<<setw(10)<<"Name  "<<setw(14)<<"Sex  "<<setw(6)<<"Age  "<<setw(8)<<" correct/wrong  "<<setw(6)<<"pertcentage  "<<setw(10)<<"time_taken";
}
//***************************************************************
//    	function to get student details from user
//****************************************************************
void Student::getstudent()
{
     cout<<"Enter Name Of Student: ";
     fflush(stdin);
     gets(name);
     cout<<"SEX: ";
     gets(sex);
     cout<<"AGE: ";
     cin>>age;
     studid=allotstudid();
     cout<<"Your id is ="<<studid<<endl;
}
//***************************************************************
//    	function to show student
//****************************************************************
void Student::showstudent()
{

     cout<<"\n"<<setw(3)<<studid<<setw(14)<<name<<setw(7)<<sex<<setw(7)<<age<<setw(11)<<right<<"/"<<wrong<<setw(14)<<p<<setw(15)<<totaltime;
}


//***************************************************************
//    	function to write in file
//****************************************************************

void Student::addstudent()
{
     ofstream fout;
     fout.open("studentfile.txt",ios::out|ios::app|ios::binary);
     if(!fout)
	      cout<<"File can not open";
     else
	      fout.write((char*)this,sizeof(*this));
     fout.close();
}

//***************************************************************
//    	function to read all records from file
//****************************************************************


void Student::viewstudent()
{
     ifstream fin;
     fin.open("studentfile.txt",ios::in|ios::binary);
     if(!fin)
	     cout<<"File not found";
     else
     {
	 showheader();
	 fin.read((char*)this,sizeof(*this));
	 while(!fin.eof())
	 {
	  showstudent();
	  fin.read((char*)this,sizeof(*this));
	 }
     }
     fin.close();
}

//***************************************************************
//    	function to search specific record from file
//****************************************************************

void Student::searchstudent()
{
     ifstream fin;
     char str[20];
     fin.open("studentfile.txt",ios::in|ios::binary);
     cout<<"Enter the name of student to search:";
     fflush(stdin);
     gets(str);
     if(!fin)
	     cout<<"File not found";
     else
     {
	 fin.read((char*)this,sizeof(*this));
	 while(!fin.eof())
	 {

	  if(!strcmp(this->name,str))
	  {
	    showheader();
	    showstudent();
	    break;
	  }
	  fin.read((char*)this,sizeof(*this));
	 }
	 if(fin.eof())
	  cout<<"\nRecord not found";
     }
     fin.close();
}

//***************************************************************
//    	function to modify record of file
//****************************************************************

void Student::modifystudent()
{
     int id,r=0;
     fstream file;
     file.open("studentfile.txt",ios::in|ios::out|ios::ate|ios::binary);
     cout<<"\nEnter record number to modify (studid): ";
     cin>>id;
     file.seekg(0);
     if(!file)
	     cout<<"File not found";
     else
     {
	 file.read((char*)this,sizeof(*this));

	 while(!file.eof())
	 {
	   r++;
	   if(studid==id)
	   {
	     showheader();
	     showstudent();
	     cout<<"\nRe-enter Student details:\n";
	     cout<<"Enter Student Name: ";
	     fflush(stdin);
	     gets(name);
	     cout<<"Enter Sex: ";
	     gets(sex);
	     file.seekp((r-1)*sizeof(Student),ios::beg);
	     file.write((char*)this,sizeof(*this));
	     break;
	   }
	   file.read((char*)this,sizeof(*this));
	 }
	 if(file.eof())
		      cout<<"Record not found";
     }
	 file.close();
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void Student::deletestudent()
{
     ifstream fin;
     ofstream fout;
     int id;
     char x;
     fin.open("studentfile.txt",ios::in|ios::binary);
     fout.open("tempfile.txt",ios::out|ios::app|ios::binary);
     cout<<"Enter Student ID to delete record";
     cin>>id;
     if(!fin)
	     cout<<"File not found";
     else
     {
	 fin.read((char*)this,sizeof(*this));
	 while(!fin.eof())
	 {
	  if(this->studid==id)
	  {
	    cout<<"Record you want to delete is:\n\n";
	    showheader();
	    showstudent();
	    cout<<"\nAre you sure you want to delete this record(y/n): ";
	    fflush(stdin);
	    cin>>x;
	    if(x=='n')
			 fout.write((char*)this,sizeof(*this));
	    else
			 cout<<"\nRecord is deleted";
	  }
	  else
	      fout.write((char*)this,sizeof(*this));
	  fin.read((char*)this,sizeof(*this));
	 }
	 fin.close();
	 fout.close();


		      system("erase studentfile.txt");
		      getch();
		      system("rename tempfile.txt studentfile.txt");


     }
}

//***************************************************************
//    	function to show toppers of file
//****************************************************************

void Student::topper()

{
     ifstream file;
     file.open("studentfile.txt",ios::in|ios::binary);
     file.seekg(0);
     if(!file)
	     cout<<"File not found";
     else
     {
	 file.read((char*)this,sizeof(*this));
	  showheader();
	 while(!file.eof())
	 {

	   if(this->right==5)
	   {

	     showstudent();

	    }
	   file.read((char*)this,sizeof(*this));
	 }

     }
	 file.close();
	 getch();
}


//***************************************************************
//    	INTRODUCTION FUNCTION  FOR ADMIN
//****************************************************************
int menu()
{

    clrscr();
    gotoxy(31,2);
    cout<<"ADMINISTRATOR";
    cout<<"\n\n\n\t1. View all Students";
    cout<<"\n\n\n\t2. Search Student";
    cout<<"\n\n\n\t3. Modify Student";
    cout<<"\n\n\n\t4. Delete Student";
    cout<<"\n\n\n\t5. Show Toppers";
    cout<<"\n\n\n\t6. BACK";
    cout<<"\n\n\n\t7. Exit";
    cout<<"\n\n\tEnter your choice : ";
    int ch;
    cin>>ch;
    return(ch);
}
//***************************************************************
//    	INTRODUCTION FUNCTION  FOR USER
//****************************************************************
int menu1()
{

    clrscr();
    gotoxy(31,2);
    cout<<"USER";
    cout<<"\n\n\n\t1. Write Test ";
    cout<<"\n\n\n\t2. View all Students";
    cout<<"\n\n\n\t3. Search Student";
    cout<<"\n\n\n\t4. Show Topper";
    cout<<"\n\n\n\t5. BACK";
    cout<<"\n\n\n\t6. EXIT";
    cout<<"\n\n\n\tRequest administrator to modify and delete your record through mail";
    cout<<"\n\n\tEnter your choice : ";
    int ch;
    cin>>ch;
    return(ch);
}


//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
 clrscr();
 gotoxy(31,8);
 cout<<"TEST YOUR SKILLS";
 gotoxy(30,10);
 cout<<"SCORE CENT PERCENT";
 gotoxy(35,12);
 cout<<"PROJECT"<<endl;
 gotoxy(35,14);
 cout<<"CBSE XII"<<endl;
 gotoxy(20,16);
 cout<<"MADE BY : SANJAY RAJU , SIVAMEENAL & RAMYA"<<endl;
 gotoxy(25,18);
 cout<<"SCHOOL : BLOSSOM PUBLIC SCHOOL";
 gotoxy(38,19);
 cout<<"THANJAVUR"<<endl;
 getch();

}



//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
    textbackground(1);
    intro();
    Student b;
    int ch,a;
    run:
    read:
    clrscr();
    textcolor(WHITE);
    gotoxy(35,5);
    cout<<"WELCOME"<<endl;
    cout<<"********************************************************************************";
    cout<<"\n\n\tEnter your choice:\n\n\n\n\t\t1.ADMINISTRATOR\n\n\n\n\t\t2.USER\n\n\n\n\t\t3.EXIT"<<endl;
    cin>>a;
    switch(a)
    {
     case 1:
	   char pass[9],word[]="brilliant";
	   cout<<"Enter the password"<<endl;
	   gets(pass);
	   if(strcmp(pass,word)==0)
	   {
	   while(1)
	   {
	   ch=menu();
	   switch(ch)
	   {

		     case 1:
			    clrscr();
			    b.viewstudent();
			    getch();
			    break;
		     case 2:
			    clrscr();
			    b.searchstudent();
			    getch();
			    break;
		     case 3:

			  clrscr();
			    b.modifystudent();
			    break;
		     case 4:
			    clrscr();
			    b.deletestudent();
			    break;
		    case 5:
			    clrscr();
			    b.topper();
			    getch();
			    break;
		     case 7:
				clrscr();
				gotoxy(20,10);
				_setcursortype(_NOCURSOR);
				textcolor(GREEN);
				textbackground(8);
				cprintf("THANK YOU ");
				gotoxy(35,15);
				cprintf("GOOD BYE");
				gotoxy(12,20);
				cprintf("*Everthing will change. Nothing will stay the same be ready*");
				getch();
				exit(0);

		     default:

			    cout<<"Enter Valid Choice";
			   goto run;

	   }
	   }
	     }
	   else
	   {
	   cout<<"Incorrect password"<<endl<<"Try again!"<<endl;
	   getch();
	   goto read;
	   }
  case 2:
	   while(1)
	   {
	    ch=menu1();
	   switch(ch)
	   {
		   case 1:
			     clrscr();
				b.getstudent();

				int choice;

				cout<<"                              Welcome to the math games!" << endl;


				cout<<"================================================================================"<<endl;
				cout << "Enter a number choice: " << endl;
				cout << "1 - Addition" << endl;
				cout << "2 - Subtraction" << endl;
				cout << "3 - Multiplication" << endl;
				cout << "4 - Division" << endl;
				cout << "5 - Exit" << endl;
				cout<<"================================================================================"<<endl;
				cout << endl << "Choice: ";
				cin >> choice;

				if(cin.fail())
				{
				cout << "Invalid answer, now quitting to prevent crash..." << endl;
				system("PAUSE");
				    return 0;
				}



				switch(choice)
				{
				case 1:
				case 2:
				case 3:
				case 4:
				b.dotest(choice);
				  break;
				default:
				 cout << "Invalid Number!" << endl;
				 system("PAUSE");
				return 0;
				}
				getch();
				cout<<"================================================================================"<<endl;
				b.score();
				b.timetaken();
				b.addstudent();
				getch();

				break;
		     case 2:


			    clrscr();
			    b.viewstudent();
			    getch();
			    break;
		     case 3:
			    clrscr();
			    b.searchstudent();
			    getch();
			    break;
		    case 4:
			    clrscr();
			    b.topper();
			    getch();
			    break;
		    case 6:
				clrscr();
				gotoxy(20,8);
				_setcursortype(_NOCURSOR);
				textcolor(GREEN);
				textbackground(8);
				cprintf("THANK YOU ");
				gotoxy(35,12);
				cprintf("GOOD BYE");
				gotoxy(12,16);
				cprintf("*Everthing will change. Nothing will stay the same be ready*");
				gotoxy(11,18);
				cprintf("Feedback and valuable suggestions are appreciable through mail");
				gotoxy(25,20);
				cprintf("E-mail:mathsmegamixblossom@gmail.com");
				getch();
				exit(0);


		    default:
			    cout<<"Enter Valid choice";
			   goto run;

	      }
	     }
case 3:
				clrscr();
				gotoxy(20,10);
				_setcursortype(_NOCURSOR);
				textcolor(GREEN);
				textbackground     (8);
				cprintf("THANK YOU ");
				gotoxy(35,15);
				cprintf("GOOD BYE");
				gotoxy(12,20);
				cprintf("*Everthing will change. Nothing will stay the same be ready*");
				getch();
				exit(0);


default:
	cout<<"Enter Valid choice";
	goto run;


	   }
	    }




//***************************************************************
//    			END OF PROJECT
//***************************************************************
