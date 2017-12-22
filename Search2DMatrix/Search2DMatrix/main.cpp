//
//  main.cpp
//  Search2DMatrix
//
//  Created by Kero on 2017/12/21.
//  Copyright © 2017年 Kei. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    if (matrix.size() == 0 || matrix[0].size() == 0 ){
        return false;
    }
    
    
    int low = 0 , high = matrix.size()-1, curr = high / 2;
    
    cout << "HIGH: " << high << endl;
    
    if ( matrix[high][0] == target ){
        cout << "HIGH[0] = target" << endl;
        return true;
    }
    
    if ( matrix[low][0] == target || matrix.size() == 1) {
        cout << "SIZE = 1" << endl;
        
    } else if ( matrix [high][0] <= target){
        cout << "[high][0] >= target" << endl;
        low = high;
    } else {
        cout << "START LOW: " << low << ",HIGH: " << high << endl;
        while(high - low > 1){
            
            if (matrix[curr][0] < target) {
                low = curr;
                curr = (low + high) / 2;
                
                cout << "LOW: " << low << ",HIGH: " << high << endl;
                
            } else if ( matrix[curr][0] > target ){
                high = curr;
                curr = (low + high) / 2;
                
                cout << "LOW: " << low << ",HIGH: " << high << endl;
            } else if ( matrix[curr][0] == target ){
                low = curr;
                break;
            }
            
        }
    }
    
    
    
    cout << "ROW #" << low << endl;
    // cout << "MAT SIZE: " << matrix[0].size() << endl;
    
    if (matrix[low][0] == target || matrix[low][matrix[0].size()-1] == target){
        return true;
    }
    
    int rlow = 0, rhigh = matrix[0].size()-1;
    curr = (rlow + rhigh)/2;
    
    while (rlow < rhigh){
        
        cout << "START LOW: " << rlow << ",HIGH: " << rhigh << ",CURR: " << curr << endl;
        cout << matrix[low][rlow] << "  :  " << matrix[low][rhigh] << " CURR: " << matrix[low][curr] << endl;
        
        if (matrix[low][rlow] == target || matrix[low][rhigh] == target){
            return true;
        }
        
        if (matrix[low][curr] < target) {
            cout << "A" << endl;
            rlow = curr + 1;
            curr = (rlow + rhigh)/2;
            
        } else if ( matrix[low][curr] > target ){
            cout << "B" << endl;
            rhigh = curr - 1;
            curr = (rlow + rhigh)/2;
            
        } else if ( matrix[low][curr] == target){
            cout << "C" << endl;
            return true;
        }
    }
    
    return false;
}
