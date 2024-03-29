#ifndef PJ_FINAL_GREEDYFUNCTION_H
#define PJ_FINAL_GREEDYFUNCTION_H


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits.h>
#include <random>
#include <time.h>
#include <algorithm>
#include <unistd.h>

int seed = 0;

using namespace std;


vector<int> GreedyFunction(vector<vector<int> > &cities, int vehicles, int capacity, int dimension, int randomizer,
                           vector<int> &demand, vector<vector<int>> &greedy_solution) {


    vector<int> vehicle_route, vehicle_all;
    int sum_distances = 0, count2 = 0, i = 0, a = 0, ra = 0, suma = 0, ind_menor, j = 0, ai = 0, dimension_achieved = 0, counter = 0;
    int menor = INT_MAX;
    vector<int> total_distances;
    int buf_demand = 0, flag = 0;
    vehicle_all.push_back(0);

    greedy_solution.clear();
    while (dimension_achieved == 0) {
        srand(randomizer + seed);
        seed += 3;

        vehicle_route.push_back(a);

        while (count2 < cities.size()) {
            for (j = 0; j < cities.size(); j++) {
                if (vehicle_all.size() == dimension) {
                    dimension_achieved = 1;
                    break;
                }
                if (count2 == 0) {
                    j = rand() % (cities.size()-1);
                    if (find(vehicle_all.begin(), vehicle_all.end(), j) == vehicle_all.end()) {
                        ra = vehicle_route[0];
                        menor = cities[ra][j];
                        ind_menor = j;
                        break;
                    }
                }


                if (cities[i][j] != 0 && cities[i][j] < menor) {
                    if (find(vehicle_all.begin(), vehicle_all.end(), j) == vehicle_all.end()) {
                        if (demand[j] < (capacity - buf_demand)) {
                            menor = cities[i][j];
                            ind_menor = j;
                        } else {
                            menor = cities[i][a];
                            ind_menor = 0;
                            flag = 1;
                        }
                    }
                }
            }
            if (dimension_achieved == 1) {
                vehicle_route.push_back(0);
                sum_distances += cities[vehicle_route.at(count2)][vehicle_route.at(count2 + 1)];
                break;
            }

            if (flag == 1) {

                vehicle_route.push_back(0);
                sum_distances += cities[vehicle_route.at(count2)][vehicle_route.at(count2 + 1)];
                i = ind_menor;
                menor = INT_MAX;
                break;
            }

            vehicle_route.push_back(ind_menor);
            vehicle_all.push_back(ind_menor);

            i = ind_menor;
            menor = INT_MAX;

            sum_distances += cities[vehicle_route.at(count2)][vehicle_route.at(count2 + 1)];
            count2++;
            buf_demand += demand[ind_menor];
        }


        count2 = 0;
        ai = 0;
        greedy_solution.push_back(vehicle_route);
        vehicle_route.clear();

        total_distances.push_back(sum_distances);
        sum_distances = 0;
        buf_demand = 0;
        flag = 0;
        counter += 1;
    }
    vehicles = counter;


     cout << endl;
    int distance = 0, sum_greedy = 0;
    int n = 0, m = 0;
    for (m = 0; m < greedy_solution.size(); m++)
    {
        for (int n = 0; n < greedy_solution.at(m).size()-1; n++)
        {
            distance += cities[greedy_solution.at(m).at(n)][greedy_solution.at(m).at(n+1)];
            cout << greedy_solution[m][n] << ", ";
        }
        cout << greedy_solution[m][n];
        sum_greedy += total_distances.at(m);
        cout << "; " << endl;
        //cout << "VEICULO " << m << ", CALCULO DA DISTANCIA: " << distance << ", CALCULO DA FINAL_ROUTE: " << final_route.at(m) << endl;
    }
    //sleep(5);

    return total_distances;

}


#endif //PJ_FINAL_GREEDYFUNCTION_H
