#include <iostream>

int main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	//(A + B) % C            ((A % C) + (B % C)) % C
	//(A ¡¿ B) % C            ((A % C) ¡¿ (B % C)) % C
	int A, B, C;
	std::cin >> A >> B >> C;

	std::cout << (A + B) % C << std::endl;
	std::cout << ((A % C) + (B % C)) % C << std::endl;
	std::cout << (A * B) % C << std::endl;
	std::cout << ((A % C) * (B % C)) % C << std::endl;

	return 0;
}