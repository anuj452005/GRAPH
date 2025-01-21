#include <bits/stdc++.h>
using namespace std;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n"
#define ll int long long
void dfs(int i, int j, int initalColor, int finalColor, vector<vector<int>> &image)
{

    int n = image.size();
    int m = image[0].size();

    if (i < 0 || j < 0)
        return;
    if (i >= n || j >= m)
        return;
    if (image[i][j] != initalColor)
        return;
    image[i][j] = finalColor;

    dfs(i - 1, j, initalColor, finalColor, image);
    dfs(i, j - 1, initalColor, finalColor, image);
    dfs(i + 1, j, initalColor, finalColor, image);
    dfs(i, j + 1, initalColor, finalColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int finalColor)
{
    int initalColor = image[sr][sc];
    if (initalColor != finalColor)
        dfs(sr, sc, initalColor, finalColor, image);
    return image;
}
void solve()
{
}

signed main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}