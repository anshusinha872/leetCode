#include<bits/stdc++.h>
using namespace std;
void floodFill_util(vector<vector<int>> &image, int sr, int sc, int color, int prev_color)
{
    int r = image.size();
    int c = image[0].size();
    queue<pair<int, int>> q;
    image[sr][sc] = color;
    q.push({sr, sc});
    while (!q.empty())
    {
        auto itr = q.front();
        q.pop();
        int x = itr.first;
        int y = itr.second;
        if (x - 1 >= 0 && image[x - 1][y] == prev_color)
        {
            image[x - 1][y] = color;
            q.push({x - 1, y});
        }
        if (x + 1 < r && image[x + 1][y] == prev_color)
        {
            image[x + 1][y] = color;
            q.push({x + 1, y});
        }
        if (y - 1 >= 0 && image[x][y - 1] == prev_color)
        {
            image[x][y - 1] = color;
            q.push({x, y - 1});
        }
        if (y + 1 < c && image[x][y + 1] == prev_color)
        {
            image[x][y + 1] = color;
            q.push({x, y + 1});
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color){
    int prev_color = 0;
    if (image[sr][sc] != color)
    {
        prev_color = image[sr][sc];
        floodFill_util(image, sr, sc, color, prev_color);
    }

    return image;
}
int main(){
    int m,n, sr, sc, color;
    cin >> m >> n >> sr >> sc >> color;
    vector<vector<int>> image(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cin >> image[i][j];
        }
    }
    image=floodFill(image, sr, sc, color);
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
        return 0;
}