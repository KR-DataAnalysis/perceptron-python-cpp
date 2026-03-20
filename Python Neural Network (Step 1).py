# 1. Import needed modules
import random
import time


# 2. Define the activation function
def activation(value):
    if value > 0:
        return 1
    else:
        return 0


# 3. Start the main program
def main():
    random.seed(int(time.time()))

    # 4. Set learning values
    learningRate = 0.1
    biasInput = 1

    # 5. Create random starting weights
    w1 = random.uniform(-1.0, 1.0)
    w2 = random.uniform(-1.0, 1.0)
    wb = random.uniform(-1.0, 1.0)

    # 6. Store training data for OR
    input1 = [0, 0, 1, 1]
    input2 = [0, 1, 0, 1]
    target = [0, 1, 1, 1]

    # 7. Print initial weights
    print("Initial weights:")
    print("w1 =", w1)
    print("w2 =", w2)
    print("wb =", wb)
    print()

    # 8. Run the training loop
    for epoch in range(20):
        print("Epoch", epoch + 1)

        # 9. Process each training example
        for i in range(4):
            # 10. Calculate weighted sum
            weightedSum = (input1[i] * w1) + (input2[i] * w2) + (biasInput * wb)

            # 11. Make prediction
            output = activation(weightedSum)

            # 12. Calculate error
            error = target[i] - output

            # 13. Update weights and bias
            w1 = w1 + (learningRate * error * input1[i])
            w2 = w2 + (learningRate * error * input2[i])
            wb = wb + (learningRate * error * biasInput)

            # 14. Print training results for this example
            print("Input: (" + str(input1[i]) + ", " + str(input2[i]) + ")   "
                  + "Target: " + str(target[i]) + "   "
                  + "Output: " + str(output) + "   "
                  + "Error: " + str(error))

        # 15. Print updated weights after each epoch
        print("Updated weights: w1 =", w1, ", w2 =", w2, ", wb =", wb)
        print("-----------------------------")

    # 16. Test the perceptron after training
    print("\nFinal testing:")
    for i in range(4):
        weightedSum = (input1[i] * w1) + (input2[i] * w2) + (biasInput * wb)
        output = activation(weightedSum)

        print(str(input1[i]) + " OR " + str(input2[i]) + " = " + str(output)
              + " (expected " + str(target[i]) + ")")


# 17. Run the program
main()
