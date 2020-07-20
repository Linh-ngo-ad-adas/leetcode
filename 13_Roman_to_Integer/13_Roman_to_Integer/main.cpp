//
//  main.cpp
//  Roman_to_Integer
//
//  Created by Linh NGO on 21/06/2020.
//  Copyright © 2020 Linh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
       /*Symbol       Value
        I             1
        V             5
        X             10
        L             50
        C             100
        D             500
        M             1000
        I can be placed before V (5) and X (10) to make 4 and 9.
        X can be placed before L (50) and C (100) to make 40 and 90.
        C can be placed before D (500) and M (1000) to make 400 and 900.*/
        
               // cout << result << endl;
        
        /*for (int i = 0; i < result.size(); i++)
        {
            cout << "index " << i << " = " << result[i] << endl;
        }*/
    // int romanToInt(string s)
        
        int result(0);
    string s("CCXL");
    
    for(int i = s.size()-1; i >= 0; i--)
    {
        if(s[i] == 'I')
        {
            if(s[i+1] == 'V' || s[i+1] == 'X')result -= 1;
            else result += 1;
        }
            
        else if(s[i] == 'V')result += 5;
        else if(s[i] == 'X')
            {
                if(s[i+1] == 'L' || s[i+1] == 'C')result -= 10;
                else result += 10;
            }
        else if(s[i] == 'L')result += 50;
        else if(s[i] == 'C')
        {
            if(s[i+1] == 'D' || s[i+1] == 'M')result -= 100;
            else result += 100;
        }
        else if(s[i] == 'D')result += 500;
        else if(s[i] == 'M')result += 1000;
    
       //else if (<#condition#>)
        
        cout << "index " << i << " = " << s[i] << endl;
    }
        
    cout << s << " vaut " << result << endl;
    
    return 0;
}
