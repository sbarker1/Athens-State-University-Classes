//Samuel Barker
//sbarker1@my.athens.edu
//00100768
//Project 3

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

//Hard coded constant variables for prices and seat selections
const float moviePriceAdultsBefore=6.00, moviePriceKidsBefore=4.00;
const float moviePriceAdultsAfter=8.00, moviePriceKidsAfter=6.00;
const int ROW=7;
const int COL=8;

typedef string movie[ROW][COL]; //Use typedef

void movies();
void printTheatre(movie);
void updateMovie(movie, int);
void createMovie(movie);



int ticketsAdd(int, int);

int kidsInput(int);

int adultsInput(int);

int price(int , int);

int admin(int , int, int, int , int ,int);



int main() 
{

  string movieOne, movieTwo;
  int movieSelection, movieTime, kidstickets, adulttickets, kids, adults, tickets, ticketsTotal, choice;
  float adulttotal, kidstotal;
  float price, priceTotal;
  movie theatre1;

  movie theatre2;

  movie theatre3;

  movie theatre4;
  
  
  createMovie(theatre1);

  createMovie(theatre2);

  createMovie(theatre3);

  createMovie(theatre4);

  do
  {
    //Movie title listings

  cout<<"\n______________Welcome to the Movie Theater!_______________\n\nNow Showing:\n-------------------------------\n";
  movieOne= "Free Birds";

  movieTwo="Bethooven";

  cout<<movieOne<<setw(10)<<"3:30"<<setw(10)<<"6:00"<<endl;
  cout<<movieTwo<<setw(11)<<"5:30"<<setw(10)<<"7:30"<<endl;
  cout<<"-------------------------------\n\n";
  cout<<"Prices:\n----------------------------------------------------------\n";
  cout<<"Adult Tickets: $6.00 matinee (before 6pm) & $8.00 (evening)"<<endl;
  cout<<"Child Tickets: $4.00 matinee (before 6pm) & $6.00 (evening)"<<endl;
  cout<<"----------------------------------------------------------\n\n";
  cout<<"Please select 1 if you would like to watch "<<movieOne<<endl<<"OR\nPlease select 2 if you would like to watch "<<movieTwo<<endl;
  cin>>movieSelection;

    if (movieSelection==-99)
    {
      choice=admin(priceTotal, ticketsTotal, kidstickets, adulttickets, adulttotal, kidstotal);
    }

    else if (movieSelection==1) 
    {
     cout<<"Please select 1 if you would like to watch "<<movieOne<<" at 3:30"<<endl<< "Please select 2 if you would like to watch "<<movieOne<<" at 6:00"<<endl;
     cin>>movieTime;


             if(movieTime==1)
             {
              printTheatre(theatre1);

              kids=kidsInput(kids);

              adults=adultsInput(adults);

              kidstickets=kidstickets+kids;

              adulttickets=adulttickets+adults;

              tickets=ticketsAdd(kids, adults);

              kids=kids*moviePriceKidsBefore;

              adults=adults*moviePriceAdultsBefore;

              adulttotal= adulttotal+adults;

              kidstotal=kidstotal+kids;

              price=adults+kids;

              priceTotal= priceTotal+kids+adults;

              ticketsTotal=ticketsTotal+tickets;

              updateMovie(theatre1, tickets);

              cout<<"Total ticket price: $"<<setprecision(2)<<fixed<<showpoint<<price<<endl<<endl;
              
              }


            else if(movieTime==2)
            {
              printTheatre(theatre2);

              kids=kidsInput(kids);

              adults=adultsInput(adults);

              kidstickets=kidstickets+kids;

              adulttickets=adulttickets+adults;

              tickets=ticketsAdd(kids, adults);

              kids=kids*moviePriceKidsAfter;

              adults=adults*moviePriceAdultsAfter;

              adulttotal= adulttotal+adults;

              kidstotal=kidstotal+kids;

              price=adults+kids;

              priceTotal= priceTotal+kids+adults;

              ticketsTotal=ticketsTotal+tickets;

              updateMovie(theatre2, tickets );
              
              cout<<"Total ticket price: $"<<setprecision(2)<<fixed<<showpoint<<price<<endl;
          
            }
    }

    else if(movieSelection==2)
    {
      cout<<"Select 1 if you would like to watch "<<movieTwo<<" at 5:30\nSelect 2 if you would like to watch "<<movieTwo<<" at 7:30"<<endl;
      cin>>movieTime;


      if(movieTime==1)
      {
          printTheatre(theatre3);

          kids=kidsInput(kids);

          adults=adultsInput(adults);

          kidstickets=kidstickets+kids;

          adulttickets=adulttickets+adults;

          tickets=ticketsAdd(kids, adults);

          kids=kids*moviePriceKidsBefore;

          adults=adults*moviePriceAdultsBefore;

          adulttotal= adulttotal+adults;

          kidstotal=kidstotal+kids;

          price=adults+kids;

          priceTotal= priceTotal+kids+adults;

          ticketsTotal=ticketsTotal+tickets;
          
                updateMovie(theatre3, tickets );  //Set total amount owed
          cout<<"Total ticket price: $"<<setprecision(2)<<fixed<<showpoint<<price<<endl<<endl;
         
        }
        else if(movieTime==2)
        {
          printTheatre(theatre4);

          kids=kidsInput(kids);

          adults=adultsInput(adults);

           kidstickets=kidstickets+kids;

          adulttickets=adulttickets+adults;

          tickets=ticketsAdd(kids, adults);

          kids=kids*moviePriceKidsAfter;

          adults=adults*moviePriceAdultsAfter;

          kidstotal=kidstotal+kids;

          adulttotal= adulttotal+adults;

          price=adults+kids;

          priceTotal= priceTotal+kids+adults;

          ticketsTotal=ticketsTotal+tickets;

          updateMovie(theatre4, tickets);
          cout<<"Total ticket price: $"<<setprecision(2)<<fixed<<showpoint<<price<<endl;
          
        }
  }
  else{
  cout<<"The selection you made was invalid!\nPlease select 1 if you would like to watch "<<movieOne<<endl<<"or select 2 if you would like to watch "<<movieTwo<<endl;    //Input validation
  }

}
while(choice!=4);
return 0;
}

void printTheatre(movie theatre) 
{
  char rows;
  rows='A';

  for (int cols = 1; cols <= COL; cols++)
  
  {
    cout<<setw(3)<<cols;
      
  }

      cout<<endl;

  for (int row = 0; row < ROW; row++) 
  {
    for (int col = 0; col < COL; col++)
    {
      if((row==0 && col ==0) || (row==1 &&col==0)|| (row==2 &&col==0)||(row==3 &&col==0)||(row==4 &&col==0) || (row==5 &&col==0) || (row==6 &&col==0))
      {
        cout<<rows;
        rows++;
      }

      cout << setw(3) << theatre[row][col];
    }
    cout << endl;
  }


  return;
}

void createMovie(movie movieOne) 
{
  for (int rows = 0; rows < 7; rows++)
  {
    for (int col = 0; col < 8; col++)
    {
      movieOne[rows][col] = "*";
    }

  }
  return;
}

void updateMovie(movie movieOne, int tickets)
{
  char row;
  int col;
  bool seatCheckFlag, rowCheck;
  cout <<"Please select your seats."<<endl;
  
for (int count =0; count<tickets; count++)
{
    rowCheck=false;

    seatCheckFlag=false;
      


  while(seatCheckFlag == false)
  {


       while(rowCheck == false)
     
      {
        cout<<"What row would you like to sit at"<<endl<<"Enter A , B , C , D , E , F , or G"<<endl;
        cin>>row;
 
        if(row=='a'||row=='A')
        {

        row=0;
        rowCheck=true;

        }
        else if(row=='b'||row=='B')
        {
        row=1;

        rowCheck=true;

        }
        else if(row=='c'||row=='C')
        {

        row=2;
        rowCheck=true;

        }
        else if(row=='d'||row=='D')
        {
         row=3;
        rowCheck=true;

        }
        else if(row=='E'||row=='e')
        {
        row=4;

        rowCheck=true;
        }
        else if(row=='F'||row=='f')
        {
        row=5;
        rowCheck=true;

        }
        else if(row=='g'|| row=='G')
        {
          row=6;
          rowCheck=true;

        }
        else 
        {
        cout<<"Your input was invalid"<<endl;

        }

    }

     rowCheck=false;

    while(rowCheck==false)
    {
    cout<<"What seat would you like on this row 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8"<<endl;
    cin>>col;
    
        if (col==1)
        {
          col=0;
          rowCheck=true;

        }
       else if(col==2)
       {
         col=1;
         rowCheck=true;

       }
        else if(col==3)
        {
         col=2;
          rowCheck=true;

        }

        else if(col==4)
        {
          col=3;
          rowCheck=true;

        }
        else if(col==5)
        {
          col=4;
          rowCheck=true;

         }
        else if(col==6)
        {
          col=5;
          rowCheck=true;

        }
        else if(col==7)
        {
          col=6;
          rowCheck=true;

        }
        else if(col==8)
        {
          col=7;
          rowCheck=true;

        }
       else
        {
      cout<<"Your input was invaild "<<endl;
        }


    }

    rowCheck=false;

    if (movieOne[row][col] =="#")
      {
        cout<<"That seat selection has been taken."<<endl;

        cout<<"Please choose another seat option that is available to you."<<endl;
      }

      else if (movieOne[row][col]=="X")
      {
        cout<<"Sorry, the seat you have selected is closed off due to social distancing"<<endl;

        cout<<"Please choose another seat option that is available to you."<<endl;
      }

      else 
      {
      movieOne[row][col] = "#";
      cout << endl;

      seatCheckFlag=true;


      }

   }
}

//Seating (#, * , X)
    for (int rows = 0; rows < 7; rows++)
    {

      for (int cols = 0; cols < 8; cols++)
      {

        if (movieOne[rows][cols] == "#")
        {
          if (cols - 1 >= 0 && cols - 1 <= COL)
          {
               if (movieOne[rows][cols - 1] == "*")
               {
                  movieOne[rows][cols - 1] = "X";
               }
          }
          
          if (cols + 1 >= 0 && cols + 1 <= COL)
          {
            if (movieOne[rows][cols + 1] == "*")
            {
              movieOne[rows][cols + 1] = "X";
            }
          }
          
          if (rows + 1 >= 0 && rows + 1 <= ROW)
          {
            if (movieOne[rows + 1][cols] == "*")
            {
              movieOne[rows + 1][cols] = "X";
            }

          }

          if (rows - 1 >= 0 && rows - 1 <= ROW)
          {
             if (movieOne[rows - 1][cols] == "*")
             {
              movieOne[rows - 1][cols] = "X";
             }

          }

        }
      }
    }


return;
}

int ticketsAdd(int kids, int adults)
{
  int tickets;
  tickets=kids+adults;

return tickets;
}


int kidsInput(int kids)
{
  cout << "Please enter how many kids are watching: ";
  cin >> kids;

return kids;
}



int adultsInput(int adults)
{
  cout << "\nPlease enter how many adults are watching: ";
  cin>>adults;

return adults;
}



int admin(int priceTotal, int ticketsTotal, int kidstickets, int adulttickets, int adulttotal, int kidstotal)
{
  int choice, userinput;
  bool choiceFlag, ticketsFlag;


 do 
 {

  cout<<"Please enter an option below: "<<endl;
  cout<<"1) Profits\n2) number of tickets sold\n3) Return to movies list\n4) Run end of day\n";
  cin>>choice;
  
  if (choice==1)
  {
    ticketsFlag=false;


    while(ticketsFlag==false)
    {
      cout<<"Select 1 to see money made by adults tickets."<<endl;
      cout<<"Select 2 to see money made by kids tickets."<<endl;
      cout<<"Select 3 to see money made all togther."<<endl;
      cout<<"Select 4 to go back to menu."<<endl;
      cin>>userinput;


      if (userinput==1)
      {
      cout<<"The amount of purchased adult tickets is: $"<<setprecision(2)<<fixed<<showpoint<<adulttotal<<endl;
      }

      else if(userinput==2)
      {
      cout<<"The amount of purchased kids tickets is: $"<<setprecision(2)<<fixed<<showpoint<<kidstotal<<endl;
      }

      else if(userinput==3)
      {
      cout<<"The total amount of many made is: $"<< setprecision(2)<<fixed<<showpoint<<priceTotal<<endl;
      }
  
      else if(userinput==4)
      {
      cout<<"Returning to menu."<<endl;

      ticketsFlag=true;
      }
  
      else
      {
      cout<<"Input entered is invalid, please select a valid option."<<endl;
      }

    }
 
  }

  else if(choice==2)
  {
    ticketsFlag=false;


    while(ticketsFlag==false)
    {

      cout<<"Select 1 to see tickets sold to adults"<<endl;

      cout<<"Select 2 to see tickets sold to kids"<<endl;
      cout<<"Select 3 to see tickets sold all togther"<<endl;
      cout<<"Select 4 to go back to menu"<<endl;
      cin>>userinput;


        if (userinput==1)
        {
          cout<<"The amount of purchased adult tickets is: "<<adulttickets<<endl;
        }
        else if (userinput==2)
        {
         cout<<"The amount of purchased kids tickets is: "<<kidstickets<<endl;
        }
        else if(userinput==3)
        {
        cout<<"The amount of purchased tickets for the day is: "<<ticketsTotal <<endl;
        }
        else if(userinput==4)
        {
          cout<< "Returning to menu"<<endl;

          ticketsFlag=true;
        }
        else
        {
        cout<<"Your input was invaild please select a vaild option"<<endl;
        }
     }
  }

  else if(choice==3)
  {
    cout<<"Returning to movie selections."<<endl;


    choiceFlag=true;
  }
  else if(choice ==4)
  {
    cout<<"Running end of day..."<<endl;

    cout<<"Have a nice day."<<endl;


    choiceFlag= true;
  }
  else
  {
    cout<<"Invalid input, please try again."<<endl;
  }
}
  while (choiceFlag!=true);
  
  return choice;
}
