//Samuel Barker
//sbarker1@my.athens.edu
//00100768
//Project 2

//Program will play blackjack, store and display results in file, and exit program when finished. 

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <fstream>

using namespace std;
int main() 
{


  ofstream outputFile;
  ifstream inputFile;

  int game, bet, hitStay, credit, winner, credit_decides;
  int userCard1,userCard2, userCard3, dealerCard1, dealerCard2, dealerCard3, userSum, sum_dealer;
  char ace, king, queen, jack, threeCardBlank;
  bool hitStayflag, credit_flags, bet_flags, testHit;
  char first_card_check;
  
  bet_flags=true;
  credit_flags=true;
  testHit=true;

  string gameHistory;

  ace='A';

  jack='J';

  queen='Q';

  king='K';

  

  
  // Display welcome message. 
  cout<<"\nWelcome to the blackjack program!\n";



do
{ 

  cout<<"---------------------------\n";
  cout<<"Type 1 to play\n"<<"Type 2 to view your game history\n"<<"Type 3 to end the game\n";
  cout<<"---------------------------"<<endl;
  cin>>game;
  
  switch(game)  //Use switch for menu functionality. 
  {

      //CASE 1 BEGINS BLACKJACK GAME
      case 1:

      hitStayflag=true;

      //opens a text file to store game history

      inputFile.open("BarkerHistory.txt");

      if(inputFile.is_open())
      {
        outputFile.open("BarkerHistory.txt",fstream::app);
      }
      else {
        outputFile.open("BarkerHistory.txt");

        outputFile<<"Card 1"<<setw(20)<<"Card 2"<<setw(20)<<"Card 3"<<setw(20)<<"Bet"<<setw(20)<<"Dealer"<<setw(20)<<"W/L"<<setw(20)<<"Balance"<<endl;

      }
      
     
      if (credit_flags==true)
      {
      //Credit balance is entered, with $10 limit. 
      cout<<"Please enter the amount of credit.\nNote: You must enter at least $10 dollars to proceed further and play."<<endl;
      cin>>credit;

      credit_flags=false;

      }
       else
      {
        cout<< "Your credit amount is: "<<credit<<endl;
      }

      while(credit<10)  //If user enters credit below 10, program will ask upcoming set of questions.
      {
      if(credit<10)
      {
        cout<<"You do not have enough credits to play blackjack.\nType 1 to add amount that is greater than $10.\nType 2 to quit.\n";
        cin>>credit_decides;

      }
        
       if(credit_decides==1) //User selects 1.
       {
          cout<<"Enter how much money you want to add."<<endl;
          cin>>credit_decides;

          credit=credit+credit_decides;

          cout<<"Your new balance is $"<<credit<<endl;

        }
        else if(credit_decides==2) //User selects 2.
        {

          cout<<"Program has ended.\nThank you for playing."<<endl;
          return 0;

        }
        else 
        {
          {

            cout<<"You have entered an invaild option, please type a 1 or 2\n"; //Input validation

          }
        }
      }
        
     
      while(bet_flags==true)
      {

      cout<<"Please enter a bet amount.\nNote: You are allowed to enter a value minimum of $10 and a max of $150"<<endl;
      cin>>bet;
      
      if (bet<10) //If value is below min.
        {

          cout<<"Your bet must be over $10. Please enter a greater amount."<<endl;
          bet_flags=true;

        }
        else if(bet>150)  //If value is over max. 
        {

          cout<<"Your bet is over the max.\nPlease enter an amount below $150."<<endl;
          bet_flags=true;

        }
        else if(credit<bet) //If credit amount doesn't agree with bet amount.
        {

          cout<<"Your bet exceeds the amount of money you have currently.\nPlease lower your bet."<<endl;
          bet_flags=true;

        }
      
       else 
       {bet_flags=false;}
      }

      credit=credit-bet; 
      

        winner= bet * 2;
    
      srand(time(NULL));  //Using srand to generate random values.

      dealerCard1=rand()%13+1; 
       
      userCard2=rand()%13+1;      //Random numbers are stored.
      
      dealerCard2=rand()%13+1;

      userCard1=rand()%13+1;
    
      

 
        if(userCard1==1)  //What is user's 1st card?
        {
          userCard1=2;
          cout<<"\nYour first card is: "<<userCard1<<endl<<endl;

          outputFile<<setw(3)<<userCard1;
        }
        else if(userCard1==2)
        {
          userCard1=3;
          cout<<"\nYour first card is: "<<userCard1<<endl;

          outputFile<<setw(3)<<userCard1;
        }
        else if(userCard1==3)
        {
          userCard1=4;
          cout<<"your first card is: "<<userCard1<<endl;

          outputFile<<setw(3)<<userCard1;
        }
        else if(userCard1==4)
        {
          userCard1=5;
          cout<<"Your first card is: "<<userCard1<<endl;

          outputFile<<setw(3)<<userCard1;
        }
        else if(userCard1==5)
        {
          userCard1=6;
          cout<<"Your first card is: "<<userCard1<<endl;

          outputFile<<setw(3)<<userCard1;
        }
        else if(userCard1==6)
        {
          userCard1=7;
          cout<<"Your first card is: "<<userCard1<<endl;

          outputFile<<setw(3)<<userCard1;
        }
        else if(userCard1==7)
        {
          userCard1=8;
          cout<<"Your first card is: "<<userCard1<<endl;

          outputFile<<setw(3)<<userCard1;
        }
        else if(userCard1==8)
        {
          userCard1=9;
          cout<<"Your first card is: "<<userCard1<<endl;

          outputFile<<setw(3)<<userCard1;
        }
        else if(userCard1==9)
        {
          userCard1=10;
          cout<<"Your first card is: "<<userCard1<<endl;

          outputFile<<setw(3)<<userCard1;
        }
        else if (userCard1==10)
        {
          userCard1=10;
          cout<<"Your first card is a "<<jack<<endl;

          outputFile<<setw(3)<<jack;
        }
        else if(userCard1==11)
        {
            userCard1=10;
            cout<<"Your first card is a "<<queen<<endl;

            outputFile<<setw(3)<<queen;
        }
        else if (userCard1==12)
        {
            userCard1=10;
            cout<<"Your first card is an "<<king<<endl;

            outputFile<<setw(3)<<king;
        }
        else if(userCard1==13)
        {
          userCard1=11; 
          cout<<"Your first card is an "<<ace<<endl;

          outputFile<<setw(3)<<ace;
        }





        cout<<"Dealer draws a card to themself faced down."<<endl;
        if(dealerCard1==1)

          dealerCard1=2;

        else if(dealerCard1==2)

          dealerCard1=3;

        else if(dealerCard1==3)

          dealerCard1=4;

        else if(dealerCard1==4)

          dealerCard1=5;

        else if(dealerCard1==5)

          dealerCard1=6;

        else if(dealerCard1==6)

          dealerCard1=7;

        else if(dealerCard1==7)

          dealerCard1=8;

        else if(dealerCard1==8)

          dealerCard1=9;

        else if(dealerCard1==9)

          dealerCard1=10;

        else if(dealerCard1==11)
        {
          dealerCard1=10;

          first_card_check=jack;
        }
        else if(dealerCard1==12)
        {
          dealerCard1=10;

          first_card_check=queen;
        }
        else if(dealerCard1==13)
        {
          dealerCard1=11;

          first_card_check=ace;  
        }





      if(userCard2==1)    //What is user's 2nd card?
      {
          userCard2=2;
          cout<<"Your second card is "<<userCard2<<endl;
          outputFile<<setw(20)<<userCard2;

      }
        else if(userCard2==2)
        {
          userCard2=3;
          cout<<"Your second card is "<<userCard2<<endl;
          outputFile<<setw(20)<<userCard2;
        }
        else if(userCard2==3)
        {
          userCard2=4;
          cout<<"Your second card is "<<userCard2<<endl;
          outputFile<<setw(20)<<userCard2;
        }
        else if(userCard2==4)
        {
          userCard2=5;
          cout<<"Your second card is "<<userCard2<<endl;
          outputFile<<setw(20)<<userCard2;
        }
        else if(userCard2==5)
        {
          userCard2=6;
          cout<<"Your second card is "<<userCard2<<endl;
          outputFile<<setw(20)<<userCard2;
        }
        else if(userCard2==6)
        {
          userCard2=7;
          cout<<"Your second card is "<<userCard2<<endl;
          outputFile<<setw(20)<<userCard2;
        }
        else if(userCard2==7)
        {
          userCard2=8;
          cout<<"Your second card is "<<userCard2<<endl;
          outputFile<<setw(20)<<userCard2;
        }
        else if(userCard2==8)
        {
          userCard2=9;
          cout<<"Your second card is "<<userCard2<<endl;
          outputFile<<setw(20)<<userCard2;
        }
        else if(userCard2==9)
        {
          userCard2=10;
          cout<<"Your second card is "<<userCard2<<endl;
          outputFile<<setw(20)<<userCard2;
        }
        else if (userCard2==10)
        {
          userCard2=10;
          cout<<"Your second card is a "<<jack<<endl;
          outputFile<<setw(20)<<jack;
        }
         else if(userCard2==11)
         {
            userCard2=10;
            cout<<"Your second card is a "<<queen<<endl;
            outputFile<<setw(20)<<queen; 
         }
        else if (userCard2==12)
        {
            userCard2=10;
            cout<<"Your second card is a "<<king<<endl;
            outputFile<<setw(20)<<king;
        }
        else if(userCard2==13)
        {
          userCard2=11; 
          cout<<"Your second card is a "<<ace<<endl;
          outputFile<<setw(20)<<ace;
        }


       if(dealerCard2==1)
       {
        dealerCard2=2;
        cout<<"The dealer's second card is: "<<dealerCard2<<endl<<endl;
       }
       else if(dealerCard2==2)
       {
        dealerCard2=3;
        cout<<"The dealer's second card is: "<<dealerCard2<<endl<<endl;
       }
       else if(dealerCard2==3)
       {
        dealerCard2=4;
        cout<<"The dealer's second card is: "<<dealerCard2<<endl<<endl;
       }
       else if(dealerCard2==4)
       {
        dealerCard2=5;
        cout<<"The dealer's second card is: "<<dealerCard2<<endl<<endl;
       }
       else if(dealerCard2==5)
       {
        dealerCard2=6;
        cout<<"The dealer's second card is: "<<dealerCard2<<endl<<endl;
       }
       else if(dealerCard2==6)
       {
        dealerCard2=7;
        cout<<"The dealer's second card is: "<<dealerCard2<<endl<<endl;
       }
       else if(dealerCard2==7)
       {
        dealerCard2=8;
        cout<<"The dealer's second card is: "<<dealerCard2<<endl<<endl;
       }
       else if(dealerCard2==8)
       {
        dealerCard2=9;
        cout<<"The dealer's second card is: "<<dealerCard2<<endl<<endl;
       }
       else if(dealerCard2==9)
       {
        dealerCard2=10;
        cout<<"The dealer's second card isL "<<dealerCard2<<endl<<endl;
       }
       else if (dealerCard2==10)
       {
        dealerCard2=10;
        cout<<"The dealer's second card is a "<<jack<<endl<<endl;
       }
       else if(dealerCard2==11)
       {
        dealerCard2=10;
        cout<<"The dealer's second card is a "<<queen<<endl<<endl;
       }
       else if(dealerCard2==12)
       {
        dealerCard2=10;
        cout<<"The dealer's second card is a "<<king<<endl<<endl;
       }
       else if(dealerCard2==13)
       {
        dealerCard2=11; 
        cout<<"The dealer's second card is a "<<ace<<endl<<endl;
       }

      sum_dealer=dealerCard1+dealerCard2; //Summation of both cards.
      
      //Detrimins if ace is a 1 or an 11 for user and dealer
       userSum=userCard1+userCard2;


        if(userSum>21 && userCard1 == 11)
        
          {
            userCard1=1;
            userSum=userCard1+userCard2;
          }
          else if(userSum>21 &&userCard2 == 11)
          {
            userCard2=1;
            userSum=userCard1+userCard2;
          }
          else if (userSum>21 && userCard1==11 && userCard2==11)
          {
            userCard1=1;
            userSum=userCard1+userCard2;
          } 
          else
          userSum= userSum;

       sum_dealer=dealerCard1+dealerCard2;


        if(sum_dealer>21 && dealerCard1 == 11)
        {
        dealerCard1=1;
        sum_dealer=dealerCard1+dealerCard2;
        }
        else if(sum_dealer>21 && dealerCard2 == 11)
        {
        dealerCard2=1;
        sum_dealer=dealerCard1+dealerCard2;
        }
        else if (sum_dealer>21 && dealerCard1==11 && dealerCard2==11)
        {
          dealerCard1=1;
          sum_dealer=dealerCard1+dealerCard2;
        }
        else 
       
      if(userSum!=21)
      {

     while(userSum!=21 && testHit==true )
     {
      cout<<"Your total right now is "<<userSum<<endl<<"Would you like to hit or stay?"<<endl;
      cout<<"Press (1) for hit"<<endl;
      cout<<"press (2) for stay"<<endl;
      cin>>hitStay;
       if(hitStay==1)
       {
          hitStayflag=true;
          testHit=false;
       }
        else if(hitStay ==2)
        {
          cout<<"Your total is "<<userSum<<endl;
          hitStayflag= false;
          testHit=false;

          threeCardBlank='-';
          outputFile<<setw(20)<<threeCardBlank;
        }
        else 

          cout<<"Your input was invaild.\nPlease type 1 if you want to hit or type 2 to stay."<<endl;
     }
    
      while(hitStayflag==true)
      {
        if(hitStay==1)
        {
          userCard3=rand()%13+1;
          }
          if(userCard3==1)
          {
            userCard3=2;
            cout<<"Your third card is "<<userCard3<<endl;
            outputFile<<setw(20)<<userCard3;
          }
           else if(userCard3==2)
           {
            userCard3=3;
            cout<<"Your third card is "<<userCard3<<endl;
            outputFile<<setw(20)<<userCard3;
            }
           else if(userCard3==3)
           {
              userCard3=4;
              cout<<"Your third card is "<<userCard3<<endl;
              outputFile<<setw(20)<<userCard3;
            }
           else if(userCard3==4)
           {
              userCard3=5;
              cout<<"Your third card is "<<userCard3<<endl;
              outputFile<<setw(20)<<userCard3;
            }
           else if(userCard3==5)
           {
              userCard3=6;
              cout<<"Your third card is "<<userCard3<<endl;
              outputFile<<setw(20)<<userCard3;
            }
           else if(userCard3==6)
           {
              userCard3=7;
              cout<<"Your third card is "<<userCard3<<endl;
              outputFile<<setw(20)<<userCard3;
            }
           else if(userCard3==7)
           {
              userCard3=8;
              cout<<"Your third card is "<<userCard3<<endl;
              outputFile<<setw(20)<<userCard3;
            }
            else if(userCard3==8)
            {
              userCard3=9;
              cout<<"Your third card is "<<userCard3<<endl;
              outputFile<<setw(20)<<userCard3;
            }
            else if(userCard3==9)
            {
              userCard3=10;
              cout<<"Your third card is "<<userCard3<<endl;
              outputFile<<setw(20)<<userCard3;
            }
            else if (userCard3==10)
            {
              userCard3=10;
              cout<<"Your third card is "<<jack<<endl;
              outputFile<<setw(20)<<jack;
            }
            else if (userCard3==11)
            {
              userCard3=10;
              cout<<"Your third card is "<<queen<<endl;
              outputFile<<setw(20)<<queen;
            }
            else if(userCard3==12)
            {
              userCard3=10;
              cout<<"Your third card is "<<king<<endl;
              outputFile<<setw(20)<<king;
            }
            else 
            {
              userCard3=11; 
              cout<<"Your third card is an "<<ace<<endl;
              outputFile<<setw(20)<<ace;
            }
           
           //Summation with 3rd card
            userSum=userSum+userCard3;

            if(userSum>21 && userCard3 == 11)
            {
            userSum=userSum-userCard3;
            userCard3=1;
            userSum=userSum+userCard3;
            hitStayflag= false;
            }
             else if(userSum>21 && userCard1 == 11)
            {
            userSum=userSum-userCard1;
            userCard1=1;
            userSum=userSum+userCard1;
            userSum=userSum+userCard3;
            hitStayflag= false;
            }
            else if(userSum>21 && userCard2 == 11)
            {
            userSum=userSum-userCard2;
            userCard2=1;
            userSum=userSum+userCard2;
            userSum=userSum+userCard3;
            hitStayflag= false;
            }
            else 
            {
            hitStayflag= false;
            }
        }
      }
        
        
          if(dealerCard1==2)
            cout<<"The dealer's first card is: "<<dealerCard1<<endl;

            else if(dealerCard1==3)

              cout<<"The dealer's first card was "<<dealerCard1<<endl;

            else if(dealerCard1==4)

              cout<<"The dealer's first card was "<<dealerCard1<<endl;
              
            else if(dealerCard1==5)

              cout<<"The dealer's first card was "<<dealerCard1<<endl;

            else if(dealerCard1==6)

              cout<<"The dealer's first card was "<<dealerCard1<<endl;

            else if(dealerCard1==7)

              cout<<"The dealer's first card was "<<dealerCard1<<endl;

            else if(dealerCard1==8)

              cout<<"The dealer's first card was "<<dealerCard1<<endl;
              
            else if(dealerCard1==9)

              cout<<"The dealer's first card was "<<dealerCard1<<endl;

            else if(dealerCard1==10 && first_card_check==jack)

              cout<<"The dealer's first card was an "<<jack<<endl;

            else if(dealerCard1==10 && first_card_check==queen)

              cout<<"The dealer's first card was an "<<queen<<endl;

            else if(dealerCard1==10 && first_card_check==king)

              cout<<"The dealer's first card was an "<<king<<endl;
            
            else if(dealerCard1==11)
            {
              cout<<"The dealer's first card was "<<ace<<endl;
            
          }

     
     if (userSum!=21)
     {
     
        //prints how much you bet to the file
         outputFile<<setw(23)<<bet;

      if(sum_dealer>21 && dealerCard1 == 11){
        dealerCard1=1;
        sum_dealer=dealerCard1+dealerCard2;
        }
        else if(sum_dealer>21 && dealerCard2 == 11){
        dealerCard2=1;
        sum_dealer=dealerCard1+dealerCard2;
        }
        else if (sum_dealer>21 && dealerCard1==11 && dealerCard2==11){
          dealerCard1=1;
          sum_dealer=dealerCard1+dealerCard2;
        }
        else 

        
        sum_dealer=dealerCard1+dealerCard2;
     

      if (sum_dealer<17){
        hitStayflag=true;
        dealerCard3=rand()%13+1;
        cout<<"The dealer has decided to hit."<<endl;
      }
      else  {
        hitStayflag=false;
        sum_dealer=sum_dealer;
        outputFile<<setw(18)<<sum_dealer;
      }
      
      while(hitStayflag==true){
        if(dealerCard3==1){
         dealerCard3=2;
         cout<<"The dealer's third card is an "<<dealerCard3<<endl;
        
         }
         else if(dealerCard3==2){
          dealerCard3=3;
          cout<<"The dealer's third card is an "<<dealerCard3<<endl;
          
         }
         else if(dealerCard3==3){
          dealerCard3=4;
          cout<<"The dealer's third card is an "<<dealerCard3<<endl;
         
         }
         else if(dealerCard3==4){
          dealerCard3=5;
          cout<<"The dealer's third card is an "<<dealerCard3<<endl;
          
         }
         else if(dealerCard3==5){
          dealerCard3=6;
          cout<<"The dealer's third card is an "<<dealerCard3<<endl;
          
         }
         else if(dealerCard3==6){
          dealerCard3=7;
          cout<<"The dealer's third card is an "<<dealerCard3<<endl;
         
         }
         else if(dealerCard3==7){
          dealerCard3=8;
          cout<<"The dealer's third card is an "<<dealerCard3<<endl;
          
         }
         else if(dealerCard3==8){
          dealerCard3=9;
          cout<<"The dealer's third card is an "<<dealerCard3<<endl;
          
         }
         else if(dealerCard3==9){
          dealerCard3=10;
          cout<<"The dealer's third card is an "<<dealerCard3<<endl;
         
         }
         else if (dealerCard3==10){
          dealerCard3=10;
          cout<<"The dealer's third card is an "<<jack<<endl;
         
         }
         else if(dealerCard3==11){
          dealerCard3=10;
          cout<<"The dealer's third card is an "<<queen<<endl;
         
         }
         else if(dealerCard3==12){
          dealerCard3=10;
          cout<<"The dealer's third card is an "<<king<<endl;
          
         }
         else {
          dealerCard3=11; 
          cout<<"The dealer's third card is an "<<ace<<endl;
          
         }
        //total for dealer if they hit
        sum_dealer=sum_dealer+dealerCard3;

        if(sum_dealer>21 && dealerCard3 == 11){
          sum_dealer=sum_dealer-dealerCard3;
          dealerCard3=1;
          sum_dealer=sum_dealer+dealerCard3;
          outputFile<<setw(20)<<sum_dealer;
          hitStayflag=false;
          }
         else if(sum_dealer>21 && dealerCard1 == 11){
          sum_dealer=sum_dealer-dealerCard1;
          dealerCard1=1;
          sum_dealer=sum_dealer+dealerCard1;
          sum_dealer=sum_dealer+dealerCard3;
           outputFile<<setw(20)<<sum_dealer;
          hitStayflag=false;
          }
         else if(sum_dealer>21 && dealerCard2 == 11){
          sum_dealer=sum_dealer-dealerCard2;
          dealerCard1=2;
          sum_dealer=sum_dealer+dealerCard2;
          sum_dealer=sum_dealer+dealerCard3;
          outputFile<<setw(20)<<sum_dealer;
          hitStayflag=false;
          }
         
          else {
          outputFile<<setw(18)<<sum_dealer;
          hitStayflag=false;
          }
       }
         
       

      //detimiuns who won the game
      if (userSum>21)
      {
        cout<<"The hand you had was "<<userSum<<" which is over 21 and you busted, The dealer won. You lost $"<<bet<<endl;
        outputFile<<setw(20)<<"L";
        
        }
        else if(sum_dealer> 21){
          cout<<"The hand the dealer had was "<<sum_dealer<< " which is over 21, so they busted.\nYou win. You won $"<<winner<<endl;
          credit=credit+winner;
          outputFile<<setw(20)<<"W";
        }
        else if (userSum == 21 && sum_dealer<userSum){
          cout<<"The user got and won Blackjack.\nThe amount won is $"<<winner<<endl;
          credit=credit+winner;
           outputFile<<setw(20)<<"W";
        }
        else if(sum_dealer==21 && sum_dealer>userSum){
          cout<<"\nThe dealer got a Blackjack and won this game.\nYou lost $"<<bet<<endl;
          outputFile<<setw(20)<<"L";
          
        }
        else if(sum_dealer == userSum){
          cout<<"\nIt was a tie.\nThere is no winner and no credits was lost.\nYou get to keep $"<<bet<<endl;
          credit=credit+bet;
          outputFile<<setw(20)<<"T";
        }
        else if (sum_dealer>userSum){
          cout<<"\nThe dealer won with a hand "<<sum_dealer<< ". You had hand of "<<userSum<< "\nYou lost $"<<bet<<endl;
          outputFile<<setw(20)<<"L";
        }
        else if (userSum>sum_dealer){
          cout<<"\nYou have won this round with hand of "<<userSum<<". The dealer had a hand of "<<sum_dealer<<"\nYou won $"<<winner<<endl;
          credit=credit+winner;
          outputFile<<setw(20)<<"W";

        }
     }
      
     
        bet_flags=true;

        while(userSum==21 && hitStayflag==true)

        if(userSum>sum_dealer)
          {
            cout<<"You got a blackjack and won!\nThe amount you won is $"<<winner<<endl;
            credit=credit+winner;
            outputFile<<setw(20)<<"W";
            hitStayflag=false;
          }
        else if(userSum ==sum_dealer )
          {
            cout<<"You and the dealer both got an blackjack.\nThat means you got a push, no money was gained or lost."<<endl;
            credit=credit+bet;
            outputFile<<setw(20)<<"T";
            hitStayflag=false;
          }
      
      outputFile<<setw(20)<<credit<<endl;
      
      hitStayflag=false;
      testHit=true;

      outputFile.close();
      inputFile.close();
     
      break;
     
    case 2: //When user selects 2, terminal prompts game history. 

    inputFile.open("BarkerHistory.txt");
    if(inputFile.is_open())
    {
    while(getline (inputFile,gameHistory))
    {

      cout<<gameHistory<<endl;

    }
      inputFile.close();
    }
    else 
    {

     cout<<"No game history found."<<endl;

    }
  }
  
}while (game!=3);

  cout<<"Program has ended.\nThank you for playing."<<endl;

return 0;
}
  