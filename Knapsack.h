#include <vector>
#include <cmath>

class knapsack {
	int capacity;
	double *dp;

	std::vector<double> values;
	std::vector<int> weights;

	public:
		void insert(double value, int weight) { 
			values.push_back(value);
			weights.push_back(weight);

		}

		double unbounded() {
			dp = new double[capacity + 1];
			
			for (int i = 0; i <= capacity + 1; i++)  
				for (int j = 0; j < values.size(); j++) 
					if (weights[j] <= i) 
						dp[i] = std::max(dp[i], dp[i - weights[j]] + values[j]);
				
			double mv = dp[capacity];
			delete[] dp;
			return mv;
		}

		double o1() {
			return o1_help(capacity, weights, values, values.size()); 
		}


		double o1_help(int c, std::vector<int> ws, std::vector<double> vs, int n) {
			if (c == 0 || n == 0) return 0;
			if (ws[n - 1] > c) return o1_help(c, ws, vs, n - 1);

			return std::max(vs[n-1] + o1_help(c - ws[n - 1], ws, vs, n - 1), o1_help(c, ws, vs, n - 1));
		}

		

			
	knapsack(int capacity) { this->capacity = capacity; }

};
