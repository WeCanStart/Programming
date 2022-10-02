#include <iostream>
#include <vector>
 
void solve(){
    int n, x;
    std::cin >> n >> x;
    std::vector<bool> map(202, false);   //вспомогательный вектор, в который
    for (int i = 0; i < n; i++){         //мы записываем наличие/отсутствие
        int num;                         //входного элемента
        std::cin >> num;
        map[num] = true;
    }
    
    int i = 0;
    while (x >= 0){                      //проходимся по местам, начиная с 1
        i++;                             //и игнорируем x раз,
        if (!map[i]){                    //а x+1 - й раз ещё доходим до
            x--;                         //ближайшего готового элемента снизу
        }
    }
    std::cout << i - 1 << std::endl;
} 
int main(){
    int t;
    std::cin >> t;
    for (int j = 0; j < t; j++){
        solve();                         //решает каждый случай отдельно
    }
    return 0;
}