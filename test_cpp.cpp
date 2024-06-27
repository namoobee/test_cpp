#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;
condition_variable cv;
bool alarm_set = false;


void timer(int time)
{
	cout << "남은시간" << endl;
	for (int i = time; i > 0; --i)
	{
		this_thread::sleep_for(chrono::seconds(1));
		{
			lock_guard<mutex> lock(mtx);
			cout << i << endl;
		}
	}
	{
		lock_guard<mutex> lock(mtx);
		alarm_set = true;
	}
	cv.notify_one();
}

void wait_for_alarm()
{
	unique_lock<mutex> lock(mtx);
	cv.wait(lock, [] { return alarm_set; });
	cout << "알람이 울립니다!!" << endl;
}

int main()
{
	cout << "알람을 기다리는 중..." << endl;

	int alarmTime;
	cout << "설정할 알람의 시간을 입력하세요(초 단위): ";
	cin >> alarmTime;

	thread timerThread(timer, alarmTime);
	thread waitThread(wait_for_alarm);

	timerThread.join();
	waitThread.join();

	return 0;
}