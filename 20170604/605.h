#include<vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int count=0;
		flowerbed.push_back(0);
        for(int i=0;i<flowerbed.size()-1;){
			if(flowerbed[i]==1)
			{
				i+=2;
			}
			else if(flowerbed[i]==0&&flowerbed[i+1]==0)
			{
				count++;
				i+=2;
			}
			else 
			{
				i++;
				while(flowerbed[i]==1&& i<flowerbed.size())
				{
					i++;
				}
				i++;
			}
        }
		return n<=count;
    }
};