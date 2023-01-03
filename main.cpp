#include <iostream>
#include <ctime>

int main() {
	double diff_sec, diff_tmp = 0;
	int min, sec, rem_sec, rem_min;

	std::cout << "Input timer limit (min sec):" << std::endl;
	std::cin >> min >> sec;

	std::time_t timeNow = std::time(nullptr);
	std::tm end_tm = *std::localtime(&timeNow);
	end_tm.tm_min += min;
	end_tm.tm_sec += sec;
	std::time_t end_t = std::mktime(&end_tm);
	while (timeNow != end_t) {
		diff_sec = std::difftime(end_t, timeNow);
		if (diff_tmp == diff_sec) {
			rem_min = (int) diff_sec / 60;
			rem_sec = (int) diff_sec % 60;
			if (rem_min > 0)
				std::cout << rem_min << " min " << rem_sec << " sec" << std::endl;
			else
				std::cout << rem_sec << " sec" << std::endl;

		}
		diff_tmp = diff_sec - 1;
		timeNow = std::time(nullptr);
	}
	std::cout << "*************" << std::endl;
	std::cout << "DIN, DIN, DIN" << std::endl;
	std::cout << "*************" << std::endl;
	return 0;
}
