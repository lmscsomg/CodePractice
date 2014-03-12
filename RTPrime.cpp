/*
 Time:2014.3.12
 Tag:Prime
 */
#include <iostream>
#include <vector>

//判断素数
bool is_Prime(int s){
  for(int i=2; i*i<=n; i++){
    if(n % i==0)
      return false;
  }
  return true;
}


//约数枚举
vector<int> divisor(int n){
  vector<int> res;
  for(int i=2; i*i<=m; i++){
    if(n % i==0){
      res.pop_back(i);
      if(i!=n/i)
	res.pop_back(n/i);
    }
  }
    return res;
}
