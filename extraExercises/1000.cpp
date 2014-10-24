#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

struct Node {
    Node(int x, int y, int cost) {
        this->x = x;
        this->y = y;
        this->cost = cost;
    }
    int x, y, cost;
};

bool compare(const Node& a, const Node& b) {
    return a.cost < b.cost;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<Node> container;
        int temp;
        bool footPrint[100];
        memset(footPrint, true, sizeof(footPrint));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> temp;
                if (j > i) {
                    container.push_back(Node(i, j, temp));
                }
            }
        }
        std::sort(container.begin(), container.end(), compare);
        std::vector<Node>::iterator it = container.begin();
        long long ans = 0;
        footPrint[it->x] = false;
        footPrint[it->y] = false;
        ans += (long long)it->cost;
        for (int i = 0; i < n - 2; i++) {
            it = container.begin();
            while (it != container.end()) {
                if ((footPrint[it->x] && (!footPrint[it->y])) || ((!footPrint[it->x]) && footPrint[it->y])) {
                    footPrint[it->x] = false;
                    footPrint[it->y] = false;
                    ans += (long long)it->cost;
                    break;
                }
                it++;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}

