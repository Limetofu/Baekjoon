#include <iostream>
#include <string>
#include <vector>

int main(void)
{
	int CaseCount{};
	std::cin >> CaseCount;

	int TypoNum{};
	std::string str{};
	std::vector<std::string> TextVec{};

	for (int i = 0; i < CaseCount; ++i)
	{
		std::cin >> TypoNum >> str;
		if (str.length() > TypoNum - 1)
		{
			str.erase(TypoNum - 1, 1);
			TextVec.emplace_back(str);
		}
		else
		{
			return 1;
		}
	}

	for (const std::string& T : TextVec)
	{
		std::cout << T << std::endl;
	}

	return 0;
}