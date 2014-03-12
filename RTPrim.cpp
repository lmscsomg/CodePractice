/
 *Some problems on prime
 *Time:2014.3.12
 *Tag:Prime
 */
#include <iostream>
#include <vector>
using namespace std;
//素数测试
bool is_prime(int n){
  for(int i=2; i*i<=n; i++){
    if(n%i==0)
      return false;
  }
  return true;
}

//约数枚举
vector<int> disivor(int n){
  vector<int> res;
  for(int i=0;i*i<=n:i++){
    if(n%i==0){
      res.push_back(i);
      if(i!=n/i)
	res.push_back(n/i);
    }
  }
  return res;
}


