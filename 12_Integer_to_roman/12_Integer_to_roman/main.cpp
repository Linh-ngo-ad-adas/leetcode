//
//  main.cpp
//  Integer_to_roman
//
//  Created by Linh NGO on 21/06/2020.
//  Copyright © 2020 Linh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <deque>


using namespace std;

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


int main(int argc, const char * argv[]) {
    /*I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900.*/


    string symbolList[4][4];
    symbolList[0][0] = "I";
    symbolList[0][1] = "IV";
    symbolList[0][2] = "V";
    symbolList[0][3] = "IX";
    symbolList[1][0] = "X";
    symbolList[1][1] = "XL";
    symbolList[1][2] = "L"; // 50
    symbolList[1][3] = "XC"; // 90
    symbolList[2][0] = "C"; // 100
    symbolList[2][1] = "CD"; // 400
    symbolList[2][2] = "D"; // 500
    symbolList[2][3] = "CM"; // 900
    symbolList[3][0] = "M"; // 1000

    //string result;
    deque<string> result;
    
    int nombre = 44;
    int temp = nombre;
    int modulo(0);
        int modulo10(0);
    int j = 0;
    while(temp != 0)
    {
        
        if(j != 3)
        {
            modulo = temp % 5; //4
            modulo10 = temp % 10;
            
            cout << "à l'indice " << j << " modulo vaut " << modulo << endl;
            cout << "à l'indice " << j << " temp vaut " << temp << endl;
                    
            
            if (modulo == 4)
             {
                 if(modulo10 > 5)result.push_front(symbolList[j][3]);
                 else result.push_front(symbolList[j][1]);
             }
             else if (modulo10 != 0)
             {
                 for (int i = 0; i < modulo; i++)
                 {
                     result.push_front(symbolList[j][0]);
                 }
                 if(modulo10 >= 5)result.push_front(symbolList[j][2]);

             }
             temp /= 10;
              }
              else
              {
                  for (int i = 0; i < temp; i++)
                   {
                       result.push_front(symbolList[j][0]);
                   }
                  break;
              }
              
              j++;
          }
          
    string romain;
    
    for (int i = 0; i<result.size(); i++)
    {
        romain += result[i];
    }
          cout << nombre << " vaut " << romain << endl;


    return 0;
}
