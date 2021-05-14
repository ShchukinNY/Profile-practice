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


    cout << "¬ведите номера каналов управлени€: " << endl; cin >> L1 >> L2 >> L3;


    cout << "¬ведите число контролируемых единиц продукции: " << endl; cin >> N;
    Input_U(N, 3, U);


    cout << "¬ведите число каналов опроса: " << endl; cin >> k;
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
    average_value(k,N,Z);
    return 0;
}
