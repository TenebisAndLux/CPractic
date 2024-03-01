#include <iostream>
#include "Detail.h"
#include "Worker.h"
#include "Engineer.h"
#include "GeneralOfDepartment.h"
#include "Manager.h"
#include "Factory.h"
#include "Randomization.h"
#include<ctime>

using namespace std;

int main() {
    int numOfChoiseS, numOfChoise, numOfChoiseE;
    int N, numberOfPersonal;

    Factory newFactory(Randomization::getFackName());

    int counterWorkers = 0;
    int counterEngineers = 0;
    int counterForemans = 0;
    int counterManagers = 0;

    int AddedWorker = 0;
    int AddedEngineer = 0;
    int AddedForeman = 0;

    srand(time(NULL));

    cout << "The program implies the sequential filling of the database of workers" << endl;

    do {
        cout << "add(1) or delete?(2)" << endl;
        cin >> numOfChoiseS;
        switch (numOfChoiseS)
        {
        case 1:
        {
            cout << "What entities to add?" << endl;
            cout << "1 - Worker and Detail" << endl;
            cout << "2 - Engineer" << endl;
            cout << "3 - Foreman" << endl;
            cout << "4 - Manager" << endl;

            cin >> numOfChoise;

            if (numOfChoise == 1) {
                cout << "How many Workers to add?" << endl;
                cin >> N;
                for (int i = 1; i <= N; i++) {
                    newFactory.AddPerson(Randomization::getRanFIO(), Randomization::getRanAge(), Randomization::getRanSalary(), PersonalPost::WORKER);
                    counterWorkers++;
                    int numberOfDetailsForWorker = 0;
                    cout << "How many Details to add?" << endl;
                    cin >> numberOfDetailsForWorker;
                    for (int j = 1; j <= numberOfDetailsForWorker; j++) {
                        ((Worker&)newFactory.GetPersonal(newFactory.getCapacityOfPersonals() - 1)).AddDetail(Randomization::getDetailName(), Randomization::getRanK1(), Randomization::getRanK2());
                    }
                }
            }
            else if (numOfChoise == 2) {
                cout << "How many Engineers to add?" << endl;
                cin >> N;
                for (int i = 1; i <= N; i++) {
                    newFactory.AddPerson(Randomization::getRanFIO(), Randomization::getRanAge(), Randomization::getRanSalary(), PersonalPost::ENGINEER);
                    counterEngineers++;
                    int numberOfWorkersForEngineer = 0;
                    cout << "How many workers do you need to add to this Engineer?" << endl;
                    cin >> numberOfWorkersForEngineer;
                    while ((counterWorkers - AddedWorker) < numberOfWorkersForEngineer){
                        cout << "You are adding too much." << endl;
                        cin >> numberOfWorkersForEngineer;
                    }
                    for (int j = 1; j <= numberOfWorkersForEngineer; j++) {
                        AddedWorker++;
                        ((Engineer&)newFactory.GetPersonal(newFactory.getCapacityOfPersonals() - 1)).addNewWorker((Worker&)newFactory.GetPersonalByPost(PersonalPost::WORKER, AddedWorker));
                    }
                }
            }
            else if (numOfChoise == 3) {
                cout << "How many Foremanrs to add?" << endl;
                cin >> N;
                for (int i = 1; i <= N; i++) {
                    newFactory.AddPerson(Randomization::getRanFIO(), Randomization::getRanAge(), Randomization::getRanSalary(), PersonalPost::FOREMAN);
                    counterForemans++;
                    int numberOfEngineersForForeman = 0;
                    cout << "How many engineers do you need to add to this Foreman?" << endl;
                    cin >> numberOfEngineersForForeman;
                    while ((counterEngineers - AddedEngineer) < numberOfEngineersForForeman) {
                        cout << "You are adding too much." << endl;
                        cin >> numberOfEngineersForForeman;
                    }
                    for (int j = 1; j <= numberOfEngineersForForeman; j++) {
                        AddedEngineer++;
                        ((Foreman&)newFactory.GetPersonal(newFactory.getCapacityOfPersonals() - 1)).addNewEngineer((Engineer&)newFactory.GetPersonalByPost(PersonalPost::ENGINEER, AddedEngineer));
                    }
                }
            }
            else if (numOfChoise == 4) {
                cout << "How many Managers to add?" << endl;
                cin >> N;
                for (int i = 1; i <= N; i++) {
                    newFactory.AddPerson(Randomization::getRanFIO(), Randomization::getRanAge(), Randomization::getRanSalary(), PersonalPost::MANAGER);
                    counterManagers++;
                    int numberOfForemansForManager = 0;
                    cout << "How many foremans do you need to add to this Manager?" << endl;
                    cin >> numberOfForemansForManager;
                    while ((counterForemans - AddedForeman) < numberOfForemansForManager) {
                        cout << "You are adding too much." << endl;
                        cin >> numberOfForemansForManager;
                    }
                    for (int j = 1; j <= numberOfForemansForManager; j++) {
                        AddedForeman++;
                        ((Manager&)newFactory.GetPersonal(newFactory.getCapacityOfPersonals() - 1)).addNewForeman((Foreman&)newFactory.GetPersonalByPost(PersonalPost::FOREMAN, AddedForeman));
                        ((Foreman&)newFactory.GetPersonalByPost(PersonalPost::FOREMAN, AddedForeman)).setManager((Manager*)&newFactory.GetPersonalByPost(PersonalPost::MANAGER, counterManagers));
                    }
                }
            }
            else {
                cout << "1)Only 1 - 4!" << endl;
                cout << "2)Database full" << endl;
            }
        }
        break;
        case 2:
            cout << "What entities to delete?" << endl;
            cout << "1 - Worker and Detail" << endl;
            cout << "2 - Engineer" << endl;
            cout << "3 - Foreman" << endl;
            cout << "4 - Manager" << endl;

            cin >> numOfChoise;

            if (numOfChoise == 1) {
                cout << "What number of Workers to delete?" << endl;
                cout << "Enter Personal number" << endl;
                cin >> numberOfPersonal;
                if (numberOfPersonal > counterWorkers) {
                cout << "This number is not in the database." << endl;
                }
                else {
                    newFactory.deleteById(numberOfPersonal, PersonalPost::WORKER);
                }
            }
            else if (numOfChoise == 2) {
                cout << "What number of Engineers to delete?" << endl;
                cout << "Enter Personal number" << endl;
                cin >> numberOfPersonal;
                if (numberOfPersonal > counterEngineers) {
                    cout << "This number is not in the database." << endl;
                }
                else {
                    newFactory.deleteById(numberOfPersonal, PersonalPost::ENGINEER);
                }
            }
            else if (numOfChoise == 3) {
                cout << "What number of Foremans to delete??" << endl;
                cout << "Enter Personal number" << endl;
                cin >> numberOfPersonal;
                if (numberOfPersonal > counterForemans) {
                    cout << "This number is not in the database." << endl;
                }
                else {
                    newFactory.deleteById(numberOfPersonal, PersonalPost::FOREMAN);
                }
            }
            else if (numOfChoise == 4) {
                cout << "What number of Managers to delete??" << endl;
                cout << "Enter Personal number" << endl;
                cin >> numberOfPersonal;
                if (numberOfPersonal > counterManagers) {
                    cout << "This number is not in the database." << endl;
                }
                else {
                    newFactory.deleteById(numberOfPersonal, PersonalPost::MANAGER);
                }
            }
            else {
                cout << "1)Only 1 - 4!" << endl;
                cout << "2)Number selection error, please try again" << endl;
            }
            break;
        }
        cout << "Exit - 0" << endl;
        cout << "Info - 1" << endl;
        cout << "Proceaed - 2" << endl;
        cin >> numOfChoiseE;
    } while (numOfChoiseE != 0 && numOfChoiseE != 1);

    if (numOfChoiseE == 1) {
        cout << endl;
        cout << "Total Info: " << endl;
        cout << endl;
        cout << newFactory.getNameOfFactory() << endl;
        cout << endl;
        cout << "Payouts: " << endl;
        cout << newFactory.getPayouts() << endl;
        cout << endl;
        cout << "Statistic-Info About Personal: " << endl;
        newFactory.printInfoAboutMinMaxSalary();
        cout << endl;
        cout << "Total-Info About Personal" << endl;
        newFactory.printInfoAboutPersonal();
        cout << endl;
        cout << "The number of people employed in each type of position: " << endl;
        cout << "Statistic-Info About Count of Personal: " << endl;
        newFactory.printInfoAboutPersonalByPost();
    };

    cout << endl;
    cout << endl;
    std::cout << "End of Test. URA COMRADS!\n";
    return 0;
}
