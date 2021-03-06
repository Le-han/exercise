/*


При разработке новой игры планируется создать несколько уровней. Каждый уровень должен иметь сложность, которая будет характеризоваться целым положительным числом. Сложности уровни должны возрастать.

Кроме того, чтобы игрок не терял мотивацию, возрастание сложности между соседними уровнями должно быть разнообразным. А именно, если сложность i-го уровня — целое число ai, то все значения ai + 1 - ai должны быть различны.

Для разработки уровня сложности b требуется b долларов. Бюджет проекта составляет n долларов. Какое максимальное количество уровней разработчики могут создать, чтобы уложиться в бюджет проекта и выполнить требования к сложности уровней?
Формат ввода

Входные данные содержат один или несколько тестов. Первая строка входных данных содержит число t — количество тестов (1 ≤ t ≤ 1000).

Каждая из следующих строк содержит одно целое число n (1 ≤ n ≤ 1016).
Формат вывода

Для каждого теста выведите одно число — максимальное количество уровней, которое можно разработать.
Пример
Ввод 	Вывод

1
10

3

*/


#include <bits/stdc++.h>

using namespace std;

struct Node {
    long long n;
    long long sum;
    long long dist;
    long long elem;
};

vector<Node>v;

Node DP(long long n) {
    for (auto item : v) {
        if (item.n == n) {
            return item;
        }
    }
    long long curr_sum = 0, cnt = 0, curr_dist = 0, curr_elem = 1,
                  prev_sum = 0, prev_elem = 1;

        while (curr_sum <= n) {
            ++cnt;
            prev_elem = curr_elem;
            prev_sum = curr_sum;
            curr_sum += curr_elem;
            curr_elem += cnt;
        }
        /*cout << cnt - 1 << ' ' << prev_elem - (cnt - 1) << ' '
             << prev_sum  << endl;*/
        v.push_back({n, prev_sum, cnt - 1,  prev_elem - (cnt - 1)});
        return {n, prev_sum, cnt - 1,  prev_elem - (cnt - 1)};
}


int main() {
    int t;
    long long n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        Node temp = DP(n);
        cout << temp.dist << endl;
    }
    return 0;
}
