/*
841. Keys and Rooms question
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Depth-First Search (DFS) to explore rooms
    void dfs(int s, vector<vector<int>> &rooms, vector<bool> &vis)
    {
        vis[s] = true; // Mark the current room as visited
        for (int i = 0; i < rooms[s].size(); i++)
        {
            if (!vis[rooms[s][i]])
            {
                dfs(rooms[s][i], rooms, vis); // Recursively visit unvisited rooms
            }
        }
    }

    // Function to check if all rooms can be visited
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> vis(n, false); // Initialize a boolean array to track visited rooms
        dfs(0, rooms, vis);         // Start DFS from room 0

        // Check if all rooms have been visited
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                return false; // If there is an unvisited room, return false
            }
        }

        return true; // All rooms have been visited
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}}; // Example input, change this to your desired input

    bool result = solution.canVisitAllRooms(rooms);

    cout << "Can visit all rooms: " << (result ? "Yes" : "No") << endl;

    return 0;
}

/*
Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation:
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
Example 2:

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.


Constraints:

n == rooms.length
2 <= n <= 1000
0 <= rooms[i].length <= 1000
1 <= sum(rooms[i].length) <= 3000
0 <= rooms[i][j] < n
All the values of rooms[i] are unique.*/