#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <vector>
#include <sstream>
#include <array>


#include "trade.h"

using namespace std;
trade::trade(double coin[3][2600],int p[15])
{
	day = 30;
	gain = 1;
	current_money = 1;
	current_bitcoin = 0;
	bitcoin_price = coin;
	parameter = p;

	// initialze the four variables based on past k day price
	// initialze the function pointer in buy and sell
}

bool trade::buy1()
{
	if ((bitcoin_price[2][day] - past_k_days_average_volume) / past_k_days_average_volume > parameter[2])
		return true;
	else
		return false;
}

bool trade::buy2()
{
	double today_price = (bitcoin_price[0][day] + bitcoin_price[1][day]) / 2;
	if ((today_price - past_k_days_average_price) / past_k_days_average_price > parameter[4])
		return true;
	else
		return false;
}

bool trade::buy3()
{
	if (bitcoin_price[0][day] > past_k_days_highest)
		return true;
	else
		return false;
}

bool trade::buy4()
{
	if ((bitcoin_price[0][day] - past_k_days_lowest) / past_k_days_lowest > parameter[6])
		return true;
	else
		return false;
}

bool trade::sell5()
{
	if ((past_k_days_average_volume - bitcoin_price[2][day]) / past_k_days_average_volume > parameter[9])
		return true;
	else
		return false;
}

bool trade::sell6()
{
	double today_price = (bitcoin_price[0][day] + bitcoin_price[1][day]) / 2;
	if ((past_k_days_average_price - today_price) / past_k_days_average_price > parameter[11])
		return true;
	else
		return false;
}

bool trade::sell7()
{
	if (bitcoin_price[1][day] < past_k_days_lowest)
		return true;
	else
		return false;
}

bool trade::sell8()
{
	if ((past_k_days_highest - bitcoin_price[1][day]) / past_k_days_highest > parameter[14])
		return true;
	else
		return false;
}

void trade::next_day()
{
	

	// update four past days variables

	if (current_money > 0 && buy()) // cash
	{
		current_bitcoin += current_money / ((bitcoin_price[0][day] + bitcoin_price[1][day]) / 2);
		current_money = 0;
	}
	else if (current_bitcoin > 0 && sell()) // bitcoin
	{
		current_money += current_bitcoin * ((bitcoin_price[0][day] + bitcoin_price[1][day]) / 2);
		current_bitcoin = 0;
	}
	day++;
}