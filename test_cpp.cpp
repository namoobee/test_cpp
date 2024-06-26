#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class BankAccount
{
private:
	int balance = 1000; // 예금된 금액(공유자원)
	mutex mtx;

public:
	// 입금
	void deposit(int amount)
	{
		mtx.lock(); // 잠금
		balance += amount;
		cout << amount << "원을 입금합니다." << endl;
		cout << "계좌의 잔고는 " << balance << "원 입니다." << endl;
		mtx.unlock(); // 잠금 해제
	}
	// 출금
	void withdraw(int amount)
	{
		mtx.lock();
		if (balance >= amount)
		{
			balance -= amount;
			cout << amount << "원을 출금합니다." << endl;
		}
		else
		{
			cout << "잔고가 부족합니다." << endl;
		}
		cout << "계좌의 잔고는 " << balance << "원 입니다." << endl;
		mtx.unlock();
	}
};

// count 횟수만큼 amount를 입금(deposit)
void deposit_iter(BankAccount& account, int amount, int count)
{
	for (int i = 0; i < count; ++i)
	{
		account.deposit(amount);
	}
}
// count 횟수만큼 amount를 출금 (withdraw)
void withdraw_iter(BankAccount& account, int amount, int count)
{
	for (int i = 0; i < count; ++i)
	{
		account.withdraw(amount);
	}
}
int main()
{
	BankAccount account;

	// 스레드를 사용하여 입금과 출금 수행
	thread deposit_thread(deposit_iter, ref(account), 100, 100);
	thread withdraw_thread(withdraw_iter, ref(account), 100, 100);

	// 스레드가 종료될 때까지 대기
	deposit_thread.join();
	withdraw_thread.join();

	return 0;
}