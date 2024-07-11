#include<iostream>
#include<string.h>
#include<time.h>
using namespace std;
class Available
{
  private:                                 
    char DayOfweek[15][7];
    char shift1[25],shift2[25];
    int i, NoD;
  public:
    //Taking input and putting available weekday
    void whenAvailable() 
    {
      cout<<"Enter no. of available days 1-7:"<<endl;//input day dr. available in week
      cin>>NoD;
      
      while (!((NoD <= 7) && (NoD >= 1))) //loop for taking data 1-7
      {
             cout<<"[ERROR] The number you entered is out of range"<<endl;
                cout<<"Enter number between 1-7"<<endl;
              cin>>NoD;
          }
      
      cout<<"Enter "<<NoD<<" days of week for Dr.Available?:"<<endl;// string type
      for(i=0;i<NoD;i++)
      {
        cin>>DayOfweek[i];
      }
      ///input for Dr. shift time 
      cout<<"Enter Dr. First shift:"<<endl;
      cin>>shift1;
        
        cout<<"Enter Dr. second shift:"<<endl;
      cin>>shift2;
         
    }
    //displaying available day and shift
    void displayAvailable()
    {
      //displaying current time from system
      time_t rawtime;
             struct tm * timeinfo;
              time ( &rawtime );
              timeinfo = localtime ( &rawtime );
              cout<<"\t\t\t\t\t\t\t\t\t\t\t\tLocal Time:"<<endl;
              cout<<"\t\t\t\t\t\t\t\t\t\t\t\t"<< asctime (timeinfo);
    
        //displaying days and shift
     cout<<"\n\t\t\t\t\tDr. is available for"<<NoD<<" days in Week"<<endl;
     cout<<" \n\t\t\t\t\t**Available days are**:"<<endl;
      
      for(i=0;i<NoD;i++)
      {
        cout<<"\t\t\t\t\t\t"<<DayOfweek[i]<<endl;
        
      }
      cout<<" \n\t\t\t\t\t**Dr. Shift are**"<<endl;
      cout<<"\t\t\t\t\t\t"<<shift1<<endl<<"\t\t\t\t\t\t"<<shift2<<endl;
    }
    
    
  
};
// int main()
// {
//   Available a1;
//   a1.whenAvailable();
//   a1.displayAvailable();
//   return 0;
  
// }
