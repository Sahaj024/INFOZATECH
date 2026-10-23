#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter number of subjects: ";
    cin >> n;

    double total = 0, marks;
    
    for(int i = 1; i <= n; i++) {
        cout << "Enter marks for subject " << i << " (out of 100): ";
        cin >> marks;
        total += marks; // Calculate total marks[span_1](start_span)[span_1](end_span)
    }

    double avg = total / n; // Calculate average percentage[span_2](start_span)[span_2](end_span)
    char grade;

    // Assign grade based on average percentage[span_3](start_span)[span_3](end_span)
    if (avg >= 90) grade = 'A';
    else if (avg >= 80) grade = 'B';
    else if (avg >= 70) grade = 'C';
    else if (avg >= 60) grade = 'D';
    else grade = 'F';

    // Display final results[span_4](start_span)[span_4](end_span)
    cout << "\n--- RESULT ---\n";
    cout << "Total Marks: " << total << " / " << (n * 100) << "\n";
    cout << "Average Percentage: " << avg << "%\n";
    cout << "Final Grade: " << grade << "\n";

    return 0;
}