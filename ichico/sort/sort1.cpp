//국영수
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct student
{
  string name;
  int lang;
  int engl;
  int math;
}student;

bool cmp(student s1, student s2){
  if(s1.lang == s2.lang){
    if(s1.engl == s2.engl){
      if(s1.math == s2.math){
        return s1.name < s2.name;
      }
      return s1.math > s2.math;
    }
    return s1.engl < s2.engl;
  }
  return s1.lang > s2.lang;
}

int main(){

  int N;

  cin >> N;

  vector<student> sts;
  for(int i=0; i<N; i++){
    student st;
    cin >> st.name >> st.lang >> st.engl >> st.math;
    sts.push_back(st);
  }

  sort(sts.begin(), sts.end(), cmp);

  for(int i=0; i<sts.size(); i++){
    cout << sts[i].name << "\n"
  }

  return 0;
}