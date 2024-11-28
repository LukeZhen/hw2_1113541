#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

class TaskPriorityQueue {
private:
    priority_queue<pair<int, string>> maxHeap; // Max heap to store tasks with priority

public:
    void addTask(const string& taskName, int priority) {
        maxHeap.push({priority, taskName});
    }

    string getHighestPriorityTask() {
        if (maxHeap.empty()) {
            return "No tasks available";
        } else {
            string taskName = maxHeap.top().second;
            maxHeap.pop();
            return taskName;
        }
    }

    vector<pair<int, string>> getRemainingTasks() {
        vector<pair<int, string>> remainingTasks;
        while (!maxHeap.empty()) {
            remainingTasks.push_back(maxHeap.top());
            maxHeap.pop();
        }
        // Reverse to maintain descending order
        reverse(remainingTasks.begin(), remainingTasks.end());
        return remainingTasks;
    }
};

int main() {
    TaskPriorityQueue taskQueue;
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline after the integer

    for (int i = 0; i < n; ++i) {
        string command;
        getline(cin, command);

        if (command.substr(0, 3) == "ADD") {
            size_t space1 = command.find(' ', 4);
            string taskName = command.substr(4, space1 - 4);
            int priority = stoi(command.substr(space1 + 1));
            taskQueue.addTask(taskName, priority);
        } else if (command == "GET") {
            cout << taskQueue.getHighestPriorityTask() << endl;
        }
    }

    // Get and print remaining tasks
    vector<pair<int, string>> remainingTasks = taskQueue.getRemainingTasks();
    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remainingTasks.size(); ++i) {
        cout << "('" << remainingTasks[i].second << "', " << remainingTasks[i].first << ")";
        if (i != remainingTasks.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
