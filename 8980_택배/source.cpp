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

	// 받는 마을 > 보내는 마을
	// 
	// 받는 마을 - 보내는 마을?


	//  N : 마을 수
	//    2 <= N <= 2000
	
	//  C : 트럭의 용량
	//    1 <= C <= 10000

	//  M : 박스 정보 개수
	//    1 <= M <= 10000
	
	// 보내는 마을 / 받는 마을 / 박스 개수(1<= c <= 10000)

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

	int weight_truck{}; // 0으로 초기화

	vector<BOX> box_truck;

	// false면, 바꿈 맞으니까, 안바꾼다!
	// 1. 받는 마을 오름차순 정렬
	std::sort(box_info.begin(), box_info.end(),
		[](BOX left, BOX right) -> bool {
			
			return left.to < right.to;
		});

	// 2. 보내는 마을 내림차순 정렬
	//   받는 마을 주소는 같아야 함
	std::sort(box_info.begin(), box_info.end(),
		[](BOX left, BOX right) -> bool {
			if (left.to == right.to) {
				return left.from > right.from;
			}
			else {
				return true;
			}
		});

	// 생각해야할 거 하나 더..
	// 제한 용량이 40이라면
	// 10, 20만 집고
	// 2->3/10을 집어야 함
	// 그런데 1->2로 내리고, 2->3을 집을 수가 있음
	// 따라서, 1->4/10만큼 집어야 함

	// if (집은 화물 중
	//     받는 마을 번호를, 보내는 마을에서 검색했을때
	//     있다면,)
	//      >> 그 용량만큼 더 집어도 됨

	// 마을 돌면서
	for (int i = 0; i < N; ++i)
	{
		// 화물 내리기
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

		// 화물 싣기 - 실을 때, box_info에서 삭제
		// 현재 마을 주소는 i + 1
		for (auto it = box_info.begin(); it != box_info.end();)
		{
			// 화물 집기 전, find해서 검사, 
			// 만약 찾은 그 화물이
			// 받는 마을이 크거나 같다면 무시

			// 남은 용량이 없다면 break
			if (remain_weight <= 0)
			{
				break;
			}

			// 보류 박스가 비었다면
			if (next_box.empty())
			{
				// 시작 위치가 현재 위치라면
				if (it->from == i + 1)
				{
					// 그냥 넣기!
					box_truck.emplace_back(*it);
					int w = clamp(it->weight, 0, remain_weight);
					weight_truck += w;
					remain_weight -= w;

					// 실었다면 삭제
					box_info.erase(it);
				}
				// 2 -> 3 / 10
				// 시작 위치기 현재 위치와 다르다면
				else
				{
					next_box.emplace_back(*it);
					// 박스 위치 보류해두기
				}
			}
			// 보류 박스가 있음
			// 도착 위치 비교 필요....?
			// 근데 이미 정렬되어있는데?
			// 이미 도착 위치가 빠른건 앞쪽에 있잖아
			// 
			// 넣은거 자체로 무게만 빼고 고려해야 한다는 뜻!
			

			else
			{
				// if (it->to <= 
			}


			// 한두개가 아니라면..?
				// copy_if
				// for_each 사용

			// begin -> end
			// 이미 정렬된 데이터

			// 
			for_each(box_info.begin(), box_info.end(),
				[&box_truck, &weight_truck, &i, &box_info, &weight_limit]
				(const BOX& box) {
					int remain_weight{ weight_limit - weight_truck };
					//if (&box == &box_info.back())
					//{
					//	// 마지막 요소일 경우
					//}

					if (box.from == i + 1)
					{
						// from이 현재 마을이라면
						// 실어도 되는건지
						
						for (const auto& b : box_info)
						{

						}
					}

					else
					{
						// capacity를 줄여야 함

					}
				});


			// 화물이 가득 찼다면 break;
		}
	}

	//  1	2	10
	//	2	3	10
	//	1	3	20
	//	1	4	30

	//	2	4	20
	//	3	4	20




	// if   (truck weight limit => 40)
	// 보내는 마을 1
	// 모두 집어버리면?
	// 받는 마을이 너무 멀다면
	// 1.  1 -> 20 / 40
	// 2.  2 -> 3  / 40
	// 3.  3 -> 4  / 40

	// 이런 상황이 되면 
	// 2, 3번 화물을 못집어서
	// 20번 마을까지 가면서 -40 손해
	// 무식한 greedy -> 해결 X

	// 마을 수가 2000 이하이기 때문..
	// 
	// || 그럼 무슨 화물을 집어야 하나. 조건식?

	// 손해를 최대한 덜 보는 순서대로 정렬


	//  6 60
	//	5
	//	1 2 30
	//	3 4 40
	//	2 5 70
	//	5 6 60
	//	1 6 40

	// 2번 마을에서 20만큼 집어야 함!
	// 그다음 마을 3 4 40을 전부 집어야 하기 때문
	// ex?
	 // 3 5 40
	 // 2 5 70
	// 3번에 내리는건 없기 때문에 집을 필요가 X
	// 그렇다면
	// 받는 마을 순으로 정렬하되
	// 순차로 도는데 앞에 정렬된게 있다면
	// 그 택배의 용량만큼 뺀 나머지 제한 용량만큼만 집기

	// 그럼 container를 뭘 쓰냐
	// vector<array>?



	return 0;
}
