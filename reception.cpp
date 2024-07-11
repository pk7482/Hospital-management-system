#include "patient.cpp"
#include "doctor.cpp"

int main() {
    patient p;
    doctor d;
    int choice;

    do{
        cout << "\n\nEnter option 1 for patient "<<endl;
        cout << "Enter option 2 for doctor " << endl;
        cout << "Enter option 3 to exit program " << endl;
        cin >> choice;
        
        switch (choice)
        {
        case 1: cout << "\n--- Patient ---"<<endl;
                p.doPatientRelatedWork();
            break;

        case 2: cout << "\n--- Doctor ---"<<endl;
                d.doDoctorRelatedWork();
            break;
        
        default:
            break;
        }
    } while(choice == 1 | choice == 2);

    return 0;
}
