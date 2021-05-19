#include <iostream>
#include "plant.h"
#include "function.h"

using namespace std;

int main()
{
    setlocale(0, "");
    int L1,L2,L3;
    int N,k, M[20];
    double U[20][3];


    Plant plant;
    plant_init(plant);

    int choice;
    cout << "Хотите провести эксперимент(1) или исследование(2) ?" << endl << "Выберите цифру в скобках:" << endl; cin >> choice;

    if (choice == 1){
    cout << "Введите номера каналов управления: " << endl; cin >> L1 >> L2 >> L3;
    cout << "Введите число контролируемых единиц продукции: " << endl; cin >> N;
    Input_U(N, 3, U);
    cout << "Введите число каналов опроса: " << endl; cin >> k;
    Input_M ( k, M);

    double Z[20][20];
    for (int i=0;i<N; i++)
    {
        plant_control (L1,U[i][0],plant);
        plant_control (L2,U[i][1],plant);
        plant_control (L3,U[i][2],plant);
        for (int j=0; j<k;j++)
        {
            Z[i][j]=plant_measure(M[j],plant);
        }
    }
    Output (L1, L2, L3, N, k, M, U, Z);
    average_value (k, N, Z);
    }
    else{
    int L;
    double U, Umin,Umax,dU;
    cout << "Введите канал упраления: "; cin >> L;
    cout << "Введите допустимое минимальное и максимальное значение на канале: "; cin >> Umin >> Umax;
    cout << "Введите точку начала исследования: "; cin >> U;
    cout << "Введите шаг увелечения точки исследования: "; cin >> dU;
    if ( U < Umin, U > Umax){
        cout << "ERROR!";
        return 1;
    }
    N=(Umax - U)/dU+1;
    double new_U[100];
    for (int i=0; i < N ; i++){
        new_U[i]=U+dU*i;
    }
    cout << "Введите число каналов опроса: " << endl; cin >> k;
    Input_M ( k, M);
    double Z[20][20];
    for (int i=0;i<N; i++)
    {
        plant_control (L,new_U[i],plant);
        for (int j=0; j<k;j++)
        {
            Z[i][j]=plant_measure(M[j],plant);
        }
    }
    cout << "шаг\t|\t" << "L=" << L << "\t|";
    for (int i=0; i<k; i++){
        cout << "\tM[" << i+1 << "]=" << M[i] <<"\t|";
    }
       cout << endl;
    for (int i=0; i<N; i++){
             cout << i << "\t|\t" << new_U[i] << "\t|" ;
            for (int j=0; j < k; j++){
                cout  << "\t" <<Z[i][j] << "\t|";
            }
        cout  << endl;
        }
    }



    return 0;
}
