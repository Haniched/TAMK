#include <iostream>

const int SECONDS_PER_MINUTE = 60;
const int MINUTES_PER_HOUR = 60;

int to_seconds(int minutes, int seconds) {
	return minutes * SECONDS_PER_MINUTE + seconds;
}

void from_seconds(int duration, int& hours, int& minutes, int& seconds) {
	minutes = duration / SECONDS_PER_MINUTE;
	seconds = duration % SECONDS_PER_MINUTE;
	hours = minutes / MINUTES_PER_HOUR;
	minutes = minutes % MINUTES_PER_HOUR;
}

int main() {
	using namespace std;

	int duration{ 0 };
	int total{ 0 };

	duration = to_seconds(3, 27);
	cout << duration << "s" << '\n';
	total += duration;

	duration = to_seconds(2, 48);
	cout << duration << "s" << '\n';
	total += duration;

	duration = to_seconds(4, 14);
	cout << duration << "s" << '\n';
	total += duration;

	duration = to_seconds(1, 57);
	cout << duration << "s" << '\n';
	total += duration;

	duration = to_seconds(6, 28);
	cout << duration << "s" << '\n';
	total += duration;

	cout << "total = " << total << "s\n";

	int hours{ 0 };
	int minutes{ 0 };
	int seconds{ 0 };

	from_seconds(total, hours, minutes, seconds);

	cout
		<< hours << "h "
		<< minutes << "m "
		<< seconds << "s "
		<< endl;
}
