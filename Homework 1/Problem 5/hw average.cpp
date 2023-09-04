#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> 

using namespace std;

int main(){
    cout << fixed << setprecision(2);
    unsigned int gradeLength, grade;

    cout << "How many grades would you like to enter?\n";
    cin >> gradeLength;
    unsigned int gradeList[gradeLength];

    for (int i = 0; i < gradeLength; i++){
        cout << "Enter a grade.\n";
        cin >> grade;
        cout << "Grade entered: " << grade << endl;
        gradeList[i] = grade;
    }

    sort(gradeList, gradeList + sizeof(gradeList) / sizeof(gradeList[0]));
    // taken from: https://www.geeksforgeeks.org/sort-c-stl/

    int iter = 1; 
    int sum;
    // the list is now sorted, so the drop grade will be at position 0 in the array, meaning we can skip it
    while (iter < gradeLength){
        sum += gradeList[iter];
        iter++;
    }
    float average = float(sum) / (gradeLength - 1);

    cout << "Dropped grade: " << gradeList[0] << endl;
    cout << "Final average: " << average << endl;
    
    return 0;
}