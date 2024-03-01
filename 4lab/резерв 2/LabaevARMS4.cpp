// LabaevARMS4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

int main(){   
    int numOfChoiseS, numOfChoise, numOfChoiseE;
    int N, numberOfPersonal;

    Factory newFactory(Randomization::getFackName());

    Worker* arrayOfWorkers[10]{};
    Engineer* arrayOfEngineer[10]{};
    Detail* arrayOfDetails[16]{};

    int counterWorkers = 0;
    int counterEngineers = 0;
    int counterForemans = 0;
    int counterManagers = 0;

    int AddedDetail = -1;
    int AddedWorker = -1;

//    cout << Randomization::getRanFIO() << endl;
 //   cout << Randomization::getDetailName() << endl;
//    cout << Randomization::getFackName() << endl;

    srand(time(NULL));

    do {
        cout << "add(1) or delete?(2)" << endl;
        cin >> numOfChoiseS;
        switch (numOfChoiseS)
        {
        case 1:
            cout << "What entities to add?" << endl;
            cout << "1 - Worker and Detail" << endl;
            cout << "2 - Engineer" << endl;
            cout << "3 - Foreman" << endl;

            cin >> numOfChoise;

            if (numOfChoise == 1) {
                cout << "How many Workers to add?" << endl;
                cin >> N;
                for (int i = 1; i <= N; i++) {
                    Worker& newWorker = *(new Worker(Randomization::getRanFIO(), Randomization::getRanAge(), Randomization::getRanSalary()));
                    newFactory.addNewPersonal(newWorker);
                    int numberOfDetailsForWorker = 0;
                    cout << "How many Details to add?" << endl;
                    cin >> numberOfDetailsForWorker;
                    for (int j = 0; j < numberOfDetailsForWorker; j++) {
                        Detail& newDetail = *(new Detail(Randomization::getDetailName(), Randomization::getRanK1(), Randomization::getRanK2()));
                        AddedDetail++;
                        arrayOfDetails[AddedDetail] = &newDetail;
                        newWorker.addNewDetail(*arrayOfDetails[AddedDetail]);
                    }

                    arrayOfWorkers[counterWorkers++] = &newWorker;
                }
            }
            else if (numOfChoise == 2) {
                cout << "How many Engineers to add?" << endl;
                cin >> N;
                for (int i = 1; i <= N; i++) {
                    Engineer& newEngineer = *(new Engineer(Randomization::getRanFIO(), Randomization::getRanAge(), Randomization::getRanSalary()));
                    newFactory.addNewPersonal(newEngineer);
                    int numberOfWorkersForEngineer = 0;
                    cout << "How many workers do you need to add to this Engineer?" << endl;
                    cin >> numberOfWorkersForEngineer;
                    for (int j = 0; j < numberOfWorkersForEngineer; j++) {
                        AddedWorker = AddedWorker+1;
                        newEngineer.addNewWorker(*arrayOfWorkers[AddedWorker]);
                    }

                    arrayOfEngineer[counterEngineers++] = &newEngineer;
                }
            }
            else if (numOfChoise == 3) {
                cout << "How many Foremanrs to add?" << endl;
                cin >> N;
                for (int i = 1; i <= N; i++) {
                    Foreman& newForeman = *(new Foreman(Randomization::getRanFIO(), Randomization::getRanAge(), Randomization::getRanSalary()));
                    newFactory.addNewPersonal(newForeman);
                    counterForemans++;
                    int numberOfEngineersForForeman = 0;
                    cout << "How many engineers do you need to add to this Foreman?" << endl;
                    cin >> numberOfEngineersForForeman;
                    for (int j = 0; j < numberOfEngineersForForeman; j++) {
                        newForeman.addNewEngineer(*arrayOfEngineer[j]);
                    }
                    Worker& newWorker = *(new Worker(Randomization::getRanFIO(), Randomization::getRanAge(), Randomization::getRanSalary()));
                    arrayOfWorkers[counterWorkers++] = &newWorker;
                    Manager& newManager = *(new Manager(newWorker));
                    newFactory.addNewPersonal(*arrayOfWorkers[counterWorkers]);
                    counterManagers++;
                }
            }
            else{
                cout << "only 1 - 3!" << endl;
            }
     break;
        case 2:
            cout << "What entities to delete?" << endl;
            cout << "1 - Worker and Detail" << endl;
            cout << "2 - Engineer" << endl;
            cout << "3 - Foreman" << endl;

            cin >> numOfChoise;

            if (numOfChoise == 1) {
                cout << "What number of Workers to delete?" << endl;
                cout << "Enter Personal number" << endl;
                cin >> numberOfPersonal;

                newFactory.deleteById(numberOfPersonal - 1);
            }
            else if (numOfChoise == 2) {
                cout << "What number of Engineers to delete?" << endl;
                cout << "Enter Personal number" << endl;
                cin >> numberOfPersonal;
                numberOfPersonal = numberOfPersonal + counterWorkers++;;

                newFactory.deleteById(numberOfPersonal - 1);
            }
            else if (numOfChoise == 3) {
                cout << "What number of Foremans to delete??" << endl;
                cout << "Enter Personal number" << endl;
                cin >> numberOfPersonal;
                numberOfPersonal = numberOfPersonal + counterWorkers + counterEngineers;

                newFactory.deleteById(numberOfPersonal - 1);
            }
            else{
                cout << "only 1 - 3!" << endl;
            }
        break;
        }
        cout << "Exit - 0" << endl;
        cout << "Info - 1" << endl;
        cout << "Proceaed - 2" << endl;
        cin >> numOfChoiseE;
    }
        while (numOfChoiseE != 0 && numOfChoiseE != 1);

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

    std::cout << "End of Test. URA COMRADS!\n"; 
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
