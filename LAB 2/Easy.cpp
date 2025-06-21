/*Multiply Two Matrices*/

#include <iostream>
#include <vector>

using namespace std;

void multiMatrices(vector<vector<int>>& m1, vector<vector<int>>& m2, vector<vector<int>>& result){
    int row1 = m1.size();
    int col1 = m1[0].size();
    int row2 = m2.size();
    int col2 = m2[0].size();

    if (col1 != row2){
        cout<<"Matrices Cannot be Computed"<<endl;
        exit(EXIT_FAILURE);
    }

    result.resize(row1, vector<int>(col2, 0));

    for (int i=0; i<row1; i++){
        for (int j=0; j<col2; j++){
            for (int k=0; k<col1; k++){
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main(){
    vector<vector<int>> m1 = {{1,1}, {2,2}};
    vector<vector<int>> m2 = {{1,1}, {2,2}};
    vector<vector<int>> res;

    multiMatrices(m1, m2, res);

    cout<<"Product of two matrices:\n";
    for (const auto& row : res){
        for (int val : row){
            cout<<val<<"\t";
        }
        cout<<endl;
    }
    return 0;
}