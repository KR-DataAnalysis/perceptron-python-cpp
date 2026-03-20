#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Simple step activation function
int activation(double value)
{
    if (value > 0)
        return 1;
    else
        return 0;
}

int main()
{
    srand(time(0));

    // Learning rate
    double learningRate = 0.1;

    // Bias input value
    int biasInput = 1;

    // Random starting weights
    double w1 = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    double w2 = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    double wb = ((double)rand() / RAND_MAX) * 2.0 - 1.0;

    // Training data for OR
    int input1[4] = {0, 0, 1, 1};
    int input2[4] = {0, 1, 0, 1};
    int target[4] = {0, 1, 1, 1};

    cout << "Initial weights:\n";
    cout << "w1 = " << w1 << endl;
    cout << "w2 = " << w2 << endl;
    cout << "wb = " << wb << endl << endl;

    // Training loop
    for (int epoch = 0; epoch < 20; epoch++)
    {
        cout << "Epoch " << epoch + 1 << endl;

        for (int i = 0; i < 4; i++)
        {
            // Weighted sum
            double sum = (input1[i] * w1) + (input2[i] * w2) + (biasInput * wb);

            // Prediction after activation
            int output = activation(sum);

            // Error
            int error = target[i] - output;

            // Update rule
            w1 = w1 + (learningRate * error * input1[i]);
            w2 = w2 + (learningRate * error * input2[i]);
            wb = wb + (learningRate * error * biasInput);

            cout << "Input: (" << input1[i] << ", " << input2[i] << ")   ";
            cout << "Target: " << target[i] << "   ";
            cout << "Output: " << output << "   ";
            cout << "Error: " << error << endl;
        }

        cout << "Updated weights: ";
        cout << "w1 = " << w1 << ", w2 = " << w2 << ", wb = " << wb << endl;
        cout << "-----------------------------" << endl;
    }

    // Testing after training
    cout << "\nFinal testing:\n";
    for (int i = 0; i < 4; i++)
    {
        double sum = (input1[i] * w1) + (input2[i] * w2) + (biasInput * wb);
        int output = activation(sum);

        cout << input1[i] << " OR " << input2[i] << " = " << output
             << " (expected " << target[i] << ")" << endl;
    }

    return 0;
}
