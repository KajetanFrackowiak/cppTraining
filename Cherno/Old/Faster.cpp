#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <mutex>
#include <chrono>

// Define a Mutex for synchronization
std::mutex mtx;

class LogisticRegression {
private:
    std::vector<double> weights;
    double learningRate;

public:
    LogisticRegression(int numFeatures, double learningRate) {
        weights.resize(numFeatures + 1, 0.0); // +1 for bias term
        this->learningRate = learningRate;
    }

    // Sigmoid function
    double sigmoid(double z) {
        return 1.0 / (1.0 + exp(-z));
    }

    // Prediction function
    double predict(const std::vector<double>& features) {
        double z = weights[0]; // bias term
        for (int i = 0; i < features.size(); ++i) {
            z += weights[i + 1] * features[i]; // weights[i+1] corresponds to feature[i]
        }
        return sigmoid(z);
    }

    // Training function with mutex for synchronization
    void trainWithMutex(const std::vector<std::vector<double>>& X, const std::vector<int>& y, int numIterations) {
        for (int iter = 0; iter < numIterations; ++iter) {
            for (int i = 0; i < X.size(); ++i) {
                // Compute gradient
                double error = predict(X[i]) - y[i];
                std::vector<double> gradient(X[i].size() + 1);
                gradient[0] = error; // Gradient of bias term
                for (int j = 0; j < X[i].size(); ++j) {
                    gradient[j + 1] = error * X[i][j]; // Gradient of weights
                }
                
                // Acquire lock before updating weights
                mtx.lock();
                // Update weights
                for (int j = 0; j < weights.size(); ++j) {
                    weights[j] -= learningRate * gradient[j];
                }
                // Release lock
                mtx.unlock();
            }
        }
    }
};

int main() {
    // Example usage
    std::vector<std::vector<double>> X = {{1.0, 2.0}, {2.0, 3.0}, {3.0, 4.0}};
    std::vector<int> y = {0, 1, 0}; // binary labels
    int numIterations = 1000;
    int numFeatures = X[0].size();
    double learningRate = 0.01;
    
    auto start = std::chrono::steady_clock::now();
    LogisticRegression model(numFeatures, learningRate);
    model.trainWithMutex(X, y, numIterations);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    
    // Test predictions
    for (int i = 0; i < X.size(); ++i) {
        std::cout << "Prediction for sample " << i << ": " << model.predict(X[i]) << std::endl;
    }
    std::cout << "Train has taken: " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    return 0;
}
