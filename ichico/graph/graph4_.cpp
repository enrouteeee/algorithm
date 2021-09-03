//행성 터널 백준-2887
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 노드의 개수
int n;
int parent[100001]; // 부모 테이블 초기화
// 모든 간선을 담을 리스트와, 최종 비용을 담을 변수
vector<pair<int, pair<int, int> > > edges;
int result;

// 특정 원소가 속한 집합을 찾기
int findParent(int x) {
    // 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

// 두 원소가 속한 집합을 합치기
void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main(void) {
    cin >> n;

    // 부모 테이블상에서, 부모를 자기 자신으로 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<pair<int, int> > x;
    vector<pair<int, int> > y;
    vector<pair<int, int> > z;

    // 모든 노드에 대한 좌표 값 입력받기
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    // 인접한 노드들로부터 간선 정보를 추출하여 처리
    for (int i = 0; i < n - 1; i++) {
        // 비용순으로 정렬하기 위해서 튜플의 첫 번째 원소를 비용으로 설정
        edges.push_back({x[i + 1].first - x[i].first, {x[i].second, x[i + 1].second}});
        edges.push_back({y[i + 1].first - y[i].first, {y[i].second, y[i + 1].second}});
        edges.push_back({z[i + 1].first - z[i].first, {z[i].second, z[i + 1].second}});
    }

    // 간선을 비용순으로 정렬
    sort(edges.begin(), edges.end());

    // 간선을 하나씩 확인하며
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // 사이클이 발생하지 않는 경우에만 집합에 포함
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            result += cost;
        }
    }

    cout << result << '\n';
}

/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct point
{
  int x;
  int y;
  int z;
}point;


int dist(point p1, point p2){
  return min(min(abs(p1.x - p2.x), abs(p1.y - p2.y)), abs(p1.z - p2.z));
}

int parent[100001];

int findP(int a){
  if(a == parent[a])
    return a;
  return parent[a] = findP(parent[a]);
}

void uni(int a, int b){
  a = parent[a];
  b = parent[b];
  if(a < b)
    parent[b] = a;
  else
    parent[a] = b;
}

int main(){

  int N;
  cin >> N;

  vector<point> ps;
  for(int i=0; i<N; i++){
    int a, b, c;
    cin >> a >> b >> c;
    point p_;
    p_.x = a;
    p_.y = b;
    p_.z = c;
    ps.push_back(p_);
  }

  priority_queue<pair<int,pair<int,int>>> pq;
  for(int i=0; i<N-1; i++){
    for(int j=i+1; j<N; j++){
      int d = dist(ps[i],ps[j]);
      pq.push(make_pair(-d,make_pair(i,j)));
    }
  }

  for(int i=0; i<N; i++)
    parent[i] = i;

  int cnt = 0;
  int ans = 0;
  while(cnt != N-1){
    int d = -pq.top().first;
    int e1 = pq.top().second.first;
    int e2 = pq.top().second.second;
    pq.pop();

    if(findP(e1) == findP(e2))
      continue;
    
    uni(e1, e2);
    cnt++;
    ans += d;
  }

  cout << ans;

  return 0;
}
*/