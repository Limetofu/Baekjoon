#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

typedef struct BOX
{
	int from;
	int to;
	int weight;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �޴� ���� > ������ ����
	// 
	// �޴� ���� - ������ ����?


	//  N : ���� ��
	//    2 <= N <= 2000
	
	//  C : Ʈ���� �뷮
	//    1 <= C <= 10000

	//  M : �ڽ� ���� ����
	//    1 <= M <= 10000
	
	// ������ ���� / �޴� ���� / �ڽ� ����(1<= c <= 10000)

	// which container?
	// greedy -> 
	// 
	// truck info
	//  - village num
	//  - info of box
	//	  -> from vill
	//    -> to vill
	//    -> weight

	// init

	int N, weight_limit, M;
	cin >> N >> weight_limit;
	cin >> M;

	vector<BOX> box_info(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> box_info[i].from >> box_info[i].to >> box_info[i].weight;
	}

	int weight_truck{}; // 0���� �ʱ�ȭ

	vector<BOX> box_truck;

	// false��, �ٲ� �����ϱ�, �ȹٲ۴�!
	// 1. �޴� ���� �������� ����
	std::sort(box_info.begin(), box_info.end(),
		[](BOX left, BOX right) -> bool {
			
			return left.to < right.to;
		});

	// 2. ������ ���� �������� ����
	//   �޴� ���� �ּҴ� ���ƾ� ��
	std::sort(box_info.begin(), box_info.end(),
		[](BOX left, BOX right) -> bool {
			if (left.to == right.to) {
				return left.from > right.from;
			}
			else {
				return true;
			}
		});

	// �����ؾ��� �� �ϳ� ��..
	// ���� �뷮�� 40�̶��
	// 10, 20�� ����
	// 2->3/10�� ����� ��
	// �׷��� 1->2�� ������, 2->3�� ���� ���� ����
	// ����, 1->4/10��ŭ ����� ��

	// if (���� ȭ�� ��
	//     �޴� ���� ��ȣ��, ������ �������� �˻�������
	//     �ִٸ�,)
	//      >> �� �뷮��ŭ �� ��� ��

	// ���� ���鼭
	for (int i = 0; i < N; ++i)
	{
		// ȭ�� ������
		for (auto it = box_truck.begin(); it != box_truck.end();)
		{
			if (it->to == i + 1)
			{
				weight_truck -= it->weight;
				it = box_truck.erase(it);
			}
			else
			{
				++it;
			}
		}

		vector<BOX> next_box;
		int remain_weight{ weight_limit - weight_truck };

		// ȭ�� �Ʊ� - ���� ��, box_info���� ����
		// ���� ���� �ּҴ� i + 1
		for (auto it = box_info.begin(); it != box_info.end();)
		{
			// ȭ�� ���� ��, find�ؼ� �˻�, 
			// ���� ã�� �� ȭ����
			// �޴� ������ ũ�ų� ���ٸ� ����

			// ���� �뷮�� ���ٸ� break
			if (remain_weight <= 0)
			{
				break;
			}

			// ���� �ڽ��� ����ٸ�
			if (next_box.empty())
			{
				// ���� ��ġ�� ���� ��ġ���
				if (it->from == i + 1)
				{
					// �׳� �ֱ�!
					box_truck.emplace_back(*it);
					int w = clamp(it->weight, 0, remain_weight);
					weight_truck += w;
					remain_weight -= w;

					// �Ǿ��ٸ� ����
					box_info.erase(it);
				}
				// 2 -> 3 / 10
				// ���� ��ġ�� ���� ��ġ�� �ٸ��ٸ�
				else
				{
					next_box.emplace_back(*it);
					// �ڽ� ��ġ �����صα�
				}
			}
			// ���� �ڽ��� ����
			// ���� ��ġ �� �ʿ�....?
			// �ٵ� �̹� ���ĵǾ��ִµ�?
			// �̹� ���� ��ġ�� ������ ���ʿ� ���ݾ�
			// 
			// ������ ��ü�� ���Ը� ���� ����ؾ� �Ѵٴ� ��!
			

			else
			{
				// if (it->to <= 
			}


			// �ѵΰ��� �ƴ϶��..?
				// copy_if
				// for_each ���

			// begin -> end
			// �̹� ���ĵ� ������

			// 
			for_each(box_info.begin(), box_info.end(),
				[&box_truck, &weight_truck, &i, &box_info, &weight_limit]
				(const BOX& box) {
					int remain_weight{ weight_limit - weight_truck };
					//if (&box == &box_info.back())
					//{
					//	// ������ ����� ���
					//}

					if (box.from == i + 1)
					{
						// from�� ���� �����̶��
						// �Ǿ �Ǵ°���
						
						for (const auto& b : box_info)
						{

						}
					}

					else
					{
						// capacity�� �ٿ��� ��

					}
				});


			// ȭ���� ���� á�ٸ� break;
		}
	}

	//  1	2	10
	//	2	3	10
	//	1	3	20
	//	1	4	30

	//	2	4	20
	//	3	4	20




	// if   (truck weight limit => 40)
	// ������ ���� 1
	// ��� ���������?
	// �޴� ������ �ʹ� �ִٸ�
	// 1.  1 -> 20 / 40
	// 2.  2 -> 3  / 40
	// 3.  3 -> 4  / 40

	// �̷� ��Ȳ�� �Ǹ� 
	// 2, 3�� ȭ���� �����
	// 20�� �������� ���鼭 -40 ����
	// ������ greedy -> �ذ� X

	// ���� ���� 2000 �����̱� ����..
	// 
	// || �׷� ���� ȭ���� ����� �ϳ�. ���ǽ�?

	// ���ظ� �ִ��� �� ���� ������� ����


	//  6 60
	//	5
	//	1 2 30
	//	3 4 40
	//	2 5 70
	//	5 6 60
	//	1 6 40

	// 2�� �������� 20��ŭ ����� ��!
	// �״��� ���� 3 4 40�� ���� ����� �ϱ� ����
	// ex?
	 // 3 5 40
	 // 2 5 70
	// 3���� �����°� ���� ������ ���� �ʿ䰡 X
	// �׷��ٸ�
	// �޴� ���� ������ �����ϵ�
	// ������ ���µ� �տ� ���ĵȰ� �ִٸ�
	// �� �ù��� �뷮��ŭ �� ������ ���� �뷮��ŭ�� ����

	// �׷� container�� �� ����
	// vector<array>?



	return 0;
}
