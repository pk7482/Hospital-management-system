// doctor. cpp 
// inherits from availableon , disease and person files

#include "availableOn.cpp"
#include "disease.cpp"
#include "person.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class doctor: public Person{
  private:
    int doctorid;
    Disease disease;
    Available availableon;
        char doctorFile[20] = "doctorData.dat";
        char doctorTempFile[20] = "doctorData2.dat";
  public:
    void getdoctordata(){
      cout << "enter data of doctor " << endl;
      getPersonData();
      cout << "enter doctor id ";
      cin >> doctorid;
      cout << "enter name of specializations ";
      disease.getDiseaseDetail();
      availableon.whenAvailable();
    }
    
    void showdoctordata(){
      cout << "\n\t\t\t DETAILS OF DOCTOR ARE:" << endl;
       showPersonData();
      cout << "doctor id is " << doctorid << endl;
       disease.showDiseaseList();
       availableon.displayAvailable();
      cout << endl << endl;
    }
    
    void adddoctordata(){
      getdoctordata();
      ofstream doctordatabase(doctorFile,ios::binary|ios::out|ios::app);
      doctordatabase.write((char*)this,sizeof(doctor));  
    }
    
    void showdoctordatafromfile(){
      ifstream readdatafromdatabase(doctorFile,ios::binary|ios::in);
      
      while(!readdatafromdatabase.eof()){
    
        if(readdatafromdatabase.read((char*)this,sizeof(doctor)))
          showdoctordata();
      }
    }
    
    void deletedoctor(){
      int n, flag = 0;
      cout << "enter the doctorid of doctor you want to delete";
      cin >> n;

      ifstream ifdoctor;
      ifdoctor.open(doctorFile,ios::binary|ios::in);
      ofstream ofdoctor;
      ofdoctor.open(doctorTempFile,ios::binary|ios::out);

      while(!ifdoctor.eof()){
        ifdoctor.read((char*)this,sizeof(doctor));
        if(ifdoctor){

          // comparing the patient Id with that
                    // of the entered patient Id
                    if (n == doctorid) {
                        flag = 1;
                    }
                    else {
                        ofdoctor.write((char*)this,sizeof(doctor));
                    }
        }
      }
      ifdoctor.close();
      ofdoctor.close();
      remove(doctorFile);
      rename(doctorTempFile,doctorFile);
      showdoctordatafromfile();

      if (flag == 1)
                cout << "\nRecord successfully deleted \n";
            else
                cout << "\nRecord not found \n";
    }
    
    void editdoctor(){
      int n, pos, flag = 0;
      cout << "enter the doctorid of doctor you want to edit";
      cin >> n;

      //int count=1;
      fstream fdoctor;
      fdoctor.open(doctorFile, ios::binary | ios::in | ios::out);

      while(!fdoctor.eof()){
                // storing the position of
                // current file pointeri.e. at
                // the end of previously read record
                pos = fdoctor.tellg();

        fdoctor.read((char*)this,sizeof(doctor));
        if(fdoctor){

                    // comparing the patient Id with that
                    // of the entered patient Id
          if (n == doctorid) {
                        flag = 1;

            // setting the new (modified )
                        // data of the object or new record
            getdoctordata();
            
                        // placing the put(writing) pointer
                        // at the starting of the  record
                        fdoctor.seekp(pos);
            
                        // writing the object to the file
            fdoctor.write((char*)this,sizeof(doctor));

                        // display the data
                        showdoctordata();
                        break;
          }
        }
      }
      fdoctor.close();

            if (flag == 1)
                cout << "\nRecord successfully modified \n";
            else
                cout << "\nRecord not found \n";
    }


void doDoctorRelatedWork() {
      char flag;
      int choice;
      do{
        cout << "enter option 1 to set doctor "<<endl;
        cout << "enter option 2 to delete " << endl;
        cout << "enter option 3 to show all data " << endl;
        cout << "enter option 4 to edit data " << endl;
        cout << "enter option 5 to exit program " << endl;
        cin >> choice;
        if (choice == 1){
            do{
            
            adddoctordata();
            cout << "add another doctor ? 1 for yes ";
            cin >> flag;
          
            }while (flag == 1);
          }
        else if(choice == 3){
            showdoctordatafromfile();
        }
        else if (choice == 2){
          deletedoctor();
          // showdoctordatafromfile();
        }  
        else if (choice == 4) {
          editdoctor();
          // showdoctordata();
        }
      }while(choice == 1 | choice == 2 | choice == 3|choice == 4);
    }  
};

// int main(){
//   doctor d;
//   d.doDoctorRelatedWork();
//   //d1.editdoctor();
//   return 0;
// }
