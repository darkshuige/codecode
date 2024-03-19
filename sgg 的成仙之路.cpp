#include <iostream>
#include <vector>
#include <limits>

std::vector<int> dijkstra(const std::vector<std::vector<int>>& graph, int start) {
    int n = graph.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::vector<bool> visited(n, false);
    dist[start] = 0;

    for (int _ = 0; _ < n; ++_) {
        int u = -1;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] != std::numeric_limits<int>::max()) {
                dist[v] = std::min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    // 初始化图，只关心与第 1 号物品相关的部分
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, std::numeric_limits<int>::max()));

    // 读取合成公式的输入
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        std::cin >> x >> y >> z;
        graph[x - 1][y - 1] = z;
        graph[y - 1][x - 1] = z;
    }

    // 计算每个节点到第 1 号物品的最短距离
    std::vector<int> dist_to_item1 = dijkstra(graph, 0);

    // 初始化答案为最大可能值
    int ans = std::numeric_limits<int>::max();

    // 尝试不同的初始金钱值
    for (int money = 1; money <= 100; ++money) {
        // 检查是否可以通过合成获得第 1 号物品
        bool can_obtain = true;
        for (int i = 0; i < n; ++i) {
            if (dist_to_item1[i] > money) {
                can_obtain = false;
                break;
            }
        }
        if (can_obtain) {
            ans = std::min(ans, money);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
