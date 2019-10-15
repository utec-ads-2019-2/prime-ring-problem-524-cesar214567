#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> primos={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int N, flag = 0, ans[20] = {1};

bool isPrime(int algo){
    for (int i=0;i<primos.size();i++){
        if (algo==primos[i]){
            return true;
        }
    }
    return false;
}

void backtracking(int L, bool visit[])
{
    if (L == N) {
        if (!isPrime(ans[N-1] + 1)) 
            return;
        cout<<"1";
        for (int i = 1; i < N; ++i)
            cout<<ans[i];
        cout<<endl;
        return;
    }
    for (int i = 2; i <= N; ++i) {
        if (visit[i]) continue;
        if (isPrime(i + ans[L - 1])) {
            visit[i] = 1;
            ans[L] = i;

            backtracking(L + 1, visit);

            visit[i] = 0;
        }
    }
}
int main()
{
    while (scanf("%d", &N) != EOF) {
        if (flag){
            cout<<endl;
        }
        ++flag;
        cout<<"caso "<<flag<<endl;
        bool visit[20] = {0};
        backtracking(1, visit);
    }
}