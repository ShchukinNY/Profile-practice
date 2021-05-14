#include <iostream>
#include "function.h"

using namespace std;

void Input_U(int N, int m, double U[][3]){
    cout << "¬ведите матрицу плана эксперимента: " << endl;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<3; j++)
        {
            cin >> U[i][j];
        }
    }
    return;
}


void Input_M (int k, int M[20]){
    cout << "¬ведите номера каналов опроса: " << endl;
    for (int i=0; i<k; i++)
    {
        cin >> M[i];
    }
    return;
}


void Output (int L1, int L2, int L3, int N, int k, int M[20], double U[][3], double Z[][20]){
     cout << "N="<< N << "\t\t|"
    <<"\tL1="  << L1 << "\t|"
    << "\tL2=" << L2 << "\t|"
    << "\tL3=" << L3 << "\t|" ;
    for (int i=0; i<k; i++){
        cout << "\tM[" << i+1 << "]=" << M[i] <<"\t|";
    }
    for (int i=0; i<N; i++){
    cout << endl;
    cout << i+1 << "\t\t" << "|"
    << "\t" << U[i][0] << "\t" << "|"
    << "\t" << U[i][1] << "\t" << "|"
    << "\t" << U[i][2] << "\t" << "|";
    for (int j=0; j<k; j++){
        cout << "\t" << Z[i][j] << "\t" << "|";
        }
    }
    cout << endl;
    return;
}


void average_value (int k, int N, double Z[][20]){
    double average_value[20];
    for (int i=0; i<k; i++){
        for (int j=0; j<N; j++){
            average_value[i]=average_value[i]+Z[j][i];
        }
        average_value[i]=average_value[i]/N;
    }
    cout << "Cреднее значение"<< "|\t-\t|\t-\t|\t-\t|";
    for (int i=0; i<k ; i++){
        cout << "\t" << average_value[i] << "\t" << "|";
    }

return;
}
