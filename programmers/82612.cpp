using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long sum = 0;
    long long cost = 0;
    for(int i=1; i<=count; i++){
        cost += price;
        sum += cost;
    }
    answer = sum - money;
    if(answer <= 0)
        return 0;

    return answer;
}