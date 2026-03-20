# Perceptron Implementation (Python + C++)

This project demonstrates a single-layer perceptron built from scratch in both Python and C++ to explore foundational machine learning concepts.

## Overview
The perceptron is trained on logical datasets (e.g., OR gate) using weighted inputs, a bias term, and a step activation function.

## Features
- Binary classification using a step activation function  
- Iterative training across multiple epochs  
- Weight updates based on error correction  
- Bias term to improve convergence  
- Implemented in both Python and C++ for comparison  

## Output
The model converged after multiple epochs, achieving 100% accuracy on OR gate inputs.

## Technologies Used
- Python  
- C++  

## What I Learned
- How perceptrons achieve convergence  
- The impact of learning rate and bias  
- Differences in implementation between Python and C++  
## Sample Output
Training output showing weight updates, error reduction, and convergence across epochs in both Python and C++ implementations.

![Training Output](perceptron_output.jpg)
## How to Run

### Python
```bash
python perceptron.py
```

### C++
```bash
g++ perceptron.cpp -o perceptron
./perceptron
```
