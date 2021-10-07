class trade {
public:
	// the parameter array
	int parameter[15]; 

	// four buying strategy
	// 1. If the past k1 days' volume raise k2 percent, buy
	// 2. If the past k3 days' average price raise k4 percent, buy
	// 3. If the price passes over the highest price since k5 days, buy
	// 4. If the price raises k6 percent from its lowest point in past k7 days, buy

	// four selling strategy
	// 5. If the past k8 days' volume drop k9 percent, sell
	// 6. If the past k10 days' average price drop k11 percent, sell
	// 7. If the price passes over the lowest price since k12 days, sell
	// 8. If the price drops k13 percent from its highest point in past k14 days, sell

	// below are the eight strategy we are going to use
	bool buy1();
	bool buy2();
	bool buy3();
	bool buy4();

	bool sell5();
	bool sell6();
	bool sell7();
	bool sell8();

	bool buy();
	bool sell();

	// some helper variables and functions

	double past_k_days_average_volume;
	double past_k_days_average_price;
	double past_k_days_highest;
	double past_k_days_lowest;

	void next_day(); // update helper variables

	int day;
	double gain;
	double current_money;
	double current_bitcoin;
	double bitcoin_price[3][2600];

};