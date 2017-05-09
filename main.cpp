//
//  main.cpp
//  SummerProject1
//
//  Created by Shaan Diwanji on 5/3/17.
//  Copyright © 2017 Shaan Diwanji. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <getopt.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <unordered_map>

using namespace std;


int main(int argc, const char * argv[]) {
    
    cout << "How many simulations of the '4-ball coloration' problem would you like to run? (sdiwanji)" << endl;
    
    
    size_t simulations = 0;
    cin >> simulations;
    
    vector<int>container(4,0);
    map<int, int>instances;
    
    for (size_t i = 0; i < simulations; ++i){
        
        for (size_t a = 0; a <= 3; ++a){
            container[a] = (int)a;
        }
        
        
        bool all_same = false;
        int iters = 0;
        
        while (!all_same){
            ++iters;
            
            
            int first_pickup = rand() % 4;
            int second_pickup = rand() % 4;
            
            while (first_pickup == second_pickup){
                second_pickup = rand() % 4;
            }
            
            int first_val;
            first_val = container[first_pickup];
            //second_val = container[second_pickup];
            
            container[second_pickup] = first_val;
            
            
            
            // verification if we have gotten an answer or not
            int f_val = container[0];
            for (int j = 1; j <= 3; ++j){
                if (container[j] != f_val){
                    break;
                } else if (j == 3){
                    if (container[j] == f_val){
                        all_same = true;
                    }
                }
            }
            //verification if we have gotten an answer or not
        }
        
        instances[iters] += 1;
        
    }
    
    
    cout << "In " << simulations << " simulations, we arrived at an answer of [Key], [Value] times" << endl;
    cout << "[Key]\t[Value]" << endl;
    
    
    int total = 0;
    for (map<int,int>::iterator it= instances.begin(); it != instances.end(); ++it){
        cout << it->first << "\t" << it->second << endl;
        total += it->first * it->second;
    }
    
    
    cout << endl << endl;
    double answer = (double)total / (int)simulations;
    cout << "The average number of steps: " << answer << endl;
    
    return 0;
}
