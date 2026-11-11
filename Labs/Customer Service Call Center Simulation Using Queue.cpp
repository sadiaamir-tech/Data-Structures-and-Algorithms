#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Call {
public:
    int callID;
    int arrivalTime;
    int processingTime;
    string customerName;

    Call(int id, int arrival, int processing, string name) {
        callID = id;
        arrivalTime = arrival;
        processingTime = processing;
        customerName = name;
    }
};

class CallCenter {
private:
    queue<Call> calls;
    int CSR;
    vector<bool> available;
    vector<int> completionTime;

public:
    CallCenter(int n) {
        CSR = n;

        for (int i = 0; i < CSR; i++) {
            available.push_back(true);
            completionTime.push_back(0);
        }
    }

    void addCall(Call c) {
        calls.push(c);
        cout << "Call added: " << c.customerName << endl;
    }

    void processCalls(int totalTime) {

        for (int time = 0; time <= totalTime; time++) {

            // Check completed calls
            for (int i = 0; i < CSR; i++) {
                if (!available[i] && completionTime[i] <= time) {
                    available[i] = true;
                    cout << "CSR " << i + 1
                         << " completed a call at time "
                         << time << endl;
                }
            }

            // Assign calls to available CSRs
            for (int i = 0; i < CSR; i++) {

                if (available[i] && !calls.empty()) {

                    if (calls.front().arrivalTime <= time) {

                        Call c = calls.front();
                        calls.pop();

                        available[i] = false;

                        completionTime[i] =
                            time + c.processingTime;

                        cout << "CSR " << i + 1
                             << " is handling Call "
                             << c.callID
                             << " (" << c.customerName << ")"
                             << " at time " << time << endl;
                    }
                }
            }
        }
    }
};

int main() {

    CallCenter center(2);

    center.addCall(Call(1, 0, 3, "Ali"));
    center.addCall(Call(2, 1, 2, "Ahmed"));
    center.addCall(Call(3, 2, 3, "Sara"));
    center.addCall(Call(4, 3, 2, "Ayesha"));

    cout << "\n--- Call Processing ---\n";

    center.processCalls(10);

    return 0;
}
